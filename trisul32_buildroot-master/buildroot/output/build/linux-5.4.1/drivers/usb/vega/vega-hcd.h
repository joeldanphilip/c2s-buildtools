/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _VEGA_HCD_H_
#define _VEGA_HCD_H_

#include <linux/spinlock.h>
//#include "vega-core.h"
#include "vega-udc.h"

#define VEGA_FLAG_BUS_WIDTH_16 0x00000002 /* 16-bit data bus width */
#define VEGA_FLAG_OTG_EN 0x00000004 /* Port 1 supports OTG */
#define VEGA_FLAG_ANALOG_OC 0x00000008 /* Analog overcurrent */
#define VEGA_FLAG_DACK_POL_HIGH 0x00000010 /* DACK active high */
#define VEGA_FLAG_DREQ_POL_HIGH 0x00000020 /* DREQ active high */
#define VEGA_FLAG_ISP1761 0x00000040 /* Chip is ISP1761 */
#define VEGA_FLAG_INTR_POL_HIGH 0x00000080 /* Interrupt polarity active high */
#define VEGA_FLAG_INTR_EDGE_TRIG 0x00000100 /* Interrupt edge triggered */

/* urb state*/
#define DELETE_URB (0x0008)
#define NO_TRANSFER_ACTIVE (0xffffffff)

struct vega_qh;
struct vega_qtd;
struct resource;
struct vega_hcd;

/*
 * 15kb divided in:
 * - 8 blocks @ 256  bytes
 * - 5 blocks @ 1024 bytes
 * -  1 blocks @ 8192 bytes
 */

#define BLOCK_1_NUM 8
#define BLOCK_2_NUM 5
#define BLOCK_3_NUM 1

#define BLOCK_1_SIZE 256
#define BLOCK_2_SIZE 1024
#define BLOCK_3_SIZE 8192
#define BLOCKS (BLOCK_1_NUM + BLOCK_2_NUM + BLOCK_3_NUM)
#define MAX_PAYLOAD_SIZE BLOCK_3_SIZE
#define PAYLOAD_AREA_SIZE 0x3C00

#define HUB_SPEED_FULL 0
#define HUB_SPEED_HIGH 1

struct vega_slotinfo {
	struct vega_qh *qh;
	struct vega_qtd *qtd;
	unsigned long timestamp;
};

/* chip memory management */
struct vega_memory_chunk {
	unsigned int start;
	unsigned int size;
	unsigned int free;
};

enum vega_queue_head_types {
	QH_CONTROL,
	QH_BULK,
	QH_INTERRUPT,
	QH_ISOCHRONOUS,
	QH_END
};

struct vega_hcd {
	struct usb_hcd *hcd;

	u32 hcs_params;
	spinlock_t lock;
	struct vega_slotinfo atl_slots[32];
	int atl_done_map;
	struct vega_slotinfo int_slots[32];
	int int_done_map;
	struct vega_slotinfo iso_slots[32];
	int iso_done_map;
	struct vega_memory_chunk memory_pool[BLOCKS];
	struct list_head qh_list[QH_END];

	/* periodic schedule support */
#define DEFAULT_I_TDPS 1024
	unsigned periodic_size;
	unsigned i_thresh;
	unsigned long reset_done;
	unsigned long next_statechange;
};

struct device;
struct gpio_desc;

static void vega_init_core(struct vega_device *vega);

static inline u32 vega_read32(void __iomem *base, u32 reg)
{
	return readl(base + reg);
}

static inline void vega_write32(void __iomem *base, u32 reg, u32 val)
{
	writel(val, base + reg);
}

int vega_hcd_register(struct vega_hcd *priv, void __iomem *regs,
		      struct resource *mem, int irq, unsigned long irqflags,
		      struct device *dev);
void vega_hcd_unregister(struct vega_hcd *priv);

int vega_init_kmem_once(void);
void vega_deinit_kmem_cache(void);

#endif /* _VEGA_HCD_H_ */
