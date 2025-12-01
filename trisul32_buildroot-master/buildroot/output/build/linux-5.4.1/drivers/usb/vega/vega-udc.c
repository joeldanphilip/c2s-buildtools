// SPDX-License-Identifier: GPL-2.0
/*
 * Driver for the NXP ISP1761 device controller
 *
 * Copyright 2014 Ideas on Board Oy
 *
 * Contacts:
 *	Laurent Pinchart <laurent.pinchart@ideasonboard.com>
 */

#include <linux/interrupt.h>
#include <linux/io.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/timer.h>
#include <linux/usb.h>

//#include "isp1760-core.h"
#include "vega-regs.h"
#include "vega-udc.h"
#include "vega-core.h"


#define vega_dbg(...)		//dev_err(__VA_ARGS__)

#define VEGA_VBUS_POLL_INTERVAL	msecs_to_jiffies(500)

struct vega_request {
	struct usb_request req;
	struct list_head queue;
	struct vega_ep *ep;
	unsigned int packet_size;
};

static inline struct vega_udc *gadget_to_udc(struct usb_gadget *gadget)
{
	return container_of(gadget, struct vega_udc, gadget);
}

static inline struct vega_ep *ep_to_udc_ep(struct usb_ep *ep)
{
	return container_of(ep, struct vega_ep, ep);
}

static inline struct vega_request *req_to_udc_req(struct usb_request *req)
{
	return container_of(req, struct vega_request, req);
}

static inline u32 vega_udc_read(struct vega_udc *udc, u16 reg)
{
	return vega_read32(udc->regs, reg);
}

static inline void vega_udc_write(struct vega_udc *udc, u16 reg, u32 val)
{
	vega_write32(udc->regs, reg, val);
}

/* -----------------------------------------------------------------------------
 * Endpoint Management
 */

static struct vega_ep *vega_udc_find_ep(struct vega_udc *udc,
					      u16 index)
{
	unsigned int i;

	if (index == 0)
		return &udc->ep[0];

	for (i = 1; i < ARRAY_SIZE(udc->ep); ++i) {
		if (udc->ep[i].addr == index)
			return udc->ep[i].desc ? &udc->ep[i] : NULL;
	}

	return NULL;
}

static void __vega_udc_select_ep(struct vega_ep *ep, int dir)
{
	vega_udc_write(ep->udc, DC_EPINDEX,
			  DC_ENDPIDX(ep->addr & USB_ENDPOINT_NUMBER_MASK) |
			  (dir == USB_DIR_IN ? DC_EPDIR : 0));
}

/**
 * vega_udc_select_ep - Select an endpoint for register access
 * @ep: The endpoint
 *
 * The ISP1761 endpoint registers are banked. This function selects the target
 * endpoint for banked register access. The selection remains valid until the
 * next call to this function, the next direct access to the EPINDEX register
 * or the next reset, whichever comes first.
 *
 * Called with the UDC spinlock held.
 */
static void vega_udc_select_ep(struct vega_ep *ep)
{
	__vega_udc_select_ep(ep, ep->addr & USB_ENDPOINT_DIR_MASK);
}

/* Called with the UDC spinlock held. */
static void vega_udc_ctrl_send_status(struct vega_ep *ep, int dir)
{
	struct vega_udc *udc = ep->udc;

	/*
	 * Proceed to the status stage. The status stage data packet flows in
	 * the direction opposite to the data stage data packets, we thus need
	 * to select the OUT/IN endpoint for IN/OUT transfers.
	 */
	vega_udc_write(udc, DC_EPINDEX, DC_ENDPIDX(0) |
			  (dir == USB_DIR_IN ? 0 : DC_EPDIR));
	vega_udc_write(udc, DC_CTRLFUNC, DC_STATUS);

	/*
	 * The hardware will terminate the request automatically and go back to
	 * the setup stage without notifying us.
	 */
	udc->ep0_state = VEGA_CTRL_SETUP;
}

/* Called without the UDC spinlock held. */
static void vega_udc_request_complete(struct vega_ep *ep,
					 struct vega_request *req,
					 int status)
{
	struct vega_udc *udc = ep->udc;
	unsigned long flags;

	vega_dbg(ep->udc->isp->dev, "completing request %p with status %d\n",req, status);

	req->ep = NULL;
	req->req.status = status;
	req->req.complete(&ep->ep, &req->req);

	spin_lock_irqsave(&udc->lock, flags);

	/*
	 * When completing control OUT requests, move to the status stage after
	 * calling the request complete callback. This gives the gadget an
	 * opportunity to stall the control transfer if needed.
	 */
	if (status == 0 && ep->addr == 0 && udc->ep0_dir == USB_DIR_OUT)
		vega_udc_ctrl_send_status(ep, USB_DIR_OUT);

	spin_unlock_irqrestore(&udc->lock, flags);
}

static void vega_udc_ctrl_send_stall(struct vega_ep *ep)
{
	struct vega_udc *udc = ep->udc;
	unsigned long flags;

	vega_dbg(ep->udc->isp->dev, "%s(ep%02x)\n", __func__, ep->addr);

	spin_lock_irqsave(&udc->lock, flags);

	/* Stall both the IN and OUT endpoints. */
	__vega_udc_select_ep(ep, USB_DIR_OUT);
	vega_udc_write(udc, DC_CTRLFUNC, DC_STALL);
	__vega_udc_select_ep(ep, USB_DIR_IN);
	vega_udc_write(udc, DC_CTRLFUNC, DC_STALL);

	/* A protocol stall completes the control transaction. */
	udc->ep0_state = VEGA_CTRL_SETUP;

	spin_unlock_irqrestore(&udc->lock, flags);
}

/* -----------------------------------------------------------------------------
 * Data Endpoints
 */

/* Called with the UDC spinlock held. */
static bool vega_udc_receive(struct vega_ep *ep,
				struct vega_request *req)
{
	struct vega_udc *udc = ep->udc;
	unsigned int len;
	u32 *buf;
	int i;

	vega_udc_select_ep(ep);
	len = vega_udc_read(udc, DC_BUFLEN) & DC_DATACOUNT_MASK;

