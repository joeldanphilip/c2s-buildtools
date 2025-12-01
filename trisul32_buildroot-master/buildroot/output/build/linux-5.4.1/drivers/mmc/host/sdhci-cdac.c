/*
 * CDAC SDHCI controller driver
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License version 2 as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 */

#include <linux/err.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#include <linux/clk.h>
#include <linux/module.h>
#include <linux/io.h>
#include <linux/gpio.h>
#include <linux/mmc/card.h>
#include <linux/mmc/host.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/of.h>
#include <linux/of_device.h>

#include "sdhci.h"
#include "sdhci-pltfm.h"

#define ALIGN_32_MASK 0xFFFFFFFC

#define MASK_8_BIT 0xFF

#define SD_FIFO_PARAM		0xe0
#define DIS_PAD_SD_CLK_GATE	0x0400 /* Turn on/off Dynamic SD Clock Gating */
#define CLK_GATE_ON		0x0200 /* Disable/enable Clock Gate */
#define CLK_GATE_CTL		0x0100 /* Clock Gate Control */
#define CLK_GATE_SETTING_BITS	(DIS_PAD_SD_CLK_GATE | \
		CLK_GATE_ON | CLK_GATE_CTL)

#define SD_CLOCK_BURST_SIZE_SETUP	0xe6
#define SDCLK_SEL_SHIFT		8
#define SDCLK_SEL_MASK		0x3
#define SDCLK_DELAY_SHIFT	10
#define SDCLK_DELAY_MASK	0x3c

#define SD_CE_ATA_2		0xea
#define MMC_CARD		0x1000
#define MMC_WIDTH		0x0100

struct sdhci_ersdhc_platdata {
	unsigned int	flags;
	unsigned int	clk_delay_cycles;
	unsigned int	clk_delay_sel;
	bool		clk_delay_enable;
	unsigned int	ext_cd_gpio;
	bool		ext_cd_gpio_invert;
	unsigned int	max_speed;
	u32		host_caps;
	u32		host_caps2;
	unsigned int	quirks;
	unsigned int	quirks2;
	unsigned int	pm_caps;
};

static void ersdhc_reset(struct sdhci_host *host, u8 mask)
{
	//struct platform_device *pdev = to_platform_device(mmc_dev(host->mmc));
	//struct sdhci_ersdhc_platdata *pdata = pdev->dev.platform_data;

	//sdhci_reset(host, mask);

	ktime_t timeout;

	sdhci_writew(host, 0x401, SDHCI_CLOCK_CONTROL); 


	while(!(sdhci_readw(host, SDHCI_CLOCK_CONTROL) & 0x2)){// wait till internal clock stable is 1

	//	printk("SDHCI_CLOCK_CONTROL  : %x",sdhci_readw(host, SDHCI_CLOCK_CONTROL));

	}

	sdhci_writeb(host, mask, SDHCI_SOFTWARE_RESET);
	//printk("SDHCI CDAC MASK: %x",(int)mask);
	if (mask & SDHCI_RESET_ALL) {
		host->clock = 0;
		/* Reset-all turns off SD Bus Power */
		//if (host->quirks2 & SDHCI_QUIRK2_CARD_ON_NEEDS_BUS_ON)
			//sdhci_runtime_pm_bus_off(host);
	}

	/* Wait max 100 ms */
	timeout = ktime_add_ms(ktime_get(), 100);

	/* hw clears the bit when it's done */
	while (sdhci_readb(host, SDHCI_SOFTWARE_RESET) & mask) {
		if (ktime_after(ktime_get(), timeout)) {
			pr_err("%s: Reset 0x%x never completed.\n",
				mmc_hostname(host->mmc), (int)mask);

			sdhci_dumpregs(host);
			return;
		}
		udelay(10);
	}

	//printk("[VEGA RESET VEGA RESET VEGA RESET VEGA RESET VEGA RESET VEGA RESET VEGA RESET VEGA RESET]");
	return;
}

