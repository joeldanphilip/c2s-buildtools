// SPDX-License-Identifier: GPL-2.0
/*
 * Driver for the NXP ISP1761 device controller
 *
 * Copyright 2014 Ideas on Board Oy
 *
 * Contacts:
 *	Laurent Pinchart <laurent.pinchart@ideasonboard.com>
 */

#ifndef _VEGA_UDC_H_
#define _VEGA_UDC_H_

#include <linux/ioport.h>
#include <linux/list.h>
#include <linux/spinlock.h>
#include <linux/timer.h>
#include <linux/usb/gadget.h>

struct vega_device;
struct vega_udc;

struct vega_ep {
	struct vega_udc *udc;
	struct usb_ep ep;

	struct list_head queue;

	unsigned int addr;
	unsigned int maxpacket;
	char name[7];

	const struct usb_endpoint_descriptor *desc;

	bool rx_pending;
	bool halted;
	bool wedged;
};

/**
 * struct vega_udc - UDC state information
 * irq: IRQ number
 * irqname: IRQ name (as passed to request_irq)
 * regs: Base address of the UDC registers
 * driver: Gadget driver
 * gadget: Gadget device
 * lock: Protects driver, vbus_timer, ep, ep0_*, DC_EPINDEX register
 * ep: Array of endpoints
 * ep0_state: Control request state for endpoint 0
 * ep0_dir: Direction of the current control request
 * ep0_length: Length of the current control request
 * connected: Tracks gadget driver bus connection state
 */

enum vega_ctrl_state {
	VEGA_CTRL_SETUP, /* Waiting for a SETUP transaction */
	VEGA_CTRL_DATA_IN, /* Setup received, data IN stage */
	VEGA_CTRL_DATA_OUT, /* Setup received, data OUT stage */
	VEGA_CTRL_STATUS, /* 0-length request in status stage */
};

struct vega_udc {
	struct vega_device *isp;

	int irq;
	char *irqname;
	void __iomem *regs;

	struct usb_gadget_driver *driver;
	struct usb_gadget gadget;

	spinlock_t lock;
	struct timer_list vbus_timer;

	struct vega_ep ep[15];

	enum vega_ctrl_state ep0_state;
	u8 ep0_dir;
	u16 ep0_length;

	bool connected;

	unsigned int devstatus;
};

//struct vega_device;
//struct vega_udc;



/*
int vega_udc_register(struct vega_device *isp, int irq, unsigned long irqflags);
void vega_udc_unregister(struct vega_device *isp);

static inline u32 vega_read32(void __iomem *base, u32 reg)
{
	return readl(base + reg);
}

static inline void vega_write32(void __iomem *base, u32 reg, u32 val)
{
	writel(val, base + reg);
}

*/



#endif
