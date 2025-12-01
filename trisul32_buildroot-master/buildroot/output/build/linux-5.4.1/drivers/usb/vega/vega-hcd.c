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

volatile unsigned int port_change_flag=0;

unsigned int atl_skipmap_global;
unsigned int int_skipmap_global;
unsigned int iso_skipmap_global;
//#define DEBUG_VEGA

#ifdef DEBUG_VEGA
	#define vega_dbg(...)		dev_err(__VA_ARGS__)
	#define vega_pr_err(...) 	pr_err(__VA_ARGS__)
	#define vega_dbg1(...)		dev_err(__VA_ARGS__)
	#define vega_dbg2(...)		dev_err(__VA_ARGS__)
	#define vega_dbg3(...)		dev_err(__VA_ARGS__)
	#define vega_dbg4(...)		dev_err(__VA_ARGS__)
	#define vega_dbg5(...)		dev_err(__VA_ARGS__)
	#define vega_probe_dbg(...)	dev_err(__VA_ARGS__)
#else
	#define vega_dbg(...)		//dev_err(__VA_ARGS__)
	#define vega_pr_err(...) 	//pr_err(__VA_ARGS__)
	#define vega_dbg1(...)		//dev_err(__VA_ARGS__)
	#define vega_dbg2(...)		//dev_err(__VA_ARGS__)
	#define vega_dbg3(...)		//dev_err(__VA_ARGS__)
	#define vega_dbg4(...)		//dev_err(__VA_ARGS__)
	#define vega_dbg5(...)		//dev_err(__VA_ARGS__)
	#define vega_hub_cotrol_dbg(...)	//dev_err(__VA_ARGS__)
	#define vega_hub_cotrol_dbg1(...)	//(__VA_ARGS__)
	#define vega_handle_ptd_dbg(...)	//dev_err(__VA_ARGS__)
	#define vega_probe_dbg(...)		//dev_err(__VA_ARGS__)
	#define vega_mem_io_dbg(...) 		//pr_err(__VA_ARGS__)

	#define vega_init_dbg(...)		//pr_err(__VA_ARGS__)


	//#define dev_err(...)	(0)
	//#define pr_err(...)	(0)
#endif

//int unskip_check=0; //cdac-test-pid
//int done_check=0; //cdac-test-pid
//int stall_check=0; ////cdac-test-pid
//int stall_count=0; ////cdac-test-pid

volatile int device_disconnected = 0;
volatile int device_connected = 0;

u32 gframe_index;

int vega_hub_speed;


static inline struct vega_hcd *hcd_to_priv(struct usb_hcd *hcd)
{
	return *(struct vega_hcd **)hcd->hcd_priv;
}

/* Philips Proprietary Transfer Descriptor (PTD) */
typedef __u32 __bitwise __dw;
struct ptd {
	__dw dw0;
	__dw dw1;
	__dw dw2;
	__dw dw3;
	__dw dw4;
	__dw dw5;
	__dw dw6;
	__dw dw7;
};

#define PTD_OFFSET		0x0400
#define ISO_PTD_OFFSET		0x0400
#define INT_PTD_OFFSET		0x0800
#define ATL_PTD_OFFSET		0x0c00
#define PAYLOAD_OFFSET		0x1000

static struct kmem_cache *qtd_cachep;
static struct kmem_cache *qh_cachep;
static struct kmem_cache *urb_listitem_cachep;

struct urb_listitem {
	struct list_head urb_list;
	struct urb *urb;
};

struct vega_qtd {
	u8 packet_type;
	void *data_buffer;
	u32 payload_addr;

	/* the rest is HCD-private */
	struct list_head qtd_list;
	struct urb *urb;
	size_t length;
	size_t actual_length;

	/* QTD_ENQUEUED:	waiting for transfer (inactive) */
	/* QTD_PAYLOAD_ALLOC:	chip mem has been allocated for payload */
	/* QTD_XFER_STARTED:	valid ptd has been written to isp176x - only
				interrupt handler may touch this qtd! */
	/* QTD_XFER_COMPLETE:	payload has been transferred successfully */
	/* QTD_RETIRE:		transfer error/abort qtd */
#define QTD_ENQUEUED		0
#define QTD_PAYLOAD_ALLOC	1
#define QTD_XFER_STARTED	2
#define QTD_XFER_COMPLETE	3
#define QTD_RETIRE		4
	u32 status;
};

/* Queue head, one for each active endpoint */
struct vega_qh {
	struct list_head qh_list;
	struct list_head qtd_list;
	u32 toggle;
	u32 ping;
	int slot;
	int tt_buffer_dirty;	/* See USB2.0 spec section 11.17.5 */
};

#define PTD_STATE_QTD_DONE	1
#define PTD_STATE_QTD_RELOAD	2
#define PTD_STATE_URB_RETIRE	3

/* ATL */
/* DW0 */
#define DW0_VALID_BIT			DW0_ACTIVE_BIT
#define FROM_DW0_VALID(x)		FROM_DW0_ACTIVE(x)
#define TO_DW1_LENGTH(x)		(((u32) x) << 3)
#define TO_DW1_MAXPACKET(x)		(((u32) x) << 17)
//#define TO_DW0_MULTI(x)		(((u32) x) << 29)
#define TO_DW1_ENDPOINT_0(x)		(((u32)	x) << 31) //Bit [0]
#define FROM_DW1_ENDPOINT_0(x)	((((u32)	x) >> 31) & 1) //Bit [0]

#define TO_DW0_ENDPOINT_1_3(x)	(((u32)	x) << 0) //Bits [1:3]
#define FROM_DW0_ENDPOINT_1_3(x)	((((u32)	x) >> 0) & 7) //Bits [1:3]

/* DW1 */
#define TO_DW0_DEVICE_ADDR(x)		(((u32) x) << 3)
#define TO_DW0_PID_TOKEN(x)		(((u32) x) << 10)
#define FROM_DW0_PID_TOKEN(x)		((((u32) x) >> 10) & 3)
#define DW2_TRANS_ISO			((u32) 1 << 15)
#define DW2_TRANS_BULK			((u32) 2 << 15)
#define DW2_TRANS_INT			((u32) 3 << 15)

#define FROM_DW2_EP_TYPE(x)		((((u32) x) >> 15) & 3)


#define DW3_TRANS_SPLIT		((u32) 1 << 0)
#define DW3_SE_USB_LOSPEED		((u32) 2 << 2)
#define TO_DW3_PORT_NUM(x)		(((u32) x) << 4)
#define TO_DW3_HUB_NUM(x)		(((u32) x) << 11)


/* DW2 */
#define TO_DW2_DATA_START_ADDR(x)	(((u32) x) << 0)
#define TO_DW0_RL(x)			((x) << 16)
#define FROM_DW0_RL(x)			(((x) >> 16) & 0xf)
/* DW3 */
#define FROM_DW2_NRBYTESTRANSFERRED(x)		(((x)>> 17) & 0x3FFF)
#define FROM_DW2_SCS_NRBYTESTRANSFERRED(x)	(((x)>> 17) & 0x07ff)
#define TO_DW0_NAKCOUNT(x)		((x) << 12)
#define FROM_DW0_NAKCOUNT(x)		(((x) >> 12) & 0xf)
#define TO_DW1_CERR(x)			((x) << 0)
#define FROM_DW1_CERR(x)		(((x) >> 0) & 0x3)
#define TO_DW2_DATA_TOGGLE(x)		((x) << 31)
#define FROM_DW2_DATA_TOGGLE(x)	(((x) >> 31) & 0x1)
#define TO_DW0_PING(x)			((x) << 24)
#define FROM_DW0_PING(x)		(((x) >> 24) & 0x1)
#define DW0_ERROR_BIT			(1 << 28)
//#define DW3_BABBLE_BIT			(1 << 29)
#define DW0_HALT_BIT			(1 << 30)
#define DW0_ACTIVE_BIT			(1 << 31)
#define FROM_DW0_ACTIVE(x)		(((x) >> 31) & 0x01)

#define INT_UNDERRUN			(1 << 2)
#define INT_BABBLE			(1 << 1)
#define INT_EXACT			(1 << 0)

#define SETUP_PID	(2)
#define IN_PID		(1)
#define OUT_PID	(0)

/* Errata 1 */
#define RL_COUNTER	(0)
#define NAK_COUNTER	(0)

#define RL_COUNTER_ATL		(10)
#define NAK_COUNTER_ATL	(10)

#define ERR_COUNTER	(3)


#define SLOT_TIMEOUT 300
#define SLOT_CHECK_PERIOD 10000
static struct timer_list errata2_timer;
static struct usb_hcd *errata2_timer_hcd;

static void handle_done_ptds(struct usb_hcd *hcd);

/*
 * Access functions for isp176x memory (offset >= 0x0400).
 *
 * bank_reads8() reads memory locations prefetched by an earlier write to
 * HC_MEMORY_REG (see isp176x datasheet). Unless you want to do fancy multi-
 * bank optimizations, you should use the more generic mem_reads8() below.
 *
 * For access to ptd memory, use the specialized ptd_read() and ptd_write()
 * below.
 *
 * These functions copy via MMIO data to/from the device. memcpy_{to|from}io()
 * doesn't quite work because some people have to enforce 32-bit access
 */
static void bank_reads8(void __iomem *src_base, u32 src_offset, u32 bank_addr,
							__u32 *dst, u32 bytes)
{
	__u32 __iomem *src;
	u32 val;
	__u8 *src_byteptr;
	__u8 *dst_byteptr;

	//pr_err("bank_reads8\n");
	/*vega_pr_err("src_base : %lx\n",src_base);
	vega_pr_err("src_offset : %x\n",src_offset);
	vega_pr_err("mem_reads8 : %lx\n", dst);*/

	src = src_base + (src_offset);

	if (src_offset < PAYLOAD_OFFSET) { //TDs area
		while (bytes >= 4) {
			*dst = le32_to_cpu(__raw_readl(src));
			bytes -= 4;
			//vega_mem_io_dbg("bank_reads8 : %x\n",*dst);
			src++;
			dst++;
			
		}
	} else { //Payload area
		while (bytes >= 4) {
	
			*dst = __raw_readl(src);
			bytes -= 4;
			//vega_mem_io_dbg("bank_reads8 : %x\n",*dst);
			src++;
			dst++;
		}
	}

	if (!bytes)
		return;

	/* in case we have 3, 2 or 1 by left. The dst buffer may not be fully
	 * allocated.
	 */
	if (src_offset < PAYLOAD_OFFSET)
		val = le32_to_cpu(__raw_readl(src)); //TDs
	else
		val = __raw_readl(src); //Payload

	dst_byteptr = (void *) dst;
	src_byteptr = (void *) &val;
	while (bytes > 0) {
		*dst_byteptr = *src_byteptr;

		//vega_mem_io_dbg("bank_reads8 : %x\n",*dst_byteptr);
		dst_byteptr++;
		src_byteptr++;
		bytes--;
	}
}

static void mem_reads8(void __iomem *src_base, u32 src_offset, void *dst,
								u32 bytes)
{

	/*vega_pr_err("src_base : %lx\n",src_base);
	vega_pr_err("src_offset : %x\n",src_offset);
	vega_pr_err("mem_reads8 : %lx\n", dst);*/
	//pr_err("mem_reads8\n");

	//vega_write32(src_base, HC_MEMORY_REG, src_offset + ISP_BANK(0));
	//ndelay(90);
	bank_reads8(src_base, src_offset, ISP_BANK(0), dst, bytes);
}

static void mem_writes8(void __iomem *dst_base, u32 dst_offset,
						__u32 const *src, u32 bytes)
{
	__u32 __iomem *dst;

	dst = dst_base + dst_offset;

	//pr_err("mem_writes8\n");
	//vega_pr_err("dst_base : %lx\n",dst_base);
	//pr_err("dst_offset : %x\n",dst_offset);

	if (dst_offset < PAYLOAD_OFFSET) {
		while (bytes >= 4) {
			//__raw_writel(cpu_to_le32(*src), dst);
			__raw_writel(*src, dst);//FIXME
			bytes -= 4;
			//vega_mem_io_dbg("mem_writes8 : %x\n",*src);
			src++;
			dst++;
		}
	} else {
	
		if(bytes>8192)
			pr_err("bytes >8K\n");
		while (bytes >= 4) {
			__raw_writel(*src, dst);
			//vega_mem_io_dbg("mem_writes8 : %x\n",*src);
			bytes -= 4;
			
			
			src++;
			dst++;
		}
	}

	if (!bytes)
		return;
	/* in case we have 3, 2 or 1 bytes left. The buffer is allocated and the
	 * extra bytes should not be read by the HW.
	 */

	if (dst_offset < PAYLOAD_OFFSET){
		//__raw_writel(cpu_to_le32(*src), dst);
		__raw_writel(*src, dst);//FIXME
		}
	else
		__raw_writel(*src, dst);
}

/*
 * Read and write ptds. 'ptd_offset' should be one of ISO_PTD_OFFSET,
 * INT_PTD_OFFSET, and ATL_PTD_OFFSET. 'slot' should be less than 32.
 */
static void ptd_read(void __iomem *base, u32 ptd_offset, u32 slot,
								struct ptd *ptd)
{
	//vega_write32(base, HC_MEMORY_REG,	ISP_BANK(0) + ptd_offset + slot*sizeof(*ptd));

	//ndelay(90);
	bank_reads8(base, ptd_offset + slot*sizeof(*ptd), ISP_BANK(0),
						(void *) ptd, sizeof(*ptd));

	if(slot>7)
	{
		pr_err("SLOT > 7\n");
	}	
	if(slot!=0)
	{
		//pr_err("W-SLOT ! 0\n");
		//while(1);
	}	
	
	/*pr_err("------------RD------------\n");
	pr_err("Slot : %d\n",slot);
	pr_err("dw0 : %x\n",ptd->dw0);
	pr_err("dw1 : %x\n",ptd->dw1);
	pr_err("dw2 : %x\n",ptd->dw2);
	pr_err("dw3 : %x\n",ptd->dw3);
	pr_err("dw4 : %x\n",ptd->dw4);
	pr_err("dw5 : %x\n",ptd->dw5);
	pr_err("dw6 : %x\n",ptd->dw6);
	pr_err("dw7 : %x\n",ptd->dw7);
	pr_err("++++++++++++RD++++++++++++\n");*/
}

static void ptd_write(void __iomem *base, u32 ptd_offset, u32 slot,
								struct ptd *ptd)
{

	//if(unskip_check)	
	//	pr_err("> unskip_check ptd_write\n");
	/*if(ptd->dw3 !=0){*/

	/*	pr_err("------------WR------------\n");
		pr_err("Slot : %d\n",slot);
		pr_err("dw0 : %x\n",ptd->dw0);
		pr_err("dw1 : %x\n",ptd->dw1);
		pr_err("dw2 : %x\n",ptd->dw2);		
		pr_err("dw3 : %x\n",ptd->dw3);
		pr_err("dw4 : %x\n",ptd->dw4);
		pr_err("dw5 : %x\n",ptd->dw5);
		pr_err("dw6 : %x\n",ptd->dw6);
		pr_err("dw7 : %x\n",ptd->dw7);
		pr_err("++++++++++++WR++++++++++++\n");*/
	//}
	mem_writes8(base, ptd_offset + slot*sizeof(*ptd) + sizeof(ptd->dw0),
						&ptd->dw1, 7*sizeof(ptd->dw1));
						
						
	//pr_err("W-SLOT %d\n", slot);					

	if(slot>7)
	{
		pr_err("W-SLOT > 7\n");
	}
	
	if(slot!=0)
	{
		//pr_err("W-SLOT ! 0\n");
		//while(1);
	}		
	/* Make sure dw0 gets written last (after other dw's and after payload)
	   since it contains the enable bit */
	wmb();
	mem_writes8(base, ptd_offset + slot*sizeof(*ptd), &ptd->dw0,
							sizeof(ptd->dw0));
}