unsigned int cdac_sdhci_timeout_clock(struct sdhci_host *host) {
	printk(" Timeout function");
	return 25000;
}
/*
static void cdac_sdhci_write_b (struct sdhci_host *host, u8 val, int reg){
	u32 new_val = 0;
	int new_reg;
	u8 * val_pos = (u8 *) &new_val;

	//mdelay(200);
	new_reg = (reg & ALIGN_32_MASK);          // align to 32 bit address
	new_val = readl(host->ioaddr + new_reg);  // read 32 bit value
    val_pos+= (reg & ~ALIGN_32_MASK);         // finding index in 32 bit value
	*val_pos = val;                           //setting value
	//printk("[$$$] W8 reg : %x new_reg : %x val : %x new_val : %x \n",reg, new_reg, val, new_val);
	printk("[08] W  ( %x : %x )  => ( %x : %x )\n", reg, val,  new_reg, new_val);
	//printk(".");
	writel(new_val, host->ioaddr + new_reg);
}

static void cdac_sdhci_write_w (struct sdhci_host *host, u16 val, int reg){
	u32 new_val = 0;
	int new_reg;
	u16 * val_pos = (u16 *) &new_val;

	//mdelay(200);
	new_reg = (reg & ALIGN_32_MASK);          // align to 32 bit address
	new_val = readl(host->ioaddr + new_reg);  // read 32 bit value
    if (reg & ~ALIGN_32_MASK)         // finding index in 32 bit value
		val_pos++;
	*val_pos = val;                           //setting value
	//printk("[$$$] W16 reg : %x new_reg : %x val : %x new_val : %x \n",reg, new_reg, val, new_val);
	//if(reg == 0x2c)
	printk("[16] W  ( %x : %x )  => ( %x : %x )\n", reg, val,  new_reg, new_val);
	//printk(".");
	writel(new_val, host->ioaddr + new_reg);
}

static u8 cdac_sdhci_read_b (struct sdhci_host *host, int reg){
	u32 val = 0;
	int new_reg;
	u8 * ret = (u8 *) &val;

	//mdelay(200);
	new_reg = (reg & ALIGN_32_MASK);          // align to 32 bit address
	val = readl(host->ioaddr + new_reg);  // read 32 bit value
	ret+= (reg & ~ALIGN_32_MASK);         // finding index in 32 bit value
	//if(reg == 0x2c)
	//printk("[$$$] R8 reg : %x new_reg : %x val : %x new_val : %x \n",reg, new_reg, val, *ret);
	//printk("[$$$] R reg : %x val : %x \n", reg, val);
	//printk(".");
	return *ret;
}

static u16 cdac_sdhci_read_w (struct sdhci_host *host, int reg){
	u32 val = 0;
	int new_reg;
	u16 * ret = (u16 *) &val;

	///mdelay(200);
	new_reg = (reg & ALIGN_32_MASK);          // align to 32 bit address
	val = readl(host->ioaddr + new_reg);  // read 32 bit value
	 if (reg & ~ALIGN_32_MASK)         // finding index in 32 bit value
		ret++;
	//if(reg == 0x2c)
//	printk("[$$$] R16 reg : %x new_reg : %x val : %x new_val : %x \n",reg, new_reg, val, *ret);
	//printk("[$$$] R reg : %x val : %x \n", reg, val);
	//printk(".");
	return *ret;
}
*/
void cdac_voltage_switch(struct sdhci_host *host){
	printk("[     VEGA     ] Voltage Switch : %x \n", host->mmc->ios.signal_voltage);

	usleep_range(5000, 6250);
	/*
		switch (host->mmc->ios.signal_voltage) {
	case MMC_SIGNAL_VOLTAGE_330:
		sdhci_writeb(host, SDHCI_POWER_ON | SDHCI_POWER_330, SDHCI_POWER_CONTROL);
		break;
	case MMC_SIGNAL_VOLTAGE_180:
		sdhci_writeb(host, SDHCI_POWER_ON | SDHCI_POWER_180, SDHCI_POWER_CONTROL);
		break;
	default:
		// No signal voltage switch required 
		break;
	}
	*/
}

void cdac_sdhci_set_clock(struct sdhci_host *host, unsigned int clock)
{
	u16 clk;

	host->mmc->actual_clock = 0;

	sdhci_writew(host, 0, SDHCI_CLOCK_CONTROL);

	if (clock == 0)
		return;

	clk = sdhci_calc_clk(host, clock, &host->mmc->actual_clock);
	//printk("CLOCK SET");
	//if(clk==0x400)
		//clk = 0x300;

	sdhci_enable_clk(host, clk);
}


static const struct sdhci_ops ersdhc_sdhci_ops = {
	.set_clock     = sdhci_set_clock,
	.get_max_clock = sdhci_pltfm_clk_get_max_clock,
	.set_bus_width = sdhci_set_bus_width,
	.reset         = ersdhc_reset,
	.set_uhs_signaling = sdhci_set_uhs_signaling,
	.get_timeout_clock = cdac_sdhci_timeout_clock,
	//.write_b = cdac_sdhci_write_b,
	//.write_w = cdac_sdhci_write_w,
	//.read_b = cdac_sdhci_read_b,
	//.read_w = cdac_sdhci_read_w,
	//.voltage_switch = cdac_voltage_switch,
};


#ifdef CONFIG_OF
static const struct of_device_id sdhci_ersdhc_of_match[] = {
	{
		.compatible = "cdac,cdac-sdhci",
	},
	{},
};
MODULE_DEVICE_TABLE(of, sdhci_ersdhc_of_match);

static struct sdhci_ersdhc_platdata *ersdhc_get_mmc_pdata(struct device *dev)
{
	struct sdhci_ersdhc_platdata *pdata;
	//struct device_node *np = dev->of_node;
	//u32 bus_width;
	//u32 clk_delay_cycles;


