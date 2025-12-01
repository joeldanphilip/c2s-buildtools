/*
 * CDAC SPI controller driver (master mode only)
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License version 2 as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 */

#include <linux/clk.h>
#include <linux/delay.h>
#include <linux/gpio.h>
#include <linux/interrupt.h>
#include <linux/io.h>
#include <linux/module.h>
#include <linux/of_irq.h>
#include <linux/of_address.h>
#include <linux/platform_device.h>
#include <linux/pm_runtime.h>
#include <linux/spi/spi.h>

/* Name of this driver */
#define CDAC_SPI_NAME		"cdac-spi"

/* Register offset definitions */
#define CDAC_SPI_CR		0x00 /* Control Register */
#define CDAC_SPI_CS		BIT(8)
#define CDAC_SPI_TX_INTR	BIT(7)
#define CDAC_SPI_RX_INTR        BIT(6)
#define CDAC_SPI_CPOL           BIT(5)
#define CDAC_SPI_CPHA           BIT(4)
#define CDAC_SPI_LSB		BIT(3)
#define CDAC_SPI_DEFAULT_CHIP   0x00000004
#define CDAC_SPI_CR_DEFAULT	(CDAC_SPI_DEFAULT_CHIP)

#define CDAC_SPI_STAT			0x04 /* Status Register */
#define CDAC_SPI_TX_STAT		BIT(7)
#define CDAC_SPI_RX_STAT BIT(6)
#define CDAC_SPI_OVERRUN		BIT(5)
#define CDAC_SPI_TX_BUSY		BIT(4)
#define CDAC_SPI_TX_INT_STAT		BIT(3)
#define CDAC_SPI_RX_INT_STAT		BIT(2)

#define CDAC_SPI_BAUD			0x08 /* Baud Rate Register */
#define CDAC_SPI_DEFAULT_BAUD		0    /* Divisor is 4 */
#define CDAC_SPI_TXD			0x0C /* Transmit Data Register */

#define CDAC_SPI_RXD			0x10 /* Receive Data Register */

/* Default number of chip select lines */
#define CDAC_SPI_DEFAULT_NUM_CS		4
#define SPI_CHIP_SEL_MASK 0xFFFC
#define SPI_AUTOSUSPEND_TIMEOUT		6000
/*
 * struct cdac_spi - This definition defines spi driver instance
 */
struct cdac_spi {
	struct spi_transfer *current_transfer;
	void __iomem *regs;
	struct clk *spi_clock;
	u32 speed_hz;
	spinlock_t lock;
	unsigned int tx_bytes_rem;
	unsigned int rx_bytes_rem;
	u32 is_decoded_cs;
	u32 status;
	bool transfer_failed;
};

struct cdac_spi_device_data {
	bool gpio_requested;
};

/* Macros for the SPI controller read/write */
static inline u32 cdac_spi_read(struct cdac_spi *xspi, u32 offset)
{
	u32 val;
	val = readl(xspi->regs + offset);
	return val;
}

static inline void cdac_spi_write(struct cdac_spi *xspi, u32 offset, u32 val)
{
	writel(val, xspi->regs + offset);
}

/**
 * cdac_spi_init_hw - Initialize the hardware and configure the SPI controller
 * @xspi:	Pointer to the cdac_spi structure
 *
 */
static void cdac_spi_init_hw(struct cdac_spi *xspi)
{
	u32 ctrl_reg;

	ctrl_reg = CDAC_SPI_CR_DEFAULT;

	if (xspi->is_decoded_cs)
		ctrl_reg |= ctrl_reg;//CDAC_SPI_CR_PERI_SEL;

	cdac_spi_write(xspi, CDAC_SPI_CR, ctrl_reg); // setting control reg
	cdac_spi_write(xspi, CDAC_SPI_BAUD, CDAC_SPI_DEFAULT_BAUD); // setting baud reg

	/* Clear the RX FIFO */
	while (cdac_spi_read(xspi, CDAC_SPI_STAT) & CDAC_SPI_RX_STAT){
			cdac_spi_read(xspi, CDAC_SPI_RXD);
	}
}

/**
 * set the logic level of the chip select line. May be called from interrupt context.
 * cdac_spi_chipselect - Select or deselect the chip select line
 * @spi:	Pointer to the spi_device structure
 * @is_high:	Select(0) or deselect (1) the chip select line
 */
