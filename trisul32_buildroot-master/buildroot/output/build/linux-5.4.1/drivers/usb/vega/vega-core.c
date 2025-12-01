#include <linux/err.h>
#include <linux/signal.h>
#include <linux/usb.h>
#include <linux/usb/hcd.h>
#include <linux/of.h>
#include <linux/of_platform.h>
#include <linux/of_address.h>
#include <linux/of_irq.h>
#include <linux/gpio/consumer.h>
#include <linux/io.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <asm/unaligned.h>
#include <asm/cacheflush.h>

#include "vega-regs.h"
#include "vega-hcd.h"
#include "vega-udc.h"
#include "vega-core.h"


int vega_usb_register(struct resource *mem, int irq, unsigned long irqflags,
		     struct device *dev, unsigned int devflags)
{
	struct vega_device *vega_usb;

	int ret;

	
	/* prevent usb-core allocating DMA pages */
	dev->dma_mask = NULL;

	vega_usb = devm_kzalloc(dev, sizeof(*vega_usb), GFP_KERNEL);
	if (!vega_usb)
		return -ENOMEM;

	vega_usb->dev = dev;
	vega_usb->devflags = devflags;

	vega_usb->rst_gpio = devm_gpiod_get_optional(dev, NULL, GPIOD_OUT_HIGH);
	if (IS_ERR(vega_usb->rst_gpio))
		return PTR_ERR(vega_usb->rst_gpio);

	vega_usb->regs = devm_ioremap_resource(dev, mem);
	if (IS_ERR(vega_usb->regs))
		return PTR_ERR(vega_usb->regs);

	vega_init_core(vega_usb);
	
	//ret = vega_hcd_register(&vega_host->hcd, vega_host->regs, mem, irq,
		//			irqflags | IRQF_SHARED, dev);

	
    
    	if (IS_ENABLED(CONFIG_USB_VEGA_HCD) && !usb_disabled()) {
		ret = vega_hcd_register(&vega_usb->hcd, vega_usb->regs, mem, irq,
					   irqflags | IRQF_SHARED, dev);
		if (ret < 0)
			return ret;
	}

	if (IS_ENABLED(CONFIG_USB_VEGA_UDC) && !udc_disabled) {
		ret = vega_udc_register(&vega_usb->udc, irq, irqflags);
		if (ret < 0) {
			vega_hcd_unregister(&vega_usb->hcd);
			return ret;
		}
	}






	if (ret < 0)
		return ret;	

	dev_set_drvdata(dev, vega_host);

	return 0;
}




static int vega_usb_probe(struct platform_device *pdev)
{
	unsigned long irqflags;
	unsigned int devflags = 0;
	struct resource *mem_res;
	struct resource *irq_res;
	int ret;
	

	vega_dbg(&pdev->dev, "<***********************vega_usb_probe***********************>\n");

	mem_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);

	irq_res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
	if (!irq_res) {
		pr_warn("vega: IRQ resource not available\n");
		return -ENODEV;
	}
	irqflags = irq_res->flags & IRQF_TRIGGER_MASK;
	
	

	ret = vega_register(mem_res, irq_res->start, irqflags, &pdev->dev,
			       devflags);
	if (ret < 0)
		return ret;


	pr_info("VEGA USB device initialised\n");

	return 0;
}





static int vega_usb_remove(struct platform_device *op)
{
	struct usb_hcd *hcd = platform_get_drvdata(op);

	pr_err( "Stopping VEGA USB Controller\n");

	usb_remove_hcd(hcd);

	usb_put_hcd(hcd);

	return 0;
}





static const struct of_device_id vega_usb_of_match[] = {
		{.compatible = "cdac,vega-usb",},
	{},
};
MODULE_DEVICE_TABLE(of, vega_hcd_of_match);

static struct platform_driver vega_usb_of_driver = {
	.probe		= vega_usb_probe,
	.remove	= vega_usb_remove,
	.shutdown	= usb_hcd_platform_shutdown,
	.driver = {
		.name = "vega-usb",
		.of_match_table = vega_usb_of_match,
	},
};