	vega_dbg(udc->isp->dev, "%s: received %u bytes (%u/%u done)\n",
		__func__, len, req->req.actual, req->req.length);

	len = min(len, req->req.length - req->req.actual);

	if (!len) {
		/*
		 * There's no data to be read from the FIFO, acknowledge the RX
		 * interrupt by clearing the buffer.
		 *
		 * TODO: What if another packet arrives in the meantime ? The
		 * datasheet doesn't clearly document how this should be
		 * handled.
		 */
		vega_udc_write(udc, DC_CTRLFUNC, DC_CLBUF);
		return false;
	}

	buf = req->req.buf + req->req.actual;

	/*
	 * Make sure not to read more than one extra byte, otherwise data from
	 * the next packet might be removed from the FIFO.
	 */
	for (i = len; i > 2; i -= 4, ++buf)
		*buf = le32_to_cpu(vega_udc_read(udc, DC_DATAPORT));
	if (i > 0)
		*(u16 *)buf = le16_to_cpu(readw(udc->regs + DC_DATAPORT));

	req->req.actual += len;

	/*
	 * TODO: The short_not_ok flag isn't supported yet, but isn't used by
	 * any gadget driver either.
	 */

	vega_dbg(udc->isp->dev,
		"%s: req %p actual/length %u/%u maxpacket %u packet size %u\n",
		__func__, req, req->req.actual, req->req.length, ep->maxpacket,
		len);

	ep->rx_pending = false;

	/*
	 * Complete the request if all data has been received or if a short
	 * packet has been received.
	 */
	if (req->req.actual == req->req.length || len < ep->maxpacket) {
		list_del(&req->queue);
		return true;
	}

	return false;
}

static void vega_udc_transmit(struct vega_ep *ep,
				 struct vega_request *req)
{
	struct vega_udc *udc = ep->udc;
	u32 *buf = req->req.buf + req->req.actual;
	int i;

	req->packet_size = min(req->req.length - req->req.actual,
			       ep->maxpacket);

	vega_dbg(udc->isp->dev, "%s: transferring %u bytes (%u/%u done)\n",
		__func__, req->packet_size, req->req.actual,
		req->req.length);

	__vega_udc_select_ep(ep, USB_DIR_IN);

	if (req->packet_size)
		vega_udc_write(udc, DC_BUFLEN, req->packet_size);

	/*
	 * Make sure not to write more than one extra byte, otherwise extra data
	 * will stay in the FIFO and will be transmitted during the next control
	 * request. The endpoint control CLBUF bit is supposed to allow flushing
	 * the FIFO for this kind of conditions, but doesn't seem to work.
	 */
	for (i = req->packet_size; i > 2; i -= 4, ++buf)
		vega_udc_write(udc, DC_DATAPORT, cpu_to_le32(*buf));
	if (i > 0)
		writew(cpu_to_le16(*(u16 *)buf), udc->regs + DC_DATAPORT);

	if (ep->addr == 0)
		vega_udc_write(udc, DC_CTRLFUNC, DC_DSEN);
	if (!req->packet_size)
		vega_udc_write(udc, DC_CTRLFUNC, DC_VENDP);
}

static void vega_ep_rx_ready(struct vega_ep *ep)
{
	struct vega_udc *udc = ep->udc;
	struct vega_request *req;
	bool complete;

	spin_lock(&udc->lock);

	if (ep->addr == 0 && udc->ep0_state != VEGA_CTRL_DATA_OUT) {
		spin_unlock(&udc->lock);
		vega_dbg(udc->isp->dev, "%s: invalid ep0 state %u\n", __func__,
			udc->ep0_state);
		return;
	}

	if (ep->addr != 0 && !ep->desc) {
		spin_unlock(&udc->lock);
		vega_dbg(udc->isp->dev, "%s: ep%02x is disabled\n", __func__,
			ep->addr);
		return;
	}

	if (list_empty(&ep->queue)) {
		ep->rx_pending = true;
		spin_unlock(&udc->lock);
		vega_dbg(udc->isp->dev, "%s: ep%02x (%p) has no request queued\n",
			__func__, ep->addr, ep);
		return;
	}

	req = list_first_entry(&ep->queue, struct vega_request,
			       queue);
	complete = vega_udc_receive(ep, req);

	spin_unlock(&udc->lock);

	if (complete)
		vega_udc_request_complete(ep, req, 0);
}

static void vega_ep_tx_complete(struct vega_ep *ep)
{
	struct vega_udc *udc = ep->udc;
	struct vega_request *complete = NULL;
	struct vega_request *req;
	bool need_zlp;

	spin_lock(&udc->lock);

	if (ep->addr == 0 && udc->ep0_state != VEGA_CTRL_DATA_IN) {
		spin_unlock(&udc->lock);
		vega_dbg(udc->isp->dev, "TX IRQ: invalid endpoint state %u\n",
			udc->ep0_state);
		return;
	}

	if (list_empty(&ep->queue)) {
		/*
		 * This can happen for the control endpoint when the reply to
		 * the GET_STATUS IN control request is sent directly by the
		 * setup IRQ handler. Just proceed to the status stage.
		 */
		if (ep->addr == 0) {
			vega_udc_ctrl_send_status(ep, USB_DIR_IN);
			spin_unlock(&udc->lock);
			return;
		}

		spin_unlock(&udc->lock);
		vega_dbg(udc->isp->dev, "%s: ep%02x has no request queued\n",
			__func__, ep->addr);
		return;
	}

	req = list_first_entry(&ep->queue, struct vega_request,
			       queue);
	req->req.actual += req->packet_size;

	need_zlp = req->req.actual == req->req.length &&
		   !(req->req.length % ep->maxpacket) &&
		   req->packet_size && req->req.zero;

	vega_dbg(udc->isp->dev,
		"TX IRQ: req %p actual/length %u/%u maxpacket %u packet size %u zero %u need zlp %u\n",
		 req, req->req.actual, req->req.length, ep->maxpacket,
		 req->packet_size, req->req.zero, need_zlp);

	/*
	 * Complete the request if all data has been sent and we don't need to
	 * transmit a zero length packet.
	 */
	if (req->req.actual == req->req.length && !need_zlp) {
		complete = req;
		list_del(&req->queue);

		if (ep->addr == 0)
			vega_udc_ctrl_send_status(ep, USB_DIR_IN);

		if (!list_empty(&ep->queue))
			req = list_first_entry(&ep->queue,
					       struct vega_request, queue);
		else
			req = NULL;
	}

	/*
	 * Transmit the next packet or start the next request, if any.
	 *
	 * TODO: If the endpoint is stalled the next request shouldn't be
	 * started, but what about the next packet ?
	 */
	if (req)
		vega_udc_transmit(ep, req);

	spin_unlock(&udc->lock);

	if (complete)
		vega_udc_request_complete(ep, complete, 0);
}