static void errata2_function(struct timer_list *unused)
{
	struct usb_hcd *hcd = errata2_timer_hcd;
	struct vega_hcd *priv = hcd_to_priv(hcd);
	int slot;
	struct ptd ptd;
	unsigned long spinflags;
	
	spin_lock_irqsave(&priv->lock, spinflags);
	pr_err("ERRATA\n");
	/*for (slot = 0; slot < 32; slot++)
		if (priv->atl_slots[slot].qh && time_after(jiffies,
					priv->atl_slots[slot].timestamp +
					msecs_to_jiffies(SLOT_TIMEOUT))) {
			ptd_read(hcd->regs, ATL_PTD_OFFSET, slot, &ptd);
			if (!FROM_DW0_ACTIVE(ptd.dw0)) //!FROM_DW0_VALID(ptd.dw0) && FIXME
				priv->atl_done_map |= 1 << slot;
		}

	if (priv->atl_done_map)
		handle_done_ptds(hcd);*/

	slot =0;
	ptd_read(hcd->regs, ATL_PTD_OFFSET, slot, &ptd);


	/*	priv->int_done_map |= 1; //vega_read32(hcd->regs, HC_INT_PTD_DONEMAP_REG);
		priv->atl_done_map |= 1; //vega_read32(hcd->regs, HC_ATL_PTD_DONEMAP_REG);
		vega_dbg1(hcd->self.controller,"priv->int_done_map %x >>>>>\n",priv->int_done_map);
		vega_dbg1(hcd->self.controller,"priv->atl_done_map %x >>>>>\n",priv->atl_done_map);
	*/

		int temp = vega_read32(hcd->regs, HC_ATL_PTD_SKIPMAP_REG);
		//dev_err(hcd->self.controller,"HC_ATL_PTD_SKIPMAP_REG %x >>>>>\n",temp);
	
		vega_write32(hcd->regs, HC_ATL_PTD_SKIPMAP_REG, 0xff);

		ptd.dw0 = 0;
		ptd_write(hcd->regs, ATL_PTD_OFFSET, slot, &ptd);

		priv->atl_done_map |= 1; //vega_read32(hcd->regs, HC_ATL_PTD_DONEMAP_REG);
		handle_done_ptds(hcd);

	spin_unlock_irqrestore(&priv->lock, spinflags);

	//errata2_timer.expires = jiffies + msecs_to_jiffies(SLOT_CHECK_PERIOD);
	//add_timer(&errata2_timer);
}



/* memory management of the 15kb on the chip from 0x1000 to 0x4C00 */
static void init_memory(struct vega_hcd *priv)
{
	int i, curr;
	u32 payload_addr;

	payload_addr = PAYLOAD_OFFSET;
	for (i = 0; i < BLOCK_1_NUM; i++) {
		priv->memory_pool[i].start = payload_addr;
		priv->memory_pool[i].size = BLOCK_1_SIZE;
		priv->memory_pool[i].free = 1;
		payload_addr += priv->memory_pool[i].size;
	}

	curr = i;
	for (i = 0; i < BLOCK_2_NUM; i++) {
		priv->memory_pool[curr + i].start = payload_addr;
		priv->memory_pool[curr + i].size = BLOCK_2_SIZE;
		priv->memory_pool[curr + i].free = 1;
		payload_addr += priv->memory_pool[curr + i].size;
	}

	curr = i;
	for (i = 0; i < BLOCK_3_NUM; i++) {
		priv->memory_pool[curr + i].start = payload_addr;
		priv->memory_pool[curr + i].size = BLOCK_3_SIZE;
		priv->memory_pool[curr + i].free = 1;
		payload_addr += priv->memory_pool[curr + i].size;
	}

	WARN_ON(payload_addr - priv->memory_pool[0].start > PAYLOAD_AREA_SIZE);
}

static void alloc_mem(struct usb_hcd *hcd, struct vega_qtd *qtd)
{
	struct vega_hcd *priv = hcd_to_priv(hcd);
	int i;

	WARN_ON(qtd->payload_addr);

	if (!qtd->length)
		return;

	for (i = 0; i < BLOCKS; i++) {
		if (priv->memory_pool[i].size >= qtd->length &&
				priv->memory_pool[i].free) {
			priv->memory_pool[i].free = 0;
			qtd->payload_addr = priv->memory_pool[i].start;
			return;
		}
	}
}

static void free_mem(struct usb_hcd *hcd, struct vega_qtd *qtd)
{
	struct vega_hcd *priv = hcd_to_priv(hcd);
	int i;

	if (!qtd->payload_addr)
		return;

	for (i = 0; i < BLOCKS; i++) {
		if (priv->memory_pool[i].start == qtd->payload_addr) {
			WARN_ON(priv->memory_pool[i].free);
			priv->memory_pool[i].free = 1;
			qtd->payload_addr = 0;
			return;
		}
	}

	vega_dbg(hcd->self.controller, "%s: Invalid pointer: %08x\n",
						__func__, qtd->payload_addr);
	WARN_ON(1);
	qtd->payload_addr = 0;
}


/*static u32 base_to_chip(u32 base)
{
	return ((base - 0x400) >> 3);
}*/

static int last_qtd_of_urb(struct vega_qtd *qtd, struct vega_qh *qh)
{
	struct urb *urb;

	if (list_is_last(&qtd->qtd_list, &qh->qtd_list))
		return 1;

	urb = qtd->urb;
	qtd = list_entry(qtd->qtd_list.next, typeof(*qtd), qtd_list);
	return (qtd->urb != urb);
}


/* magic numbers that can affect system performance */
#define	EHCI_TUNE_CERR		3	/* 0-3 qtd retries; 0 == don't stop */
#define	EHCI_TUNE_RL_HS		4	/* nak throttle; see 4.9 */
#define	EHCI_TUNE_RL_TT		0
#define	EHCI_TUNE_MULT_HS	1	/* 1-3 transactions/uframe; 4.10.3 */
#define	EHCI_TUNE_MULT_TT	1
#define	EHCI_TUNE_FLS		2	/* (small) 256 frame schedule */

static void create_ptd_atl(struct vega_qh *qh,
			struct vega_qtd *qtd, struct ptd *ptd)
{
	u32 maxpacket;
	u32 multi;
	u32 rl = RL_COUNTER;
	u32 nak = NAK_COUNTER;
	
	if (vega_hub_speed != HUB_SPEED_HIGH){
		if (usb_pipebulk(qtd->urb->pipe) || usb_pipecontrol(qtd->urb->pipe)){
			rl = RL_COUNTER_ATL;
			nak = NAK_COUNTER_ATL;
		}
	}
	
	memset(ptd, 0, sizeof(*ptd));

	vega_pr_err("create_ptd_atl\n");
	
	/* according to 3.6.2, max packet len can not be > 0x400 */
	maxpacket = usb_maxpacket(qtd->urb->dev, qtd->urb->pipe,
						usb_pipeout(qtd->urb->pipe));
	vega_pr_err("maxpacket : %x , multi : %x\n",maxpacket, multi);
	multi =  1 + ((maxpacket >> 11) & 0x3);
	maxpacket &= 0x7ff;

	//pr_err("maxpacket : %x , multi : %x\n",maxpacket, multi);

	/* DW0 */
	ptd->dw0 = DW0_ACTIVE_BIT;
	ptd->dw0 |= (usb_pipeendpoint(qtd->urb->pipe) >> 1); // Bits [1:3] of endpoint number
	ptd->dw0 |= TO_DW0_DEVICE_ADDR(usb_pipedevice(qtd->urb->pipe));
	ptd->dw0 |= TO_DW0_PID_TOKEN(qtd->packet_type);
	vega_pr_err("\n--------------------------------\n");
	/*if(qtd->packet_type == 0)
		pr_err("<OUT>\n");
	else if(qtd->packet_type == 1)
		pr_err("<IN>\n");
	else if(qtd->packet_type == 2)
		vega_pr_err("<SETUP>\n");
	else
		pr_err("<PING>\n");*/
	ptd->dw0 |= TO_DW0_RL(rl);
	ptd->dw0 |= TO_DW0_NAKCOUNT(nak);
	
	/*pr_err("------bDeviceClass----------\n");
	//pr_err("dev num: %08lx\n",qtd->urb->dev->tt->hub->devnum);
	//pr_err("maxchild: %08lx\n",qtd->urb->dev->maxchild);
	pr_err("bDeviceClass: %08lx\n",qtd->urb->dev->descriptor.bDeviceClass);
	pr_err("bDeviceSubClass: %08lx\n",qtd->urb->dev->descriptor.bDeviceSubClass);*/
	
	
	if (vega_hub_speed == HUB_SPEED_HIGH){
		if (qtd->urb->dev->speed != USB_SPEED_HIGH) {
			//FIXME printf("SPLIT bit not in VEGA\n");
			//vega_dbg(hcd->self.controller,"SPLIT bit not in VEGA\n");
			/* split transaction */
			//if (usb_pipeint(qtd->urb->pipe))
			//	pr_err("Split\n");
			ptd->dw3 = 0;

			ptd->dw3 |= DW3_TRANS_SPLIT;
			
			if (qtd->urb->dev->speed == USB_SPEED_LOW)
				ptd->dw3 |= DW3_SE_USB_LOSPEED;

			ptd->dw3 |= TO_DW3_PORT_NUM(qtd->urb->dev->ttport);
			ptd->dw3 |= TO_DW3_HUB_NUM(qtd->urb->dev->tt->hub->devnum);
			
			/* SE bit for Split INT transfers */
			if (usb_pipeint(qtd->urb->pipe) &&
					(qtd->urb->dev->speed == USB_SPEED_LOW))
				ptd->dw3 |= 2 << 2;

		} else {
			
			//FIXME 
			///pr_err("MULTI bit not in VEGA\n");
			/*ptd->dw0 |= TO_DW0_MULTI(multi);*/
			//pr_err("High speed device\n");

			if (usb_pipecontrol(qtd->urb->pipe)){
				ptd->dw0 &= ~TO_DW0_PING(1);
				//pr_err("CTL PING=0\n");
			}
			else if (usb_pipebulk(qtd->urb->pipe))
			{

				if(qtd->packet_type == 0) //OUT Transfer
				{
					ptd->dw0 |= TO_DW0_PING(qh->ping);
					//pr_err("BLK OUT PING=%x\n",qh->ping);
				}
				else
				{
					ptd->dw0 &= ~TO_DW0_PING(1);
					//pr_err("BLK IN PING=0\n");
				}
				
			}
			ptd->dw3 = 0;
			//pr_err("ping :%x\n",qh->ping);
		}
	}else{

		//pr_err("Full speed hub\n");


		ptd->dw3 = 0;
		
		if (qtd->urb->dev->speed == USB_SPEED_LOW)
			ptd->dw3 |= DW3_SE_USB_LOSPEED;

		//ptd->dw3 |= TO_DW3_PORT_NUM(qtd->urb->dev->ttport);
		//ptd->dw3 |= TO_DW3_HUB_NUM(qtd->urb->dev->tt->hub->devnum);
		
	}

	/* DW1 */
	ptd->dw1 = TO_DW1_LENGTH(qtd->length);
	
	
	if(qtd->length>8192)
		pr_err("qtd->length : %d\n",qtd->length);
	//pr_err("qtd->length : %d\n",qtd->length);
	ptd->dw1 |= TO_DW1_MAXPACKET(maxpacket);
	ptd->dw1 |= TO_DW1_ENDPOINT_0(usb_pipeendpoint(qtd->urb->pipe) & 1); // Bit[0] of endpoint number	

	if  (!usb_pipeisoc(qtd->urb->pipe))
		ptd->dw1 |= TO_DW1_CERR(ERR_COUNTER); 	/* Cerr */
	//pr_err("ptd->dw1 : %lx\n",ptd->dw1);
	/* DW2 */
	ptd->dw2 = 0;
	ptd->dw2 |= TO_DW2_DATA_START_ADDR(qtd->payload_addr);
	
	//ptd->dw2 &= ~TO_DW2_DATA_TOGGLE(1); //|= TO_DW2_DATA_TOGGLE(qh->toggle); FIXME
	if  (!usb_pipeisoc(qtd->urb->pipe))
		ptd->dw2 |= TO_DW2_DATA_TOGGLE(qh->toggle);// FIXME
	

	//pr_err("qh->toggle : %x,ptd->dw2 %x \n",qh->toggle, ptd->dw2);

	if (usb_pipebulk(qtd->urb->pipe)){
		ptd->dw2 |= DW2_TRANS_BULK;
		//if((qtd->length == 13) && (qtd->packet_type == IN_PID))
			//pr_err("bulk len==13\n");
	}
	else if  (usb_pipeint(qtd->urb->pipe)){
		ptd->dw2 |= DW2_TRANS_INT;
		//pr_err("usb_pipeint\n");
	}
	else if  (usb_pipeisoc(qtd->urb->pipe)){
		ptd->dw2 |= DW2_TRANS_ISO;
		//pr_err("usb_pipeisoc\n");
	}

	//vega_pr_err("qh->toggle : %x, qtd->urb->pipe : %x\n",qh->toggle,qtd->urb->pipe);
	

	if (usb_pipecontrol(qtd->urb->pipe)) {
		if (qtd->data_buffer == qtd->urb->setup_packet){
			ptd->dw2 &= ~TO_DW2_DATA_TOGGLE(1);
			//vega_pr_err("TO_DW2_DATA_TOGGLE CLEAR\n");
		}
		else //if (last_qtd_of_urb(qtd, qh)) //FIXME
		{
			ptd->dw2 |= TO_DW2_DATA_TOGGLE(1);
			//vega_pr_err("TO_DW2_DATA_TOGGLE \n");
		}
	}

	//pr_err("qh->toggle : %x,ptd->dw2 %x \n",qh->toggle, ptd->dw2);

	/* DW3 */
	
		
	ptd->dw4 = 0;
	ptd->dw5 = 0;
	ptd->dw6 = 0;
	ptd->dw7 = 0;
	
	//Reserved

}

static void transform_add_int(struct vega_qh *qh,
			struct vega_qtd *qtd, struct ptd *ptd)
{
	u32 usof, frame_index;
	u32 uFrame_7_3, uFrame, frame_interval;

	/*
	 * Most of this is guessing. ISP1761 datasheet is quite unclear, and
	 * the algorithm from the original Philips driver code, which was
	 * pretty much used in this driver before as well, is quite horrendous
	 * and, i believe, incorrect. The code below follows the datasheet and
	 * USB2.0 spec as far as I can tell, and plug/unplug seems to be much
	 * more reliable this way (fingers crossed...).
	 */