static void cdac_spi_chipselect(struct spi_device *spi, bool is_high)
{
	struct cdac_spi *xspi ;
	u32 ctrl_reg;


	xspi = spi_master_get_devdata(spi->master);
	ctrl_reg = cdac_spi_read(xspi, CDAC_SPI_CR);

	if (is_high){
		/* deselect */
		ctrl_reg &= ~CDAC_SPI_CS;
	}
	else{
		/*select*/
		ctrl_reg |= CDAC_SPI_CS;
	}

	cdac_spi_write(xspi, CDAC_SPI_CR, ctrl_reg);
}

/**
 * cdac_spi_config_clock_freq - Sets clock frequency
 * Sets the requested clock frequency.
 */
static void cdac_spi_config_clock_freq(struct spi_device *spi,
				       struct spi_transfer *transfer)
{
	struct cdac_spi *xspi = spi_master_get_devdata(spi->master);
	u32 baud_rate_val = 0, frequency, baud_divisor = 4;

	if (xspi->speed_hz != transfer->speed_hz) {
		frequency = clk_get_rate(xspi->spi_clock);
		// Set the clock frequency
	  while(baud_divisor < 2048){  /* C-DAC SPI Clock Frequency Divisor ranges from 4 to 2048 */
			if(transfer->speed_hz >= (frequency / baud_divisor)){
				break;
			}
			baud_rate_val++;
			baud_divisor = baud_divisor << 1;  /* Clock Frequency Divisor increses as powers of 2 */
		}
		xspi->speed_hz = transfer->speed_hz;
		cdac_spi_write(xspi, CDAC_SPI_BAUD, baud_rate_val << 4);
	}
}

static inline void cdac_spi_rx(struct cdac_spi *xspi)
{
	unsigned int len = xspi->current_transfer->len;
	unsigned int remaining = xspi->rx_bytes_rem;
	u8  *rx_buf = xspi->current_transfer->rx_buf;

	if (!remaining)
		return;

	rx_buf[len - remaining] = cdac_spi_read(xspi, CDAC_SPI_RXD);
	xspi->rx_bytes_rem--;
}

/**
 * cdac_spi_irq - Interrupt service routine of the SPI controller
 * Return:	IRQ_HANDLED when handled; IRQ_NONE otherwise.
 */
static irqreturn_t cdac_spi_irq(int irq, void *dev_id)
{
	struct spi_master *master;
	struct cdac_spi *xspi;
	u32 ctrl_reg;

	master = dev_id; // controller
	xspi = spi_master_get_devdata(master);

	spin_lock(&xspi->lock);
	xspi->status = cdac_spi_read(xspi, CDAC_SPI_STAT);

	if (xspi->status & CDAC_SPI_OVERRUN) {
		xspi->transfer_failed = true;
		ctrl_reg = cdac_spi_read(xspi, CDAC_SPI_CR);
		cdac_spi_write(xspi, CDAC_SPI_CR, ctrl_reg & ~CDAC_SPI_RX_INTR); // Disable RX interrupt.
		spin_unlock(&xspi->lock);
		return IRQ_HANDLED;
	}

	if (xspi->status & CDAC_SPI_RX_INT_STAT) {
		cdac_spi_rx(xspi);
		spin_unlock(&xspi->lock);
		return IRQ_HANDLED;
	}

	spin_unlock(&xspi->lock);
	return IRQ_NONE;
}

//set up the controller to transfer a single message.
static int cdac_prepare_message(struct spi_master *master,
				struct spi_message *msg)
{
	u32 ctrl_reg;
	struct cdac_spi *xspi = spi_master_get_devdata(master);
	struct spi_device *spi = msg->spi;
	u32 *controller_state = spi->controller_state;
	/* Wait while SPI busy */
	do {
		xspi->status = cdac_spi_read(xspi, CDAC_SPI_STAT);
	} while (xspi->status & CDAC_SPI_TX_BUSY);

	ctrl_reg = (*controller_state | CDAC_SPI_RX_INTR);
	cdac_spi_write(xspi, CDAC_SPI_CR, ctrl_reg);
	return 0;
}
//undo any work done by prepare_message.
static int cdac_unprepare_message(struct spi_master *master,
				struct spi_message *msg)
{
	u32 ctrl_reg;
	struct cdac_spi *xspi = spi_master_get_devdata(master);
	struct spi_device *spi = msg->spi;
	u32 *controller_state = spi->controller_state;
	ctrl_reg = (*controller_state & ~CDAC_SPI_RX_INTR);
	cdac_spi_write(xspi, CDAC_SPI_CR, ctrl_reg);
	return 0;
}