static int __vega_udc_set_halt(struct vega_ep *ep, bool halt)
{
	struct vega_udc *udc = ep->udc;

	vega_dbg(udc->isp->dev, "%s: %s halt on ep%02x\n", __func__,
		halt ? "set" : "clear", ep->addr);

	if (ep->desc && usb_endpoint_xfer_isoc(ep->desc)) {
		vega_dbg(udc->isp->dev, "%s: ep%02x is isochronous\n", __func__,
			ep->addr);
		return -EINVAL;
	}

	vega_udc_select_ep(ep);
	vega_udc_write(udc, DC_CTRLFUNC, halt ? DC_STALL : 0);

	if (ep->addr == 0) {
		/* When halting the control endpoint, stall both IN and OUT. */
		__vega_udc_select_ep(ep, USB_DIR_IN);
		vega_udc_write(udc, DC_CTRLFUNC, halt ? DC_STALL : 0);
	} else if (!halt) {
		/* Reset the data PID by cycling the endpoint enable bit. */
		u16 eptype = vega_udc_read(udc, DC_EPTYPE);

		vega_udc_write(udc, DC_EPTYPE, eptype & ~DC_EPENABLE);
		vega_udc_write(udc, DC_EPTYPE, eptype);

		/*
		 * Disabling the endpoint emptied the transmit FIFO, fill it
		 * again if a request is pending.
		 *
		 * TODO: Does the gadget framework require synchronizatino with
		 * the TX IRQ handler ?
		 */
		if ((ep->addr & USB_DIR_IN) && !list_empty(&ep->queue)) {
			struct vega_request *req;

			req = list_first_entry(&ep->queue,
					       struct vega_request, queue);
			vega_udc_transmit(ep, req);
		}
	}

	ep->halted = halt;

	return 0;
}

/* -----------------------------------------------------------------------------
 * Control Endpoint
 */

static int vega_udc_get_status(struct vega_udc *udc,
				  const struct usb_ctrlrequest *req)
{
	struct vega_ep *ep;
	u16 status;

	if (req->wLength != cpu_to_le16(2) || req->wValue != cpu_to_le16(0))
		return -EINVAL;

	switch (req->bRequestType) {
	case USB_DIR_IN | USB_RECIP_DEVICE:
		status = udc->devstatus;
		break;

	case USB_DIR_IN | USB_RECIP_INTERFACE:
		status = 0;
		break;

	case USB_DIR_IN | USB_RECIP_ENDPOINT:
		ep = vega_udc_find_ep(udc, le16_to_cpu(req->wIndex));
		if (!ep)
			return -EINVAL;

		status = 0;
		if (ep->halted)
			status |= 1 << USB_ENDPOINT_HALT;
		break;

	default:
		return -EINVAL;
	}

	vega_udc_write(udc, DC_EPINDEX, DC_ENDPIDX(0) | DC_EPDIR);
	vega_udc_write(udc, DC_BUFLEN, 2);

	writew(cpu_to_le16(status), udc->regs + DC_DATAPORT);

	vega_udc_write(udc, DC_CTRLFUNC, DC_DSEN);

	vega_dbg(udc->isp->dev, "%s: status 0x%04x\n", __func__, status);

	return 0;
}

static int vega_udc_set_address(struct vega_udc *udc, u16 addr)
{
	if (addr > 127) {
		vega_dbg(udc->isp->dev, "invalid device address %u\n", addr);
		return -EINVAL;
	}

	if (udc->gadget.state != USB_STATE_DEFAULT &&
	    udc->gadget.state != USB_STATE_ADDRESS) {
		vega_dbg(udc->isp->dev, "can't set address in state %u\n",
			udc->gadget.state);
		return -EINVAL;
	}

	usb_gadget_set_state(&udc->gadget, addr ? USB_STATE_ADDRESS :
			     USB_STATE_DEFAULT);

	vega_udc_write(udc, DC_ADDRESS, DC_DEVEN | addr);

	spin_lock(&udc->lock);
	vega_udc_ctrl_send_status(&udc->ep[0], USB_DIR_OUT);
	spin_unlock(&udc->lock);

	return 0;
}

static bool vega_ep0_setup_standard(struct vega_udc *udc,
				       struct usb_ctrlrequest *req)
{
	bool stall;