	printk("ersdhc_get_mmc_pdata");
	pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
	if (!pdata)
		return NULL;
	return pdata;
}
#else
static inline struct sdhci_ersdhc_platdata *ersdhc_get_mmc_pdata(struct device *dev)
{
	return NULL;
}
#endif

static int sdhci_ersdhc_probe(struct platform_device *pdev)
{
	struct sdhci_pltfm_host *pltfm_host;
	struct sdhci_ersdhc_platdata *pdata = pdev->dev.platform_data;
	struct device *dev = &pdev->dev;
	struct sdhci_host *host = NULL;
	const struct of_device_id *match;

	int ret;
	//struct clk *clk;

	//printk("Probe fun()\n");
	//pr_err("TEST");
	host = sdhci_pltfm_init(pdev, NULL, 0);
	if (IS_ERR(host))
		return PTR_ERR(host);

	//clk = devm_clk_get(dev, "sdhci_clock");
	pltfm_host = sdhci_priv(host);

	//clk = devm_clk_get(dev, "sdhci_clock");
	//if (IS_ERR(clk)) {
	//	dev_err(dev, "failed to get io clock\n");
	//	ret = PTR_ERR(clk);
	//	goto free;
	//}

	//printk("probe host->clock = %x, clk = %x ",host->clock,clk_get_rate(clk));

	//pltfm_host->clk = clk;

	//printk("probe host->clock = %x, host->mmc->actual_clock = %x, /host->mmc->ios->clock = %x", host->clock, host->mmc->actual_clock, host->mmc->ios.clock);

	//host->clock
	//host->mmc->actual_clock
	//host->mmc->ios.clock

	//ret = clk_prepare_enable(clk);
	//if (ret) {
	//	dev_err(&pdev->dev, "failed to enable io clock\n");
	//	goto free;
	//}
	//printk("2probe host->clock = %x, host->mmc->actual_clock = %x, /host->mmc->ios->clock = %x", host->clock, host->mmc->actual_clock, host->mmc->ios.clock);

	host->quirks = SDHCI_QUIRK_BROKEN_ADMA | SDHCI_QUIRK_BROKEN_DMA| SDHCI_QUIRK_MULTIBLOCK_READ_ACMD12;
	//	| SDHCI_QUIRK_CAP_CLOCK_BASE_BROKEN;

			//	| SDHCI_QUIRK_BROKEN_TIMEOUT_VAL


    // CDAC
	//host->quirks |= SDHCI_QUIRK_MISSING_CAPS ;
	host->quirks2 = SDHCI_QUIRK2_PRESET_VALUE_BROKEN | SDHCI_QUIRK2_DISABLE_HW_TIMEOUT | SDHCI_QUIRK2_NO_1_8_V;//| SDHCI_QUIRK2_PRESET_VALUE_BROKEN;
	host->mmc->caps2 = MMC_CAP2_NO_SDIO | MMC_CAP2_NO_MMC ;

	match = of_match_device(of_match_ptr(sdhci_ersdhc_of_match), &pdev->dev);
	if (match) {
		pdata = ersdhc_get_mmc_pdata(dev);
	}
	/*
	if (pdata) {
		if (pdata->flags & PXA_FLAG_CARD_PERMANENT) {
			// on-chip device 
			printk("Test");
		}
	}
	*/
	host->ops = &ersdhc_sdhci_ops;
	//printk("Ok 1 \n");
	//printk("1 mmc caps2 : %x",host->mmc->caps2 );
	ret = sdhci_add_host(host);
	//printk("1b mmc caps2 : %x",host->mmc->caps2 );
	//printk("Ok 2, ret = %d \n",ret);
	//printk(" Caps : %x, Capas1 : %x Quirks : %x Quirks2 : %x \n", host->caps, host->caps1, host->quirks, host->quirks2);
	//if (ret)
		//goto disable_clk;

	//printk(" Caps : %x, Capas1 : %x Quirks : %x Quirks2 : %x \n", host->caps, host->caps1, host->quirks, host->quirks2);
	//printk("probeX host->clock = %x, host->mmc->actual_clock = %x, /host->mmc->ios->clock = %x", host->clock, host->mmc->actual_clock, host->mmc->ios.clock);
	return 0;

//disable_clk:
	//clk_disable_unprepare(clk);
//free:
	//sdhci_pltfm_free(pdev);
	return ret;
}

static struct platform_driver sdhci_ersdhc_driver = {
	.driver		= {
		.name	= "sdhci-cdac",
		.of_match_table = of_match_ptr(sdhci_ersdhc_of_match),
		.pm	= &sdhci_pltfm_pmops,
	},
	.probe		= sdhci_ersdhc_probe,
	.remove		= sdhci_pltfm_unregister,
};

module_platform_driver(sdhci_ersdhc_driver);

MODULE_DESCRIPTION("SDHCI driver for C-DAC SDHCI controller");
MODULE_AUTHOR("Anoop Varghese <vanoop@cdac.in>");
MODULE_LICENSE("GPL v2");