static inline void cdac_spi_tx(struct cdac_spi *xspi)
{
	unsigned int len = xspi->current_transfer->len;
	unsigned int remaining = xspi->tx_bytes_rem;
	const u8  *tx_buf = xspi->current_transfer->tx_buf;
	if (!remaining){
		return;
	}

	if (((xspi->status & CDAC_SPI_TX_BUSY)==0) && (xspi->status & CDAC_SPI_TX_STAT)){
			cdac_spi_write(xspi, CDAC_SPI_TXD, tx_buf[len - remaining]);
			xspi->tx_bytes_rem--;
	}
}

/**
 * cdac_transfer_one -
 */
static int cdac_transfer_one(struct spi_master *master,
			     struct spi_device *spi,
			     struct spi_transfer *transfer)
{
	struct cdac_spi *xspi = spi_master_get_devdata(master);

	cdac_spi_config_clock_freq(spi, transfer);

	xspi->transfer_failed = false;
	xspi->current_transfer = transfer;
	xspi->tx_bytes_rem = transfer->len;
	xspi->rx_bytes_rem = transfer->len;

	while ((xspi->tx_bytes_rem || xspi->rx_bytes_rem) && !xspi->transfer_failed) {
		xspi->status = cdac_spi_read(xspi, CDAC_SPI_STAT);
		if (xspi->status & CDAC_SPI_OVERRUN) {
			xspi->transfer_failed = true;
		}
		if (xspi->status & CDAC_SPI_RX_STAT) {
			cdac_spi_rx(xspi);
		}
		cdac_spi_tx(xspi);
		cpu_relax();
	}

	if (xspi->transfer_failed) {
		return -EIO;
	}

	return 0;
}
/*
updates the device mode and clocking records used by a device’s SPI controller; protocol code may call this.
This must fail if an unrecognized or unsupported mode is requested.
It’s always safe to call this unless transfers are pending on the device whose settings are being modified.
*/
static int cdac_spi_setup(struct spi_device *spi)
{
	u32 ctrl_reg;
	int ret = -EINVAL;
	u32 *cdac_controller_state = spi->controller_state;
	struct cdac_spi *xspi = spi_master_get_devdata(spi->master);

	ctrl_reg = cdac_spi_read(xspi, CDAC_SPI_CR);

	if (spi->mode & SPI_CPOL)
		ctrl_reg |= CDAC_SPI_CPOL;
	else
		ctrl_reg &= ~CDAC_SPI_CPOL;

	if (spi->mode & SPI_CPHA)
		ctrl_reg |= CDAC_SPI_CPHA;
	else
		ctrl_reg &= ~CDAC_SPI_CPHA;
	if (spi->mode & SPI_LSB_FIRST)
		ctrl_reg |= CDAC_SPI_LSB;
	else
		ctrl_reg &= ~CDAC_SPI_LSB;

	if (spi->mode & SPI_LOOP){
		return ret;
	}

	/* setting chip select */
	ctrl_reg = (ctrl_reg & SPI_CHIP_SEL_MASK) | (spi->chip_select & 0x3);

	// this seems to be the first time we're here
	if (!cdac_controller_state) {
		cdac_controller_state = kzalloc(sizeof(*cdac_controller_state), GFP_KERNEL);
		if (!cdac_controller_state)
			return -ENOMEM;
		spi->controller_state = cdac_controller_state;
	}
	*cdac_controller_state = ctrl_reg;
	cdac_spi_write(xspi, CDAC_SPI_CR, ctrl_reg);
	return 0;
}

static void cdac_spi_cleanup(struct spi_device *spi)
{
	struct cdac_spi_device_data *cdac_spi_data = spi_get_ctldata(spi);
	if (cdac_spi_data) {
		if (cdac_spi_data->gpio_requested)
			gpio_free(spi->cs_gpio);
		kfree(cdac_spi_data);
		spi_set_ctldata(spi, NULL);
	}
}

/*
 * cdac_spi_probe - Probe method for the SPI driver
 * This function initializes the driver data structures and the hardware.
 */