	switch (req->bRequest) {
	case USB_REQ_GET_STATUS:
		return vega_udc_get_status(udc, req);

	case USB_REQ_CLEAR_FEATURE:
		switch (req->bRequestType) {
		case USB_DIR_OUT | USB_RECIP_DEVICE: {
			/* TODO: Handle remote wakeup feature. */
			return true;
		}

		case USB_DIR_OUT | USB_RECIP_ENDPOINT: {
			u16 index = le16_to_cpu(req->wIndex);
			struct vega_ep *ep;

			if (req->wLength != cpu_to_le16(0) ||
			    req->wValue != cpu_to_le16(USB_ENDPOINT_HALT))
				return true;

			ep = vega_udc_find_ep(udc, index);
			if (!ep)
				return true;

			spin_lock(&udc->lock);

			/*
			 * If the endpoint is wedged only the gadget can clear
			 * the halt feature. Pretend success in that case, but
			 * keep the endpoint halted.
			 */
			if (!ep->wedged)
				stall = __vega_udc_set_halt(ep, false);
			else
				stall = false;

			if (!stall)
				vega_udc_ctrl_send_status(&udc->ep[0],
							     USB_DIR_OUT);

			spin_unlock(&udc->lock);
			return stall;
		}

		default:
			return true;
		}
		break;

	case USB_REQ_SET_FEATURE:
		switch (req->bRequestType) {
		case USB_DIR_OUT | USB_RECIP_DEVICE: {
			/* TODO: Handle remote wakeup and test mode features */
			return true;
		}

		case USB_DIR_OUT | USB_RECIP_ENDPOINT: {
			u16 index = le16_to_cpu(req->wIndex);
			struct vega_ep *ep;

			if (req->wLength != cpu_to_le16(0) ||
			    req->wValue != cpu_to_le16(USB_ENDPOINT_HALT))
				return true;

			ep = vega_udc_find_ep(udc, index);
			if (!ep)
				return true;

			spin_lock(&udc->lock);

			stall = __vega_udc_set_halt(ep, true);
			if (!stall)
				vega_udc_ctrl_send_status(&udc->ep[0],
							     USB_DIR_OUT);

			spin_unlock(&udc->lock);
			return stall;
		}

		default:
			return true;
		}
		break;

	case USB_REQ_SET_ADDRESS:
		if (req->bRequestType != (USB_DIR_OUT | USB_RECIP_DEVICE))
			return true;

		return vega_udc_set_address(udc, le16_to_cpu(req->wValue));

	case USB_REQ_SET_CONFIGURATION:
		if (req->bRequestType != (USB_DIR_OUT | USB_RECIP_DEVICE))
			return true;

		if (udc->gadget.state != USB_STATE_ADDRESS &&
		    udc->gadget.state != USB_STATE_CONFIGURED)
			return true;

		stall = udc->driver->setup(&udc->gadget, req) < 0;
		if (stall)
			return true;

		usb_gadget_set_state(&udc->gadget, req->wValue ?
				     USB_STATE_CONFIGURED : USB_STATE_ADDRESS);

		/*
		 * SET_CONFIGURATION (and SET_INTERFACE) must reset the halt
		 * feature on all endpoints. There is however no need to do so
		 * explicitly here as the gadget driver will disable and
		 * reenable endpoints, clearing the halt feature.
		 */
		return false;

	default:
		return udc->driver->setup(&udc->gadget, req) < 0;
	}
}

static void vega_ep0_setup(struct vega_udc *udc)
{
	union {
		struct usb_ctrlrequest r;
		u32 data[2];
	} req;
	unsigned int count;
	bool stall = false;

	spin_lock(&udc->lock);

	vega_udc_write(udc, DC_EPINDEX, DC_EP0SETUP);

	count = vega_udc_read(udc, DC_BUFLEN) & DC_DATACOUNT_MASK;
	if (count != sizeof(req)) {
		spin_unlock(&udc->lock);

		dev_err(udc->isp->dev, "invalid length %u for setup packet\n",	count);

		vega_udc_ctrl_send_stall(&udc->ep[0]);
		return;
	}

	req.data[0] = vega_udc_read(udc, DC_DATAPORT);
	req.data[1] = vega_udc_read(udc, DC_DATAPORT);

	if (udc->ep0_state != VEGA_CTRL_SETUP) {
		spin_unlock(&udc->lock);
		vega_dbg(udc->isp->dev, "unexpected SETUP packet\n");
		return;
	}

	/* Move to the data stage. */
	if (!req.r.wLength)
		udc->ep0_state = VEGA_CTRL_STATUS;
	else if (req.r.bRequestType & USB_DIR_IN)
		udc->ep0_state = VEGA_CTRL_DATA_IN;
	else
		udc->ep0_state = VEGA_CTRL_DATA_OUT;

	udc->ep0_dir = req.r.bRequestType & USB_DIR_IN;
	udc->ep0_length = le16_to_cpu(req.r.wLength);

	spin_unlock(&udc->lock);

	vega_dbg(udc->isp->dev,
		"%s: bRequestType 0x%02x bRequest 0x%02x wValue 0x%04x wIndex 0x%04x wLength 0x%04x\n",
		__func__, req.r.bRequestType, req.r.bRequest,
		le16_to_cpu(req.r.wValue), le16_to_cpu(req.r.wIndex),
		le16_to_cpu(req.r.wLength));

	if ((req.r.bRequestType & USB_TYPE_MASK) == USB_TYPE_STANDARD)
		stall = vega_ep0_setup_standard(udc, &req.r);
	else
		stall = udc->driver->setup(&udc->gadget, &req.r) < 0;

	if (stall)
		vega_udc_ctrl_send_stall(&udc->ep[0]);
}

/* -----------------------------------------------------------------------------
 * Gadget Endpoint Operations
 */

static int vega_ep_enable(struct usb_ep *ep,
			     const struct usb_endpoint_descriptor *desc)
{
	struct vega_ep *uep = ep_to_udc_ep(ep);
	struct vega_udc *udc = uep->udc;
	unsigned long flags;
	unsigned int type;

	vega_dbg(uep->udc->isp->dev, "%s\n", __func__);

	/*
	 * Validate the descriptor. The control endpoint can't be enabled
	 * manually.
	 */
	if (desc->bDescriptorType != USB_DT_ENDPOINT ||
	    desc->bEndpointAddress == 0 ||
	    desc->bEndpointAddress != uep->addr ||
	    le16_to_cpu(desc->wMaxPacketSize) > ep->maxpacket) {
		vega_dbg(udc->isp->dev,
			"%s: invalid descriptor type %u addr %02x ep addr %02x max packet size %u/%u\n",
			__func__, desc->bDescriptorType,
			desc->bEndpointAddress, uep->addr,
			le16_to_cpu(desc->wMaxPacketSize), ep->maxpacket);
		return -EINVAL;
	}

	switch (usb_endpoint_type(desc)) {
	case USB_ENDPOINT_XFER_ISOC:
		type = DC_ENDPTYP_ISOC;
		break;
	case USB_ENDPOINT_XFER_BULK:
		type = DC_ENDPTYP_BULK;
		break;
	case USB_ENDPOINT_XFER_INT:
		type = DC_ENDPTYP_INTERRUPT;
		break;
	case USB_ENDPOINT_XFER_CONTROL:
	default:
		vega_dbg(udc->isp->dev, "%s: control endpoints unsupported\n",
			__func__);
		return -EINVAL;
	}

	spin_lock_irqsave(&udc->lock, flags);

	uep->desc = desc;
	uep->maxpacket = le16_to_cpu(desc->wMaxPacketSize);
	uep->rx_pending = false;
	uep->halted = false;
	uep->wedged = false;

	vega_udc_select_ep(uep);
	vega_udc_write(udc, DC_EPMAXPKTSZ, uep->maxpacket);
	vega_udc_write(udc, DC_BUFLEN, uep->maxpacket);
	vega_udc_write(udc, DC_EPTYPE, DC_EPENABLE | type);

	spin_unlock_irqrestore(&udc->lock, flags);

	return 0;
}