	if(qtd->urb->dev->descriptor.bDeviceClass != 0x09){ //Device class is not a hub
		
		if  (usb_pipeint(qtd->urb->pipe)){
		
			if (qtd->urb->dev->speed == USB_SPEED_HIGH) { //vega_hub_speed //HUB_SPEED_HIGH
			
				/* urb->interval is in units of microframes (1/8 ms) */

				if (qtd->urb->interval > 8) {//2^(bInterval-1)
					usof = 0x01; /* One bit set*/
					
					if(qtd->urb->interval > 256)
						qtd->urb->interval = 256; //Host controller supports only upto 32 ms
					uFrame_7_3 = qtd->urb->interval / 16; /* uFrame[7:3] = 1, period = 2ms for interval = 16;  uFrame[7:3] = 2, period = 4ms for interval = 32 etc.*/
				}
				else if (qtd->urb->interval > 4) //bInterval
				{
					usof = 0x01;
					if (qtd->urb->interval == 5)
						uFrame_7_3 = 0x1; 
					else if (qtd->urb->interval == 6)
						uFrame_7_3 = 0x2;
					else if (qtd->urb->interval == 7)
						uFrame_7_3 = 0x4;
					else if (qtd->urb->interval == 8)
						uFrame_7_3 = 0x8;
				
				}
				else //bInterval
				{
					if (qtd->urb->interval == 1)
						usof = 0xff; /* All bits set => interval 125us */
					else if (qtd->urb->interval == 2)
						usof = 0xaa; /* 4 bits set => interval 250us */
					else if (qtd->urb->interval == 3)
						usof = 0x11; /* 2 bits set => interval 500us */
					else if (qtd->urb->interval == 4)
						usof = 0x01; /* 1 bit set => interval 1ms */
					uFrame_7_3 = 0;
				}
				
				
				//if (qtd->urb->dev->speed != USB_SPEED_HIGH)
				//	usof = 0x1d; //For Split transfer
				//pr_err("HIGH p : %x u : %x interval :%x >>>>>\n", uFrame_7_3, usof, qtd->urb->interval);	
				
			} else {
				/* urb->interval is in units of frames (1 ms) */
				
				usof = 0x1d; //For Split transfer
				
				if(qtd->urb->interval > 32)
					qtd->urb->interval = 32; //Host controller supports only upto 32 ms
				uFrame_7_3 = qtd->urb->interval / 2; //uFrame_7_3 = 0 for 1ms, 1 for 2ms, 2 for 4ms, 4 for 8ms etc..
				//usof = 0x01; /* One bit set*/
				
				//pr_err("USB_SPEED_full period : %x usof : %x qtd->urb->interval :%x >>>>>\n", uFrame_7_3, usof, qtd->urb->interval);	
				
			}

		}
		else if  (usb_pipeisoc(qtd->urb->pipe)){
			
			if (vega_hub_speed == HUB_SPEED_HIGH) {
			
				if (qtd->urb->interval > 4) {
					usof = 0x01; /* One bit set*/
				}
				else{
					if (qtd->urb->interval == 1)
						usof = 0xff; /* All bits set => interval 125us */
					else if (qtd->urb->interval == 2)
						usof = 0xaa; /* 4 bits set => interval 250us */
					else if (qtd->urb->interval == 3)
						usof = 0x11; /* 2 bits set => interval 500us */
					else if (qtd->urb->interval == 4)
						usof = 0x01; /* 1 bit set => interval 1ms */
				}
				
				
				frame_index = gframe_index >> 3; //Frame Number
				uFrame_7_3 = frame_index; //Next Frame after 2 Frames (2ms)
			
			} else {
			
				frame_interval = 1 << (qtd->urb->interval - 1); //ms
				
				//frame_index = frame_index >> 3; //Frame Number
				uFrame_7_3 = gframe_index + frame_interval; //Next Frame after (2 + frame_interval) Frames
			}
		}
	} else { //Device class is a Hub
	
		//pr_err("Hub Class : %d\n",qtd->urb->dev->descriptor.bDeviceClass);
	
		if  (usb_pipeint(qtd->urb->pipe)){

			/* urb->interval is in units of frames (1 ms) */
			
			usof = 0x1d; //For Split transfer
			
			if(qtd->urb->interval > 32)
				qtd->urb->interval = 32; //Host controller supports only upto 32 ms
			uFrame_7_3 = qtd->urb->interval / 2; //uFrame_7_3 = 0 for 1ms, 1 for 2ms, 2 for 4ms, 4 for 8ms etc..


		}
		else if  (usb_pipeisoc(qtd->urb->pipe)){
			

			frame_interval = 1 << (qtd->urb->interval - 1); //ms
			
			//frame_index = frame_index >> 3; //Frame Number
			uFrame_7_3 = gframe_index + frame_interval; //Next Frame after (2 + frame_interval) Frames
		}

	}

	uFrame = uFrame_7_3 << 3;

	ptd->dw0 |= (uFrame<<12);
	ptd->dw0 |= (usof<<20);
	//pr_err(" dw0 : %x  \n", ptd->dw0);
}

static void create_ptd_int(struct vega_qh *qh,
			struct vega_qtd *qtd, struct ptd *ptd)
{
	//vega_dbg(hcd->self.controller,"create_ptd_int>>>>\n");
	create_ptd_atl(qh, qtd, ptd);
	transform_add_int(qh, qtd, ptd);
}


static void create_ptd_iso(struct vega_qh *qh,
			struct vega_qtd *qtd, struct ptd *ptd)
{
	//pr_err("create_ptd_iso : same as int>>>>\n");
	create_ptd_atl(qh, qtd, ptd);
	transform_add_int(qh, qtd, ptd);
}



static void vega_urb_done(struct usb_hcd *hcd, struct urb *urb)
__releases(priv->lock)
__acquires(priv->lock)
{
	struct vega_hcd *priv = hcd_to_priv(hcd);

	if (!urb->unlinked) {
		if (urb->status == -EINPROGRESS)
			urb->status = 0;
	}

	if (usb_pipein(urb->pipe) && usb_pipetype(urb->pipe) != PIPE_CONTROL) {
		void *ptr;
		for (ptr = urb->transfer_buffer;
		     ptr < urb->transfer_buffer + urb->transfer_buffer_length;
		     ptr += PAGE_SIZE)
			flush_dcache_page(virt_to_page(ptr)); 
	}

	/* complete() can reenter this HCD */
	usb_hcd_unlink_urb_from_ep(hcd, urb);
	spin_unlock(&priv->lock);
	usb_hcd_giveback_urb(hcd, urb, urb->status);
	spin_lock(&priv->lock);
}

static struct vega_qtd *qtd_alloc(gfp_t flags, struct urb *urb,
								u8 packet_type)
{
	struct vega_qtd *qtd;

	qtd = kmem_cache_zalloc(qtd_cachep, flags);
	if (!qtd)
		return NULL;

	INIT_LIST_HEAD(&qtd->qtd_list);
	qtd->urb = urb;
	qtd->packet_type = packet_type;
	qtd->status = QTD_ENQUEUED;
	qtd->actual_length = 0;

	return qtd;
}

static void qtd_free(struct vega_qtd *qtd)
{
	WARN_ON(qtd->payload_addr);
	kmem_cache_free(qtd_cachep, qtd);
}

static void start_bus_transfer(struct usb_hcd *hcd, u32 ptd_offset, int slot,
				struct vega_slotinfo *slots,
				struct vega_qtd *qtd, struct vega_qh *qh,
				struct ptd *ptd)
{
	struct vega_hcd *priv = hcd_to_priv(hcd);
	int skip_map;
	int temp;
	
	vega_dbg(hcd->self.controller,"start_bus_transfer>>>>\n");

	WARN_ON((slot < 0) || (slot > 31));
	WARN_ON(qtd->length && !qtd->payload_addr);
	WARN_ON(slots[slot].qtd);
	WARN_ON(slots[slot].qh);
	WARN_ON(qtd->status != QTD_PAYLOAD_ALLOC);

	/* Make sure done map has not triggered from some unlinked transfer */
	if (ptd_offset == ATL_PTD_OFFSET) {
		priv->atl_done_map |= vega_read32(hcd->regs,
						HC_ATL_PTD_DONEMAP_REG);
		priv->atl_done_map &= ~(1 << slot);
	} else if (ptd_offset == ISO_PTD_OFFSET) {
		priv->iso_done_map |= vega_read32(hcd->regs, HC_ISO_PTD_DONEMAP_REG);
		priv->iso_done_map &= ~(1 << slot);
	}	
	 else {
		priv->int_done_map |= vega_read32(hcd->regs,
						HC_INT_PTD_DONEMAP_REG);
		priv->int_done_map &= ~(1 << slot);
	}

	qh->slot = slot;
	qtd->status = QTD_XFER_STARTED;
	slots[slot].timestamp = jiffies;
	slots[slot].qtd = qtd;
	slots[slot].qh = qh;
	ptd_write(hcd->regs, ptd_offset, slot, ptd);

	vega_dbg1(hcd->self.controller,"start_bus_transfer \n");

	if (ptd_offset == ATL_PTD_OFFSET) {
		skip_map = atl_skipmap_global; //vega_read32(hcd->regs, HC_ATL_PTD_SKIPMAP_REG);
		vega_dbg(hcd->self.controller,"skip_map wr %x >>>>>\n",skip_map);
		skip_map &= ~(1 << qh->slot);
		
		//if(skip_map !=0xfffffffe)
		//	pr_err("skip_map atl %x >>>>>\n",skip_map);
			
		atl_skipmap_global = skip_map;
		vega_write32(hcd->regs, HC_ATL_PTD_SKIPMAP_REG, skip_map);
		
		/*if((qtd->length == 13) && (qtd->packet_type == IN_PID)){
			//pr_err("bulk len==13 unskip\n");
			unskip_check = 1;
			if(stall_check){//cdac-test-pid
				stall_check = 0;
				temp =  stall_count | (stall_count << 8) | (stall_count << 16) | (stall_count << 24);
				vega_write32(hcd->regs, HC_SCRATCH_REG, temp);
				stall_count++;
			}
			
							
					pr_err("------------unskip---td wr val---------\n");
					pr_err("Slot : %d\n",slot);
					pr_err("dw0 : %x\n",ptd->dw0);
					pr_err("dw1 : %x\n",ptd->dw1);
					pr_err("dw2 : %x\n",ptd->dw2);		
					pr_err("dw3 : %x\n",ptd->dw3);
					pr_err("dw4 : %x\n",ptd->dw4);
					pr_err("dw5 : %x\n",ptd->dw5);
					pr_err("dw6 : %x\n",ptd->dw6);
					pr_err("dw7 : %x\n",ptd->dw7);
					pr_err("++++++++++++unskip++++++++++++\n");
		
		}*/
		
		
		//pr_err("unskip\n");
		
	
		vega_dbg1(hcd->self.controller,"skip_map wr %x >>>>>\n",skip_map);
		skip_map = vega_read32(hcd->regs, HC_ATL_PTD_SKIPMAP_REG); //FIXME
		
		//pr_err("unskip_map \n");

	/*	while(1){
			if(vega_read32(hcd->regs, HC_ATL_PTD_DONEMAP_REG)==1)
				break;
		}*/
		vega_dbg1(hcd->self.controller,"done_map set\n");
	} else if(ptd_offset == ISO_PTD_OFFSET) {
		skip_map = iso_skipmap_global; //vega_read32(hcd->regs, HC_INT_PTD_SKIPMAP_REG);
		skip_map &= ~(1 << qh->slot);
		
		//if(skip_map !=0xfe)
		//pr_err("skip_map iso %x >>>>>\n",skip_map);
		iso_skipmap_global=skip_map;
		vega_write32(hcd->regs, HC_ISO_PTD_SKIPMAP_REG, skip_map);
		skip_map = vega_read32(hcd->regs, HC_ISO_PTD_SKIPMAP_REG); //FIXME
	}
	
	
	 else {
		skip_map = int_skipmap_global; //vega_read32(hcd->regs, HC_INT_PTD_SKIPMAP_REG);
		skip_map &= ~(1 << qh->slot);
		
		//if(skip_map !=0xfffffffe)
		//	pr_err("skip_map int %x >>>>>\n",skip_map);

		//if(skip_map !=0xfe)
		//pr_err("skip_map int %x >>>>>\n",skip_map);
		int_skipmap_global=skip_map;
		vega_write32(hcd->regs, HC_INT_PTD_SKIPMAP_REG, skip_map);
		skip_map = vega_read32(hcd->regs, HC_INT_PTD_SKIPMAP_REG); //FIXME
	}
}

static int is_short_bulk(struct vega_qtd *qtd)
{
	return (usb_pipebulk(qtd->urb->pipe) &&
					(qtd->actual_length < qtd->length));
}

static void collect_qtds(struct usb_hcd *hcd, struct vega_qh *qh,
						struct list_head *urb_list)
{
	int last_qtd;
	struct vega_qtd *qtd, *qtd_next;
	struct urb_listitem *urb_listitem;

	int k=0;
	
	
	//if(done_check){
		//pr_err("collect_qtds \n");
	//}//cdac-test-pid
	
	

	list_for_each_entry_safe(qtd, qtd_next, &qh->qtd_list, qtd_list) {
		vega_dbg1(hcd->self.controller,"collect_qtds status %x, length %x, pkt typ %x\n",qtd->status,qtd->actual_length,qtd->packet_type);
		if (qtd->status < QTD_XFER_COMPLETE)
			break;
			
		//if(done_check){
			//pr_err("collect_qtds 1 \n");
		//}	

		last_qtd = last_qtd_of_urb(qtd, qh);

		if ((!last_qtd) && (qtd->status == QTD_RETIRE))
			qtd_next->status = QTD_RETIRE;

		if (qtd->status == QTD_XFER_COMPLETE) {
		
			/*if(done_check){//cdac-test-pid
				//pr_err("collect_qtds 2 \n");
				
				if (qtd->actual_length == 0){

					vega_write32(hcd->regs, HC_SCRATCH_REG, 0x12345678);
					pr_err("td error \n"); 
				}
				
			}*/
		
		
			if (qtd->actual_length) {
			
				//if(done_check){ //cdac-test-pid
					//pr_err("collect_qtds 3\n");
				//}
			
			
				switch (qtd->packet_type) {
				case IN_PID:
					//vega_pr_err("<<<<<IN payload : %d\n", qtd->actual_length);
					mem_reads8(hcd->regs, qtd->payload_addr,
							qtd->data_buffer,
							qtd->actual_length);
							
							
					//if(done_check){ //cdac-test-pid
						//pr_err("bulk len==13 , data copied qtd->actual_length = %x\n", qtd->actual_length);
						//done_check = 0;
					//}
					
						
							
							
					//unsigned char *	mem_data = (unsigned char  *)(qtd->data_buffer);
						//vega_mem_io_dbg("------------IN payload %lx------------\n",qtd->payload_addr);
						//for(k=0;k<qtd->actual_length;k++){
							//vega_pr_err("%d: %x\n",k,mem_data[k]);
							
						//}
						//vega_mem_io_dbg("------------IN payload-over------------\n");
					/* Fall through (?) */
				case OUT_PID:
					qtd->urb->actual_length +=
							qtd->actual_length;
					/* Fall through ... */
				case SETUP_PID:
					break;
				}
			}

			if (is_short_bulk(qtd)) {
				if (qtd->urb->transfer_flags & URB_SHORT_NOT_OK)
					qtd->urb->status = -EREMOTEIO;
				if (!last_qtd)
					qtd_next->status = QTD_RETIRE;
			}
		}

		if (qtd->payload_addr)
			free_mem(hcd, qtd);

		if (last_qtd) {
			if ((qtd->status == QTD_RETIRE) &&
					(qtd->urb->status == -EINPROGRESS))
				qtd->urb->status = -EPIPE;
			/* Defer calling of urb_done() since it releases lock */
			urb_listitem = kmem_cache_zalloc(urb_listitem_cachep,
								GFP_ATOMIC);
			if (unlikely(!urb_listitem))
				break; /* Try again on next call */
			urb_listitem->urb = qtd->urb;
			list_add_tail(&urb_listitem->urb_list, urb_list);
		}

		list_del(&qtd->qtd_list);
		qtd_free(qtd);
	}
}

