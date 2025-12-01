#ifndef _VEGA_CORE_H_
#define _VEGA_CORE_H_

#include "vega-hcd.h"
#include "vega-udc.h"

struct vega_hcd;


struct vega_device {
	struct device *dev;

	void __iomem *regs;
	unsigned int devflags;
	struct gpio_desc *rst_gpio;

	struct vega_hcd hcd;
	struct vega_udc udc;
};


int vega_usb_register(struct resource *mem, int irq, unsigned long irqflags,
		     struct device *dev, unsigned int devflags);




static int vega_usb_probe(struct platform_device *pdev);





static int vega_usb_remove(struct platform_device *op);






#endif /* _VEGA_CORE_H_ */