static int vega_ep_disable(struct usb_ep *ep)
{
	struct vega_ep *uep = ep_to_udc_ep(ep);
	struct vega_udc *udc = uep->udc;
	struct vega_request *req, *nreq;
	LIST_HEAD(req_list);
	unsigned long flags;

	vega_dbg(udc->isp->dev, "%s\n", __func__);

	spin_lock_irqsave(&udc->lock, flags);

	if (!uep->desc) {
		vega_dbg(udc->isp->dev, "%s: endpoint not enabled\n", __func__);
		spin_unlock_irqrestore(&udc->lock, flags);
		return -EINVAL;
	}

	uep->desc = NULL;
	uep->maxpacket = 0;

	vega_udc_select_ep(uep);
	vega_udc_write(udc, DC_EPTYPE, 0);

	/* TODO Synchronize with the IRQ handler */

	list_splice_init(&uep->queue, &req_list);

	spin_unlock_irqrestore(&udc->lock, flags);

	list_for_each_entry_safe(req, nreq, &req_list, queue) {
		list_del(&req->queue);
		vega_udc_request_complete(uep, req, -ESHUTDOWN);
	}

	return 0;
}

static struct usb_request *vega_ep_alloc_request(struct usb_ep *ep,
						    gfp_t gfp_flags)
{
	struct vega_request *req;

	req = kzalloc(sizeof(*req), gfp_flags);
	if (!req)
		return NULL;

	return &req->req;
}

static void vega_ep_free_request(struct usb_ep *ep, struct usb_request *_req)
{
	struct vega_request *req = req_to_udc_req(_req);

	kfree(req);
}

static int vega_ep_queue(struct usb_ep *ep, struct usb_request *_req,
			    gfp_t gfp_flags)
{
	struct vega_request *req = req_to_udc_req(_req);
	struct vega_ep *uep = ep_to_udc_ep(ep);
	struct vega_udc *udc = uep->udc;
	bool complete = false;
	unsigned long flags;
	int ret = 0;

	_req->status = -EINPROGRESS;
	_req->actual = 0;

	spin_lock_irqsave(&udc->lock, flags);

	vega_dbg(udc->isp->dev,
		"%s: req %p (%u bytes%s) ep %p(0x%02x)\n", __func__, _req,
		_req->length, _req->zero ? " (zlp)" : "", uep, uep->addr);

	req->ep = uep;

	if (uep->addr == 0) {
		if (_req->length != udc->ep0_length &&
		    udc->ep0_state != VEGA_CTRL_DATA_IN) {
			vega_dbg(udc->isp->dev,
				"%s: invalid length %u for req %p\n",
				__func__, _req->length, req);
			ret = -EINVAL;
			goto done;
		}

		switch (udc->ep0_state) {
		case VEGA_CTRL_DATA_IN:
			vega_dbg(udc->isp->dev, "%s: transmitting req %p\n",
				__func__, req);

			list_add_tail(&req->queue, &uep->queue);
			vega_udc_transmit(uep, req);
			break;

		case VEGA_CTRL_DATA_OUT:
			list_add_tail(&req->queue, &uep->queue);
			__vega_udc_select_ep(uep, USB_DIR_OUT);
			vega_udc_write(udc, DC_CTRLFUNC, DC_DSEN);
			break;

		case VEGA_CTRL_STATUS:
			complete = true;
			break;

		default:
			vega_dbg(udc->isp->dev, "%s: invalid ep0 state\n",
				__func__);
			ret = -EINVAL;
			break;
		}
	} else if (uep->desc) {
		bool empty = list_empty(&uep->queue);

		list_add_tail(&req->queue, &uep->queue);
		if ((uep->addr & USB_DIR_IN) && !uep->halted && empty)
			vega_udc_transmit(uep, req);
		else if (!(uep->addr & USB_DIR_IN) && uep->rx_pending)
			complete = vega_udc_receive(uep, req);
	} else {
		vega_dbg(udc->isp->dev,
			"%s: can't queue request to disabled ep%02x\n",
			__func__, uep->addr);
		ret = -ESHUTDOWN;
	}

done:
	if (ret < 0)
		req->ep = NULL;

	spin_unlock_irqrestore(&udc->lock, flags);

	if (complete)
		vega_udc_request_complete(uep, req, 0);

	return ret;
}

static int vega_ep_dequeue(struct usb_ep *ep, struct usb_request *_req)
{
	struct vega_request *req = req_to_udc_req(_req);
	struct vega_ep *uep = ep_to_udc_ep(ep);
	struct vega_udc *udc = uep->udc;
	unsigned long flags;

	vega_dbg(uep->udc->isp->dev, "%s(ep%02x)\n", __func__, uep->addr);

	spin_lock_irqsave(&udc->lock, flags);

	if (req->ep != uep)
		req = NULL;
	else
		list_del(&req->queue);

	spin_unlock_irqrestore(&udc->lock, flags);

	if (!req)
		return -EINVAL;

	vega_udc_request_complete(uep, req, -ECONNRESET);
	return 0;
}