#define ENQUEUE_DEPTH	2
static void enqueue_qtds(struct usb_hcd *hcd, struct vega_qh *qh)
{
	struct vega_hcd *priv = hcd_to_priv(hcd);
	int ptd_offset;
	struct vega_slotinfo *slots;
	int curr_slot, free_slot;
	int n;
	struct ptd ptd;
	struct vega_qtd *qtd;
	int k=0;
	//unsigned int  *mem_data;
	
	vega_dbg1(hcd->self.controller,"enqueue_qtds>>>>\n");

	if (unlikely(list_empty(&qh->qtd_list))) {
		WARN_ON(1);
		return;
	}

	/* Make sure this endpoint's TT buffer is clean before queueing ptds */
	if (qh->tt_buffer_dirty){
		pr_err(">>>>>>Buffer dirty \n");
		return;
	}

	if (usb_pipeint(list_entry(qh->qtd_list.next, struct vega_qtd,
							qtd_list)->urb->pipe)) {
		ptd_offset = INT_PTD_OFFSET;
		slots = priv->int_slots;
	} else if(usb_pipeisoc(list_entry(qh->qtd_list.next, struct vega_qtd,
							qtd_list)->urb->pipe)) {
		ptd_offset = ISO_PTD_OFFSET;
		slots = priv->iso_slots;
	}
	   else{
		ptd_offset = ATL_PTD_OFFSET;
		slots = priv->atl_slots;
	}

	free_slot = -1;
	for (curr_slot = 0; curr_slot < 32; curr_slot++) {
		if ((free_slot == -1) && (slots[curr_slot].qtd == NULL))
			free_slot = curr_slot;
		if (slots[curr_slot].qh == qh)
			break;
	}

	n = 0;
	list_for_each_entry(qtd, &qh->qtd_list, qtd_list) {
		if (qtd->status == QTD_ENQUEUED) {
			WARN_ON(qtd->payload_addr);
			alloc_mem(hcd, qtd);
			if ((qtd->length) && (!qtd->payload_addr))
				break;
				vega_mem_io_dbg("qtd->length: %x, qtd->packet_type: %x \n",qtd->length, qtd->packet_type);

			if ((qtd->length) &&
			    ((qtd->packet_type == SETUP_PID) ||
			     (qtd->packet_type == OUT_PID))) {

				mem_writes8(hcd->regs, qtd->payload_addr,
						qtd->data_buffer, qtd->length);
						//mem_data = (unsigned int  *)(qtd->data_buffer);
						//vega_pr_err(">>>>>OUT Payload :%d \n",qtd->length);
						//vega_mem_io_dbg("------------payload------------\n");

				//for(k=0;k<qtd->length;k++){
					//vega_pr_err("%d: %x\n",k,mem_data[k]);
					
				//}
				//vega_mem_io_dbg("------------payload-over------------\n");
			}

			qtd->status = QTD_PAYLOAD_ALLOC;
		}

		if (qtd->status == QTD_PAYLOAD_ALLOC) {
/*
			if ((curr_slot > 31) && (free_slot == -1))
				vega_dbg(hcd->self.controller, "%s: No slot "
					"available for transfer\n", __func__);
*/
			/* Start xfer for this endpoint if not already done */
			
			
			if ((curr_slot > 31) && (free_slot > -1)) {
				if (usb_pipeint(qtd->urb->pipe))
					create_ptd_int(qh, qtd, &ptd);
				else if (usb_pipeisoc(qtd->urb->pipe)){
					gframe_index = vega_read32(hcd->regs, HC_FRINDEX); //uFrame Number
					create_ptd_iso(qh, qtd, &ptd);
				}
				else
					create_ptd_atl(qh, qtd, &ptd);
				//pr_err("enqueue_qtds -> start_bus_transfer >>>>>\n");
				start_bus_transfer(hcd, ptd_offset, free_slot,
							slots, qtd, qh, &ptd);
				curr_slot = free_slot;
			}

			n++;
			if (n >= ENQUEUE_DEPTH)
				break;
		}
	}
}

static void schedule_ptds(struct usb_hcd *hcd)
{
	struct vega_hcd *priv;
	struct vega_qh *qh, *qh_next;
	struct list_head *ep_queue;
	LIST_HEAD(urb_list);
	struct urb_listitem *urb_listitem, *urb_listitem_next;
	int i;

	//pr_err("schedule_ptds\n");

	if (!hcd) {
		WARN_ON(1);
		return;
	}

	priv = hcd_to_priv(hcd);

	/*
	 * check finished/retired xfers, transfer payloads, call urb_done()
	 */
	for (i = 0; i < QH_END; i++) {
		ep_queue = &priv->qh_list[i];
		list_for_each_entry_safe(qh, qh_next, ep_queue, qh_list) {
			collect_qtds(hcd, qh, &urb_list);
			if (list_empty(&qh->qtd_list))
				list_del(&qh->qh_list);
		}
	}

	list_for_each_entry_safe(urb_listitem, urb_listitem_next, &urb_list,
								urb_list) {
		vega_urb_done(hcd, urb_listitem->urb);
		kmem_cache_free(urb_listitem_cachep, urb_listitem);
	}
	
	//unskip_check = 0; //cdac-test-pid

	/*
	 * Schedule packets for transfer.
	 *
	 * According to USB2.0 specification:
	 *
	 * 1st prio: interrupt xfers, up to 80 % of bandwidth
	 * 2nd prio: control xfers
	 * 3rd prio: bulk xfers
	 *
	 * ... but let's use a simpler scheme here (mostly because ISP1761 doc
	 * is very unclear on how to prioritize traffic):
	 *
	 * 1) Enqueue any queued control transfers, as long as payload chip mem
	 *    and PTD ATL slots are available.
	 * 2) Enqueue any queued INT transfers, as long as payload chip mem
	 *    and PTD INT slots are available.
	 * 3) Enqueue any queued bulk transfers, as long as payload chip mem
	 *    and PTD ATL slots are available.
	 *
	 * Use double buffering (ENQUEUE_DEPTH==2) as a compromise between
	 * conservation of chip mem and performance.
	 *
	 * I'm sure this scheme could be improved upon!
	 */
	for (i = 0; i < QH_END; i++) {
		ep_queue = &priv->qh_list[i];
		list_for_each_entry_safe(qh, qh_next, ep_queue, qh_list)
			enqueue_qtds(hcd, qh);
	}
	//pr_err("schedule_ptds over\n");
}

#define PTD_STATE_QTD_DONE	1
#define PTD_STATE_QTD_RELOAD	2
#define PTD_STATE_URB_RETIRE	3

static int check_int_transfer(struct usb_hcd *hcd, struct ptd *ptd,
								struct urb *urb)
{
	int mode_ctl, ep_num, ep_dir;
	
	if (ptd->dw0 & DW0_HALT_BIT) {

		urb->status = -EPIPE; //stall
		
		
		ep_num = (FROM_DW0_ENDPOINT_1_3(ptd->dw0) << 1) | FROM_DW1_ENDPOINT_0(ptd->dw1);
		
		ep_dir = FROM_DW0_PID_TOKEN(ptd->dw0);
		
		mode_ctl = vega_read32(hcd->regs, HC_HW_MODE_CTRL);
		
		mode_ctl = mode_ctl | (ep_dir << 12) | (ep_num << 7) | HW_PID_RESET;
		vega_write32(hcd->regs, HC_HW_MODE_CTRL, mode_ctl ); // Do PID reset
		mdelay(10);
		mode_ctl &= ~HW_PID_RESET;
		vega_write32(hcd->regs, HC_HW_MODE_CTRL, mode_ctl ); // Clear PID reset
		

		return PTD_STATE_URB_RETIRE;
	}
	
	if ((ptd->dw0 & DW0_ERROR_BIT)) {
		
		pr_err("int ERROR BIT, CERR %x \n",FROM_DW1_CERR(ptd->dw1));
		u32 temp = vega_read32(hcd->regs, HC_PORTSC1);
	
		return PTD_STATE_URB_RETIRE;
		
	}
	
	//if (!FROM_DW0_NAKCOUNT(ptd->dw0) ) {
		/*
		 * NAKs are handled in HW by the chip. Usually if the
		 * device is not able to send data fast enough.
		 * This happens mostly on slower hardware.
		 */
		//pr_err("NACK COUNT OVER\n");
		//return PTD_STATE_QTD_RELOAD;

		//}

	//if (!FROM_DW0_NAKCOUNT(ptd->dw0) && (ptd->dw0 & DW0_ACTIVE_BIT)) {
		/*
		 * NAKs are handled in HW by the chip. Usually if the
		 * device is not able to send data fast enough.
		 * This happens mostly on slower hardware.
		 */
	//	pr_err("NACK COUNT OVER\n");
	//	return PTD_STATE_QTD_RELOAD;
//	}

	return PTD_STATE_QTD_DONE;
}


static int check_iso_transfer(struct usb_hcd *hcd, struct ptd *ptd,
								struct urb *urb)
{
	int mode_ctl, ep_num, ep_dir;
	
	if (ptd->dw0 & DW0_HALT_BIT) {

		urb->status = -EPIPE; //stall
		
		
		ep_num = (FROM_DW0_ENDPOINT_1_3(ptd->dw0) << 1) | FROM_DW1_ENDPOINT_0(ptd->dw1);
		
		ep_dir = FROM_DW0_PID_TOKEN(ptd->dw0);
		
		mode_ctl = vega_read32(hcd->regs, HC_HW_MODE_CTRL);
		
		mode_ctl = mode_ctl | (ep_dir << 12) | (ep_num << 7) | HW_PID_RESET;
		vega_write32(hcd->regs, HC_HW_MODE_CTRL, mode_ctl ); // Do PID reset
		mdelay(10);
		mode_ctl &= ~HW_PID_RESET;
		vega_write32(hcd->regs, HC_HW_MODE_CTRL, mode_ctl ); // Clear PID reset
		

		return PTD_STATE_URB_RETIRE;
	}

	return PTD_STATE_QTD_DONE;
}

static int check_atl_transfer(struct usb_hcd *hcd, struct ptd *ptd,
								struct urb *urb)
{
	WARN_ON(!ptd);
	vega_dbg1(hcd->self.controller,"check_atl_transfer function>>>> %x\n",ptd->dw0);
	int mode_ctl, ep_num, ep_dir;
	static int qtd_reload_count = 0;

	if (ptd->dw0 & DW0_HALT_BIT) {
		

		urb->status = -EPIPE; //stall
		
		ep_num = (FROM_DW0_ENDPOINT_1_3(ptd->dw0) << 1) | FROM_DW1_ENDPOINT_0(ptd->dw1);
		
		ep_dir = FROM_DW0_PID_TOKEN(ptd->dw0);
		
		mode_ctl = vega_read32(hcd->regs, HC_HW_MODE_CTRL);
		
		mode_ctl = mode_ctl | (ep_dir << 12) | (ep_num << 7) | HW_PID_RESET;
		vega_write32(hcd->regs, HC_HW_MODE_CTRL, mode_ctl ); // Do PID reset
		mdelay(10);
		mode_ctl &= ~HW_PID_RESET;
		vega_write32(hcd->regs, HC_HW_MODE_CTRL, mode_ctl ); // Clear PID reset
	
		return PTD_STATE_URB_RETIRE;
	}
	
	if ((ptd->dw0 & DW0_ERROR_BIT)) {
		
		pr_err("atl ERROR BIT, CERR %x \n",FROM_DW1_CERR(ptd->dw1));
		u32 temp = vega_read32(hcd->regs, HC_PORTSC1);

		urb->status = -EPROTO;
				/*	pr_err("------------CERR---td RD val---------\n");
					pr_err("dw0 : %x\n",ptd->dw0);
					pr_err("dw1 : %x\n",ptd->dw1);
					pr_err("dw2 : %x\n",ptd->dw2);		
					pr_err("dw3 : %x\n",ptd->dw3);
					pr_err("dw4 : %x\n",ptd->dw4);
					pr_err("dw5 : %x\n",ptd->dw5);
					pr_err("dw6 : %x\n",ptd->dw6);
					pr_err("dw7 : %x\n",ptd->dw7);
					pr_err("++++++++++++CERR++++++++++++\n");*/


	
		return PTD_STATE_URB_RETIRE;

	}

	if (vega_hub_speed != HUB_SPEED_HIGH){ //added as full speed hub was not working
		
		if (!FROM_DW0_NAKCOUNT(ptd->dw0) ) {
			/*
			 * NAKs are handled in HW by the chip. Usually if the
			 * device is not able to send data fast enough.
			 * This happens mostly on slower hardware.
			 */
			//pr_err("NACK COUNT OVER\n");

			//if(FROM_DW2_EP_TYPE(ptd->dw2) == 0) //Control transfer -- infinite retry on NAK
			//	return PTD_STATE_QTD_DONE;
			//else{ //Bulk transfer -- 5000 retry on NAK
				qtd_reload_count++;
				if(qtd_reload_count > 5000) {
					qtd_reload_count = 0;
					urb->status = -EPROTO;
					pr_err("NACK  retry\n");
					return PTD_STATE_URB_RETIRE;
				} else
					return PTD_STATE_QTD_RELOAD;
			//}

		}
	}

	//if (!FROM_DW0_NAKCOUNT(ptd->dw0) && (ptd->dw0 & DW0_ACTIVE_BIT)) {
		/*
		 * NAKs are handled in HW by the chip. Usually if the
		 * device is not able to send data fast enough.
		 * This happens mostly on slower hardware.
		 */
		//pr_err("NACK COUNT OVER\n");
		//return PTD_STATE_QTD_RELOAD;
	//}

	return PTD_STATE_QTD_DONE;
}


