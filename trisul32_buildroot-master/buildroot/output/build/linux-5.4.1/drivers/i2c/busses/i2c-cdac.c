/*
 * CDAC master mode driver
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/clk.h>
#include <linux/completion.h>
#include <linux/err.h>
#include <linux/i2c.h>
#include <linux/interrupt.h>
#include <linux/io.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/delay.h>

#define DBG(f, x...) pr_debug(f, ## x)
#define DBG1(f, x...) pr_debug(f, ## x)
#define DBG2(f, x...) pr_debug(f, ## x)
#define DBG3(f, x...) pr_debug(f, ## x)

/* timeout waiting for the controller to respond */
#define CDAC_I2C_TIMEOUT (msecs_to_jiffies(1000))

#define CDAC_I2C_C		0x0
#define CDAC_I2C_S		0x1
#define CDAC_I2C_S1		0x2
#define CDAC_I2C_IER		0x3
#define CDAC_I2C_TXFIFO		0x4
#define CDAC_I2C_RXFIFO		0x5

#define CDAC_I2C_CHL		0x6
#define CDAC_I2C_CHH		0x7
#define CDAC_I2C_CHHL		0x8
#define CDAC_I2C_CHHH		0x9

#define CDAC_I2C_TXFIFO_CLR	0xa

#define CDAC_I2C_TX_CLEAR	BIT(0)

#define CDAC_I2C_C_ST	BIT(0)

#define CDAC_I2C_IER_INTRX	BIT(2)
#define CDAC_I2C_IER_INTGL	BIT(0)
#define CDAC_I2C_IER_INTTX	BIT(1)
#define CDAC_I2C_S_STOP	BIT(1)

#define CDAC_I2C_S_TXW	BIT(1)
#define CDAC_I2C_S_RXR	BIT(2)

#define CDAC_I2C_S_RXC  BIT(7)

#define CDAC_I2C_S_TX_FIFO_FULL		BIT(2)
#define CDAC_I2C_S_RX_FIFO_EMPTY 	BIT(6)

#define CDAC_I2C_S1_NACK BIT(0)

#define CDAC_I2C_S_LEN	BIT(3) /* Fake bit for SW error reporting */

struct cdac_i2c_dev {
	struct device *dev;
	void __iomem *regs;
	u32 clk;
	int irq;
	u32 bus_clk_rate;
	struct i2c_adapter adapter;
	struct completion completion;
	struct i2c_msg *curr_msg;
	int num_msgs;
	u32 msg_err;
	u8 *msg_buf;
	u8 intr_flag;
	size_t msg_buf_remaining;
};

static int i2c_data_addr_flag=0;

static inline void cdac_i2c_writeb(struct cdac_i2c_dev *i2c_dev,
				      u32 reg, u8 val)
{
	writeb(val, i2c_dev->regs + reg);
}

static inline u8 cdac_i2c_readb(struct cdac_i2c_dev *i2c_dev, u32 reg)
{
	return readb(i2c_dev->regs + reg);
}

static int cdac_i2c_set_divider(struct cdac_i2c_dev *i2c_dev)
{
	u8 chl,chh,chhl,chhh;
	u16 chl_chh,chhl_chhh;


	chl_chh 	= DIV_ROUND_UP( i2c_dev->clk,(2*i2c_dev->bus_clk_rate)); //Clock Period half register
	chhl_chhh 	= DIV_ROUND_UP( i2c_dev->clk,(4*i2c_dev->bus_clk_rate)); //Clock Period half half register

	chl = chl_chh & 0xff;
	chh = chl_chh >> 8;

	chhl = chhl_chhh & 0xff;
	chhh = chhl_chhh >> 8;

	cdac_i2c_writeb(i2c_dev, CDAC_I2C_CHL, chl);
	cdac_i2c_writeb(i2c_dev, CDAC_I2C_CHH, chh);
	cdac_i2c_writeb(i2c_dev, CDAC_I2C_CHHL, chhl);
	cdac_i2c_writeb(i2c_dev, CDAC_I2C_CHHH, chhh);
	return 0;
}

static void cdac_fill_txfifo(struct cdac_i2c_dev *i2c_dev)
{
	u8 val;
	u8 count=0;
	u8 temp_char=0;

	while (i2c_dev->msg_buf_remaining) {

		val = cdac_i2c_readb(i2c_dev, CDAC_I2C_S);
		if ((val & CDAC_I2C_S_TX_FIFO_FULL))
			break; //TX FIFO full
		cdac_i2c_writeb(i2c_dev, CDAC_I2C_TXFIFO,
				   *i2c_dev->msg_buf);

		if(i2c_data_addr_flag ==1)
		{
		  if(count==0)
			temp_char=*i2c_dev->msg_buf;
		  if(count==1){
		DBG2("T: 0x%02x%02x, ",temp_char,*i2c_dev->msg_buf);
			i2c_data_addr_flag =0;
		  }
		  count++;
		}
		i2c_dev->msg_buf++;
		i2c_dev->msg_buf_remaining--;
	}
}