static int __vega_ep_set_halt(struct vega_ep *uep, bool stall, bool wedge)
{
	struct vega_udc *udc = uep->udc;
	int ret;

	if (!uep->addr) {
		/*
		 * Halting the control endpoint is only valid as a delayed error
		 * response to a SETUP packet. Make sure EP0 is in the right
		 * stage and that the gadget isn't trying to clear the halt
		 * condition.
		 */
		if (WARN_ON(udc->ep0_state == VEGA_CTRL_SETUP || !stall ||
			     wedge)) {
			return -EINVAL;
		}
	}

	if (uep->addr && !uep->desc) {
		vega_dbg(udc->isp->dev, "%s: ep%02x is disabled\n", __func__,
			uep->addr);
		return -EINVAL;
	}

	if (uep->addr & USB_DIR_IN) {
		/* Refuse to halt IN endpoints with active transfers. */
		if (!list_empty(&uep->queue)) {
			vega_dbg(udc->isp->dev,
				"%s: ep%02x has request pending\n", __func__,
				uep->addr);
			return -EAGAIN;
		}
	}

	ret = __vega_udc_set_halt(uep, stall);
	if (ret < 0)
		return ret;

	if (!uep->addr) {
		/*
		 * Stalling EP0 completes the control transaction, move back to
		 * the SETUP state.
		 */
		udc->ep0_state = VEGA_CTRL_SETUP;
		return 0;
	}

	if (wedge)
		uep->wedged = true;
	else if (!stall)
		uep->wedged = false;

	return 0;
}

static int vega_ep_set_halt(struct usb_ep *ep, int value)
{
	struct vega_ep *uep = ep_to_udc_ep(ep);
	unsigned long flags;
	int ret;

	vega_dbg(uep->udc->isp->dev, "%s: %s halt on ep%02x\n", __func__,
		value ? "set" : "clear", uep->addr);

	spin_lock_irqsave(&uep->udc->lock, flags);
	ret = __vega_ep_set_halt(uep, value, false);
	spin_unlock_irqrestore(&uep->udc->lock, flags);

	return ret;
}

static int vega_ep_set_wedge(struct usb_ep *ep)
{
	struct vega_ep *uep = ep_to_udc_ep(ep);
	unsigned long flags;
	int ret;

	vega_dbg(uep->udc->isp->dev, "%s: set wedge on ep%02x)\n", __func__,
		uep->addr);

	spin_lock_irqsave(&uep->udc->lock, flags);
	ret = __vega_ep_set_halt(uep, true, true);
	spin_unlock_irqrestore(&uep->udc->lock, flags);

	return ret;
}

static void vega_ep_fifo_flush(struct usb_ep *ep)
{
	struct vega_ep *uep = ep_to_udc_ep(ep);
	struct vega_udc *udc = uep->udc;
	unsigned long flags;

	spin_lock_irqsave(&udc->lock, flags);  //compatible

	vega_udc_select_ep(uep);

	/*
	 * Set the CLBUF bit twice to flush both buffers in case double
	 * buffering is enabled.
	 */
	vega_udc_write(udc, DC_CTRLFUNC, DC_CLBUF);
	vega_udc_write(udc, DC_CTRLFUNC, DC_CLBUF);

	spin_unlock_irqrestore(&udc->lock, flags);
}

static const struct usb_ep_ops vega_ep_ops = {
	.enable = vega_ep_enable,
	.disable = vega_ep_disable,
	.alloc_request = vega_ep_alloc_request,
	.free_request = vega_ep_free_request,
	.queue = vega_ep_queue,
	.dequeue = vega_ep_dequeue,
	.set_halt = vega_ep_set_halt,
	.set_wedge = vega_ep_set_wedge,
	.fifo_flush = vega_ep_fifo_flush,
};

/* -----------------------------------------------------------------------------
 * Device States
 */

/* Called with the UDC spinlock held. */
static void vega_udc_connect(struct vega_udc *udc)
{
	usb_gadget_set_state(&udc->gadget, USB_STATE_POWERED);
	mod_timer(&udc->vbus_timer, jiffies + VEGA_VBUS_POLL_INTERVAL);
}

void vega_set_pullup(struct vega_device *isp, bool enable)
{
	vega_udc_write(isp->regs, HW_OTG_CTRL_SET,
			enable ? HW_DP_PULLUP : HW_DP_PULLUP << 16);
}

/* Called with the UDC spinlock held. */
static void vega_udc_disconnect(struct vega_udc *udc)
{
	if (udc->gadget.state < USB_STATE_POWERED)
		return;

	vega_dbg(udc->isp->dev, "Device disconnected in state %u\n",
		 udc->gadget.state);

	udc->gadget.speed = USB_SPEED_UNKNOWN;
	usb_gadget_set_state(&udc->gadget, USB_STATE_ATTACHED);

	if (udc->driver->disconnect)
		udc->driver->disconnect(&udc->gadget);

	del_timer(&udc->vbus_timer);

	/* TODO Reset all endpoints ? */
}

static void vega_udc_init_hw(struct vega_udc *udc)
{
	/*
	 * The device controller currently shares its interrupt with the host
	 * controller, the DC_IRQ polarity and signaling mode are ignored. Set
	 * the to active-low level-triggered.
	 *
	 * Configure the control, in and out pipes to generate interrupts on
	 * ACK tokens only (and NYET for the out pipe). The default
	 * configuration also generates an interrupt on the first NACK token.
	 */
	vega_udc_write(udc, DC_INTCONF, DC_CDBGMOD_ACK | DC_DDBGMODIN_ACK |
			  DC_DDBGMODOUT_ACK_NYET);

	vega_udc_write(udc, DC_INTENABLE, DC_IEPRXTX(7) | DC_IEPRXTX(6) |
			  DC_IEPRXTX(5) | DC_IEPRXTX(4) | DC_IEPRXTX(3) |
			  DC_IEPRXTX(2) | DC_IEPRXTX(1) | DC_IEPRXTX(0) |
			  DC_IEP0SETUP | DC_IEVBUS | DC_IERESM | DC_IESUSP |
			  DC_IEHS_STA | DC_IEBRST);

	if (udc->connected)
		vega_set_pullup(udc->isp, true);

	vega_udc_write(udc, DC_ADDRESS, DC_DEVEN);
}