static void handle_done_ptds(struct usb_hcd *hcd)
{
	struct vega_hcd *priv = hcd_to_priv(hcd);
	struct ptd ptd;
	struct vega_qh *qh;
	int slot;
	int state;
	struct vega_slotinfo *slots;
	u32 ptd_offset;
	struct vega_qtd *qtd;
	int modified;
	int skip_map;
	
	vega_dbg1(hcd->self.controller,"handle_done_ptds>>>>\n");
	//pr_err("priv->int_done_map %x >>>>>\n",priv->int_done_map);
	//pr_err("priv->atl_done_map %x >>>>>\n",priv->atl_done_map);

	//skip_map = int_skipmap_global; //vega_read32(hcd->regs, HC_INT_PTD_SKIPMAP_REG);
	
	//pr_err("skip_map 1 %x >>>>>\n",skip_map);
	//pr_err("priv->int_done_map 1 %x >>>>>\n",priv->int_done_map);
	
	//skip_map = vega_read32(hcd->regs, HC_ATL_Pvega_usb_remove(struct platform_device *op);
TD_SKIPMAP_REG);
	//pr_err("skip_map 2 %x >>>>>\n",skip_map);
	//pr_err("priv->atl_done_map 2 %x >>>>>\n",priv->atl_done_map);
	
	skip_map = int_skipmap_global ; //vega_read32(hcd->regs, HC_ATL_PTD_SKIPMAP_REG); //FIXME
	priv->int_done_map &= ~skip_map;
	skip_map = atl_skipmap_global ; //vega_read32(hcd->regs, HC_ATL_PTD_SKIPMAP_REG);  //FIXME
	priv->atl_done_map &= ~skip_map;

	skip_map = iso_skipmap_global ; //vega_read32(hcd->regs, HC_ATL_PTD_SKIPMAP_REG);  //FIXME
	priv->iso_done_map &= ~skip_map;

	modified = priv->int_done_map || priv->atl_done_map ||priv->iso_done_map;
	
	//pr_err("priv->int_done_map %x >>>>>\n",priv->int_done_map);
	//pr_err("priv->atl_done_map %x >>>>>\n",priv->atl_done_map);
	


	while (priv->int_done_map || priv->atl_done_map || priv->iso_done_map) {
		//vega_pr_err(".");
		if (priv->int_done_map) {
			/* INT ptd */
			slot = __ffs(priv->int_done_map);
			priv->int_done_map &= ~(1 << slot);
			slots = priv->int_slots;
			/* This should not trigger, and could be removed if
			   noone have any problems with it triggering: */
			if (!slots[slot].qh) {
				WARN_ON(1);
				continue;
			}
			ptd_offset = INT_PTD_OFFSET;
			ptd_read(hcd->regs, INT_PTD_OFFSET, slot, &ptd);
			state = check_int_transfer(hcd, &ptd,
							slots[slot].qtd->urb);
		} else if(priv->iso_done_map)
		{		
			/* ISO ptd */
			slot = __ffs(priv->iso_done_map);
			priv->iso_done_map &= ~(1 << slot);
			slots = priv->iso_slots;
			/* This should not trigger, and could be removed if
			   noone have any problems with it triggering: */
			if (!slots[slot].qh) {
				WARN_ON(1);
				continue;
			}
			ptd_offset = ISO_PTD_OFFSET;
			ptd_read(hcd->regs, ISO_PTD_OFFSET, slot, &ptd);
			state = check_iso_transfer(hcd, &ptd,
							slots[slot].qtd->urb);	

		}		
		 else {
			 //pr_err("done\n");
			/* ATL ptd */
			//pr_err("ATL ptd>>>>\n");
			//pr_err("priv->atl_done_map %x >>>>>\n",priv->atl_done_map);
			slot = __ffs(priv->atl_done_map);
			priv->atl_done_map &= ~(1 << slot);
			slots = priv->atl_slots;
			/* This should not trigger, and could be removed if
			   noone have any problems with it triggering: */
			if (!slots[slot].qh) {
				WARN_ON(1);
				continue;
			}
			ptd_offset = ATL_PTD_OFFSET;
			ptd_read(hcd->regs, ATL_PTD_OFFSET, slot, &ptd);
			//pr_err("done_map \n");
			state = check_atl_transfer(hcd, &ptd,
							slots[slot].qtd->urb);
							
							
			//vega_dbg1(hcd->self.controller,"state: %x\n",state);				
		}

		vega_handle_ptd_dbg(hcd->self.controller,"ptd.dw0 :%x, ptd.dw1 :%x, ptd.dw2 :%x\n",ptd.dw0,ptd.dw1,ptd.dw2);

		qtd = slots[slot].qtd;
		slots[slot].qtd = NULL;
		qh = slots[slot].qh;
		slots[slot].qh = NULL;
		qh->slot = -1;

		WARN_ON(qtd->status != QTD_XFER_STARTED);

		switch (state) {
		case PTD_STATE_QTD_DONE:
			if ((usb_pipeint(qtd->urb->pipe)) &&
				       (qtd->urb->dev->speed != USB_SPEED_HIGH)) {
				qtd->actual_length =
				       FROM_DW2_SCS_NRBYTESTRANSFERRED(ptd.dw2);
			//	pr_err("int qtd->actual_length:%x\n", qtd->actual_length);	   

			}

			else if ((usb_pipeisoc(qtd->urb->pipe)) &&
				       (qtd->urb->dev->speed != USB_SPEED_HIGH)){
				qtd->actual_length =
				       FROM_DW2_SCS_NRBYTESTRANSFERRED(ptd.dw2);

				//pr_err("iso qtd->actual_length:%x\n", qtd->actual_length);	   
			}
			else {
				qtd->actual_length =
					FROM_DW2_NRBYTESTRANSFERRED(ptd.dw2);
							
				/*if((qtd->actual_length == 0) || (qtd->actual_length == 13)){
				
					pr_err("bulk qtd->actual_length:%d\n", qtd->actual_length);	  
				
					pr_err("------------uc------------\n");
					pr_err("Slot : %d\n",slot);
					pr_err("dw0 : %x\n",ptd.dw0);
					pr_err("dw1 : %x\n",ptd.dw1);
					pr_err("dw2 : %x\n",ptd.dw2);		
					pr_err("dw3 : %x\n",ptd.dw3);
					pr_err("dw4 : %x\n",ptd.dw4);
					pr_err("dw5 : %x\n",ptd.dw5);
					pr_err("dw6 : %x\n",ptd.dw6);
					pr_err("dw7 : %x\n",ptd.dw7);
					pr_err("++++++++++++uc++++++++++++\n");
				}*/
				 
			}
					
			/*if (usb_pipebulk(qtd->urb->pipe)){	//cdac-test-pid
				if((qtd->length == 13) && (qtd->packet_type == IN_PID)){
					//pr_err("bulk len==13 done, qtd->actual_length = %d\n", qtd->actual_length);
					done_check=1;
				}
			}*/
					
					

			vega_handle_ptd_dbg(hcd->self.controller,"qtd->actual_length:%x\n", qtd->actual_length);	
			
								

			qtd->status = QTD_XFER_COMPLETE;
			
			if(qtd->packet_type == 0) {
			
				qh->ping = FROM_DW0_PING(ptd.dw0);
				
				//pr_err("aa qh->ping=%d\n", qh->ping);
			}
			
			if (list_is_last(&qtd->qtd_list, &qh->qtd_list) ||
							is_short_bulk(qtd))
				qtd = NULL;
			else
				qtd = list_entry(qtd->qtd_list.next,
							typeof(*qtd), qtd_list);

			qh->toggle = FROM_DW2_DATA_TOGGLE(ptd.dw2);

			break;

		case PTD_STATE_QTD_RELOAD: /* QTD_RETRY, for atls only */
			vega_pr_err("PTD_STATE_QTD_RELOAD\n");
			qtd->status = QTD_PAYLOAD_ALLOC;
			ptd.dw0 |= DW0_VALID_BIT;
			/* RL counter = ERR counter */
			ptd.dw0 &= ~TO_DW0_NAKCOUNT(0xf);
			ptd.dw0 |= TO_DW0_NAKCOUNT(FROM_DW0_RL(ptd.dw0));
			ptd.dw1 &= ~TO_DW1_CERR(3);
			ptd.dw1 |= TO_DW1_CERR(ERR_COUNTER);
			qh->toggle = FROM_DW2_DATA_TOGGLE(ptd.dw2);

			if(qtd->packet_type == 0) {
				qh->ping = FROM_DW0_PING(ptd.dw0);
				//pr_err("bb qh->ping=%d\n", qh->ping);
			}
			break;

		case PTD_STATE_URB_RETIRE:
			qtd->status = QTD_RETIRE;
			vega_pr_err("PTD_STATE_URB_RETIRE\n");
			if(vega_hub_speed == HUB_SPEED_HIGH) {
				if ((qtd->urb->dev->speed != USB_SPEED_HIGH) &&
						(qtd->urb->status != -EPIPE) &&
						(qtd->urb->status != -EREMOTEIO)) {
					qh->tt_buffer_dirty = 1;
					if (usb_hub_clear_tt_buffer(qtd->urb))
						/* Clear failed; let's hope things work
						anyway */
						qh->tt_buffer_dirty = 0;
				}
			}
			qtd = NULL;
			qh->toggle = 0;
			qh->ping = 0;		
			break;

		default:
			WARN_ON(1);
			continue;
		}

		if (qtd && (qtd->status == QTD_PAYLOAD_ALLOC)) {
			if (slots == priv->int_slots) {
				if (state == PTD_STATE_QTD_RELOAD)
					vega_dbg(hcd->self.controller,
						"%s: PTD_STATE_QTD_RELOAD on "
						"interrupt packet\n", __func__);
				if (state != PTD_STATE_QTD_RELOAD)
					create_ptd_int(qh, qtd, &ptd);
			}else if (slots == priv->iso_slots) {
				if (state == PTD_STATE_QTD_RELOAD)
					vega_dbg(hcd->self.controller,
						"%s: PTD_STATE_QTD_RELOAD on "
						"iso packet\n", __func__);
				if (state != PTD_STATE_QTD_RELOAD)
					create_ptd_iso(qh, qtd, &ptd);
			} 
			else {
				if (state != PTD_STATE_QTD_RELOAD)
					create_ptd_atl(qh, qtd, &ptd);
			}
			//pr_err("handle_done_ptds -> start_bus_transfer >>>>>\n");
			start_bus_transfer(hcd, ptd_offset, slot, slots, qtd,
				qh, &ptd);
		}
	}


	if (modified) {

		//if(done_check)
			//pr_err("bulk len==13 schedule_ptds  \n");
		schedule_ptds(hcd);
		//pr_err("modified\n");
	}

	vega_dbg1(hcd->self.controller,"handle_done_ptds over>>>>\n");
}



static int handshake_hcd(struct usb_hcd *hcd, u32 reg,
		      u32 mask, u32 done, int usec)
{
	u32 result;

	do {
		result = vega_read32(hcd->regs, reg);
		
		if (result == ~0)
			return -ENODEV;
		result &= mask;
		if (result == done)
			return 0;
		udelay(1);
		usec--;
	} while (usec > 0);
	return -ETIMEDOUT;
}

static int handshake(struct vega_device *hcd, u32 reg,
		      u32 mask, u32 done, int usec)
{
	u32 result;

	do {
		result = vega_read32(hcd->regs, reg);
		
		if (result == ~0)
			return -ENODEV;
		result &= mask;
		if (result == done)
			return 0;
		udelay(1);
		usec--;
	} while (usec > 0);
	return -ETIMEDOUT;
}

/* one-time init, only for memory state */
static int priv_init(struct usb_hcd *hcd)
{
	struct vega_hcd		*priv = hcd_to_priv(hcd);
	u32			hcc_params;
	int i;

	spin_lock_init(&priv->lock);

	vega_init_dbg("priv_init\n");

	for (i = 0; i < QH_END; i++)
		INIT_LIST_HEAD(&priv->qh_list[i]);

	/*
	 * hw default: 1K periodic list heads, one per frame.
	 * periodic_size can shrink by USBCMD update if hcc_params allows.
	 */
	priv->periodic_size = DEFAULT_I_TDPS;

	/* controllers may cache some of the periodic schedule ... */
	hcc_params = vega_read32(hcd->regs, HC_HCCPARAMS);
	/* full frame cache */
	if (HCC_ISOC_CACHE(hcc_params))
		priv->i_thresh = 8;
	else /* N microframes cached */
		priv->i_thresh = 2 + HCC_ISOC_THRES(hcc_params);


	pr_err("priv_init priv->periodic_size %d, priv->i_thresh %d\n", priv->periodic_size, priv->i_thresh);
	

	return 0;
}

static struct vega_qh *qh_alloc(gfp_t flags)
{
	struct vega_qh *qh;

	qh = kmem_cache_zalloc(qh_cachep, flags);
	if (!qh)vega_init_core
		return NULL;

	INIT_LIST_HEAD(&qh->qh_list);
	INIT_LIST_HEAD(&qh->qtd_list);
	qh->slot = -1;

	return qh;
}

static void qh_free(struct vega_qh *qh)
{
	WARN_ON(!list_empty(&qh->qtd_list));
	WARN_ON(qh->slot > -1);
	kmem_cache_free(qh_cachep, qh);
}

/* reset a non-running (STS_HALT == 1) controller */
static int ehci_reset(struct usb_hcd *hcd)
{
	struct vega_hcd *priv = hcd_to_priv(hcd);
	int ret =0;

	u32 command = vega_read32(hcd->regs, HC_USBCMD);

	//command |= CMD_RESET;
	//vega_write32(hcd->regs, HC_USBCMD, command);
	hcd->state = HC_STATE_HALT;
	priv->next_statechange = jiffies;
	
	vega_write32(hcd->regs, HC_INTERRUPT_REG, 0xffffffff); //FIXME Clear interrupts	
	vega_write32(hcd->regs, HC_INTERRUPT_ENABLE, 0); //FIXME Clear interrupt enable

	
	vega_dbg(hcd->self.controller, "HC_INTERRUPT_ENABLE : %x\n", vega_read32(hcd->regs, HC_INTERRUPT_ENABLE));

	vega_init_dbg("ehci_reset over\n");


	return 0;//FIXME
	
	ret = handshake_hcd(hcd, HC_USBCMD, CMD_RESET, 0, 250 * 1000);
	vega_dbg(hcd->self.controller, "handshake : %d\n", ret);



	return ret;
}

static void vega_init_core(struct vega_device *vega)
{
	u32 otgctrl = 0;
	u32 hwmode;
	u32 mode_ctl;

	/* Low-level chip reset */
	/*if (vega->rst_gpio) {
		gpiod_set_value_cansleep(isp->rst_gpio, 1);
		msleep(50);
		gpiod_set_value_cansleep(isp->rst_gpio, 0);
	}*/

	/*
	 * Reset the host controller, including the CPU interface
	 * configuration.
	 */
	vega_dbg(vega->dev, "vega->regs : %lx \n",(long unsigned int)vega->regs);
	
	vega_write32(vega->regs, HC_PORT1_CTRL, 0);
	 
	vega_write32(vega->regs, HC_RESET_REG, SW_RESET_RESET_ALL); //FIXME
	udelay(1000);
	vega_write32(vega->regs, HC_RESET_REG, 0); //FIXME

	vega_dbg(vega->dev,"SW Reset !! ");

	vega_write32(vega->regs, DC_UNLOCKDEV, 0x00BC0064); //FIXME  75 mHz 
	//vega_write32(vega->regs, DC_UNLOCKDEV, 0x003f0021); //FIXME  25 mHz


	vega_dbg(vega->dev,"Time reg written !! ");
	
	//vega_write32(vega->regs, HC_SOF_COUNT, 0xcdb4); //SOF count for full speed hub
	//vega_write32(vega->regs, HC_FULL_SPEED_SOF_COUNT, 0xcdb4); 

	//vega_write32(vega->regs, HS_IPD_COUNT, 0x0096); //IPD Count for High Speed

	//vega_write32(vega->regs, HC_FULL_SPEED_TR_IPD, 0x5dc); 

	//vega_write32(vega->regs, HC_FULL_SPEED_HUB_IPD, 0x87); 
	
	//dev_err(vega->dev,"HC_SOF_COUNT reg written !! ");
		    
   	otgctrl =  (HW_OTG_SE0_EN); 
   	vega_write32(vega->regs, HC_PORT1_CTRL, otgctrl);
	otgctrl |=  (HW_OTG_DISABLE);
	vega_write32(vega->regs, HC_PORT1_CTRL, otgctrl);

	//dev_err(vega->dev,"HC_OTG_STATUS !! %0x",vega_read32(vega->regs,HC_OTG_STATUS) );

	otgctrl |=HW_VBUS_DRV;	 //Set for RPDP board, clear for VU440 board
	vega_write32(vega->regs, HC_PORT1_CTRL, otgctrl);

	//Wail for VBUS VALID
	handshake(vega,HC_OTG_STATUS, HW_VBUS_VLD, HW_VBUS_VLD , 250 * 1000 );

	vega_dbg(vega->dev, "HC_OTG_STATUS : %x", vega_read32(vega->regs,HC_OTG_STATUS) );

	otgctrl |=  (HW_DM_PULLDOWN | HW_DP_PULLDOWN);
	
	vega_write32(vega->regs, HC_PORT1_CTRL, otgctrl);

	/* Setup HW Mode Control: This assumes a level active-low interrupt */
	//hwmode = HW_DATA_BUS_32BIT;
	hwmode = HW_INTR_HIGH_ACT;


	/*
	 * We have to set this first in case we're in 16-bit mode.
	 * Write it twice to ensure correct upper bits if switching
	 * to 16-bit mode.
	 */
	vega_write32(vega->regs, HC_HW_MODE_CTRL, hwmode);
	//vega_write32(vega->regs, HC_HW_MODE_CTRL, hwmode);
	
	vega_dbg(vega->dev, "HC_HW_MODE_CTRL : %x", hwmode);
	
	mode_ctl = vega_read32(vega->regs, HC_HW_MODE_CTRL);
	
	vega_dbg(vega->dev, "mode_ctl : %x ",mode_ctl);

	vega_init_dbg("vega_init_core over\n");



	dev_info(vega->dev, "bus width: %u, oc: %s",
		 vega->devflags & VEGA_FLAG_BUS_WIDTH_16 ? 16 : 32,
		 vega->devflags & VEGA_FLAG_ANALOG_OC ? "analog" : "digital");
}

static irqreturn_t vega_irq(struct usb_hcd *hcd)
{
	struct vega_hcd *priv = hcd_to_priv(hcd);
	u32 imask;
	irqreturn_t irqret = IRQ_NONE;
	unsigned long		flags;


	//pr_err( "<***********************vega_irq***********************>\n");

	spin_lock_irqsave(&priv->lock, flags);

	vega_dbg1(hcd->self.controller, "HC_HW_MODE_CTRL : %x\n", vega_read32(hcd->regs, HC_HW_MODE_CTRL));
	
	imask = vega_read32(hcd->regs, HC_INTERRUPT_REG);
	vega_dbg1(hcd->self.controller,"HC_INTERRUPT_REG >>>>> %x \n",imask);
	
	if (!(hcd->state & HC_STATE_RUNNING))
		goto leave;

	imask = vega_read32(hcd->regs, HC_INTERRUPT_REG);
	
	
	//pr_err("isr INTR status: %0x\n",imask);
	
	vega_dbg1(hcd->self.controller,"HC_INTERRUPT_REG >>>>> %x \n",imask);
	if (unlikely(imask==0))
		goto leave;
	vega_write32(hcd->regs, HC_INTERRUPT_REG, imask); /* Clear */
	if(imask & (HC_INTL_INT | HC_ATL_INT | HC_ISO_INT))//Checking int/iso/atl interrupts
	{
		vega_dbg1(hcd->self.controller,"USB IRQ CLEAR>>>>>\n");
		vega_dbg1(hcd->self.controller,"priv->int_done_map %x >>>>>\n",priv->int_done_map);
		vega_dbg1(hcd->self.controller,"priv->atl_done_map %x >>>>>\n",priv->atl_done_map);
		vega_dbg1(hcd->self.controller,"priv->iso_done_map %x >>>>>\n",priv->iso_done_map);
		priv->int_done_map |= vega_read32(hcd->regs, HC_INT_PTD_DONEMAP_REG);
		priv->atl_done_map |= vega_read32(hcd->regs, HC_ATL_PTD_DONEMAP_REG);
		priv->iso_done_map |= vega_read32(hcd->regs, HC_ISO_PTD_DONEMAP_REG);
		vega_dbg1(hcd->self.controller,"priv->int_done_map %x >>>>>\n",priv->int_done_map);
		vega_dbg1(hcd->self.controller,"priv->atl_done_map %x >>>>>\n",priv->atl_done_map);
		vega_dbg1(hcd->self.controller,"priv->iso_done_map %x >>>>>\n",priv->iso_done_map);
		
		//del_timer(&errata2_timer);

		handle_done_ptds(hcd);
	}
	
	if(imask &  HC_DISCONNECT_INT)
	{
		device_disconnected = 1;
		//msleep(10); //Debounce time
		handshake_hcd(hcd, HC_PORTSC1, 2, 1 , 50*1000); //Debounce time
	} 

	if(imask &  HC_CONNECT_INT)
	{
		device_connected = 1;
		//msleep(10); //Debounce time
		handshake_hcd(hcd, HC_PORTSC1, 2, 1 , 50*1000); //Debounce time
	} 

	irqret = IRQ_HANDLED;
leave:

	spin_unlock_irqrestore(&priv->lock, flags);

	vega_probe_dbg(hcd->self.controller, "<***********************vega_irq over %x***********************>\n", irqret);
	
	

	if(imask &  (HC_DISCONNECT_INT | HC_CONNECT_INT))
	{
		//pr_err("DISCONNECT/CONNECT INTR : %0x\n",imask);

		port_change_flag = 1;
		usb_hcd_poll_rh_status(hcd);
	}


	//pr_err("isr INTR return: \n");

	return irqret;
	
}

