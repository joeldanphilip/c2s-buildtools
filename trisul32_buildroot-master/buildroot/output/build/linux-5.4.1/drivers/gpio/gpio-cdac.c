/*
 * CDAC GPIO driver
 *
 *  Copyright (C) 2020 C-DAC Thiruvananthapuram.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#include <linux/err.h>
#include <linux/module.h>
#include <linux/of_device.h>
#include <linux/gpio/driver.h>
#include <linux/platform_device.h>

#define NO_OF_GIPO 16
#define MODULE_NAME "cdac-gpio"
#define GPIO_OUT 0
#define GPIO_IN 1
#define GPIO_HIGH 1
#define GPIO_LOW 0

struct cdac_gpio_priv {
	struct gpio_chip	gc;
	void __iomem		*base;
	unsigned		flags;
};
struct cdac_gpio_priv *priv;

static const struct of_device_id cdac_gpio_ids[] = {
	{
		.compatible	= "cdac,cdac-gpio",
	},
	{ }
};
MODULE_DEVICE_TABLE(of, cdac_gpio_ids);

static int cdac_get_direction(struct gpio_chip *gc, unsigned offset)
{
	/*
			returns direction for signal “offset”, 0=out, 1=in, (same as GPIOF_DIR_XXX), or negative error.
	*/
	u16 direction_reg;
	direction_reg = readw(priv->base + 0x40000);

	if(direction_reg & (1 << (offset))){
		return GPIO_OUT;
	}
	else{
		return GPIO_IN;
	}
}

static int cdac_direction_input(struct gpio_chip *gc, unsigned offset)
{
	/*
			configures signal “offset” as input, or returns error.
	*/
	u16 direction_reg;
	direction_reg = readw(priv->base + 0x40000);
	direction_reg &= ~(1 << (offset));
	writew(direction_reg, priv->base + 0x40000);
	__asm__ __volatile__ ("fence");
	return 0;
}

static int cdac_direction_output(struct gpio_chip *gc, unsigned offset, int value)
{
	u16 direction_reg;

	direction_reg = readw(priv->base + 0x40000);
	direction_reg |= (1 << (offset));
	writew(direction_reg, priv->base + 0x40000);
	__asm__ __volatile__ ("fence");
	return 0;
}

static int cdac_get(struct gpio_chip *gc, unsigned offset)
{
	u16 data_reg;

	data_reg = readw((unsigned long *)(((unsigned long)(priv->base))|(1 << (offset+2))));
	if(data_reg){
		return GPIO_HIGH;
	}
	else{
		return GPIO_LOW;
	}
}

static void cdac_set(struct gpio_chip *gc, unsigned offset, int value)
{
	u16 data_reg = 0;
	if(value){
		data_reg = 0xFFFF;
	}
	writew(data_reg, (unsigned long *)(((unsigned long)(priv->base))|(1 << (offset+2))));
}

static int cdac_gpio_probe(struct platform_device *pdev)
{
	struct resource *res;
	int base = -1;

	priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;
	priv->flags = (uintptr_t)of_device_get_match_data(&pdev->dev);
	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	priv->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(priv->base))
		return PTR_ERR(priv->base);

	of_property_read_u32(pdev->dev.of_node, "gpio-base",
				   &base);
	if (base < 0) {
		dev_err(&pdev->dev, "Could not read gpio-base property\n");
		return -ENODEV;
	}
	writew(0x00FF, priv->base + 0x40000);
	__asm__ __volatile__("fence");

	priv->gc.get_direction = cdac_get_direction;
	priv->gc.direction_input = cdac_direction_input;
	priv->gc.direction_output = cdac_direction_output;
	priv->gc.get = cdac_get;
	priv->gc.set = cdac_set;
	priv->gc.base = base;
	priv->gc.ngpio = NO_OF_GIPO;
	priv->gc.owner = THIS_MODULE;
	priv->gc.label = MODULE_NAME;

	return devm_gpiochip_add_data(&pdev->dev, &priv->gc, priv);
}

static struct platform_driver cdac_gpio_driver = {
	.driver	= {
		.name		= MODULE_NAME,
		.of_match_table	= cdac_gpio_ids,
	},
	.probe	= cdac_gpio_probe,
};
module_platform_driver(cdac_gpio_driver);

MODULE_DESCRIPTION("C-DAC Thiruvananthapuram GPIO driver");
MODULE_AUTHOR("Anoop Varghese <vanoop@cdac.in>");
MODULE_LICENSE("GPL v2");