static void vega_udc_reset(struct vega_udc *udc)
{
	unsigned long flags;

	spin_lock_irqsave(&udc->lock, flags);

	/*
	 * The bus reset has reset most registers to their default value,
	 * reinitialize the UDC hardware.
	 */
	vega_udc_init_hw(udc);

	udc->ep0_state = VEGA_CTRL_SETUP;
	udc->gadget.speed = USB_SPEED_FULL;

	usb_gadget_udc_reset(&udc->gadget, udc->driver);

	spin_unlock_irqrestore(&udc->lock, flags);
}

static void vega_udc_suspend(struct vega_udc *udc)
{
	if (udc->gadget.state < USB_STATE_DEFAULT)
		return;

	if (udc->driver->suspend)
		udc->driver->suspend(&udc->gadget);
}

static void vega_udc_resume(struct vega_udc *udc)
{
	if (udc->gadget.state < USB_STATE_DEFAULT)
		return;

	if (udc->driver->resume)
		udc->driver->resume(&udc->gadget);
}

/* -----------------------------------------------------------------------------
 * Gadget Operations
 */

static int vega_udc_get_frame(struct usb_gadget *gadget)
{
	struct vega_udc *udc = gadget_to_udc(gadget);

	return vega_udc_read(udc, DC_FRAMENUM) & ((1 << 11) - 1);
}

static int vega_udc_wakeup(struct usb_gadget *gadget)
{
	struct vega_udc *udc = gadget_to_udc(gadget);

	vega_dbg(udc->isp->dev, "%s\n", __func__);
	return -ENOTSUPP;
}

static int vega_udc_set_selfpowered(struct usb_gadget *gadget,
				       int is_selfpowered)
{
	struct vega_udc *udc = gadget_to_udc(gadget);

	if (is_selfpowered)
		udc->devstatus |= 1 << USB_DEVICE_SELF_POWERED;
	else
		udc->devstatus &= ~(1 << USB_DEVICE_SELF_POWERED);

	return 0;
}

static int vega_udc_pullup(struct usb_gadget *gadget, int is_on)
{
	struct vega_udc *udc = gadget_to_udc(gadget);

	vega_set_pullup(udc->isp, is_on);
	udc->connected = is_on;

	return 0;
}

static int vega_udc_start(struct usb_gadget *gadget,
			     struct usb_gadget_driver *driver)
{
	struct vega_udc *udc = gadget_to_udc(gadget);
	unsigned long flags;

	/* The hardware doesn't support low speed. */
	if (driver->max_speed < USB_SPEED_FULL) {
		dev_err(udc->isp->dev, "Invalid gadget driver\n");
		return -EINVAL;
	}

	spin_lock_irqsave(&udc->lock, flags);

	if (udc->driver) {
		dev_err(udc->isp->dev, "UDC already has a gadget driver\n");
		spin_unlock_irqrestore(&udc->lock, flags);
		return -EBUSY;
	}

	udc->driver = driver;

	spin_unlock_irqrestore(&udc->lock, flags);

	vega_dbg(udc->isp->dev, "starting UDC with driver %s\n",
		driver->function);

	udc->devstatus = 0;
	udc->connected = true;

	usb_gadget_set_state(&udc->gadget, USB_STATE_ATTACHED);

	/* DMA isn't supported yet, don't enable the DMA clock. */
	vega_udc_write(udc, DC_MODE, DC_GLINTENA);

	vega_udc_init_hw(udc);

	vega_dbg(udc->isp->dev, "UDC started with driver %s\n",
		driver->function);

	return 0;
}

static int vega_udc_stop(struct usb_gadget *gadget)
{
	struct vega_udc *udc = gadget_to_udc(gadget);
	unsigned long flags;

	vega_dbg(udc->isp->dev, "%s\n", __func__);

	del_timer_sync(&udc->vbus_timer);

	vega_udc_write(udc, DC_MODE, 0);

	spin_lock_irqsave(&udc->lock, flags);
	udc->driver = NULL;
	spin_unlock_irqrestore(&udc->lock, flags);

	return 0;
}

static const struct usb_gadget_ops vega_udc_ops = {
	.get_frame = vega_udc_get_frame,
	.wakeup = vega_udc_wakeup,
	.set_selfpowered = vega_udc_set_selfpowered,
	.pullup = vega_udc_pullup,
	.udc_start = vega_udc_start,
	.udc_stop = vega_udc_stop,
};

/* -----------------------------------------------------------------------------
 * Interrupt Handling
 */

static irqreturn_t vega_udc_irq(int irq, void *dev)
{
	struct vega_udc *udc = dev;
	unsigned int i;
	u32 status;

	status = vega_udc_read(udc, DC_INTERRUPT)
	       & vega_udc_read(udc, DC_INTENABLE);
	vega_udc_write(udc, DC_INTERRUPT, status);

	if (status & DC_IEVBUS) {
		vega_dbg(udc->isp->dev, "%s(VBUS)\n", __func__);
		/* The VBUS interrupt is only triggered when VBUS appears. */
		spin_lock(&udc->lock);
		vega_udc_connect(udc);
		spin_unlock(&udc->lock);
	}

	if (status & DC_IEBRST) {
		vega_dbg(udc->isp->dev, "%s(BRST)\n", __func__);

		vega_udc_reset(udc);
	}

	for (i = 0; i <= 7; ++i) {
		struct vega_ep *ep = &udc->ep[i*2];

		if (status & DC_IEPTX(i)) {
			vega_dbg(udc->isp->dev, "%s(EPTX%u)\n", __func__, i);
			vega_ep_tx_complete(ep);
		}

		if (status & DC_IEPRX(i)) {
			vega_dbg(udc->isp->dev, "%s(EPRX%u)\n", __func__, i);
			vega_ep_rx_ready(i ? ep - 1 : ep);
		}
	}

	if (status & DC_IEP0SETUP) {
		vega_dbg(udc->isp->dev, "%s(EP0SETUP)\n", __func__);

		vega_ep0_setup(udc);
	}

	if (status & DC_IERESM) {
		vega_dbg(udc->isp->dev, "%s(RESM)\n", __func__);
		vega_udc_resume(udc);
	}

	if (status & DC_IESUSP) {
		vega_dbg(udc->isp->dev, "%s(SUSP)\n", __func__);

		spin_lock(&udc->lock);
		if (!(vega_udc_read(udc, DC_MODE) & DC_VBUSSTAT))
			vega_udc_disconnect(udc);
		else
			vega_udc_suspend(udc);
		spin_unlock(&udc->lock);
	}

	if (status & DC_IEHS_STA) {
		vega_dbg(udc->isp->dev, "%s(HS_STA)\n", __func__);
		udc->gadget.speed = USB_SPEED_HIGH;
	}

	return status ? IRQ_HANDLED : IRQ_NONE;
}