static int vega_setup(struct usb_hcd *hcd)
{	
	struct vega_hcd *priv = hcd_to_priv(hcd);
	int result;
	u32 scratch;

	vega_probe_dbg(hcd->self.controller, "<***********************vega_setup***********************>\n");
	/* Change bus pattern */
	scratch = vega_read32(hcd->regs, HC_CHIP_ID_REG);
	
	vega_dbg(hcd->self.controller, "HC_CHIP_ID_REG %x\n",scratch);
	
		/*
	 * The RESET_HC bit in the SW_RESET register is supposed to reset the
	 * host controller without touching the CPU interface registers, but at
	 * least on the ISP1761 it seems to behave as the RESET_ALL bit and
	 * reset the whole device. We thus can't use it here, so let's reset
	 * the host controller through the EHCI USB Command register. The device
	 * has been reset in core code anyway, so this shouldn't matter.
	 */
	vega_write32(hcd->regs, HC_BUFFER_STATUS_REG, 0);
	atl_skipmap_global=NO_TRANSFER_ACTIVE;
	vega_write32(hcd->regs, HC_ATL_PTD_SKIPMAP_REG, NO_TRANSFER_ACTIVE);
	int_skipmap_global=NO_TRANSFER_ACTIVE;
	iso_skipmap_global=NO_TRANSFER_ACTIVE;
	vega_write32(hcd->regs, HC_INT_PTD_SKIPMAP_REG, NO_TRANSFER_ACTIVE);
	vega_write32(hcd->regs, HC_ISO_PTD_SKIPMAP_REG, NO_TRANSFER_ACTIVE);

	vega_dbg(hcd->self.controller, "b4 ehci_reset\n");

	result = ehci_reset(hcd);
	
	vega_dbg(hcd->self.controller, "after ehci_reset %d\n", result);
	
	if (result)
		return result;
		
	vega_dbg(hcd->self.controller, "reset success%d\n", result);

	vega_write32(hcd->regs, HC_INTERRUPT_ENABLE, INTERRUPT_ENABLE_MASK);
	
	//pr_err("INTERRUPT_ENABLE_MASK\n\r");

	vega_dbg(hcd->self.controller, "HC_HW_MODE_CTRL : %x\n", vega_read32(hcd->regs, HC_HW_MODE_CTRL));
	vega_dbg(hcd->self.controller, "HC_INTERRUPT_ENABLE : %x\n", vega_read32(hcd->regs, HC_INTERRUPT_ENABLE));
	
	priv->hcs_params = 0x0101; //vega_read32(hcd->regs, HC_HCSPARAMS); FIXME only one port

	vega_probe_dbg(hcd->self.controller, "<***********************vega_setup over***********************>\n");

						vega_init_dbg("vega_setup over\n");


	return priv_init(hcd);
}




static int vega_run(struct usb_hcd *hcd)
{
	int retval;
	u32 temp;
	u32 command;
	u32 chipid;
	vega_probe_dbg(hcd->self.controller, "<***********************vega_run***********************>\n");
	vega_dbg(hcd->self.controller, "HC_HW_MODE_CTRL : %x\n", vega_read32(hcd->regs, HC_HW_MODE_CTRL));
	
	hcd->uses_new_polling = 1;

	hcd->state = HC_STATE_RUNNING;

	//set_bit(HCD_FLAG_POLL_RH, &hcd->flags);

	/* Set PTD interrupt AND & OR maps */
	vega_write32(hcd->regs, HC_ATL_IRQ_MASK_AND_REG, 0);
	vega_write32(hcd->regs, HC_ATL_IRQ_MASK_OR_REG, 0xffffffff);
	vega_write32(hcd->regs, HC_INT_IRQ_MASK_AND_REG, 0);
	vega_write32(hcd->regs, HC_INT_IRQ_MASK_OR_REG, 0xffffffff);
	vega_write32(hcd->regs, HC_ISO_IRQ_MASK_AND_REG, 0);
	vega_write32(hcd->regs, HC_ISO_IRQ_MASK_OR_REG, 0xffffffff);
	/* step 23 passed */

	temp = vega_read32(hcd->regs, HC_HW_MODE_CTRL);
	vega_write32(hcd->regs, HC_HW_MODE_CTRL, temp | HW_GLOBAL_INTR_EN);
	
	vega_dbg(hcd->self.controller, "HC_HW_MODE_CTRL : %x\n", vega_read32(hcd->regs, HC_HW_MODE_CTRL));

	//command = vega_read32(hcd->regs, HC_USBCMD);
	//command &= ~(CMD_LRESET|CMD_RESET);
	//command |= CMD_RUN;
	//vega_write32(hcd->regs, HC_USBCMD, command);
	//while(1);
	//retval = handshake_hcd(hcd, HC_USBCMD, CMD_RUN, CMD_RUN, 250 * 1000);
	vega_dbg(hcd->self.controller, "handshake : %x\n",retval);
	//if (retval)
	//	return retval;

	/*
	 * XXX
	 * Spec says to write FLAG_CF as last config action, priv code grabs
	 * the semaphore while doing so.
	 */
	//down_write(&ehci_cf_port_reset_rwsem);
	/*vega_write32(hcd->regs, HC_CONFIGFLAG, FLAG_CF);

	retval = handshake(hcd, HC_CONFIGFLAG, FLAG_CF, FLAG_CF, 250 * 1000);*/
	//up_write(&ehci_cf_port_reset_rwsem);
	/*vega_dbg(hcd->self.controller, "handshake : %x\n",retval);
	if (retval)
		return retval;*/

	/*errata2_timer_hcd = hcd;
	timer_setup(&errata2_timer, errata2_function, 0);
	errata2_timer.expires = jiffies + msecs_to_jiffies(SLOT_CHECK_PERIOD);
	add_timer(&errata2_timer);*/

	chipid = vega_read32(hcd->regs, HC_CHIP_ID_REG);
	dev_info(hcd->self.controller, "USB ISP %04x HW rev. %d started\n",
					chipid & 0xffff, chipid >> 16);

	/* PTD Register Init Part 2, Step 28 */

	/* Setup registers controlling PTD checking */
	vega_write32(hcd->regs, HC_ATL_PTD_LASTPTD_REG, 0x80000000);
	vega_write32(hcd->regs, HC_INT_PTD_LASTPTD_REG, 0x80000000);
	vega_write32(hcd->regs, HC_ISO_PTD_LASTPTD_REG, 0x80000000);
	atl_skipmap_global=0xffffffff;
	vega_write32(hcd->regs, HC_ATL_PTD_SKIPMAP_REG, 0xffffffff);
	int_skipmap_global=0xffffffff;
	iso_skipmap_global=0xffffffff;
	vega_write32(hcd->regs, HC_INT_PTD_SKIPMAP_REG, 0xffffffff);
	vega_write32(hcd->regs, HC_ISO_PTD_SKIPMAP_REG, 0xffffffff);
	vega_write32(hcd->regs, HC_BUFFER_STATUS_REG,
						ATL_BUF_FILL | INT_BUF_FILL | ISO_BUF_FILL);

	/* GRR this is run-once init(), being done every time the HC starts.
	 * So long as they're part of class devices, we can't do it init()
	 * since the class device isn't created that early.
	 */

					vega_init_dbg("vega_run over\n");

	vega_probe_dbg(hcd->self.controller, "<***********************vega_run over***********************>\n");

	return 0;	
}

static int qtd_fill(struct vega_qtd *qtd, void *databuffer, size_t len)
{
	qtd->data_buffer = databuffer;

	if (len > MAX_PAYLOAD_SIZE)
		len = MAX_PAYLOAD_SIZE;
	qtd->length = len;

	return qtd->length;
}

static void qtd_list_free(struct list_head *qtd_list)
{
	struct vega_qtd *qtd, *qtd_next;

	list_for_each_entry_safe(qtd, qtd_next, qtd_list, qtd_list) {
		list_del(&qtd->qtd_list);
		qtd_free(qtd);
	}
}

/*
 * Packetize urb->transfer_buffer into list of packets of size wMaxPacketSize.
 * Also calculate the PID type (SETUP/IN/OUT) for each packet.
 */
#define max_packet(wMaxPacketSize) ((wMaxPacketSize) & 0x07ff)
static void packetize_urb(struct usb_hcd *hcd,
		struct urb *urb, struct list_head *head, gfp_t flags)
{
	struct vega_qtd *qtd;
	void *buf;
	int len, maxpacketsize;
	u8 packet_type;

	/*
	 * URBs map to sequences of QTDs:  one logical transaction
	 */

	if (!urb->transfer_buffer && urb->transfer_buffer_length) {
		/* XXX This looks like usb storage / SCSI bug */
		vega_dbg1(hcd->self.controller,
				"buf is null, dma is %08lx len is %d\n",
				(long unsigned)urb->transfer_dma,
				urb->transfer_buffer_length);
		WARN_ON(1);
	}

	if (usb_pipein(urb->pipe))
		packet_type = IN_PID;
	else
		packet_type = OUT_PID;

	if (usb_pipecontrol(urb->pipe)) {
		qtd = qtd_alloc(flags, urb, SETUP_PID);
		if (!qtd)
			goto cleanup;
		qtd_fill(qtd, urb->setup_packet, sizeof(struct usb_ctrlrequest));
		list_add_tail(&qtd->qtd_list, head);

		/* for zero length DATA stages, STATUS is always IN */
		if (urb->transfer_buffer_length == 0)
			packet_type = IN_PID;
	}

	maxpacketsize = max_packet(usb_maxpacket(urb->dev, urb->pipe,
						usb_pipeout(urb->pipe)));

	/*
	 * buffer gets wrapped in one or more qtds;
	 * last one may be "short" (including zero len)
	 * and may serve as a control status ack
	 */
	buf = urb->transfer_buffer;
	len = urb->transfer_buffer_length;

	for (;;) {
		int this_qtd_len;

		qtd = qtd_alloc(flags, urb, packet_type);
		if (!qtd)
			goto cleanup;
		this_qtd_len = qtd_fill(qtd, buf, len);
		list_add_tail(&qtd->qtd_list, head);

		len -= this_qtd_len;
		buf += this_qtd_len;

		if (len <= 0)
			break;
	}

	/*
	 * control requests may need a terminating data "status" ack;
	 * bulk ones may need a terminating short packet (zero length).
	 */
	if (urb->transfer_buffer_length != 0) {
		int one_more = 0;

		if (usb_pipecontrol(urb->pipe)) {
			one_more = 1;
			if (packet_type == IN_PID)
				packet_type = OUT_PID;
			else
				packet_type = IN_PID;
		} else if (usb_pipebulk(urb->pipe)
				&& (urb->transfer_flags & URB_ZERO_PACKET)
				&& !(urb->transfer_buffer_length %
							maxpacketsize)) {
			one_more = 1;
		}
		if (one_more) {
			qtd = qtd_alloc(flags, urb, packet_type);
			if (!qtd)
				goto cleanup;

			/* never any data in such packets */
			qtd_fill(qtd, NULL, 0);
			list_add_tail(&qtd->qtd_list, head);
		}
	}

	return;

cleanup:
	qtd_list_free(head);
}

static void vega_stop(struct usb_hcd *hcd)
{
	dev_err(hcd->self.controller, "<***********************vega_stop***********************>\n");
	
	
}

static void vega_shutdown(struct usb_hcd *hcd)
{
	dev_err(hcd->self.controller, "<***********************vega_shutdown***********************>\n");
	
	
}



static int vega_urb_enqueue(struct usb_hcd *hcd, struct urb *urb,
		gfp_t mem_flags)
{
	struct vega_hcd *priv = hcd_to_priv(hcd);
	struct list_head *ep_queue;
	struct vega_qh *qh, *qhit;
	unsigned long spinflags;
	LIST_HEAD(new_qtds);
	int retval;
	int qh_in_queue;
	
	//pr_err("vega_urb_enqueue\n");
	
	vega_probe_dbg(hcd->self.controller, "<***********************vega_urb_enqueue***********************>\n");

	vega_dbg2(hcd->self.controller,"urb->pipe : %x\n",urb->pipe);

	switch (usb_pipetype(urb->pipe)) {
	case PIPE_CONTROL:
		ep_queue = &priv->qh_list[QH_CONTROL];
		vega_dbg2(hcd->self.controller,"PIPE_CONTROL\n");
		break;
	case PIPE_BULK:
		ep_queue = &priv->qh_list[QH_BULK];
		vega_dbg2(hcd->self.controller,"PIPE_BULK\n");
		break;
	case PIPE_INTERRUPT:
		if (urb->interval < 0)
			return -EINVAL;
		/* FIXME: Check bandwidth  */
		ep_queue = &priv->qh_list[QH_INTERRUPT];
		vega_dbg1(hcd->self.controller,"PIPE_INTERRUPT\n");
		break;
	case PIPE_ISOCHRONOUS:		
		vega_dbg1(hcd->self.controller,"PIPE_ISOCHRONOUS\n");		
		if (urb->interval < 0)
			return -EINVAL;
		/* FIXME: Check bandwidth  */
		ep_queue = &priv->qh_list[QH_ISOCHRONOUS];			
		break;
	default:
		vega_dbg1(hcd->self.controller, "%s: unknown pipe type\n",
							__func__);
		vega_dbg1(hcd->self.controller,"unknown pipe type\n");						
		return -EPIPE;
	}

	if (usb_pipein(urb->pipe))
		urb->actual_length = 0;

	packetize_urb(hcd, urb, &new_qtds, mem_flags);
	if (list_empty(&new_qtds))
		return -ENOMEM;

	retval = 0;
	spin_lock_irqsave(&priv->lock, spinflags);

	if (!test_bit(HCD_FLAG_HW_ACCESSIBLE, &hcd->flags)) {
		retval = -ESHUTDOWN;
		qtd_list_free(&new_qtds);
		goto out;
	}
	retval = usb_hcd_link_urb_to_ep(hcd, urb);
	if (retval) {
		qtd_list_free(&new_qtds);
		goto out;
	}

	qh = urb->ep->hcpriv;
	if (qh) {
		qh_in_queue = 0;
		list_for_each_entry(qhit, ep_queue, qh_list) {
			if (qhit == qh) {
				qh_in_queue = 1;
				break;
			}
		}
		if (!qh_in_queue)
			list_add_tail(&qh->qh_list, ep_queue);
	} else {
		qh = qh_alloc(GFP_ATOMIC);
		if (!qh) {
			retval = -ENOMEM;
			usb_hcd_unlink_urb_from_ep(hcd, urb);
			qtd_list_free(&new_qtds);
			goto out;
		}
		list_add_tail(&qh->qh_list, ep_queue);
		urb->ep->hcpriv = qh;
	}

	list_splice_tail(&new_qtds, &qh->qtd_list);
	schedule_ptds(hcd);

	int imask = vega_read32(hcd->regs, HC_INTERRUPT_ENABLE);
	//pr_err("HC_INTERRUPT_ENABLE >>>>> %x \n",imask);


	//vega_dbg1(hcd->self.controller,"priv->int_done_map %x >>>>>\n",	vega_read32(hcd->regs, HC_ATL_PTD_DONEMAP_REG));

	vega_dbg1(hcd->self.controller,"vega_urb_enqueue OVER %x\n",retval);
	/*	errata2_timer_hcd = hcd;
		timer_setup(&errata2_timer, errata2_function, 0);
		errata2_timer.expires = jiffies + msecs_to_jiffies(SLOT_CHECK_PERIOD);
		add_timer(&errata2_timer);*/

out:
	spin_unlock_irqrestore(&priv->lock, spinflags);
	return retval;

}