static void cdac_drain_rxfifo(struct cdac_i2c_dev *i2c_dev)
{
	u8 val, count=0;

        while (((cdac_i2c_readb(i2c_dev, CDAC_I2C_S))  & CDAC_I2C_S_RXC ) != CDAC_I2C_S_RXC) ; //Wait for stop complete

	while (i2c_dev->msg_buf_remaining) {
		val = cdac_i2c_readb(i2c_dev, CDAC_I2C_S);

		if ((val & CDAC_I2C_S_RX_FIFO_EMPTY)){
		  if(count!=16)
			DBG3("Count %d",count);
		  break;
		}
		*i2c_dev->msg_buf = cdac_i2c_readb(i2c_dev,
						 CDAC_I2C_RXFIFO);
		count++;
		if(*i2c_dev->msg_buf)
			DBG2("%c ",*i2c_dev->msg_buf);
		i2c_dev->msg_buf++;
		i2c_dev->msg_buf_remaining--;
	}
}

/*
 * Repeated Start Condition (Sr)

 */

static void cdac_i2c_start_transfer(struct cdac_i2c_dev *i2c_dev)
{
	u8 c = CDAC_I2C_C_ST;
	u16 temp_addr;
	struct i2c_msg *msg = i2c_dev->curr_msg;
//	bool last_msg = (i2c_dev->num_msgs == 1);

	//mdelay(10);

	if (!i2c_dev->num_msgs)
		return;
	DBG2("M: %d,L: %d",i2c_dev->num_msgs,msg->len);
	//DBG2("M");
	i2c_dev->num_msgs--;
	i2c_dev->msg_buf = msg->buf;
	i2c_dev->msg_buf_remaining = msg->len;

	if ((msg->flags & I2C_M_RD) )
	{
		if(msg->len > 16) {
			c |= (16) << 2 ;
			DBG3("L: 16");
		}
		else{
			c |= (msg->len) << 2 ;
			DBG3("L: %d",msg->len);
		}
		i2c_dev->msg_buf_remaining = msg->len;
		temp_addr = ((msg->addr << 1) | 0x1); //R/W bit in address
		cdac_i2c_writeb(i2c_dev, CDAC_I2C_C, c);
                //check start sequence initiated
                while (((cdac_i2c_readb(i2c_dev, CDAC_I2C_S))  & 0x01) != 0x01) ;

		cdac_i2c_writeb(i2c_dev, CDAC_I2C_TXFIFO , temp_addr);
		DBG1("R");
		i2c_data_addr_flag =1;
		cdac_i2c_writeb(i2c_dev, CDAC_I2C_IER, (CDAC_I2C_IER_INTRX | CDAC_I2C_IER_INTGL)); //Enable RX interrupt
		return;
	}
	else
	{
		temp_addr = ((msg->addr << 1) | 0x0); //R/W bit in address
		cdac_i2c_writeb(i2c_dev, CDAC_I2C_C, c);
                //check start sequence initiated
                while (((cdac_i2c_readb(i2c_dev, CDAC_I2C_S))  & 0x01) != 0x01) ;
		cdac_i2c_writeb(i2c_dev, CDAC_I2C_TXFIFO , temp_addr);

		DBG1("W");
		i2c_data_addr_flag =1;
		cdac_i2c_writeb(i2c_dev, CDAC_I2C_IER, (CDAC_I2C_IER_INTTX | CDAC_I2C_IER_INTGL)); //Enable TX interrupt
		return;
	}


}

/*
 * IRQ handling
 */