static void vega_udc_vbus_poll(struct timer_list *t)
{
	struct vega_udc *udc = from_timer(udc, t, vbus_timer);
	unsigned long flags;

	spin_lock_irqsave(&udc->lock, flags);

	if (!(vega_udc_read(udc, DC_MODE) & DC_VBUSSTAT))
		vega_udc_disconnect(udc);
	else if (udc->gadget.state >= USB_STATE_POWERED)
		mod_timer(&udc->vbus_timer,
			  jiffies + VEGA_VBUS_POLL_INTERVAL);

	spin_unlock_irqrestore(&udc->lock, flags);
}

/* -----------------------------------------------------------------------------
 * Registration
 */

static void vega_udc_init_eps(struct vega_udc *udc)
{
	unsigned int i;

	INIT_LIST_HEAD(&udc->gadget.ep_list);

	for (i = 0; i < ARRAY_SIZE(udc->ep); ++i) {
		struct vega_ep *ep = &udc->ep[i];
		unsigned int ep_num = (i + 1) / 2;
		bool is_in = !(i & 1);

		ep->udc = udc;

		INIT_LIST_HEAD(&ep->queue);

		ep->addr = (ep_num && is_in ? USB_DIR_IN : USB_DIR_OUT)
			 | ep_num;
		ep->desc = NULL;

		sprintf(ep->name, "ep%u%s", ep_num,
			ep_num ? (is_in ? "in" : "out") : "");

		ep->ep.ops = &vega_ep_ops;
		ep->ep.name = ep->name;

		/*
		 * Hardcode the maximum packet sizes for now, to 64 bytes for
		 * the control endpoint and 512 bytes for all other endpoints.
		 * This fits in the 8kB FIFO without double-buffering.
		 */
		if (ep_num == 0) {
			usb_ep_set_maxpacket_limit(&ep->ep, 64);
			ep->ep.caps.type_control = true;
			ep->ep.caps.dir_in = true;
			ep->ep.caps.dir_out = true;
			ep->maxpacket = 64;
			udc->gadget.ep0 = &ep->ep;
		} else {
			usb_ep_set_maxpacket_limit(&ep->ep, 512);
			ep->ep.caps.type_iso = true;
			ep->ep.caps.type_bulk = true;
			ep->ep.caps.type_int = true;
			ep->maxpacket = 0;
			list_add_tail(&ep->ep.ep_list, &udc->gadget.ep_list);
		}

		if (is_in)
			ep->ep.caps.dir_in = true;
		else
			ep->ep.caps.dir_out = true;
	}
}

static int vega_udc_init(struct vega_udc *udc)
{
	u16 scratch;
	u32 chipid;

	/*
	 * Check that the controller is present by writing to the scratch
	 * register, modifying the bus pattern by reading from the chip ID
	 * register, and reading the scratch register value back. The chip ID
	 * and scratch register contents must match the expected values.
	 */
	vega_udc_write(udc, DC_SCRATCH, 0xbabe);
	chipid = vega_udc_read(udc, DC_CHIPID);
	scratch = vega_udc_read(udc, DC_SCRATCH);

	if (scratch != 0xbabe) {
		dev_err(udc->isp->dev,
			"udc: scratch test failed (0x%04x/0x%08x)\n",
			scratch, chipid);
		return -ENODEV;
	}

	if (chipid != 0x00011582 && chipid != 0x00158210) {
		dev_err(udc->isp->dev, "udc: invalid chip ID 0x%08x\n", chipid);
		return -ENODEV;
	}

	/* Reset the device controller. */
	vega_udc_write(udc, DC_MODE, DC_SFRESET);
	usleep_range(10000, 11000);
	vega_udc_write(udc, DC_MODE, 0);
	usleep_range(10000, 11000);

	return 0;
}

int vega_udc_register(struct vega_device *isp, int irq,
			 unsigned long irqflags)
{
	struct vega_udc *udc = &isp->udc;
	int ret;

	udc->irq = -1;
	udc->isp = isp;
	udc->regs = isp->regs;

	spin_lock_init(&udc->lock);
	timer_setup(&udc->vbus_timer, vega_udc_vbus_poll, 0);

	ret = vega_udc_init(udc);
	if (ret < 0)
		return ret;

	udc->irqname = kasprintf(GFP_KERNEL, "%s (udc)", dev_name(isp->dev));
	if (!udc->irqname)
		return -ENOMEM;

	ret = request_irq(irq, vega_udc_irq, IRQF_SHARED | irqflags,
			  udc->irqname, udc);
	if (ret < 0)
		goto error;

	udc->irq = irq;

	/*
	 * Initialize the gadget static fields and register its device. Gadget
	 * fields that vary during the life time of the gadget are initialized
	 * by the UDC core.
	 */
	udc->gadget.ops = &vega_udc_ops;
	udc->gadget.speed = USB_SPEED_UNKNOWN;
	udc->gadget.max_speed = USB_SPEED_HIGH;
	udc->gadget.name = "vega-udc";      // previously isp1761_udc

	vega_udc_init_eps(udc);

	ret = usb_add_gadget_udc(isp->dev, &udc->gadget);
	if (ret < 0)
		goto error;

	return 0;

error:
	if (udc->irq >= 0)
		free_irq(udc->irq, udc);
	kfree(udc->irqname);

	return ret;
}

void vega_udc_unregister(struct vega_device *isp)
{
	struct vega_udc *udc = &isp->udc;

	if (!udc->isp)
		return;

	usb_del_gadget_udc(&udc->gadget);

	free_irq(udc->irq, udc);
	kfree(udc->irqname);
}