static void kill_transfer(struct usb_hcd *hcd, struct urb *urb,
		struct vega_qh *qh)
{
	struct vega_hcd *priv = hcd_to_priv(hcd);
	int skip_map;

		vega_init_dbg("kill_transfer \n");


	WARN_ON(qh->slot == -1);

	/* We need to forcefully reclaim the slot since some transfers never
	   return, e.g. interrupt transfers and NAKed bulk transfers. */
	if (usb_pipecontrol(urb->pipe) || usb_pipebulk(urb->pipe)) {
		skip_map = atl_skipmap_global; //vega_read32(hcd->regs, HC_ATL_PTD_SKIPMAP_REG);
		skip_map |= (1 << qh->slot);
		atl_skipmap_global=skip_map;
		vega_write32(hcd->regs, HC_ATL_PTD_SKIPMAP_REG, skip_map);
		priv->atl_slots[qh->slot].qh = NULL;
		priv->atl_slots[qh->slot].qtd = NULL;
	} 
	else if (usb_pipeisoc(urb->pipe))
	{
		skip_map = iso_skipmap_global; //vega_read32(hcd->regs, HC_INT_PTD_SKIPMAP_REG);
		skip_map |= (1 << qh->slot);
		iso_skipmap_global=skip_map;
		vega_write32(hcd->regs, HC_ISO_PTD_SKIPMAP_REG, skip_map);
		priv->iso_slots[qh->slot].qh = NULL;
		priv->iso_slots[qh->slot].qtd = NULL;
	}
	else {
		skip_map = int_skipmap_global; //vega_read32(hcd->regs, HC_INT_PTD_SKIPMAP_REG);
		skip_map |= (1 << qh->slot);
		int_skipmap_global=skip_map;
		vega_write32(hcd->regs, HC_INT_PTD_SKIPMAP_REG, skip_map);
		priv->int_slots[qh->slot].qh = NULL;
		priv->int_slots[qh->slot].qtd = NULL;
	}

	qh->slot = -1;
}

/*
 * Retire the qtds beginning at 'qtd' and belonging all to the same urb, killing
 * any active transfer belonging to the urb in the process.
 */
static void dequeue_urb_from_qtd(struct usb_hcd *hcd, struct vega_qh *qh,
						struct vega_qtd *qtd)
{
	struct urb *urb;
	int urb_was_running;

	urb = qtd->urb;
	urb_was_running = 0;
	list_for_each_entry_from(qtd, &qh->qtd_list, qtd_list) {
		if (qtd->urb != urb)
			break;

		if (qtd->status >= QTD_XFER_STARTED)
			urb_was_running = 1;
		if (last_qtd_of_urb(qtd, qh) &&
					(qtd->status >= QTD_XFER_COMPLETE))
			urb_was_running = 0;

		if (qtd->status == QTD_XFER_STARTED)
			kill_transfer(hcd, urb, qh);
		qtd->status = QTD_RETIRE;
	}

	if(vega_hub_speed == HUB_SPEED_HIGH) {
		if ((urb->dev->speed != USB_SPEED_HIGH) && urb_was_running) {
			qh->tt_buffer_dirty = 1;
			
				if (usb_hub_clear_tt_buffer(urb))
					/* Clear failed; let's hope things work anyway */
					qh->tt_buffer_dirty = 0;
		}
		
	}

	// if ((urb->dev->speed != USB_SPEED_HIGH) && urb_was_running) {
	// 	qh->tt_buffer_dirty = 1;
	// 	//pr_err("#####################clear tt\n");
	// 	if(vega_hub_speed == HUB_SPEED_HIGH) {
	// 		if (usb_hub_clear_tt_buffer(urb))
	// 			/* Clear failed; let's hope things work anyway */
	// 			qh->tt_buffer_dirty = 0;
	// 	}
	// }
}

static int vega_urb_dequeue(struct usb_hcd *hcd, struct urb *urb,
		int status)
{
	struct vega_hcd *priv = hcd_to_priv(hcd);
	unsigned long spinflags;
	struct vega_qh *qh;
	struct vega_qtd *qtd;
	int retval = 0;

	vega_probe_dbg(hcd->self.controller, "<***********************vega_urb_dequeue***********************>\n");
	//pr_err("vega_urb_dequeue schedule_ptds\n");
	
	spin_lock_irqsave(&priv->lock, spinflags);
	retval = usb_hcd_check_unlink_urb(hcd, urb, status);
	if (retval)
		goto out;

	qh = urb->ep->hcpriv;
	if (!qh) {
		retval = -EINVAL;
		goto out;
	}

	list_for_each_entry(qtd, &qh->qtd_list, qtd_list)
		if (qtd->urb == urb) {
			dequeue_urb_from_qtd(hcd, qh, qtd);
			list_move(&qtd->qtd_list, &qh->qtd_list);
			break;
		}

	urb->status = status;

	
	schedule_ptds(hcd);
	
	//pr_err("vega_urb_dequeue\n");
	vega_dbg1(hcd->self.controller, "<***********************vega_urb_dequeue OVER %x***********************>\n",retval);


out:
	spin_unlock_irqrestore(&priv->lock, spinflags);
	return retval;
}

static void vega_endpoint_disable(struct usb_hcd *hcd,
		struct usb_host_endpoint *ep)
{
	
	struct vega_hcd *priv = hcd_to_priv(hcd);
	unsigned long spinflags;
	struct vega_qh *qh, *qh_iter;
	int i;
	vega_probe_dbg(hcd->self.controller, "<***********************vega_endpoint_disable***********************>\n");
	spin_lock_irqsave(&priv->lock, spinflags);

	qh = ep->hcpriv;
	if (!qh)
		goto out;
		
	schedule_ptds(hcd);	

	WARN_ON(!list_empty(&qh->qtd_list));

	for (i = 0; i < QH_END; i++)
		list_for_each_entry(qh_iter, &priv->qh_list[i], qh_list)
			if (qh_iter == qh) {
				list_del(&qh_iter->qh_list);
				i = QH_END;
				break;
			}
	qh_free(qh);
	ep->hcpriv = NULL;
	

	//pr_err("vega_endpoint_disable schedule_ptds\n");


out:

	//pr_err("vega_endpoint_disable\n");
	
	
	spin_unlock_irqrestore(&priv->lock, spinflags);
	vega_dbg1(hcd->self.controller, "<***********************vega_endpoint_disable over***********************>\n");

}

static int vega_get_frame(struct usb_hcd *hcd)
{
	struct vega_hcd *priv = hcd_to_priv(hcd);
	u32 fr;

	dev_err(hcd->self.controller, "<***********************vega_get_frame***********************>\n");

	fr = vega_read32(hcd->regs, HC_FRINDEX);
	return (fr >> 3) % priv->periodic_size;
}

static void vega_endpoint_reset(struct usb_hcd *hcd, struct usb_host_endpoint *ep){

	dev_err(hcd->self.controller, "<***********************vega_endpoint_reset***********************>\n");
}



static int vega_hub_status_data(struct usb_hcd *hcd, char *buf)
{
	struct vega_hcd *priv = hcd_to_priv(hcd);
	u32 temp, status = 0;
	u32 mask;
	int retval = 1;
	unsigned long flags;
	
	//pr_err("vega_hub_status_data\n");
	/* if !PM, root hub timers won't get shut down ... */
	/*if (!HC_IS_RUNNING(hcd->state))
		return 0;*/
	//mask = PORT_CSC;


	/*temp = vega_read32(hcd->regs, HC_PORTSC1);

	if (temp & PORT_OWNER) {
		if (temp & PORT_CSC) {
			temp &= ~PORT_CSC;
			vega_write32(hcd->regs, HC_PORTSC1, temp);
			vega_dbg4(hcd->self.controller, "<***********************HC_PORTSC1 write %x***********************>\n",temp);

			goto done;
		}
	}*/

	/*
	 * Return status information even for ports with OWNER set.
	 * Otherwise hub_wq wouldn't see the disconnect event when a
	 * high-speed device is switched over to the companion
	 * controller by the user.
	 */

	/*if ((temp & mask) != 0
			|| ((temp & PORT_RESUME) != 0
				&& time_after_eq(jiffies,
					priv->reset_done))) {*/

	spin_lock_irqsave(&priv->lock, flags);
	/* init status to no-changes */
	buf[0] = 0;
	if(port_change_flag)	
		buf [0] |= (1 << 1);
		//status = STS_PCD;

	spin_unlock_irqrestore(&priv->lock, flags);
	//pr_err("<***********************vega_hub_status_data over status %x, retval %x***********************>\n",status,retval);
	if(port_change_flag){
		port_change_flag = 0;
		return 1;
	} else
		return 0;
}

static void vega_hub_descriptor(struct vega_hcd *priv,
		struct usb_hub_descriptor *desc)
{
	int ports = 1;// HCS_N_PORTS(priv->hcs_params);
	u16 temp;

	desc->bDescLength = 7 + 2 * (1 + (ports / 8));
	desc->bDescriptorType = USB_DT_HUB;
	desc->bNbrPorts = ports;

	/* priv 1.0, 2.3.9 says 20ms max */
	desc->bPwrOn2PwrGood = 10;
	desc->bHubContrCurrent = 0;

	/* no power switching */
	temp = HUB_CHAR_NO_LPSM;
	/* No Over-current Protection support */
	temp = HUB_CHAR_NO_OCPM;
	if(vega_hub_speed == HUB_SPEED_HIGH)
		temp |= USB_HUB_PR_HS_MULTI_TT; //FIXME 
	desc->wHubCharacteristics = cpu_to_le16(temp);
	printk("desc->wHubCharacteristics=%x\n", desc->wHubCharacteristics);

	/* ports removable, and usb 1.0 legacy PortPwrCtrlMask */
	memset(&desc->u.hs.DeviceRemovable[0], 0, (1 + (ports / 8)));

}

#define	PORT_WAKE_BITS	(PORT_WKOC_E|PORT_WKDISC_E|PORT_WKCONN_E)

static int check_reset_complete(struct usb_hcd *hcd, int index,
		int port_status)
{
	//if (!(port_status & PORT_CONNECT))
	///	return port_status;

	int ret = handshake_hcd(hcd, HC_PORTSC1 , PORT_PE, PORT_PE , 100*1000);
	if(ret != 0) {
		pr_err("error!!!!!port not enabled\n");
		/* if reset finished and it's still not enabled -- handoff */
		return 0;
	}

	port_status = vega_read32(hcd->regs, HC_PORTSC1);

	vega_write32(hcd->regs, HC_USBCMD, CMD_RUN); //Start to send SOF

	vega_dbg4(hcd->self.controller, "check_reset_complete, HC_USBCMD %x +++++ \n",CMD_RUN);


	if (!(port_status & PORT_HIGH_SPEED)) {
	
		dev_info(hcd->self.controller,
					"port %d full speed --> companion\n",
					index + 1);
		vega_hub_speed = HUB_SPEED_FULL;
		//port_status |= PORT_OWNER;
		//port_status &= ~PORT_RWC_BITS;
		//vega_write32(hcd->regs, HC_PORTSC1, port_status);
		vega_dbg4(hcd->self.controller, "check_reset_complete, HC_PORTSC1 Wr %x +++++ \n",port_status);
	} else {
		dev_info(hcd->self.controller, "port %d high speed\n",
								index + 1);
		vega_hub_speed = HUB_SPEED_HIGH;
	}

	vega_init_dbg("check_reset_complete over\n");


	return port_status;
}

int port_power_flag = 1;