static irqreturn_t cdac_i2c_isr(int this_irq, void *data)
{
	struct cdac_i2c_dev *i2c_dev = data;
	u32 val, err;
	struct i2c_msg *msg = i2c_dev->curr_msg;
	u8 c = CDAC_I2C_C_ST;
        u16 temp_addr;
	 //check for TX complete for avoid unwanted NACK
        if(((cdac_i2c_readb(i2c_dev, CDAC_I2C_S))  & 0x10) != 0x10)
	{
		DBG1("*");
		return IRQ_HANDLED;
	}

	val = cdac_i2c_readb(i2c_dev, CDAC_I2C_S1);
	err = val & (CDAC_I2C_S1_NACK);
	if (err) {
			DBG1("#");

		        i2c_dev->num_msgs++;

                        cdac_i2c_writeb(i2c_dev, CDAC_I2C_C, CDAC_I2C_S_STOP);
                        while (((cdac_i2c_readb(i2c_dev, CDAC_I2C_S))  & 0x02) != 0x02) ; //Wait for stop$
                        cdac_i2c_start_transfer(i2c_dev);
		return IRQ_HANDLED;
	}


	if ((val & CDAC_I2C_S_TXW)){ // && (val_ier & CDAC_I2C_IER_INTTX)) { //
		DBG1("T :%d",i2c_dev->msg_buf_remaining);
		if (!i2c_dev->msg_buf_remaining) {
			i2c_dev->msg_err = 0;
			goto complete;
		}

		cdac_fill_txfifo(i2c_dev);
		if (i2c_dev->num_msgs && !i2c_dev->msg_buf_remaining) {
			i2c_dev->curr_msg++;
			cdac_i2c_writeb(i2c_dev, CDAC_I2C_C, CDAC_I2C_S_STOP);
			while (((cdac_i2c_readb(i2c_dev, CDAC_I2C_S))  & 0x02) != 0x02) ; //Wait for stop complete
			cdac_i2c_start_transfer(i2c_dev);
		}

		return IRQ_HANDLED;
	}

	if ((val & CDAC_I2C_S_RXR)){ // && (val_ier & CDAC_I2C_IER_INTRX)) { //
		DBG1("R");
		if (!i2c_dev->msg_buf_remaining) {
			i2c_dev->msg_err = 0;
			goto complete;
		}

		cdac_drain_rxfifo(i2c_dev);

		if (!i2c_dev->msg_buf_remaining) {
                        i2c_dev->msg_err = 0;
                        goto complete;

                }
		else
		{
			//cdac_i2c_writeb(i2c_dev, CDAC_I2C_C, CDAC_I2C_S_STOP);
			while (((cdac_i2c_readb(i2c_dev, CDAC_I2C_S))  & 0x02) != 0x02) ; //Wait for stop complete

			if(i2c_dev->msg_buf_remaining > 16) {
				c |= (16) << 2 ;
				DBG3("L: 16");

			}
			else{
				c |= (i2c_dev->msg_buf_remaining) << 2 ;
				DBG3("L: %d",i2c_dev->msg_buf_remaining);
			}
			temp_addr = ((msg->addr << 1) | 0x1); //R/W bit in address
			cdac_i2c_writeb(i2c_dev, CDAC_I2C_C, c);
	                //check start sequence initiated
	                while (((cdac_i2c_readb(i2c_dev, CDAC_I2C_S))  & 0x01) != 0x01) ;
			cdac_i2c_writeb(i2c_dev, CDAC_I2C_TXFIFO , temp_addr);
			DBG("RD: temp_addr %x\n",temp_addr);

		}
		return IRQ_HANDLED;
	}

	return IRQ_NONE;

complete:
	DBG2("C\n");
	complete(&i2c_dev->completion);
	cdac_i2c_writeb(i2c_dev, CDAC_I2C_C, CDAC_I2C_S_STOP);
	while (((cdac_i2c_readb(i2c_dev, CDAC_I2C_S))  & 0x02) != 0x02) ; //Wait for stop complete
	cdac_i2c_writeb(i2c_dev, CDAC_I2C_IER,  0x0 );
	return IRQ_HANDLED;
}

static int cdac_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg msgs[],
			    int num)
{
	struct cdac_i2c_dev *i2c_dev = i2c_get_adapdata(adap);
	unsigned long time_left;
	int i, ret;

	DBG1(">");
	for (i = 0; i < (num - 1); i++)
		if (msgs[i].flags & I2C_M_RD) {
			dev_warn_once(i2c_dev->dev,
				      "only one read message supported, has to be last\n");
			return -EOPNOTSUPP;
		}

	ret = cdac_i2c_set_divider(i2c_dev);
	if (ret)
		return ret;

	i2c_dev->curr_msg = msgs;
	i2c_dev->num_msgs = num;
	reinit_completion(&i2c_dev->completion);

	cdac_i2c_start_transfer(i2c_dev);

	time_left = wait_for_completion_timeout(&i2c_dev->completion,	CDAC_I2C_TIMEOUT );
	if (!time_left) {
		cdac_i2c_writeb(i2c_dev, CDAC_I2C_TXFIFO_CLR,  CDAC_I2C_TX_CLEAR);
		dev_err(i2c_dev->dev, "i2c transfer timed out\n");
		return -ETIMEDOUT;
	}

	if (!i2c_dev->msg_err)
		return num;

	dev_dbg(i2c_dev->dev, "i2c transfer failed: %x\n", i2c_dev->msg_err);

	if (i2c_dev->msg_err & CDAC_I2C_S1_NACK)
		return -EREMOTEIO;

	return -EIO;
}

static u32 cdac_i2c_func(struct i2c_adapter *adap)
{
	return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}