static int cdac_spi_probe(struct platform_device *pdev)
{
	int ret = 0, irq;
	struct spi_master *master;
	struct cdac_spi *xspi;
	struct resource *res;
	u32 num_cs,max_freq;

	master = spi_alloc_master(&pdev->dev, sizeof(*xspi));
	if (!master)
		return -ENOMEM;

	xspi = spi_master_get_devdata(master);
	master->dev.of_node = pdev->dev.of_node;
	platform_set_drvdata(pdev, master);

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	xspi->regs = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(xspi->regs)) {
		ret = PTR_ERR(xspi->regs);
		goto remove_master;
	}

	xspi->spi_clock = devm_clk_get(&pdev->dev, "spi_clock");
	if (IS_ERR(xspi->spi_clock)) {
		dev_err(&pdev->dev, "spi_clock clock not found.\n");
		ret = PTR_ERR(xspi->spi_clock);
		goto remove_master;
	}

	ret = clk_prepare_enable(xspi->spi_clock);
	if (ret) {
		dev_err(&pdev->dev, "Unable to enable device clock.\n");
		goto remove_master;
	}

	xspi->speed_hz = clk_get_rate(xspi->spi_clock) / 4;

	/* This is optional parameter */
	if (of_property_read_u32(pdev->dev.of_node, "spi-max-frequency", &max_freq))
		max_freq = xspi->speed_hz;

	if (max_freq >  xspi->speed_hz) {
			dev_err(&pdev->dev, "invalid clock frequency %d\n", max_freq);
			return -ENXIO;
	}

	ret = of_property_read_u32(pdev->dev.of_node, "num-cs", &num_cs);
	if (ret < 0)
		master->num_chipselect = CDAC_SPI_DEFAULT_NUM_CS;
	else
		master->num_chipselect = num_cs;

	ret = of_property_read_u32(pdev->dev.of_node, "is-decoded-cs",
				   &xspi->is_decoded_cs);
	if (ret < 0)
		xspi->is_decoded_cs = 0;

	/* SPI controller initializations */
	cdac_spi_init_hw(xspi);

	irq = platform_get_irq(pdev, 0);
	if (irq <= 0) {
		ret = -ENXIO;
		dev_err(&pdev->dev, "irq number is invalid\n");
		goto clk_dis_all;
	}

	ret = devm_request_irq(&pdev->dev, irq, cdac_spi_irq,
			       0, pdev->name, master);
	if (ret != 0) {
		ret = -ENXIO;
		dev_err(&pdev->dev, "request_irq failed\n");
		goto clk_dis_all;
	}
	master->prepare_message = cdac_prepare_message;
	master->unprepare_message = cdac_unprepare_message;
	master->transfer_one = cdac_transfer_one;
	master->set_cs = cdac_spi_chipselect;
	master->setup = cdac_spi_setup;
	master->cleanup = cdac_spi_cleanup;
	master->auto_runtime_pm = true;
	master->mode_bits = SPI_CPOL | SPI_CPHA;
	master->flags = SPI_MASTER_MUST_RX | SPI_MASTER_MUST_TX;
	master->max_speed_hz = max_freq;
	master->bits_per_word_mask = SPI_BPW_MASK(8);

	ret = spi_register_master(master);
	if (ret) {
		dev_err(&pdev->dev, "spi_register_master failed\n");
		goto clk_dis_all;
	}

	dev_info(&pdev->dev, "CDAC SPI Master Controller at 0x%08lx (irq %d)\n",(unsigned long)res->start, irq);
	return ret;

clk_dis_all:
	clk_disable_unprepare(xspi->spi_clock);
remove_master:
	spi_master_put(master);
	return ret;
}

/**
 * cdac_spi_remove - Remove method for the SPI driver
 * @pdev:	Pointer to the platform_device structure
 * Return:	0 on success and error value on error
 */
static int cdac_spi_remove(struct platform_device *pdev)
{
	struct spi_master *master = platform_get_drvdata(pdev);
	struct cdac_spi *xspi = spi_master_get_devdata(master);
	clk_disable_unprepare(xspi->spi_clock);
	spi_unregister_master(master);
	return 0;
}

static const struct of_device_id cdac_spi_of_match[] = {
	{ .compatible = "cdac,spi" },
	{ /* end of table */ }
};
MODULE_DEVICE_TABLE(of, cdac_spi_of_match);

/* cdac_spi_driver - This structure defines the SPI subsystem platform driver */
static struct platform_driver cdac_spi_driver = {
	.probe	= cdac_spi_probe,
	.remove	= cdac_spi_remove,
	.driver = {
		.name = CDAC_SPI_NAME,
		.of_match_table = cdac_spi_of_match,
	},
};

module_platform_driver(cdac_spi_driver);

MODULE_DESCRIPTION("C-DAC Thiruvananthapuram SPI Controller Driver");
MODULE_AUTHOR("Anoop Varghese <vanoop@cdac.in>");
MODULE_LICENSE("GPL v2");