static int vega_hub_control(struct usb_hcd *hcd, u16 typeReq,
		u16 wValue, u16 wIndex, char *buf, u16 wLength)
{
	
	struct vega_hcd *priv = hcd_to_priv(hcd);
	int ports = HCS_N_PORTS(priv->hcs_params);
	u32 temp;
	unsigned long flags;
	int retval = 0;
	int i=0;
	unsigned selector;
	u32 port_status;	
	static u32 port_change = 0;	


	////vega_hub_cotrol_dbg1(hcd->self.controller, "<***********************vega_hub_control wValue =%x, wIndex =%x, wLength =%x, typeReqn =%x\n", wValue, wIndex, wLength, typeReq);  /////cdac

	/*
	 * FIXME:  support SetPortFeatures USB_PORT_FEAT_INDICATOR.
	 * HCS_INDICATOR may say we can change LEDs to off/amber/green.
	 * (track current state ourselves) ... blink for diagnostics,
	 * power, "this is the one", etc.  EHCI spec supports this.
	 */

	spin_lock_irqsave(&priv->lock, flags);
	switch (typeReq) {
	case ClearHubFeature:
		dev_err(hcd->self.controller, "ClearHubFeature +++++ \n");
		switch (wValue) {
		case C_HUB_LOCAL_POWER:
		case C_HUB_OVER_CURRENT:
			/* no hub-wide feature/status flags */
			break;
		default:
			goto error;
		}
		break;
	case ClearPortFeature:
		vega_hub_cotrol_dbg(hcd->self.controller, "ClearPortFeature +++++ \n");
		if (!wIndex || wIndex > ports)
			goto error;
		wIndex--;
		temp = vega_read32(hcd->regs, HC_PORTSC1);
		vega_hub_cotrol_dbg(hcd->self.controller, "hub control HC_PORTSC1 read :%x, \n",temp);
		/*
		 * Even if OWNER is set, so the port is owned by the
		 * companion controller, hub_wq needs to be able to clear
		 * the port-change status bits (especially
		 * USB_PORT_STAT_C_CONNECTION).
		 */
		vega_hub_cotrol_dbg(hcd->self.controller, "ClearPortFeature +++++, %d \n",wValue);
		switch (wValue) {
		case USB_PORT_FEAT_ENABLE:
			temp = vega_read32(hcd->regs, HC_PORTSC1);
			vega_hub_cotrol_dbg1(hcd->self.controller, "HC_PORTSC1 write :%x, \n",(temp & ~PORT_PE));
			vega_write32(hcd->regs, HC_PORTSC1, (temp & ~PORT_PE));
			break;
		case USB_PORT_FEAT_C_ENABLE:
			vega_hub_cotrol_dbg1(hcd->self.controller,"+++++++CL+++++++++USB_PORT_FEAT_C_ENABLE++++++++++++++++++++");
			port_change &= (~USB_PORT_STAT_C_ENABLE);
			/* XXX error? */
			break;
		case USB_PORT_FEAT_SUSPEND:
			dev_err(hcd->self.controller,"++++++++++CL++++++USB_PORT_FEAT_SUSPEND++++++++++++++++++++");
			if (temp & PORT_RESET)
				goto error;

			if (temp & PORT_SUSPEND) {
				if ((temp & PORT_PE) == 0)
					goto error;
				/* resume signaling for 20 msec */
				vega_write32(hcd->regs, HC_PORTSC1,
							temp | PORT_RESUME);
				vega_hub_cotrol_dbg(hcd->self.controller, "HC_PORTSC1 write :%x, \n",(temp | PORT_RESUME));
			
				priv->reset_done = jiffies +
					msecs_to_jiffies(USB_RESUME_TIMEOUT);
			}
			break;
		case USB_PORT_FEAT_C_SUSPEND:
			dev_err(hcd->self.controller,"++++++++++CL++++++USB_PORT_FEAT_C_SUSPEND++++++++++++++++++++");
			port_change &= (~USB_PORT_STAT_C_SUSPEND);
			break;
		case USB_PORT_FEAT_POWER:
			vega_hub_cotrol_dbg1(hcd->self.controller,"++++++CL++++++++++USB_PORT_FEAT_POWER++++++++++++++++++++");
			port_power_flag = 0;
			// &= ~(USB_PORT_STAT_C_ENABLE | USB_PORT_STAT_C_SUSPEND | USB_PORT_STAT_C_CONNECTION | USB_PORT_STAT_C_RESET);
			//if (HCS_PPC(priv->hcs_params))
			//	vega_write32(hcd->regs, HC_PORTSC1,	temp & ~PORT_POWER);
			break;
		case USB_PORT_FEAT_C_CONNECTION:
			vega_hub_cotrol_dbg1(hcd->self.controller,"+++++CL+++++++++++USB_PORT_FEAT_C_CONNECTION++++++++++++++++++++");
			port_change &= (~USB_PORT_STAT_C_CONNECTION);
			break;
		case USB_PORT_FEAT_C_OVER_CURRENT:
			dev_err(hcd->self.controller,"++++++CL++++++++++USB_PORT_FEAT_C_OVER_CURRENT++++++++++++++++++++");
			/* XXX error ?*/
			break;
		case USB_PORT_FEAT_C_RESET:
			vega_hub_cotrol_dbg1(hcd->self.controller,"++++++CL++++++++++USB_PORT_FEAT_C_RESET++++++++++++++++++++");
			port_change &= (~USB_PORT_STAT_C_RESET);
			/* GetPortStatus clears reset */
			break;
		default:
			goto error;
		}
		//vega_read32(hcd->regs, HC_USBCMD);
		break;
	case GetHubDescriptor:
		vega_hub_cotrol_dbg(hcd->self.controller, "GetHubDescriptor +++++ \n");
		vega_hub_descriptor(priv, (struct usb_hub_descriptor *) buf);
		break;
	case GetHubStatus:
		vega_hub_cotrol_dbg(hcd->self.controller, "GetHubStatus +++++ \n");
		/* no hub-wide feature/status flags */
		memset(buf, 0, 4);
		break;
	case GetPortStatus:			
		if (!wIndex || wIndex > ports)
			goto error;
		wIndex--;
		port_status = 0;
		////vega_hub_cotrol_dbg(hcd->self.controller, "GetPortStatus %x +++++ \n",temp); ////cdac
		/* wPortChange bits */
		if (device_disconnected){
			port_change |= USB_PORT_STAT_C_CONNECTION; //set connection change bit
			device_disconnected = 0;	
			vega_write32(hcd->regs, HC_USBCMD, 0);//Set Run/Stop bit zero
			temp = vega_read32(hcd->regs, HC_PORTSC1);
			temp &= ~PORT_PE;
			vega_write32(hcd->regs, HC_PORTSC1, temp);
		}
		else if (device_connected){
			port_change |= USB_PORT_STAT_C_CONNECTION; //set connection change bit
			device_connected = 0;
		} else {
			temp = handshake_hcd(hcd, HC_PORTSC1, PORT_CONNECT, PORT_CONNECT , 50*1000); //polling
		}

		temp = vega_read32(hcd->regs, HC_PORTSC1);
		/* whoever resumes must GetPortStatus to complete it!! */
		if (temp & PORT_RESUME) {
			dev_err(hcd->self.controller, "Port resume should be skipped.\n");

			/* Remote Wakeup received? */
			if (!priv->reset_done) {
				/* resume signaling for 20 msec */
				priv->reset_done = jiffies
						+ msecs_to_jiffies(20);
				/* check the port again */
				mod_timer(&hcd->rh_timer, priv->reset_done);
			}

			/* resume completed? */
			else if (time_after_eq(jiffies,
					priv->reset_done)) {
				port_change |= USB_PORT_STAT_C_SUSPEND;
				priv->reset_done = 0;

				/* stop resume signaling */
				temp = vega_read32(hcd->regs, HC_PORTSC1);
				vega_write32(hcd->regs, HC_PORTSC1,
					temp & ~(PORT_RESUME));

				retval = handshake_hcd(hcd, HC_PORTSC1,
					   PORT_RESUME, 0, 2000 /* 2msec */);
				vega_hub_cotrol_dbg(hcd->self.controller, "HC_PORTSC1 read :%x, \n",(vega_read32(hcd->regs, HC_PORTSC1)));

				if (retval != 0) {
					vega_hub_cotrol_dbg(hcd->self.controller,
						"port %d resume error %d\n",
						wIndex + 1, retval);
					goto error;
				}
				temp &= ~(PORT_SUSPEND|PORT_RESUME|(3<<10));
			}
		}

		/* whoever resets must GetPortStatus to complete it!! */
		if ((temp & PORT_RESET)
				&& time_after_eq(jiffies,
					priv->reset_done)) {
			vega_hub_cotrol_dbg(hcd->self.controller, "PORT_RESET\n");		
			priv->reset_done = 0;

			/* force reset to complete */
			temp = vega_read32(hcd->regs, HC_PORTSC1);
			vega_write32(hcd->regs, HC_PORTSC1, temp & ~PORT_RESET);
			port_change |= USB_PORT_STAT_C_RESET;
			vega_dbg4(hcd->self.controller, "HC_PORTSC1 wr :%x, \n",(temp & ~PORT_RESET));

			/*retval=0;		
			if (retval != 0) {
				vega_hub_cotrol_dbg(hcd->self.controller, "port %d reset error %d\n",
						wIndex + 1, retval);
				goto error;
			}*/

			/* see what we found out */
			temp = check_reset_complete(hcd, wIndex, vega_read32(hcd->regs, HC_PORTSC1));
			
		}
		/*
		 * Even if OWNER is set, there's no harm letting hub_wq
		 * see the wPortStatus values (they should all be 0 except
		 * for PORT_POWER anyway).
		 */

		/*if (temp & PORT_OWNER)
			vega_hub_cotrol_dbg(hcd->self.controller, "PORT_OWNER is set\n");*/

		temp = vega_read32(hcd->regs, HC_PORTSC1);
		if (temp & PORT_CONNECT) {
			/////vega_hub_cotrol_dbg(hcd->self.controller, "++++++++++++++++++++PORT_CONNECT \n"); /////cdac
			port_status |= USB_PORT_STAT_CONNECTION;
			/* status may be from integrated TT */
		}
		if (temp & PORT_PE)
			port_status |= USB_PORT_STAT_ENABLE;
		if (temp & (PORT_SUSPEND|PORT_RESUME))
			port_status |= USB_PORT_STAT_SUSPEND;
		if (temp & PORT_RESET)
			port_status |= USB_PORT_STAT_RESET;
		if (port_power_flag)
			port_status |= USB_PORT_STAT_POWER;
		if(temp & PORT_HIGH_SPEED)
			port_status |= USB_PORT_STAT_HIGH_SPEED;
		if(temp & PORT_LOW_SPEED)
			port_status |= USB_PORT_STAT_LOW_SPEED;

		////vega_hub_cotrol_dbg(hcd->self.controller, "**********************port status+change %x  \n", (port_status | (port_change << 16))); ////cdac

		put_unaligned(cpu_to_le32((port_status | (port_change << 16))), (__le32 *) buf);
		break;
	case SetHubFeature:
		dev_err(hcd->self.controller,"++++++++++++++++SetHubFeature++++++++++++++++++++");
		switch (wValue) {
		case C_HUB_LOCAL_POWER:
		case C_HUB_OVER_CURRENT:
			/* no hub-wide feature/status flags */
			break;
		default:
			goto error;
		}
		break;
	case SetPortFeature:
		//dev_err(hcd->self.controller, "SetPortFeature +++++ \n");
		selector = wIndex >> 8;
		wIndex &= 0xff;
		if (!wIndex || wIndex > ports)
			goto error;
		wIndex--;
		temp = vega_read32(hcd->regs, HC_PORTSC1);
		/*if (temp & PORT_OWNER)
			break;*/

/*		temp &= ~PORT_RWC_BITS; */
		/////vega_hub_cotrol_dbg(hcd->self.controller, "SetPortFeature +++++ switch : %d \n",wValue);  ////cdac
		switch (wValue) {
		
		case USB_PORT_FEAT_ENABLE:
			dev_err(hcd->self.controller,"++++++++++set++++++++++++++++USB_PORT_FEAT_ENABLE \n");
			break;

		case USB_PORT_FEAT_SUSPEND:
			dev_err(hcd->self.controller,"+++++++++++set+++++++++++++++USB_PORT_FEAT_SUSPEND \n");
			if ((temp & PORT_PE) == 0
					|| (temp & PORT_RESET) != 0)
				goto error;
			vega_write32(hcd->regs, HC_PORTSC1, temp | PORT_SUSPEND);
			break;
		case USB_PORT_FEAT_POWER:
			vega_hub_cotrol_dbg1(hcd->self.controller,"+++++++++++set+++++++++++++++USB_PORT_FEAT_POWER \n");
			port_power_flag = 1;
			//if (HCS_PPC(priv->hcs_params))
				//vega_write32(hcd->regs, HC_PORTSC1,	temp | PORT_POWER);
			break;
		case USB_PORT_FEAT_RESET:
		
		vega_hub_cotrol_dbg(hcd->self.controller,"+++++++++++set+++++++++++++++USB_PORT_FEAT_RESET \n");
				if (temp & PORT_RESUME)
				goto error;
			/* line status bits may report this as low speed,
			 * which can be fine if this root hub has a
			 * transaction translator built in.
			 */
			/*if ((temp & (PORT_PE|PORT_CONNECT)) == PORT_CONNECT
					&& PORT_USB11(temp)) {
				temp |= PORT_OWNER;
			} else {*/

				vega_write32(hcd->regs, HC_USBCMD, 0);//Set Run/Stop bit zero
				temp = vega_read32(hcd->regs, HC_PORTSC1);
				temp |= PORT_RESET;
				temp &= ~PORT_PE;
				
				//pr_err("PORT_RESET\n");

				/*
				 * caller must wait, then call GetPortStatus
				 * usb 2.0 spec says 50 ms resets on root
				 */
				priv->reset_done = jiffies +
					msecs_to_jiffies(100);
			//}
				vega_write32(hcd->regs, HC_PORTSC1, temp);
			break;
		default:
			goto error;
		}
		break;

	default:
error:
		/* "stall" on error */
		vega_dbg(hcd->self.controller, "error \n");
		retval = -EPIPE;
	}

	/////vega_hub_cotrol_dbg(hcd->self.controller, "vega_hub_control over %x\n",retval); ////cdac

	spin_unlock_irqrestore(&priv->lock, flags);
	return retval;
	
}

static void vega_clear_tt_buffer_complete(struct usb_hcd *hcd,
						struct usb_host_endpoint *ep)
{
	//dev_err(hcd->self.controller, "<***********************vega_clear_tt_buffer_complete***********************>\n");
	
	
	struct vega_hcd *priv = hcd_to_priv(hcd);
	struct vega_qh *qh = ep->hcpriv;
	unsigned long spinflags;

	if (!qh)
		return;

	spin_lock_irqsave(&priv->lock, spinflags);
	qh->tt_buffer_dirty = 0;
	
	//pr_err("vega_clear_tt_buffer_complete schedule_ptds\n");
	schedule_ptds(hcd);
	spin_unlock_irqrestore(&priv->lock, spinflags);
	
}

static const struct hc_driver vega_hc_driver = {
	.description		= "VEGA HCD",
	.product_desc		= "VEGA USB Host Cotroller Driver",
	.hcd_priv_size		= sizeof(struct vega_hcd),

	/*
	 * generic hardware linkage
	 */
	.irq			= vega_irq,
	.flags			= HCD_MEMORY | HCD_USB2 ,

	/*
	 * basic lifecycle operations
	 */
	.reset			= vega_setup,
	.start			= vega_run,
	.stop			= vega_stop,
	.shutdown		= vega_shutdown,

	/*
	 * managing i/o requests and associated device resources
	 */
	.urb_enqueue		= vega_urb_enqueue,
	.urb_dequeue		= vega_urb_dequeue,
	.endpoint_disable	= vega_endpoint_disable,
	//.endpoint_reset		= vega_endpoint_reset,

	/*
	 * scheduling support
	 */
	.get_frame_number	= vega_get_frame,

	/*
	 * root hub support
	 */
	.hub_status_data	= vega_hub_status_data,
	.hub_control		= vega_hub_control,

	.clear_tt_buffer_complete = vega_clear_tt_buffer_complete,
};

int vega_hcd_register(struct vega_hcd *priv, void __iomem *regs,
			 struct resource *mem, int irq, unsigned long irqflags,
			 struct device *dev)
{
	struct usb_hcd *hcd;
	int ret;

	hcd = usb_create_hcd(&vega_hc_driver, dev, dev_name(dev));
	if (!hcd)
		return -ENOMEM;

	*(struct vega_hcd **)hcd->hcd_priv = priv;

	priv->hcd = hcd;

	init_memory(priv);

	hcd->irq = irq;
	hcd->regs = regs;
	hcd->rsrc_start = mem->start;
	hcd->rsrc_len = resource_size(mem);

	hcd->has_tt = 1;
	
	/* This driver doesn't support wakeup requests */
	hcd->cant_recv_wakeups = 1;

	ret = usb_add_hcd(hcd, irq, irqflags);
	if (ret)
		goto error;

	device_wakeup_enable(hcd->self.controller);

	return 0;

error:
	usb_put_hcd(hcd);
	return ret;
}

////


int __init vega_init_kmem_once(void)
{
	urb_listitem_cachep = kmem_cache_create("vega_urb_listitem",
			sizeof(struct urb_listitem), 0, SLAB_TEMPORARY |
			SLAB_MEM_SPREAD, NULL);

	if (!urb_listitem_cachep)
		return -ENOMEM;

	qtd_cachep = kmem_cache_create("vega_qtd",
			sizeof(struct vega_qtd), 0, SLAB_TEMPORARY |
			SLAB_MEM_SPREAD, NULL);

	if (!qtd_cachep)
		return -ENOMEM;

	qh_cachep = kmem_cache_create("vega_qh", sizeof(struct vega_qh),
			0, SLAB_TEMPORARY | SLAB_MEM_SPREAD, NULL);

	if (!qh_cachep) {
		kmem_cache_destroy(qtd_cachep);
		return -ENOMEM;
	}

	return 0;
}

void vega_deinit_kmem_cache(void)
{
	kmem_cache_destroy(qtd_cachep);
	kmem_cache_destroy(qh_cachep);
	kmem_cache_destroy(urb_listitem_cachep);
}

/**
 * vega_hcd_vega_of_probe - Probe method for the USB host controller
 * @op:		pointer to the platform_device bound to the host controller
 *
 * This function requests resources and sets up appropriate properties for the
 * host controller. Because the vega USB host controller can be configured
 * as HS only or HS/FS only, it checks the configuration in the device tree
 * entry, and sets an appropriate value for hcd->has_tt.
 */

////

/**
 * vega_hcd_vega_of_remove - shutdown hcd and release resources
 * @op:		pointer to platform_device structure that is to be removed
 *
 * Remove the hcd structure, and release resources that has been requested
 * during probe.
 */

////


/*
static const struct of_device_id vega_hcd_of_match[] = {
		{.compatible = "cdac,vega-usb",},
	{},
};
MODULE_DEVICE_TABLE(of, vega_hcd_of_match);

static struct platform_driver vega_hcd_of_driver = {
	.probe		= vega_hcd_probe,
	.remove	= vega_hcd_remove,
	.shutdown	= usb_hcd_platform_shutdown,
	.driver = {
		.name = "vega-usb",
		.of_match_table = vega_hcd_of_match,
	},
};

*/

static int __init vega_init(void)
{
	int ret, any_ret = -ENODEV;

	vega_init_kmem_once();

	ret = platform_driver_register(&vega_hcd_of_driver);
	if (!ret)
		any_ret = 0;

	if (any_ret)
		vega_deinit_kmem_cache();
	return any_ret;
}
module_init(vega_init);

static void __exit vega_exit(void)
{
	platform_driver_unregister(&vega_hcd_of_driver);

	vega_deinit_kmem_cache();
}
module_exit(vega_exit);
