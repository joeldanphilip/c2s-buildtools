/*
 * cdac_wdt.c
 *
 *Copyright (C) 2020 C-DAC Thiruvananthapuram.
 *
 */
#include <linux/module.h>
#include <linux/types.h>
#include <linux/watchdog.h>
#include <linux/interrupt.h>
#include <linux/pm.h>
#include <linux/platform_device.h>
#include <linux/io.h>
#include <linux/bitops.h>
#include <linux/of.h>
#include <linux/clk.h>
#include <linux/delay.h>
#include <linux/err.h>
#include <linux/jiffies.h>
#include <linux/timer.h>

#define DRV_NAME "C-DAC Watchdog"

/*
 * C-DAC Watchdog register definitions
 */
#define CDAC_WDT_KEY 				0x5a5a5a5a
#define CDAC_WDT_CONTROL_REG 		0x00
#define CDAC_WDT_SERVICE_REG 		0x04
#define CDAC_WDT_RESET_STAT_REG 	0x08
#define CDAC_WDT_INTERRUPT_CTRL_REG 0x0C
#define WDT_ENABLE 					0x1
#define WDT_INTERRUPT_ENABLE 		0x1 << 1
#define WDT_PROC_RESET_ENABLE 		0x1 << 2
#define WDT_SYS_RESET_ENABLE 		0x1 << 3
#define WDT_COUNTER_VAL 			GENMASK(23, 4) 		/* User configurable counter value */
#define WDT_INTERRUPT_COUNTER 		GENMASK(19, 0)
#define CDAC_WDT_TIMER_INTERVAL 	20
#define CDAC_WDT_CLK_DIVIDER     	3051

static unsigned int margin;
static int irq;
static void __iomem *virtbase;
static struct device *parent;
unsigned int clk, one_sec_timeout;

/* Watchdog Functions.*/
static int cdac_start(struct watchdog_device *wdt_dev)
{
	unsigned int reg, wdt_timeout;

	one_sec_timeout = (clk/CDAC_WDT_CLK_DIVIDER); // Interrupt comes 1s before reset.
	wdt_timeout = one_sec_timeout * (wdt_dev->timeout + 1);
	//printk("C-DAC Watchdod start %x  :  %x \n",wdt_timeout,(one_sec_timeout & WDT_INTERRUPT_COUNTER));
	writel((one_sec_timeout & WDT_INTERRUPT_COUNTER), (virtbase + CDAC_WDT_INTERRUPT_CTRL_REG));
	reg = (WDT_ENABLE | WDT_INTERRUPT_ENABLE| WDT_PROC_RESET_ENABLE |
	       WDT_SYS_RESET_ENABLE | (WDT_COUNTER_VAL & (wdt_timeout << 4)));
	writel(reg, (virtbase + CDAC_WDT_CONTROL_REG));
	return 0;
}

static int cdac_stop(struct watchdog_device *wdt_dev)
{
	unsigned int reg;

	//printk("C-DAC Watchdod stop \n");
	reg = 0; // Disabling everything.
	writel(reg, (virtbase + CDAC_WDT_CONTROL_REG));
	return 0;
}

static int cdac_wdt_ping(struct watchdog_device *wdd)
{
	//printk("C-DAC Watchdog ping \n");
	/* Feed the watchdog */
	writel(CDAC_WDT_KEY, (virtbase + CDAC_WDT_SERVICE_REG));
	return 0;
}

static int cdac_settimeout(struct watchdog_device *wdt_dev, unsigned int time)
{
	wdt_dev->timeout = time;
	cdac_stop(wdt_dev);
	cdac_start(wdt_dev);
	return 0;
}
/* TODO */
/*
static unsigned int cdac_gettimeleft(struct watchdog_device *wdt_dev)
{
	unsigned int timeleft;

	timeleft = 1;
	printk("C-DAC Watchdod get_timeleft : %d\n", timeleft);

	return timeleft;
}
*/
/*
 * This interrupt occurs 10 ms before the watchdog WILL bark.
 */
static irqreturn_t cdac_wdt_interrupt(int irq, void *data)
{
	readl(virtbase + CDAC_WDT_RESET_STAT_REG); // clearing interrupt.
	panic("C-DAC Watchdog");
	/* This code should not be reached */
	return IRQ_HANDLED;
}

static const struct watchdog_info cdac_ident = {
	.options = WDIOF_CARDRESET | WDIOF_SETTIMEOUT | WDIOF_KEEPALIVEPING,
	.identity = DRV_NAME,
};

static const struct watchdog_ops cdac_ops = {
	.owner = THIS_MODULE,
	.start = cdac_start,
	.stop = cdac_stop,
	.ping = cdac_wdt_ping,
	.set_timeout = cdac_settimeout,
	//.get_timeleft = cdac_gettimeleft,
};

static struct watchdog_device cdac_wdt = {
	.info = &cdac_ident,
	.ops = &cdac_ops,
	.min_timeout = 1,
	.max_timeout = 30,
	.timeout = 20,
};

static int __init cdac_wdog_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	int ret = 0;
	struct resource *res;

	parent = dev;
	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	virtbase = devm_ioremap_resource(dev, res);
	if (IS_ERR(virtbase)) {
		return PTR_ERR(virtbase);
	}

	ret = of_property_read_u32(dev->of_node, "clock-frequency",
					   &clk);
	if (ret < 0) {
		dev_err(dev, "Couldn't determine clock-frequency.\n");
		goto error;
	}
	irq = platform_get_irq(pdev, 0);
	if (request_irq(irq, cdac_wdt_interrupt, 0, DRV_NAME, pdev)) {
		ret = -EIO;
		goto error;
	}

	watchdog_init_timeout(&cdac_wdt, margin, dev);
	cdac_wdt.parent = dev;
	ret = watchdog_register_device(&cdac_wdt);
	if (ret)
		goto error;
	dev_info(dev, "initialized. (timeout=%d sec)\n", cdac_wdt.timeout);
	return 0;

error:
	return ret;
}

static const struct of_device_id cdac_dt_match[] = {
	{ .compatible = "cdac,cdac_wdog" },
	{},
};

static struct platform_driver cdac_driver = {
	.driver = {
		.name	= "cdac_wdog",
		.of_match_table = cdac_dt_match,
	},
};

module_platform_driver_probe(cdac_driver, cdac_wdog_probe);
module_param(margin, uint, 0);
MODULE_PARM_DESC(margin, "Watchdog margin in seconds (default 20s)");
MODULE_ALIAS("platform:cdac-watchdog");
MODULE_DESCRIPTION("C-DAC Thiruvananthapuram Watchdog Driver");
MODULE_AUTHOR("Anoop Varghese <vanoop@cdac.in>");
MODULE_LICENSE("GPL v2");