static const struct i2c_algorithm cdac_i2c_algo = {
	.master_xfer	= cdac_i2c_xfer,
	.functionality	= cdac_i2c_func,
};

/*
 * This HW was reported to have problems with clock stretching:
 * http://www.advamation.com/knowhow/raspberrypi/rpi-i2c-bug.html
 * https://www.raspberrypi.org/forums/viewtopic.php?p=146272
 */
static const struct i2c_adapter_quirks cdac_i2c_quirks = {
	.flags = I2C_AQ_NO_CLK_STRETCH,
};

static int cdac_i2c_probe(struct platform_device *pdev)
{
	struct cdac_i2c_dev *i2c_dev;
	struct resource *mem;

	int ret, irq;
	struct i2c_adapter *adap;

	printk("In cdac i2c_probe\n");


	i2c_dev = devm_kzalloc(&pdev->dev, sizeof(*i2c_dev), GFP_KERNEL);
	if (!i2c_dev)
		return -ENOMEM;
	platform_set_drvdata(pdev, i2c_dev);
	i2c_dev->dev = &pdev->dev;
	init_completion(&i2c_dev->completion);

	mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	i2c_dev->regs = devm_ioremap_resource(&pdev->dev, mem);
	if (IS_ERR(i2c_dev->regs))
		return PTR_ERR(i2c_dev->regs);

	/*i2c_dev->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(i2c_dev->clk)) {
		if (PTR_ERR(i2c_dev->clk) != -EPROBE_DEFER)
			dev_err(&pdev->dev, "Could not get clock\n");
		return PTR_ERR(i2c_dev->clk);
	}*/

	ret = of_property_read_u32(pdev->dev.of_node, "system-frequency",
				   &i2c_dev->clk);
	if (ret < 0) {
		dev_warn(&pdev->dev,
			 "Could not read system-frequency property\n");
		i2c_dev->clk = 25000000;
	}

	ret = of_property_read_u32(pdev->dev.of_node, "clock-frequency",
				   &i2c_dev->bus_clk_rate);
	if (ret < 0) {
		dev_warn(&pdev->dev,
			 "Could not read clock-frequency property\n");
		i2c_dev->bus_clk_rate = 100000;
	}

	irq = platform_get_irq(pdev, 0);
	//irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);

	if (!irq) {
		dev_err(&pdev->dev, "No IRQ resource\n");
		return -ENODEV;
	}
	i2c_dev->irq = irq;

	ret = request_irq(i2c_dev->irq, cdac_i2c_isr, 0,  dev_name(&pdev->dev), i2c_dev);
	if (ret) {
		dev_err(&pdev->dev, "Could not request IRQ\n");
		return -ENODEV;
	}
	dev_info(&pdev->dev,
		 "C-DAC I2C Controller at 0x%08lx (irq %d)\n",
		 (unsigned long)i2c_dev->regs, irq);
	//DBG("request_irq over\n");
	adap = &i2c_dev->adapter;
	i2c_set_adapdata(adap, i2c_dev);
	adap->owner = THIS_MODULE;
	adap->class = I2C_CLASS_DEPRECATED;
	strlcpy(adap->name, "cdac I2C adapter", sizeof(adap->name));
	adap->algo = &cdac_i2c_algo;
	adap->dev.parent = &pdev->dev;
	adap->dev.of_node = pdev->dev.of_node;
	//adap->quirks = &cdac_i2c_quirks;

	cdac_i2c_writeb(i2c_dev, CDAC_I2C_C, 0);
	ret = i2c_add_adapter(adap);
	if (ret)
		free_irq(i2c_dev->irq, i2c_dev);

	printk("In cdac i2c added\n");

	return ret;
}

static int cdac_i2c_remove(struct platform_device *pdev)
{
	struct cdac_i2c_dev *i2c_dev = platform_get_drvdata(pdev);

	free_irq(i2c_dev->irq, i2c_dev);
	i2c_del_adapter(&i2c_dev->adapter);

	return 0;
}

static const struct of_device_id cdac_i2c_of_match[] = {
	{ .compatible = "cdac,mdp-i2c" },
	{},
};
MODULE_DEVICE_TABLE(of, cdac_i2c_of_match);

static struct platform_driver cdac_i2c_driver = {
	.probe		= cdac_i2c_probe,
	.remove		= cdac_i2c_remove,
	.driver		= {
		.name	= "i2c-cdac",
		.of_match_table = cdac_i2c_of_match,
	},
};
module_platform_driver(cdac_i2c_driver);

MODULE_AUTHOR("Pemjith A V <premjith@cdac.in>");
MODULE_DESCRIPTION("CDAC I2C bus adapter");
MODULE_LICENSE("GPL v2");
MODULE_ALIAS("platform:i2c-cdac");
