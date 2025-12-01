// SPDX-License-Identifier: GPL-2.0-only
/*
 * linux/drivers/mmc/host/cdac_mmc.c - cdac_X0 MMC driver
 *
 *  Copyright (c) 2005, Advanced Micro Devices, Inc.
 *
 *  Developed with help from the 2.4.30 MMC cdac_XX controller including
 *  the following copyright notices:
 *     Copyright (c) 2003-2004 Embedded Edge, LLC.
 *     Portions Copyright (C) 2002 Embedix, Inc
 *     Copyright 2002 Hewlett-Packard Company

 *  2.6 version of this driver inspired by:
 *     (drivers/mmc/wbsd.c) Copyright (C) 2004-2005 Pierre Ossman,
 *     All Rights Reserved.
 *     (drivers/mmc/pxa.c) Copyright (C) 2003 Russell King,
 *     All Rights Reserved.
 *

 */

/* Why don't we use the SD controllers' carddetect feature?
 *
 * From the AU1100 MMC application guide:
 * If the Au1100-based design is intended to support both MultiMediaCards
 * and 1- or 4-data bit SecureDigital cards, then the solution is to
 * connect a weak (560KOhm) pull-up resistor to connector pin 1.
 * In doing so, a MMC card never enters SPI-mode communications,
 * but now the SecureDigital card-detect feature of CD/DAT3 is ineffective
 * (the low to high transition will not occur).
 */

#include <linux/clk.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#include <linux/mm.h>
#include <linux/interrupt.h>
#include <linux/dma-mapping.h>
#include <linux/scatterlist.h>
#include <linux/highmem.h>
#include <linux/leds.h>
#include <linux/mmc/host.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <linux/spinlock.h>
#include <linux/linkage.h>
#include <linux/delay.h>

#include "cdac_emmc.h"
#include "cdac_dmac.h"
#include "cdac_datatype.h"
#include "cdac_globals.h"

//#define SINGLE_CORE_EMMC

//#define DUAL_CORE_EMMC

#define cdac_pr_info(...) //pr_info(__VA_ARGS__)
#define cdac_printk(...) //printk(__VA_ARGS__)


volatile unsigned char gTx_memory[512];
volatile unsigned char gRx_memory[512];



/*
typedef unsigned char UC; //1 Byte
typedef unsigned short US; //2 Bytes
typedef unsigned int UI; //4 Bytes
typedef unsigned long UL; //8 Bytes
*/

/****************** DMA *******************/

	volatile UL *ch0SrcReg  = (UL*)(0x10000B10);
	volatile UL *ch0DstReg  = (UL*)(0x10000B18);
	volatile UL *ch0LLIReg  = (UL*)(0x10000B20);
	volatile UL *ch0CtrlReg = (UL*)(0x10000B28);
	
	volatile UL gDst_addr,gSrc_addr;
	DMAtransfer_Type gDMAtransfer;




/*****************************************/


//#include <asm/io.h>
//#include <asm/mach-au1x00/au1000.h>
//#//include <asm/mach-au1x00/au1x00_xx_dbdma.h>
//#include <asm/mach-au1x00/au1100_mmc.h>

volatile UL gHostIEReg_val,command_complete_flag;

	//Command Response types
#define CMD_NO_RESP						0  // No response
#define CMD_RESP_LEN_48					1  // R1,R3,R5 (48  BIT RESPONSE)
#define CMD_RESP_LEN_48_WITH_BUSY		2  // R1b (48  BIT RESPONSE WITH BUSY)
#define CMD_RESP_LEN_136				3  // R2 (136 BIT)

#define DRIVER_NAME "cdac_emmc"

/* Set this to enable special debugging macros */
/* #define DEBUG */

#ifdef DEBUG
#define DBG(fmt, idx, args...)	\
		pr_debug("cdac_mmc(%d): DEBUG: " fmt, idx, ##args)
#else
#define DBG(fmt, idx, args...) do {} while (0)
#endif

/* Hardware definitions */
#define CDAC_MMC_DESCRIPTOR_COUNT 1

/* max DMA seg size: 64KB on Au1100, 4MB on Au1200 */
#define AU1100_MMC_DESCRIPTOR_SIZE 0x0000ffff
#define AU1200_MMC_DESCRIPTOR_SIZE 0x003fffff

#define CDAC_MMC_OCR (MMC_VDD_27_28 | MMC_VDD_28_29 | MMC_VDD_29_30 | \
		MMC_VDD_30_31 | MMC_VDD_31_32 | MMC_VDD_32_33 | \
		MMC_VDD_33_34 | MMC_VDD_34_35 | MMC_VDD_35_36)

/* This gives us a hard value for the stop command that we can write directly
 * to the command register.
 */
//#define STOP_CMD	\
		(SD_CMD_RT_1B | SD_CMD_CT_7 | (0xC << SD_CMD_CI_SHIFT) | SD_CMD_GO)
/* This is the set of interrupts that we configure by default. */
#define CDAC_MMC_INTERRUPTS 				\
		(SD_CONFIG_SC | SD_CONFIG_DT | SD_CONFIG_RAT |	\
				SD_CONFIG_CR | SD_CONFIG_I)

/* The poll event (looking for insert/remove events runs twice a second. */
#define CDAC_MMC_DETECT_TIMEOUT (HZ/2)

struct cdac_mmc_host {
	struct mmc_host *mmc;
	struct mmc_request *mrq;

	UI flags;
	void __iomem *iobase;
	void __iomem *dmabase;
	UI clock;
	UI bus_width;
	UI power_mode;

	int status;

	struct {
		int len;
		int dir;
	} dma;

	struct {
		int index;
		int offset;
		int len;
	} pio;

	UI tx_chan;
	UI rx_chan;

	int irq;
	
	spinlock_t chip_lock;

	struct tasklet_struct finish_task;
	struct tasklet_struct data_task;
	struct cdac_mmc_platform_data *platdata;
	struct platform_device *pdev;
	struct resource *ioarea;
	struct clk *clk;
};

/* Status flags used by the host structure */
#define HOST_F_XMIT	0x0001
#define HOST_F_RECV	0x0002
#define HOST_F_DMA	0x0010
#define HOST_F_DBDMA	0x0020
#define HOST_F_ACTIVE	0x0100
#define HOST_F_STOP	0x1000

#define HOST_S_IDLE	0x0001
#define HOST_S_CMD	0x0002
#define HOST_S_DATA	0x0003
#define HOST_S_STOP	0x0004

/************CDAC EMMC REGISTERS **********/
#define STATUS 0x00
#define LWR_RSP 0x08
#define UPR_RSP 0x10
#define CMD 0x18
#define OP_MODE 0x20
#define OP_FREQ 0x28
#define RSP_TIMEOUT 0x30
#define WR_TRANS_TIMEOUT 0x38
#define RD_TRANS_TIMEOUT 0x40
#define LWR_CSD 0x50
#define UPR_CSD 0x58
#define WR_TST 0x60
#define RD_TST 0x68
#define WR_PROT 0x70
#define WR_PROT_TYPE 0x78
#define INTERRUPT_ENABLE 0x80
#define INTERRUPT_STATUS 0x88
#define STATUS_REG_2 0x90
#define BOOT_FIFO 0xD0
#define RD_DATA_FIFO 0xD0
#define WR_DATA_FIFO 0xF0

/* Easy access macros */

#define HOST_STATUS(h)	((h)->iobase + STATUS)
#define HOST_LWR_RSP(h)	((h)->iobase + LWR_RSP)
#define HOST_UPR_RSP(h)	((h)->iobase + UPR_RSP)
#define HOST_CMD(h)	((h)->iobase + CMD)
#define HOST_OP_MODE(h)	((h)->iobase + OP_MODE)
#define HOST_OP_FREQ(h)	((h)->iobase + OP_FREQ)
#define HOST_RSP_TIMEOUT(h)	((h)->iobase + RSP_TIMEOUT)
#define HOST_WR_TRANS_TIMEOUT(h)	((h)->iobase + WR_TRANS_TIMEOUT)
#define HOST_RD_TRANS_TIMEOUT(h)	((h)->iobase + RD_TRANS_TIMEOUT)
#define HOST_LWR_CSD(h)	((h)->iobase + LWR_CSD)
#define HOST_UPR_CSD(h)	((h)->iobase + UPR_CSD)
#define HOST_WR_TST(h)	((h)->iobase + WR_TST)
#define HOST_RD_TST(h)	((h)->iobase + RD_TST)
#define HOST_WR_PROT(h)	((h)->iobase + WR_PROT)
#define HOST_WR_PROT_TYPE(h)	((h)->iobase + WR_PROT_TYPE)
#define HOST_IE(h)	((h)->iobase + INTERRUPT_ENABLE)
#define HOST_INTERRUPT_STATUS(h)	((h)->iobase + INTERRUPT_STATUS)
#define HOST_BOOT_FIFO(h)	((h)->iobase + BOOT_FIFO)
#define HOST_RD_DATA_FIFO(h)	((h)->iobase + RD_DATA_FIFO)
#define HOST_WR_DATA_FIFO(h)	((h)->iobase + WR_DATA_FIFO)
/************CDAC EMMC REGISTERS **********/


/**********CDAC DMA REGISTERS ***************/

#define DMA_GLOBAL_CTRLREG 	0x00
#define DMA_GLOBAL_STATUSREG 	0x08

#define DMA_CH0_SRC_ADDRREG 	0x10
#define DMA_CH0_DST_ADDRREG 	0x18
#define DMA_CH0_LLIREG 		0x20
#define DMA_CH0_CTRL_STATUSREG 	0x28

#define DMA_CH1_SRC_ADDRREG 	0x30
#define DMA_CH1_DST_ADDRREG 	0x38
#define DMA_CH1_LLIREG 		0x40
#define DMA_CH1_CTRL_STATUSREG 	0x48

#define DMA_CH2_SRC_ADDRREG 	0x50
#define DMA_CH2_DST_ADDRREG 	0x58
#define DMA_CH2_LLIREG 		0x60
#define DMA_CH2_CTRLSTATUS_REG 	0x68

#define DMA_CH3_SRC_ADDRREG 	0x70
#define DMA_CH3_DST_ADDRREG 	0x78
#define DMA_CH3_LLIREG 		0x80
#define DMA_CH3_CTRL_STATUSREG 	0x88




/* Easy access macros */

#define DMA_GLOBAL_CTRL_REG(h)	((h)->dmabase + DMA_GLOBAL_CTRLREG)
#define DMA_GLOBAL_STATUS_REG(h)	((h)->dmabase + DMA_GLOBAL_STATUSREG)

#define DMA_CH0_SRC_ADDR_REG(h)	((h)->dmabase + DMA_CH0_SRC_ADDRREG)
#define DMA_CH0_DST_ADDR_REG(h)	((h)->dmabase + DMA_CH0_DST_ADDRREG)
#define DMA_CH0_LLI_REG(h)		((h)->dmabase + DMA_CH0_LLIREG)
#define DMA_CH0_CTRL_STATUS_REG(h)	((h)->dmabase + DMA_CH0_CTRL_STATUSREG)

#define DMA_CH1_SRC_ADDR_REG(h)	((h)->dmabase + DMA_CH1_SRC_ADDRREG)
#define DMA_CH1_DST_ADDR_REG(h)	((h)->dmabase + DMA_CH1_DST_ADDRREG)
#define DMA_CH1_LLI_REG(h)		((h)->dmabase + DMA_CH1_LLIREG)
#define DMA_CH1_CTRL_STATUS_REG(h)	((h)->dmabase + DMA_CH1_CTRL_STATUSREG)

#define DMA_CH2_SRC_ADDR_REG(h)	((h)->dmabase + DMA_CH2_SRC_ADDRREG)
#define DMA_CH2_DST_ADDR_REG(h)	((h)->dmabase + DMA_CH2_DST_ADDRREG)
#define DMA_CH2_LLI_REG(h)		((h)->dmabase + DMA_CH2_LLIREG)
#define DMA_CH3_CTRL_STATUS_REG(h)	((h)->dmabase + DMA_CH2_CTRL_STATUSREG)

#define DMA_CH3_SRC_ADDR_REG(h)	((h)->dmabase + DMA_CH3_SRC_ADDRREG)
#define DMA_CH3_DST_ADDR_REG(h)	((h)->dmabase + DMA_CH3_DST_ADDRREG)
#define DMA_CH3_LLI_REG(h)		((h)->dmabase + DMA_CH3_LLIREG)
#define DMA_CH3_CTRL_STATUS_REG(h)	((h)->dmabase + DMA_CH3_CTRL_STATUSREG)


/**********CDAC DMA REGISTERS ***************/




#define OP_FREQ_400KHz	0
#define OP_FREQ_25MHz	1
#define OP_FREQ_50MHz	2

#define RSP_TIMEOUT_MAX 0x40
#define RSP_TIMEOUT_MIN 0x02

//#define WR_TRANS_TIMEOUT_MAX 0xA
#define WR_TRANS_TIMEOUT_MAX 0xFFFFFFFF
#define RD_TRANS_TIMEOUT_MAX 0x17bf1A0


#define ALL_INTERRUPTS_SET (0x202 | (1<<11) | (1<<12) | (1<<13))

#define CDAC_MMC_OP_MODE_NUM_BLOCK(n) (n << 45) /*Number of blocks Bits 45 to 60*/
#define CDAC_MMC_OP_MODE_STOP_EMMC_CLK(x) (x << 44) /*Stop EMMC Clock - Old was 49 */
#define CDAC_MMC_OP_MODE_TOT_FRAMES_TO_INRPT(x) (x << 41) /*Total number of frames in FIFO to be interrupted */
#define CDAC_MMC_OP_MODE_ERR_OVERRIDE(x) (x << 40) /*Error override */
#define CDAC_MMC_OP_MODE_CMD_LINE_VALID(x) (x << 39) /*Command line low/high bit is Valid. [34th bit is valid] */
#define CDAC_MMC_OP_MODE_OPEN_ENDED_TRANSN(x) (x << 38) /*Open ended transaction */
#define CDAC_MMC_OP_MODE_CLR_BOOT_FIFO(x) (x << 37) /*Clear boot FIFO */
#define CDAC_MMC_OP_MODE_CLR_RDDATA_FIFO(x) (x << 36) /*Clear read data FIFO */
#define CDAC_MMC_OP_MODE_CLR_WRDATA_FIFO(x) (x << 35) /*Clear write data FIFO */
#define CDAC_MMC_OP_MODE_CMD_LINE(x) (x << 34) /*command line high */
#define CDAC_MMC_OP_MODE_BOOT_ACK_EN(x) (x << 33) /*Boot acknowledgment enabled */
#define CDAC_MMC_OP_MODE_DEV_RESET(x) (x << 32) /*Active low device reset */
#define CDAC_MMC_OP_MODE_LEN_BLOCK(n) (n << 8) /*Length of each block*/
#define CDAC_MMC_OP_MODE_DATA_BUS_WIDTH(n) (n << 4) /*Data bus width*/
#define CDAC_MMC_OP_MODE_DATA_TSFR(n) (n << 0) /* Data transfer mode*/

#define CDAC_MMC_RSP_TYPE(x) (x << 40) /* Type of Response to the command */
#define CDAC_MMC_CMD_TYPE(x) (x << 38) /* Type of the command */
#define CDAC_MMC_CMD_ARG(x) (x << 6) /* Command argument/data address*/
#define CDAC_MMC_CMD_INDEX(x) (x << 0) /* Command index*/

#define CDAC_MMC_RSP_NONE 0x00
#define CDAC_MMC_RSP_48 0x01
#define CDAC_MMC_RSP_48_BUSY 0x02
#define CDAC_MMC_RSP_136 0x03


#define CDAC_MMC_STATUS_BOOT_FIFO_EMP ((UL)1<<40) // 40 bit
#define CDAC_MMC_STATUS_WDATA_FIFO_EMP  ((UL)1<<37) // 37 bit
#define CDAC_MMC_STATUS_WDATA_FIFO_FULL ((UL)1<<36) // 36 bit
#define CDAC_MMC_STATUS_RDATA_END_BIT_ERR  ((UL)1<<33) // 33 bit
#define CDAC_MMC_STATUS_CMD_RSP_END_ERR ((UL)1<<32) // 32 bit
#define CDAC_MMC_STATUS_CMD_RSP_TXN_ERR ((UL)1<<31) // 31 bit
#define CDAC_MMC_STATUS_SIN_BLK_RD_CPLT ((UL)1<<29)
#define CDAC_MMC_STATUS_RD_TRANSN_TIMEOUT_ERR ((UL)1<<28) // 28 bit
#define CDAC_MMC_STATUS_WTRANS_TMOUT_ERR ((UL)1<<27)
#define CDAC_MMC_STATUS_CMD_RSP_TO_ERR ((UL)1<<26)
#define CDAC_MMC_STATUS_SIN_BLK_WR_CPLT ((UL)1<<23)
#define CDAC_MMC_STATUS_RX_CRC_ERR  ((UL)1<<25) // 25 bit
#define CDAC_MMC_STATUS_MUL_BLK_RD_CPLT ((UL)1<<14)
#define CDAC_MMC_STATUS_MUL_BLK_WR_CPLT ((UL)1<<13)



#define CDAC_MMC_STATUS_RSP_RXD ((UL)1<<2)
#define CDAC_MMC_STATUS_CMD_SENT ((UL)1<<1)
#define CDAC_MMC_STATUS_DEV_BUSY ((UL)1<<0)




#define CDAC_MMC_INTR_STATUS_SIN_BLK_RD_CPLT_INTR ((UL)1<<4)
#define CDAC_MMC_INTR_STATUS_SIN_BLK_WR_CPLT_INTR ((UL)1<<3)
#define CDAC_MMC_INT_STATUS_CMD_SENT 	 ((UL)1<<1)
#define CDAC_MMC_INT_STATUS_CMD_COMPLETE  ((UL)1<<0)

#define CDAC_MMC_INTR_STATUS_RSP_TMOUT ((UL)1<<11)
#define CDAC_MMC_INTR_STATUS_WRT_TMOUT ((UL)1<<12)
#define CDAC_MMC_INTR_STATUS_RRT_TMOUT ((UL)1<<13)



#define CDAC_MMC_INTR_STATUS_NO_BLK_AVL_B_FIFO_INTR ((UL)1<<26)
#define CDAC_MMC_INTR_STATUS_WR_DATA_FIFO_EMPTY_INTR ((UL)1<<28)





//#define CDAC_MMC_INTR_EN_NUM_BLK_AVL_R_FIFO_INTR ((UL)1 << 25)
#define CDAC_MMC_INTR_EN_NUM_BLK_AVL_BOOT_FIFO_INTR ((UL)1 << 26)
#define CDAC_MMC_INTR_EN_WR_DATA_FIFO_EMPTY_INTR ((UL)1 << 28)
/* Easy access macros */
/*
 #define HOST_STATUS(h)	((h)->iobase + SD_STATUS)
 #define HOST_CONFIG(h)	((h)->iobase + SD_CONFIG)
 #define HOST_ENABLE(h)	((h)->iobase + SD_ENABLE)
 #define HOST_TXPORT(h)	((h)->iobase + SD_TXPORT)
 #define HOST_RXPORT(h)	((h)->iobase + SD_RXPORT)
 #define HOST_CMDARG(h)	((h)->iobase + SD_CMDARG)
 #define HOST_BLKSIZE(h)	((h)->iobase + SD_BLKSIZE)
 #define HOST_CMD(h)	((h)->iobase + SD_CMD)
 #define HOST_CONFIG2(h)	((h)->iobase + SD_CONFIG2)
 #define HOST_TIMEOUT(h)	((h)->iobase + SD_TIMEOUT)
 #define HOST_DEBUG(h)	((h)->iobase + SD_DEBUG)
 */

#define DMA_GBLCTRL 0x00
#define DMA_GBLSTATUS 0x08
#define SRC_ADDR 0x10
#define DST_ADDR 0x18
#define DMA_CNLCSR 0x20
#define DMA_CNLLLI 0x28

//#define DMA_ACTIVE 0x01

#define SRC_DW_8 					0
#define SRC_DW_16 				1
#define SRC_DW_32 				2
#define SRC_DW_64 				3
#define SRC_DW_128 				4
#define SRC_DW_256 				5

#define DST_DW_8 					0
#define DST_DW_16 				1
#define DST_DW_32 				2
#define DST_DW_64 				3
#define DST_DW_128 			4

#define DST_CONFIG_ERROR_WIDTH 			5

#define LM_ACE 				0
#define LM_AXI 				1
#define LM_NO_MSEL	2

#define CHK_CH0_DTD								(1 << 1)
#define CHK_CH1_DTD								(1 << 2)
#define CHK_CH2_DTD								(1 << 3)
#define CHK_CH3_DTD								(1 << 4)

#define DMA_INACTIVE 	0
#define DMA_ACTIVE 		1

#define LLI_DISABLE 			0
#define LLI_ENABLE 			2

#define CIE_DISABLE 		    0
#define CIE_ENABLE 		    1

#define SAI_DISABLE 			0
#define SAI_ENABLE 		    1

#define DAI_DISABLE 		0
#define DAI_ENABLE 		    1

#define CBE_DISABLE 		0
#define CBE_ENABLE 		 1

#define DCE_DISABLE 		0
#define DCE_ENABLE 		1

#define DMA_INTR_DISABLE 		0
#define DMA_INTR_ENABLE 			1

#define CMS_ACE2ACE 		0
#define CMS_AXI2ACE 		1
#define CMS_ACE2AXI 		2
#define CMS_AXI2AXI 		3

#define CTS_1						1
#define CTS_2						2
#define CTS_4    					4  // For 512 Bytes transfer
#define CTS_32    					32 // For 4096 Bytes transfer
#define CTS_40    					40

#define CTS_8 						8
#define CTS_16 						16
#define CTS_128 					128
#define CTS_255 					255

#define CTS_256 					256
#define CTS_512						512
#define CTS_1024					1024
#define CTS_2048					2048
#define CTS_4096					4096
#define CTS_8191					8191

#define CBS_DISABLED 		0
#define CBS_2 						1
#define CBS_4 						2
#define CBS_8 						3

#define NO_LLI													0
#define NO_NEXT_LLI									0
#define DMA_CHANNEL(h)	\
		(((h)->flags & HOST_F_XMIT) ? (h)->tx_chan : (h)->rx_chan)
//#ifdef DMA
/*
#define DMA_GBL_CTRL(h) ((h)->dmabase + DMA_GBLCTRL)
#define DMA_GBL_STATUS(h) ((h)->dmabase + DMA_GBLSTATUS)
#define DMA_SRC_ADDR(h) ((h)->dmabase + SRC_ADDR)
#define DMA_DST_ADDR(h) ((h)->dmabase + DST_ADDR)
#define DMA_CNL_CSR(h)	((h)->dmabase + DMA_CNLCSR)
#define DMA_CNL_LLI(h)	((h)->dmabase + DMA_CNLLLI)

#define DMA_CNL_CSR_CBS(x) (x << 29)
#define DMA_CNL_CSR_CIC(x) (x << 26)
#define DMA_CNL_CSR_CTS(x) (x << 13)
#define DMA_CNL_CSR_CMS(x) (x << 11)
#define DMA_CNL_CSR_CBE(x) (x << 10)
#define DMA_CNL_CSR_SAI(x) (x << 9)
#define DMA_CNL_CSR_DAI(x) (x << 8)
#define DMA_CNL_CSR_DDW(x) (x << 5)
#define DMA_CNL_CSR_SDW(x) (x << 2)
#define DMA_CNL_CSR_CIE(x) (x << 1)
#define DMA_CNL_CSR_DCE(x) (x << 0)

#define DMA_GBL_CTRL_DMA_ENABLE(x) (x << 0) //DMA ENABLE 
#define DMA_GBL_CTRL_DMA__INTR_ENABLE(x) (x << 1) /* DMA INTERRUPT ENABLE 
*/

void cdac_mmc_cmd_complete(struct cdac_mmc_host *host);
void Enable_DMAC(struct cdac_mmc_host *host);
unsigned long  Read_DMAC_Global_Status_Reg(struct cdac_mmc_host *host);
void Check_DMAC_transferDone(struct cdac_mmc_host *host,UC channelNum);

/*
static int cdac_dma_drv_probe(struct platform_device *pdev) {
	struct resource *r;
	struct device_node *np = pdev->dev.of_node;
	struct cdac_mmc_host *host;	
	
	
	cdac_printk("\n\r cdac_dma_drv_probe.............\n\r");
	
	r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!r) {
		dev_err(&pdev->dev, "no DMAio defined\n");
		
		release_resource(host->ioarea);
		return;
	}
	
	cdac_pr_info(DRIVER_NAME ": r->start %lx pdev->name %s\n", r->start, pdev->name);
	

	host->dmabase = ioremap(r->start, resource_size(r));
	
	
	cdac_pr_info(DRIVER_NAME " host->dmabase %lx \n", host->dmabase);

	if (!host->dmabase) {
		dev_err(&pdev->dev, "cannot remap mmio\n");
		
		 iounmap((void*) host->dmabase);

		return;
	}
	
	
	

	Enable_DMAC(host);	// Enabling DMAC.

	return 0;
}

static int cdac_dma_drv_remove(struct platform_device *pdev) {

//	iounmap((volatile void*) (gDma_base));
	return 0;
}

static const struct of_device_id cdac_dma_match[] = { { .type = "dma",
		.compatible = "cdac,cdac_dma" }, { } };
		
MODULE_DEVICE_TABLE( of, cdac_dma_match);


static struct platform_driver cdac_dma_driver = {


	.probe = cdac_dma_drv_probe,
	.remove = cdac_dma_drv_remove,
	.driver = {
		.name = "cdac_dma",
                .owner = THIS_MODULE,
		.of_match_table = of_match_ptr(cdac_dma_match),
	},
#ifdef CONFIG_PM
	//.suspend = cdac_mmc_suspend,
	//.resume = cdac_mmc_resume,
#endif
};*/

/*
static void DMA_initialisation(struct cdac_mmc_host *host) {

	unsigned long reg_value = 0;
	unsigned long status = 0;
	reg_value = DMA_GBL_CTRL_DMA__INTR_ENABLE(1) | DMA_GBL_CTRL_DMA_ENABLE(1); // DMA INTERRUPT ENABLE & DMA ENABLE
	__raw_writeq(reg_value, DMA_GBL_CTRL(host)); //writing Global control register

	do {
		status = __raw_readq(DMA_GBL_STATUS(host));
	} while (((status & DMA_ACTIVE) != DMA_ACTIVE)); // Check if channel is active or not

}*/
/*
void DMA_config_channel(struct cdac_mmc_host *host, UC channel,
		UI ch_source_addr, UI ch_dest_addr, UC DAI, UC SAI) {
	int channel_num = channel, test = 0;

	//int test = 0;
	unsigned long reg_value = 0;
	__raw_writeq(ch_source_addr, DMA_SRC_ADDR(host)); // Set channel  SRC Addr

	//Transmit_uart("\n\r SrcAddrReg : 0x");
	//disp_Rx_data_UL(DMAC_channelReg(channel).SrcAddrReg);

	__raw_writeq(ch_dest_addr, DMA_DST_ADDR(host)); // Set channel DEST Addr

	reg_value =
			DMA_CNL_CSR_CBS(
					CBS_8)| DMA_CNL_CSR_CTS(CTS_4) | DMA_CNL_CSR_CMS(CMS_AXI2AXI) | DMA_CNL_CSR_CBE(CBE_ENABLE) | DMA_CNL_CSR_SAI(SAI)| DMA_CNL_CSR_DAI(DAI)| DMA_CNL_CSR_DDW(DST_DW_128)| DMA_CNL_CSR_SDW(SRC_DW_128)| DMA_CNL_CSR_CIE(CIE_ENABLE)|DMA_CNL_CSR_DCE(DCE_ENABLE);

	__raw_writeq(reg_value, DMA_CNL_CSR(host));

}*/

//#endif
static inline int has_dbdma(void) {

	return 1;
	
}

static inline void IRQ_ON(struct cdac_mmc_host *host, UI mask) {
	
	unsigned long val,reg_value,data;
	
	//printk(DRIVER_NAME "***************************:IRQ_ON\n");
	//return;
	
	//val = gHostIEReg_val;//__raw_readq(HOST_IE(host));
	val = __raw_readq(HOST_IE(host));
	val |= mask;
	gHostIEReg_val = val;
	__raw_writeq(val, HOST_IE(host));
	//val = 0x7C02198;
	//cdac_pr_info(DRIVER_NAME "*****************:IRQ_ooonnnn %x\n", val);
	//__raw_writeq(val, HOST_IE(host)); // hdg: delete if not reqd, value as per firmware
	
	
	data = __raw_readq(HOST_IE(host));
	reg_value = __raw_readq(HOST_OP_MODE(host));
	
	cdac_pr_info(DRIVER_NAME "IE Reg data  0x %lx \n",data);
	//cdac_pr_info(DRIVER_NAME "Op Mode Reg data  0x %lx \n",reg_value);
	
	//cdac_pr_info(DRIVER_NAME "*****************:IRQ_ON %x\n", val);
	
	wmb(); /* drain writebuffer */
}
//#ifdef UNUSED
//static inline void FLUSH_FIFO(struct cdac_mmc_host *host) {
//UI val = __raw_readq(HOST_CONFIG2(host));

//__raw_writeq(val | SD_CONFIG2_FF, HOST_CONFIG2(host));//karthika edited
//	wmb(); /* drain writebuffer */
//	mdelay(1);

/* SEND_STOP will turn off clock control - this re-enables it */
//val &= ~SD_CONFIG2_DF;//karthika edited
//	__raw_writeq(val, HOST_CONFIG2(host));
//	wmb(); /* drain writebuffer */
//}
//#endif
//static inline
 void IRQ_OFF(struct cdac_mmc_host *host, UI mask) {

	UI val;
	cdac_pr_info(DRIVER_NAME "***************************:IRQ_OFF\n");

	// val = gHostIEReg_val;//__raw_readq(HOST_IE(host)); //write irq enable register
	 val = __raw_readq(HOST_IE(host)); //write irq enable register
	 cdac_pr_info(DRIVER_NAME "***************:IRQ_OFF before masking %x\n", val);
	val &= ~mask;
	__raw_writeq(val, HOST_IE(host));
	
	//cdac_pr_info(DRIVER_NAME "gHostIEReg_val  0x %lx \n",gHostIEReg_val);
	
	cdac_pr_info(DRIVER_NAME "***************:IRQ_OFF after mask %x\n", val);
		
	wmb(); /* drain writebuffer */
}

//static inline 
void SEND_STOP(struct cdac_mmc_host *host) {
	UI config2;
	unsigned long  reg_val = 0;
	cdac_pr_info(DRIVER_NAME ":SEND_STOPp\n");
	//printk(":SEND_STOP\n");
	//WARN_ON(host->status != HOST_S_DATA);
	host->status = HOST_S_STOP;
	//reg_val = __raw_readq(HOST_OP_MODE(host));
	//reg_val |= ((UL)1 << 37); // Clears Boot FIFO
	//__raw_writeq(reg_val, HOST_OP_MODE(host));
	//reg_val = __raw_readq(HOST_OP_MODE(host));
	//cdac_printk("*****Boot FIFO : Opmode Reg Val:0x %lx",reg_val);
	//cdac_printk("EMMC : Boot FIFO Cleared");	
	
	

	//config2 = __raw_readq(HOST_CONFIG2(host));
//		__raw_writeq(config2 | SD_CONFIG2_DF, HOST_CONFIG2(host));
	wmb(); /* drain writebuffer */


	/*if (!(host->flags & HOST_F_XMIT))
	{
		IRQ_OFF(host,ALL_INTERRUPTS_SET);

		/* Send the stop command */
		/*reg_val = 0x000002800000000C; // STOP Command arg using CMD 12 with HPI bit set (6th bit : Refer JEDEC spec for emmc)
		__raw_writeq(reg_val, HOST_CMD(host));
		
		//pr_info(DRIVER_NAME ":reg_value %lx \n",reg_val);
		while (!(__raw_readq(HOST_STATUS(host)) & (CDAC_MMC_STATUS_CMD_SENT))); //waiting for command to be sent
		cdac_pr_info(DRIVER_NAME ": ***** AF OPMODE REG VAL %lx \n",__raw_readq(HOST_OP_MODE(host)));
		wmb(); /* drain writebuffer */
	
		//IRQ_ON(host,ALL_INTERRUPTS_SET);
		
	//}

}

static void cdac_mmc_set_power(struct cdac_mmc_host *host, int state) {
	cdac_pr_info(DRIVER_NAME ":cdac_mmc_set_power\n");
	//if (host->platdata && host->platdata->set_power)
	//	host->platdata->set_power(host->mmc, state);
	
	
}

static void cdac_mmc_finish_request(struct cdac_mmc_host *host) {

	struct mmc_request *mrq = host->mrq;
	cdac_pr_info(DRIVER_NAME ":cdac_mmc_finish_request\n");
	host->mrq = NULL;
	host->flags =0; //&= HOST_F_ACTIVE | HOST_F_DMA;
	host->dma.len = 0;
	host->dma.dir = 0;
	host->pio.index = 0;
	host->pio.offset = 0;
	host->pio.len = 0;
	host->status = HOST_S_IDLE;
	mmc_request_done(host->mmc, mrq);

}

static void cdac_mmc_tasklet_finish(unsigned long param) {
	struct cdac_mmc_host *host = (struct cdac_mmc_host*) param;
	//cdac_pr_info(DRIVER_NAME ":cdac_mmc_tasklet_finish\n");
	cdac_mmc_finish_request(host);
}

static int cdac_mmc_send_command(struct cdac_mmc_host *host, int wait,
		struct mmc_command *cmd, struct mmc_data *data) {
		
		//printk(":SC_START");
		
		static int bus_width_1_flag=0;
		static int bus_width_4_flag=0;
		static int bus_width_8_flag=0;
		UL status_reg_value = 0;
		
		do
		{
			status_reg_value = __raw_readq(HOST_STATUS(host));
		}
		while(!(status_reg_value & CDAC_MMC_STATUS_DEV_BUSY)); // Wait until device is IDLE : 0: Busy, 1: IDLE
		
		
	
	UL command, argument, resp_type, cmd_type,cmd_type1;
	UL opmodereg_value = 0,reg_value = 0,int_status = 0;

	UL flag = 0;
	UL temp = 0;
	
	
		

	command = cmd->opcode;
	argument = cmd->arg;
	resp_type = mmc_resp_type(cmd);
	cmd_type = (mmc_cmd_type(cmd));
	
		

	if(cmd_type == MMC_CMD_AC)
		cmd_type = 0x00;
	else if(cmd_type == MMC_CMD_ADTC)
		cmd_type = 0x03;
	else if(cmd_type == MMC_CMD_BC)
		cmd_type = 0x00;
	else if(cmd_type == MMC_CMD_BCR)
		cmd_type = 0x01;	
		
		
		
		
	//cmd_type1 = (mmc_cmd_type(cmd));
	flag =  cmd->flags;
	

	
	if(resp_type == MMC_RSP_NONE)
		resp_type = CMD_NO_RESP;// No response
	else if((resp_type) == MMC_RSP_R1)
		resp_type = CMD_RESP_LEN_48; // R1 (48  BIT RESPONSE)
	else if((resp_type ) == 1)	
		resp_type = CMD_RESP_LEN_48_WITH_BUSY; // R1b 
	else if((resp_type) == MMC_RSP_R5)	
		resp_type = CMD_RESP_LEN_48; // R5,R6,R7 (48  BIT RESPONSE) THESE RESPONSES ARE SAME AS PER "core.h" file.
	else if((resp_type) == MMC_RSP_R1B)
		resp_type = CMD_RESP_LEN_48_WITH_BUSY; // R1b (48  BIT RESPONSE WITH BUSY)
	else if((resp_type ) == MMC_RSP_R2)
		resp_type = CMD_RESP_LEN_136; // R2 (136 BIT)
		
	if(command == 1)
	{
		resp_type = CMD_RESP_LEN_48; // R3
	}
		
	//cdac_pr_info(DRIVER_NAME ": @####HDG Test :: variable resp_type:  %lx \n",resp_type);
	//cdac_pr_info(DRIVER_NAME ": ####HDG Test :: variable flag:  %lx \n",flag);
//#ifdef DEBUG	
	// cdac_pr_info(DRIVER_NAME ": HDG Test :: variable command:  %lx \n",command);
	// cdac_pr_info(DRIVER_NAME ": HDG Test :: variable argument:  %lx \n",argument);
	 cdac_pr_info(DRIVER_NAME ": HDG Test :: After change cmd_type:  %lx \n",cmd_type);
	// //cdac_pr_info(DRIVER_NAME ": HDG Test :: variable cmd_type1:  %lx \n",cmd_type1);
	 cdac_pr_info(DRIVER_NAME ": HDG Test :: Afher change resp_type:  %lx \n",resp_type);
	// cdac_pr_info(DRIVER_NAME ": HDG Test :: variable resp_type-driver:  %lx \n",mmc_resp_type(cmd));
	// cdac_pr_info(DRIVER_NAME ": HDG Test :: variable flag:  %lx \n",flag);
//#endif
	//cdac_pr_info(DRIVER_NAME ": \n\r\n\r\n\r"); 

	reg_value = CDAC_MMC_CMD_INDEX(command) | CDAC_MMC_CMD_ARG(argument) | CDAC_MMC_CMD_TYPE(cmd_type) | CDAC_MMC_RSP_TYPE(resp_type);

	temp = (reg_value & 0x3FFFFFFFC0) >>6;
	//printk("\n C");
	
	//printk("\n\n\n Command:   %ld \n",command); //cdac1
	
	//printk("\n argument:   %lx \n",temp); //cdac1
	
	// cdac_pr_info(DRIVER_NAME ": HDG Test :: CDAC_MMC_CMD command:  %lx \n",CDAC_MMC_CMD_INDEX(command));
	// cdac_pr_info(DRIVER_NAME ": HDG Test :: CDAC_MMC_CMD argument:  %lx \n",CDAC_MMC_CMD_ARG(argument));
	// cdac_pr_info(DRIVER_NAME ": HDG Test :: CDAC_MMC_CMD resp_type:  %lx \n",CDAC_MMC_RSP_TYPE(resp_type));
	// cdac_pr_info(DRIVER_NAME ": HDG Test :: CDAC_MMC_CMD ccmd_type:  %lx \n",CDAC_MMC_CMD_TYPE(cmd_type));

	//cdac_pr_info(DRIVER_NAME "IE %lx \n",__raw_readq(HOST_IE(host)));


	if(reg_value == 0x200EDC00040) // Checking if CMD=6 and Bus width = 1, Right shift value in () by 6 times to chec command.
	{
		//printk("BUS_WIDTH 1-------------------");
		bus_width_1_flag = 1;
	}
	else if(reg_value == 0x200EDC04040) // Checking if CMD=6 and Bus width = 4
	{
		//printk("BUS_WIDTH 4-----NOT SUPPORTED--------------");
		bus_width_4_flag = 1; // Currently unsupported by CDAC EMMC DUT
	}
	else if(reg_value == 0x200edc08046) // Checking if CMD=6 and Bus width = 8
	{
		//printk("BUS_WIDTH 8-------------------");
		bus_width_8_flag = 1;
	}
	
	if(command == 23){

	//printk("\nCMD 23 ************ "); //cdac1
	
		opmodereg_value = __raw_readq(HOST_OP_MODE(host));	
		//printk("Opmode Val BF %lx \n",opmodereg_value);
		opmodereg_value &= ~((UL)1<<38); //Clear OpenEnded transaction bit in EMMC : HDG
		/*if(data){
		    printk("data->blocks %lx \n",data->blocks);
		    opmodereg_value |=((UL)data->blocks << 45);
		}
		else{
		        printk("error- \n");
		        opmodereg_value |=((UL)0);
		    }*/
		    opmodereg_value |=((UL)argument << 45);

		//printk("Opmode Val AF %lx \n",opmodereg_value);
		__raw_writeq(opmodereg_value, HOST_OP_MODE(host));	
	}
	
	if(command == 24){
	// This may be deleted as no of blocks to write for single blk transaction will be updated in H/w.
		opmodereg_value = __raw_readq(HOST_OP_MODE(host));
		opmodereg_value &= 0xE0001FFFFFFFFFFF; // Clears bit from 45 to 60. 
		opmodereg_value = opmodereg_value | (CDAC_MMC_OP_MODE_NUM_BLOCK(1UL))
				| (CDAC_MMC_OP_MODE_LEN_BLOCK(512UL));
		
		
		__raw_writeq(opmodereg_value, HOST_OP_MODE(host));
		//printk("\n24 OPMODE VAL: 0x %lx ",opmodereg_value);
	
	}
		
	/*
	else if(command == 3){

	cdac_pr_info(DRIVER_NAME ":waiting intr %lx \n",reg_value);
		__raw_writeq(0x0000018400000003, HOST_CMD(host)); //writing command and parameters

	}
	
	else if(command == 5){

	cdac_pr_info(DRIVER_NAME ":waiting intr %lx \n",reg_value);
		__raw_writeq(0x0000018400000005, HOST_CMD(host)); //writing command and parameters

	}
	
	else if(command == 7){

	cdac_pr_info(DRIVER_NAME ":waiting intr %lx \n",reg_value);
		__raw_writeq(0x0000028400000007, HOST_CMD(host)); //writing command and parameters

	}
	
	else if(command == 8){

	cdac_pr_info(DRIVER_NAME ":waiting intr %lx \n",reg_value);
		__raw_writeq(0x000001C000000008, HOST_CMD(host)); //writing command and parameters

	}
	
	
		
	else if(command == 9){

	cdac_pr_info(DRIVER_NAME ":waiting intr %lx \n",reg_value);
		__raw_writeq(0x0000038400000009, HOST_CMD(host)); //writing command and parameters

	}*/
	//else{
		__raw_writeq(reg_value, HOST_CMD(host)); //writing command and parameters
	//}
	
	cdac_pr_info(DRIVER_NAME ":reg_value %lx \n",reg_value);
	
	

		
	//cdac_pr_info(DRIVER_NAME ": cmd_reg %lx \n",__raw_readq(HOST_CMD(host)));
	//status_reg_value = __raw_readq(HOST_STATUS(host));
	//cdac_pr_info(DRIVER_NAME ":status_reg_value %lx \n",status_reg_value);
	///while (!(__raw_readq(HOST_STATUS(host)) & (CDAC_MMC_STATUS_CMD_SENT))); //waiting for command to be sent
	
	
	// reg_value = HOST_LWR_CSD(host);
	
	// cdac_pr_info(DRIVER_NAME ":Low Resp Reg %lx \n",reg_value);
	
	// reg_value = HOST_UPR_CSD(host);
	
	// cdac_pr_info(DRIVER_NAME ":Upp Resp Reg %lx \n",reg_value);
	
	
	//cdac_pr_info(DRIVER_NAME ":cdac_mmc_CMD_SENT\n");
//cdac_pr_info(DRIVER_NAME ":cdac_mmc_send_command end\n");cdac_mmc_send_command

//int_status = __raw_readq(HOST_INTERRUPT_STATUS(host));
//	cdac_pr_info(DRIVER_NAME ": Interrupt Status %lx \n",int_status);
	//Transmit_uart("\n\r  CMD SENT !!! ");
//status_reg_value = __raw_readq(HOST_STATUS(host));
//cdac_mmc_cmd_complete(host, status_reg_value);

	cdac_pr_info(DRIVER_NAME ": ***** AF OPMODE REG VAL %lx \n",__raw_readq(HOST_OP_MODE(host)));
			//printk(":SC_END");
	return 0;

}

static void cdac_mmc_data_complete(struct cdac_mmc_host *host, UI status) {
	struct mmc_request *mrq = host->mrq;
	struct mmc_data *data;
	UI crc;
	cdac_pr_info(DRIVER_NAME ":cdac_mmc_data_complete\n");
	//WARN_ON((host->status != HOST_S_DATA) && (host->status != HOST_S_STOP));

	if (host->mrq == NULL)
		return;

	data = mrq->cmd->data;

	//if (status == 0)
	//	status = __raw_readq(HOST_STATUS(host));
		
	cdac_printk("***** aaa *********");

	/* The transaction is really over when the SD_STATUS_DB bit is clear */
	//	while ((host->flags & HOST_F_XMIT) && (status & SD_STATUS_DB))
	//status = __raw_readq(HOST_STATUS(host));
	
	cdac_printk("***** BBB *********");

	data->error = 0;
	//dma_unmap_sg(mmc_dev(host->mmc), data->sg, data->sg_len, host->dma.dir);

	/* Process any errors */
	//crc = (status & (SD_STATUS_WC | SD_STATUS_RC));
	/*if (host->flags & HOST_F_XMIT)
		crc |= ((status & 0x07) == 0x02) ? 0 : 1;

	if (crc){
		printk("CRC :error%d\n",crc);
		data->error = -EILSEQ;
		}
		
	cdac_printk("CRC :%d",crc);*/
		
	cdac_printk("***** CCC *********");

	/* Clear the CRC bits */
	//__raw_writeq(SD_STATUS_WC | SD_STATUS_RC, HOST_STATUS(host));
	//data->bytes_xfered = 0;

	if (!data->error) {
	
		//data->bytes_xfered = (data->blocks * data->blksz) - host->pio.len;
		//printk("data->bytes_xfered :%d",data->bytes_xfered);
	}
	
	cdac_printk("***** DDD *********");

	cdac_mmc_finish_request(host);
	
	cdac_printk("***** EEE *********");
}

static void cdac_mmc_tasklet_data(unsigned long param) {
	struct cdac_mmc_host *host = (struct cdac_mmc_host*) param;
	cdac_pr_info(DRIVER_NAME ":cdac_mmc_tasklet_data\n");
	UI status;
	cdac_mmc_data_complete(host, status);
}

#define CDAC_MMC_MAX_TRANSFER 64



static void cdac_emmc_push_data(struct cdac_mmc_host *host, void *buf, int cnt){

	UL tx_mem_phy_addr;
	UL wTempCtrlVal = 0;
	volatile unsigned long *tx_memory;
	tx_memory = (unsigned long *)kmalloc(cnt, GFP_KERNEL);
	tx_mem_phy_addr = virt_to_phys(tx_memory);
	UI status;
	UI i;
	
	//printk("*******tx_mem_phy_addr %lx",tx_mem_phy_addr);
	
	/*printk("*******TX DATA");
	for(i=0;i<64;i++)
	{
	 printk("\n %lx",tx_memory[i*8]);
	}*/
	
	memcpy(tx_memory,buf,cnt);
	//memcpy(gTx_memory,tx_memory,host->pio.len);
#ifdef SINGLE_CORE_EMMC	
	write_csr(0x5c8,1); // flush data

	
#endif	
	/************DMA ROUTINE**************/

	__raw_writeq(tx_mem_phy_addr, DMA_CH0_SRC_ADDR_REG(host));
	__asm__ __volatile__ ("fence");
	
	__raw_writeq((EHC_BASE_ADDRESS + WR_DATA_FIFO), DMA_CH0_DST_ADDR_REG(host));
	__asm__ __volatile__ ("fence");

	__raw_writeq(0, DMA_CH0_LLI_REG(host));
	__asm__ __volatile__ ("fence");
	
#ifdef SINGLE_CORE_EMMC

	Init_DMA_Ch_CtrlReg_params_sram_to_sram
		(DCE_ENABLE, CIE_ENABLE, SRC_DW_128, DST_DW_128,DAI_DISABLE,\
				SAI_ENABLE, CBE_ENABLE, CMS_AXI2AXI, CTS_16, CBS_2);
	wTempCtrlVal = gDMAtransfer.Control.dword;

#endif
#ifdef DUAL_CORE_EMMC
	wTempCtrlVal = 0;
	/*Init_DMA_Ch_CtrlReg_params_sram_to_sram
	(DCE_ENABLE, CIE_ENABLE, SRC_DW_128, DST_DW_128,DAI_DISABLE,\
			SAI_ENABLE, CBE_ENABLE, CMS_AXI2ACE, CTS_16, CBS_2);*/
			
	Init_DMA_Ch_CtrlReg_params_sram_to_sram
	(DCE_ENABLE, CIE_ENABLE, SRC_DW_128, DST_DW_128,DAI_DISABLE,\
			SAI_ENABLE, CBE_ENABLE, CMS_ACE2AXI, CTS_16, CBS_2);
			
			
	wTempCtrlVal = gDMAtransfer.Control.dword;
	
#endif
	__raw_writeq(wTempCtrlVal, DMA_CH0_CTRL_STATUS_REG(host));

	
	//pr_info(DRIVER_NAME ": DMA Transfer Completed\n");

	/************DMA ROUTINE END**************/
	
	Check_DMAC_transferDone(host,0);
	kfree(tx_memory);
			//printk("Check_DMAC_transferDone *******  \n");
	status = __raw_readq(HOST_STATUS(host));
	if (status & CDAC_MMC_STATUS_WTRANS_TMOUT_ERR) {
		DBG("Write transaction timeout error [%d + %d]\n", host->pdev->id, host->pio.len,
				count);
		return;
	}

}


void cdac_mmc_send_pio(struct cdac_mmc_host *host) {
	int i;
	struct mmc_data *data;
	int sg_len, max, count;
	unsigned char  val;
	volatile unsigned char *sg_ptr = NULL;
	UL status;
	unsigned long reg_val = 0;
	struct scatterlist *sg;
	
	static volatile void *buf;
	unsigned int offset;
	unsigned int len;
	//unsigned int fifo_depth = host->fifo_depth;
	unsigned int remain, fcnt;

	
	//pr_info(DRIVER_NAME ":cdac_mmc_send_pio\n");//cdac
	
	
	
	if (!(host->flags & HOST_F_XMIT))
		return;
		
			//pr_info(DRIVER_NAME ":cdac_mmc_send_pio 2\n");//cdac
		
	
	//printk("\n\r host->mrq->data 0x%lx\n",&host->mrq->data);	
	data = host->mrq->data;	
		
		/* This is the pointer to the data buffer */
	//sg = data->sg;
	//sg_ptr = kmap_atomic(sg_page(sg));

	cdac_printk("data->sg[host->pio.index].length %lx",data->sg[host->pio.index].length);
	cdac_printk("host->pio.offset %lx:", host->pio.offset);
	cdac_printk("sg_len %lx",sg_len);
	cdac_printk("host->pio.len %lx",host->pio.len);

		//pr_info(DRIVER_NAME ":cdac_mmc_send_pio 1\n");//cdac
	
	/*#######################################*/
	
	UI no_of_blks = 0;

	//memcpy(gTx_memory,tx_memory,host->pio.len);
	


	remain = host->pio.len;
	offset = 0;
	
	//sg = &data->sg[host->pio.index];
	sg = data->sg;
	sg_ptr = kmap_atomic(sg_page(sg)) + sg->offset;
	buf = sg_ptr;
	
		//printk("sg->offset %lx\n",sg->offset);

	do {
		fcnt = 512;
		len = min(remain, fcnt);
		if (!len)
			break;
		//while((__raw_readq(HOST_STATUS(host)) & CDAC_MMC_STATUS_WDATA_FIFO_FULL) == 1);
		
	
			
		cdac_emmc_push_data(host, (void *)(buf + offset), len);
		data->bytes_xfered += len;
		offset += len;
		remain -= len;
		//printk("Send Remain******* %d \n",remain);
		if(remain)
			while((__raw_readq(HOST_STATUS(host)) & CDAC_MMC_STATUS_WDATA_FIFO_EMP) == 0);
			
		//printk("Send Remain dddd******* %d \n",remain);


	} while (remain);
		
	//kfree(tx_memory);
	kunmap_atomic(sg_ptr);
	//IRQ_OFF(host, SD_CONFIG_TH); //Disable FIFO empty interrupt
	IRQ_OFF(host,CDAC_MMC_INTR_EN_WR_DATA_FIFO_EMPTY_INTR);

	if (host->flags & HOST_F_STOP)
		SEND_STOP(host); //FIXME

	//printk("\n\rafter send stop%lx\n");	

	tasklet_schedule(&host->data_task);

}
/*
void cdac_mmc_send_pio_sgr(struct cdac_mmc_host *host) {
	struct mmc_data *data;
	int sg_len, max, count;
	unsigned char  val;
	unsigned char *sg_ptr = NULL;
	UL status;
	unsigned long reg_val = 0;
	struct scatterlist *sg;
	
	cdac_pr_info(DRIVER_NAME ":cdac_mmc_send_pio_sgr\n");
	
	if (!(host->flags & HOST_F_XMIT))
		return;
		
			
	data = host->mrq->data;	
		
		/* This is the pointer to the data buffer */
/*	sg = &data->sg[host->pio.index];
	sg_ptr = kmap_atomic(sg_page(sg)) + sg->offset + host->pio.offset;
	cdac_printk("sg->offset %lx",sg->offset);
	cdac_printk("data->sg[host->pio.index].length %lx",data->sg[host->pio.index].length);
	cdac_printk("host->pio.offset %lx:", host->pio.offset);
	cdac_printk("sg_len %lx",sg_len);
	cdac_printk("host->pio.len %lx",host->pio.len);

	
	
	/*#######################################*/
	
/*	UI no_of_blks = 0;
	UL tx_mem_phy_addr;
	volatile unsigned long *tx_memory;
	tx_memory=(unsigned long *)kmalloc((host->pio.len), GFP_KERNEL);
	tx_mem_phy_addr = virt_to_phys(tx_memory);
	
	memcpy(tx_memory,sg_ptr,host->pio.len);
#ifdef SINGLE_CORE_EMMC	
	write_csr(0x5c8,1); // flush data
#endif	
	/************DMA ROUTINE**************/
/*	UL wTempCtrlVal = 0;

	__raw_writeq(tx_mem_phy_addr, DMA_CH0_SRC_ADDR_REG(host));
	__asm__ __volatile__ ("fence");
	
	__raw_writeq((EHC_BASE_ADDRESS + WR_DATA_FIFO), DMA_CH0_DST_ADDR_REG(host));
	__asm__ __volatile__ ("fence");

	__raw_writeq(0, DMA_CH0_LLI_REG(host));
	__asm__ __volatile__ ("fence");
	
#ifdef SINGLE_CORE_EMMC

	Init_DMA_Ch_CtrlReg_params_sram_to_sram
		(DCE_ENABLE, CIE_ENABLE, SRC_DW_128, DST_DW_128,DAI_DISABLE,\
				SAI_ENABLE, CBE_ENABLE, CMS_AXI2AXI, CTS_16, CBS_2);
	wTempCtrlVal = gDMAtransfer.Control.dword;

#endif
#ifdef DUAL_CORE_EMMC
	wTempCtrlVal = 0;
	Init_DMA_Ch_CtrlReg_params_sram_to_sram
	(DCE_ENABLE, CIE_ENABLE, SRC_DW_128, DST_DW_128,DAI_DISABLE,\
			SAI_ENABLE, CBE_ENABLE, CMS_AXI2ACE, CTS_16, CBS_2);
	wTempCtrlVal = gDMAtransfer.Control.dword;
	//Transmit_uart("\n\r DMA wTempCtrlVal : 0x ");disp_Rx_data_UL(wTempCtrlVal);
	cdac_pr_info(DRIVER_NAME "SR_DMA wTempCtrlVal : 0x  0x %lx \n",wTempCtrlVal);

#endif
	__raw_writeq(wTempCtrlVal, DMA_CH0_CTRL_STATUS_REG(host));

	
	cdac_pr_info(DRIVER_NAME ": DMA Transfer Completed\n");

	/************DMA ROUTINE END**************/
	/*#######################################*/
	
	
/*	if (status & CDAC_MMC_STATUS_WDATA_FIFO_FULL)
		return; // Write data FIFO is FULL


	if (status & CDAC_MMC_STATUS_WTRANS_TMOUT_ERR) {
		DBG("Write transaction timeout error [%d + %d]\n", host->pdev->id, host->pio.len,
				count);
		return;
	}
	
	Check_DMAC_transferDone(host,0);
	__asm__ __volatile__ ("fence");




	/* This is the space left inside the buffer */
/*	sg_len = data->sg[host->pio.index].length - host->pio.offset;
	cdac_printk("AFTER TRASFER");
	cdac_printk("data->sg[host->pio.index].length %lx",data->sg[host->pio.index].length);
	cdac_printk("host->pio.offset %lx:", host->pio.offset);
	cdac_printk("sg_len %lx",sg_len);
	cdac_printk("host->pio.len %lx",host->pio.len);
	reg_val = __raw_readq(HOST_STATUS(host));
	cdac_printk("HOST_STATUS VAL: 0x %lx bytes",reg_val);

	/* Check if we need less than the size of the sg_buffer */
	//max = (sg_len > host->pio.len) ? host->pio.len : sg_len;
	//if (max > CDAC_MMC_MAX_TRANSFER)
	//	max = CDAC_MMC_MAX_TRANSFER;
		
	//cdac_printk(" host->pio.len %lx:",  host->pio.len);
	//cdac_printk(" max %lx:",  max);
	
/*	kfree(tx_memory);

/*
	for (count = 0; count < max; count++) {
	
		cdac_printk("count %lx",count);
		status = __raw_readq(HOST_STATUS(host));
		cdac_printk("status %lx",status);
		

		if ((status & CDAC_MMC_STATUS_WFIFO_FULL)) //checks whether WFIFO is full
			break;

		val = sg_ptr[count];
		
		cdac_printk("val %lx",val);

		__raw_writeq((unsigned long) val, HOST_WR_DATA_FIFO(host));
		wmb(); /* drain writebuffer */
	//}
	
/*	kunmap_atomic(sg_ptr);

	//host->pio.len -= count;
	//host->pio.offset += count;
	
	host->pio.len -= 512;
	host->pio.offset += 512;
	
	
	
	//host->pio.offset += host->pio.len;
	//host->pio.len = 0;

	/*if (count == sg_len) {
		host->pio.index++;
		host->pio.offset = 0;
	}*/
	
/*	if (host->pio.len == 0) {
		IRQ_OFF(host,CDAC_MMC_INTR_EN_WR_DATA_FIFO_EMPTY_INTR);

		if (host->flags & HOST_F_STOP)
			SEND_STOP(host); //FIXME

		tasklet_schedule(&host->data_task);
		cdac_printk("Tx Complete Set*******");
		return;
	}	


}*/

/*
static void cdac_mmc_send_pio_old(struct cdac_mmc_host *host) {
	struct mmc_data *data;
	int sg_len, max, count;
	unsigned char *sg_ptr, val;
	UL status;
	struct scatterlist *sg;
	cdac_pr_info(DRIVER_NAME ":cdac_mmc_send_pio\n");
	data = host->mrq->data;
	
	if (!(host->flags & HOST_F_XMIT))
		return;
	
	/* This is the pointer to the data buffer */
/*	sg = &data->sg[host->pio.index];
	sg_ptr = kmap_atomic(sg_page(sg)) + sg->offset + host->pio.offset;
	
	
	
	cdac_printk("sg->offset %lx",sg->offset);
	


	/* This is the space left inside the buffer */
/*	sg_len = data->sg[host->pio.index].length - host->pio.offset;
	cdac_printk("data->sg[host->pio.index].length %lx",data->sg[host->pio.index].length);
	cdac_printk("host->pio.offset %lx:", host->pio.offset);
	cdac_printk("sg_len %lx",sg_len);
	cdac_printk("host->pio.len %lx",host->pio.len);

	/* Check if we need less than the size of the sg_buffer */
/*	max = (sg_len > host->pio.len) ? host->pio.len : sg_len;
	if (max > CDAC_MMC_MAX_TRANSFER)
		max = CDAC_MMC_MAX_TRANSFER;
		
	cdac_printk(" host->pio.len %lx:",  host->pio.len);
	cdac_printk(" max %lx:",  max);

	for (count = 0; count < max; count++) {
	
		cdac_printk("count %lx",count);
		status = __raw_readq(HOST_STATUS(host));
		cdac_printk("status %lx",status);
		

		if ((status & CDAC_MMC_STATUS_WFIFO_FULL)) //checks whether WFIFO is full
			break;

		val = sg_ptr[count];
		
		cdac_printk("val %lx",val);

		__raw_writeq((unsigned long) val, HOST_WR_DATA_FIFO(host));
		wmb(); /* drain writebuffer */
/*	}
	kunmap_atomic(sg_ptr);

	host->pio.len -= count;
	host->pio.offset += count;

/*	if (count == sg_len) {
		host->pio.index++;
		host->pio.offset = 0;
	}

	if (host->pio.len == 0) {
		//IRQ_OFF(host, SD_CONFIG_TH); //Disable FIFO empty interrupt
		IRQ_OFF(host,CDAC_MMC_INTR_EN_WR_DATA_FIFO_EMPTY_INTR);

		if (host->flags & HOST_F_STOP)
			SEND_STOP(host); //FIXME

		tasklet_schedule(&host->data_task);
	}
}*/



static void cdac_emmc_pull_data(struct cdac_mmc_host *host, void *buf, int cnt){

	volatile unsigned long *rx_memory;
	u64 rx_mem_phy_addr;
	u64 wTempCtrlVal = 0;

	rx_memory = (unsigned long *)kmalloc(cnt, GFP_KERNEL);
	rx_mem_phy_addr = virt_to_phys(rx_memory);

	/************DMA ROUTINE**************/

	__raw_writeq((EHC_BASE_ADDRESS + 0xD0), DMA_CH0_SRC_ADDR_REG(host));
	__asm__ __volatile__ ("fence");
	
	__raw_writeq(rx_mem_phy_addr, DMA_CH0_DST_ADDR_REG(host));
	__asm__ __volatile__ ("fence");

	__raw_writeq(0, DMA_CH0_LLI_REG(host));
	__asm__ __volatile__ ("fence");
	
#ifdef SINGLE_CORE_EMMC
	Init_DMA_Ch_CtrlReg_params_sram_to_sram
		(DCE_ENABLE, CIE_ENABLE, SRC_DW_128, DST_DW_128,DAI_ENABLE,\
				SAI_DISABLE, CBE_ENABLE, CMS_AXI2AXI, CTS_16, CBS_2);
	wTempCtrlVal = gDMAtransfer.Control.dword;

#endif
#ifdef DUAL_CORE_EMMC
	wTempCtrlVal = 0;
	/*Init_DMA_Ch_CtrlReg_params_sram_to_sram
	(DCE_ENABLE, CIE_ENABLE, SRC_DW_128, DST_DW_128,DAI_ENABLE,\
			SAI_DISABLE, CBE_ENABLE, CMS_AXI2ACE, CTS_16, CBS_2);*/
			
			
	Init_DMA_Ch_CtrlReg_params_sram_to_sram
	(DCE_ENABLE, CIE_ENABLE, SRC_DW_128, DST_DW_128,DAI_ENABLE,\
			SAI_DISABLE, CBE_ENABLE, CMS_AXI2ACE, CTS_16, CBS_2);
			
	wTempCtrlVal = gDMAtransfer.Control.dword;
	//Transmit_uart("\n\r DMA wTempCtrlVal : 0x ");disp_Rx_data_UL(wTempCtrlVal);
	cdac_pr_info(DRIVER_NAME "SR_DMA wTempCtrlVal : 0x  0x %lx \n",wTempCtrlVal);

#endif
	__raw_writeq(wTempCtrlVal, DMA_CH0_CTRL_STATUS_REG(host));

	Check_DMAC_transferDone(host,0);
	__asm__ __volatile__ ("fence");

	//printk("RR: DMA Transfer Completed\n");

	/************DMA ROUTINE END**************/
	
#ifdef SINGLE_CORE_EMMC	
	write_csr(0x5c8,1); // flush data

#endif

	memcpy(buf, rx_memory, cnt);
	//printk("RR: DMA Transfer Completed 11\n");
//	memcpy(gRx_memory, rx_memory, host->pio.len);
	
	kfree(rx_memory);
		//printk("RR: DMA Transfer Completed 22\n");

}


void cdac_mmc_receive_pio(struct cdac_mmc_host *host) {

	int i;
	struct mmc_data *data;
	int max,rx_len, count, sg_len = 0;
	volatile unsigned char *sg_ptr = NULL;
	UI status, val,no_of_blks = 0;
	UL reg_value,rx_mem_phy_addr;
	struct scatterlist *sg;
	//pr_info(DRIVER_NAME ":cdac_mmc_receive_pio\n");
	data = host->mrq->data;
	unsigned int len;
	static volatile void *buf;
	unsigned int remain, fcnt;
	unsigned int offset;


	
	no_of_blks = data->blocks;
	//printk("No of Blks:%d %d\n",no_of_blks, data->blksz);
	

	// sg = data->sg;
	 
	remain = host->pio.len;
	offset = 0;
	
	//sg = &data->sg[host->pio.index];
	sg = data->sg;
	sg_ptr = kmap_atomic(sg_page(sg)) + sg->offset;
	buf = sg_ptr;	

	//printk("\n pull sg->offset %lx",sg->offset);
	do {
			fcnt = 512;
			len = min(remain, fcnt);
			if (!len)
				break;
			//while((__raw_readq(HOST_STATUS(host)) & CDAC_MMC_STATUS_BLK_RX_AVILABLE) == 0);


			status = __raw_readq(HOST_STATUS(host));
			
			//if (status & CDAC_MMC_STATUS_BOOT_FIFO_EMP)
			//	return; ///Stop copying Rx data if Rx FIFO is empty

			if (status & CDAC_MMC_STATUS_RX_CRC_ERR) {
				DBG("RX CRC Error [%d + %d].\n", host->pdev->id, host->pio.len, count);
				return;
			}

			if (status & CDAC_MMC_STATUS_RDATA_END_BIT_ERR) {
				DBG("Rd data end bit error [%d + %d]\n", host->pdev->id, host->pio.len,
						count);
				return;
			}

			if (status & CDAC_MMC_STATUS_RD_TRANSN_TIMEOUT_ERR) {
				DBG("RD transaction TIMEOUT [%d + %d]\n", host->pdev->id, host->pio.len,
						count);
				return;
			}


	
			cdac_emmc_pull_data(host, (void *)(buf + offset), len);
			data->bytes_xfered += len;
			offset += len;
			remain -= len;
			//printk("Receive remain****** \n");
			if(remain)
				while((__raw_readq(HOST_STATUS(host)) & CDAC_MMC_STATUS_BOOT_FIFO_EMP));
			//printk("Receive remain dddd******\n");


		} while (remain);

	
	

	if (!(host->flags & HOST_F_RECV))
		return;


	kunmap_atomic(sg_ptr);

	

	//memcpy(gRx_memory, rx_memory, host->pio.len);
	
	//printk("RX DATA*******");
	for(i=0;i<64;i++)
	{
	// printk("\n %lx",rx_memory[i*8]);
	}
	
	//printk("\n NEXT READ " );
	
	/*for (count = 0; count < rx_len; count++) 
	{
 		cdac_printk("%02x",sg_ptr[count]); // HDG: Prints value to UART 

 		if((count % 8) == 0)
 			cdac_pr_info("\n");

	}*/
	
	//kfree(rx_memory);
		
	/*if (sg_ptr)
	{
		kunmap_atomic(sg_ptr);
	}*/

	host->pio.index = 0;

	//pr_info(DRIVER_NAME "II********\n");
	IRQ_OFF(host, CDAC_MMC_INTR_EN_NUM_BLK_AVL_BOOT_FIFO_INTR); 
	if (host->flags & HOST_F_STOP)
		SEND_STOP(host);

	tasklet_schedule(&host->data_task);
	
}

/*
static void cdac_mmc_receive_pio(struct cdac_mmc_host *host) {
	struct mmc_data *data;
	int rx_len, count, sg_len = 0;
	unsigned char *sg_ptr = NULL;
	UI status, val;
	UL reg_value;
	struct scatterlist *sg;
	cdac_pr_info(DRIVER_NAME ":cdac_mmc_receive_pio\n");
	data = host->mrq->data;

	if (!(host->flags & HOST_F_RECV))
		return;

	///max = host->pio.len;

	/*if (host->pio.index < host->dma.len) {
	 sg = &data->sg[host->pio.index];
	 sg_ptr = kmap_atomic(sg_page(sg)) + sg->offset + host->pio.offset;

	 /// This is the space left inside the buffer
	 sg_len = sg_dma_len(&data->sg[host->pio.index]) - host->pio.offset;

	 /// Check if we need less than the size of the sg_buffer
	 if (sg_len < max)
	 max = sg_len;
	 }

	 if (max > CDAC_MMC_MAX_TRANSFER)
	 max = CDAC_MMC_MAX_TRANSFER;*/

/*	status = __raw_readq(HOST_STATUS(host));
	
	reg_value = __raw_readq(HOST_STATUS(host));
	
	cdac_pr_info(DRIVER_NAME "HOST STATUS data  0x %lx \n",reg_value);

	if (status & CDAC_MMC_STATUS_BOOT_FIFO_EMP)
		return; ///Stop copying Rx data if Rx FIFO is empty

	if (status & CDAC_MMC_STATUS_RX_CRC_ERR) {
		DBG("RX CRC Error [%d + %d].\n", host->pdev->id, host->pio.len, count);
		return;
	}

	if (status & CDAC_MMC_STATUS_RDATA_END_BIT_ERR) {
		DBG("Rd data end bit error [%d + %d]\n", host->pdev->id, host->pio.len,
				count);
		return;
	}

	if (status & CDAC_MMC_STATUS_RD_TRANSN_TIMEOUT_ERR) {
		DBG("RD transaction TIMEOUT [%d + %d]\n", host->pdev->id, host->pio.len,
				count);
		return;
	}

	///rx_len = read from ststus register * 512;

	//Call DMA function to copy rx_len bytes of data

	/*for (count = 0; count < max; count++) {

	 val = __raw_readq(HOST_RD_DATA_FIFO(host));

	 if (sg_ptr)
	 sg_ptr[count] = (unsigned char) (val & 0xFF);
	 }*/
	 
/*	if (sg_ptr)
		kunmap_atomic(sg_ptr);

	host->pio.len -= count;
	host->pio.offset += count;

	if (sg_len && count == sg_len) {
		host->pio.index++;
		host->pio.offset = 0;
	}

	if (host->pio.len == 0) {
		/* IRQ_OFF(host, SD_CONFIG_RA | SD_CONFIG_RF); */
		//		IRQ_OFF(host, SD_CONFIG_NE); //Disable Rx FIFO not empt bit in Interrupt enable register
/*		IRQ_OFF(host, CDAC_MMC_INTR_EN_NUM_BLK_AVL_BOOT_FIFO_INTR); 
		if (host->flags & HOST_F_STOP)
			SEND_STOP(host);

		tasklet_schedule(&host->data_task);
	}
}*/

/* This is called when a command has been completed - grab the response
 * and check for errors.  Then start the data transfer if it is indicated.
 */
void cdac_mmc_cmd_complete(struct cdac_mmc_host *host) {

	struct mmc_request *mrq = host->mrq;
	struct mmc_command *cmd;
	UL r[4],dUpper_resp = 0,dLower_resp = 0,status = 0;
	int i, trans;
	unsigned long response = 0;
	
	//printk("\n t");
		
	if (!host->mrq)
		return;

	cmd = mrq->cmd;
	
	

	UL cmd_reg_value = __raw_readq(HOST_CMD(host));


	if (((cmd_reg_value >> 40) & 0x03) != CDAC_MMC_RSP_NONE) {
	


	while(1)
	{	
		//cdac_printk("I");
		status = __raw_readq(HOST_STATUS(host));
		if(status & CDAC_MMC_STATUS_CMD_RSP_TO_ERR){
		printk("CMD: %d\n",cmd->opcode);
			pr_info(DRIVER_NAME "####Resp Timeout Occured");
			host->status = HOST_S_DATA;
			cmd->error = -1;
			break;
		}
		if (status & CDAC_MMC_STATUS_RSP_RXD)
		{
			//response =  (__raw_readq(HOST_LWR_RSP(host)));
			//printk("\n LResp 0x: %lx\n",response);
			//response =  (__raw_readq(HOST_UPR_RSP(host)));
			//printk("\n UResp 0x: %lx\n",response);
			break;
		}

	}
	
			
		if (status & CDAC_MMC_STATUS_RSP_RXD) {
			cdac_pr_info(DRIVER_NAME ":BBB \n" );
			 if (((cmd_reg_value >> 40) & 0x03) == CDAC_MMC_RSP_136){
				//cdac_pr_info(DRIVER_NAME ":DDD \n" );
				/* original code
				cmd->resp[0] = (__raw_readq(HOST_LWR_RSP(host))& 0xFFFFFFFF);
				cmd->resp[1] = (__raw_readq(HOST_LWR_RSP(host)) >>32);
				cmd->resp[2] = (__raw_readq(HOST_UPR_RSP(host))& 0xFFFFFFFF); 
				cmd->resp[3] = (__raw_readq(HOST_UPR_RSP(host)) >>32); 
				*/	

				dLower_resp =  (__raw_readq(HOST_LWR_RSP(host)));
				// Below code used for testing: HDG
				r[3] = (UI)(dLower_resp& 0xFFFFFFFF);
				r[2] = (UI)(dLower_resp >>32);
				
				//cdac_pr_info(DRIVER_NAME "####dUpper_resp  %lx \n",dUpper_resp );
				
		
				dUpper_resp  = (__raw_readq(HOST_UPR_RSP(host)));			
				//cdac_pr_info(DRIVER_NAME "####as such dUpper_resp %lx \n",dUpper_resp );
				
				//dUpper_resp  = (dUpper_resp << 8);				
				//cdac_pr_info(DRIVER_NAME "####shifted by 8 dUpper_resp %lx \n",dUpper_resp );
				
				r[1] = (UI)(dUpper_resp & 0xFFFFFFFF); 
				//cdac_pr_info(DRIVER_NAME "####as such dUpper_resp LSB %lx \n",cmd->resp[2] );
				
				r[0] = (UI)(dUpper_resp >>32); 
				//cdac_pr_info(DRIVER_NAME "####as such dUpper_resp MSB %lx \n",cmd->resp[3] );
				
				/* The CRC is omitted from the response, so really
				 * we only got 120 bytes, but the engine expects
				 * 128 bits, so we have to shift things up.
				 */
				for (i = 0; i < 4; i++) {
					cmd->resp[i] = (r[i] & 0x00FFFFFF) << 8;
					if (i != 3)
						cmd->resp[i] |= (r[i + 1] & 0xFF000000) >> 24;
				}

			}
			else
			{
				cdac_pr_info(DRIVER_NAME ":CCC \n" );
				cmd->resp[0] = (UI)(__raw_readq(HOST_LWR_RSP(host))& 0xFFFFFFFF);
				cmd->resp[1] = 0;//(UI)(__raw_readq(HOST_LWR_RSP(host)) >>32);
				cmd->resp[2] = 0;
				cmd->resp[3] = 0;

			}
			//#ifdef DEBUG	
			/*if(cmd->opcode == 13)
			{
			pr_info(DRIVER_NAME ":cmd->resp[0]  %lx \n",cmd->resp[0] );
			pr_info(DRIVER_NAME ":cmd->resp[1]  %lx \n",cmd->resp[1] );
			pr_info(DRIVER_NAME ":cmd->resp[2]  %lx \n",cmd->resp[2] );
			pr_info(DRIVER_NAME ":cmd->resp[3]  %lx \n",cmd->resp[3] );
			}*/
			//#endif
		}
	}

	/* Figure out errors */
	/*if (status & (CDAC_MMC_STATUS_CMD_RSP_TXN_ERR | CDAC_MMC_STATUS_CMD_RSP_END_ERR
					| CDAC_MMC_STATUS_CMD_RSP_TO_ERR))
					

	cmd->error = -EILSEQ;*/

	trans = host->flags & (HOST_F_XMIT | HOST_F_RECV);
	
	cdac_printk("Status:0x %lx", status);

	command_complete_flag = 1; //command complete

	if (!trans || cmd->error) {
	
		
		//printk("cmd finish %d %x %x\n", cmd->opcode, host->flags, cmd->error);
		//printk("Trans:0x %lx", trans);
		//	IRQ_OFF(host, SD_CONFIG_TH | SD_CONFIG_RA | SD_CONFIG_RF);
		tasklet_schedule(&host->finish_task);
		//printk("END ");
		return;
	}
	


	host->status = HOST_S_DATA;

	/*if ((host->flags & (HOST_F_DMA | HOST_F_DBDMA))) {
		//UI channel = DMA_CHANNEL(host);

		/* Start the DBDMA as soon as the buffer gets something in it */

		/*if (host->flags & HOST_F_RECV) {
			//			UI mask = SD_STATUS_DB | SD_STATUS_NE;

			//		while ((status & mask) != mask)
			//status = __raw_readq(HOST_STATUS(host));
		}

		//	cdac_xx_dbdma_start(channel);
	}*/

}

static void cdac_mmc_set_clock(struct cdac_mmc_host *host, int rate) {
	unsigned int pbus = clk_get_rate(host->clk);
	unsigned int divisor = ((pbus / rate) / 2) - 1;
	UI config;
	cdac_pr_info(DRIVER_NAME ":cdac_mmc_set_clock\n");
	
	if(rate == 450000)
	{
		__raw_writeq(OP_FREQ_400KHz, HOST_OP_FREQ(host));
		//printk(": EMMC Freq %lx \n",__raw_readq(HOST_OP_FREQ(host))); 	//HDG:OK
	}
	
	else if(rate == 24000000)
	{
		__raw_writeq(OP_FREQ_25MHz, HOST_OP_FREQ(host));
		//printk(": Freq %lx \n",__raw_readq(HOST_OP_FREQ(host))); 	//HDG:OK
	}
	
	else
	{
		//printk(":Other Clock Frequency\n");
		//printk("clk freq: %ld Hz \n",rate);

	}
	//config = __raw_readq(HOST_CONFIG(host));

	//	config &= ~(SD_CONFIG_DIV);
	//config |= (divisor & SD_CONFIG_DIV) | SD_CONFIG_DE;

//		__raw_writeq(config, HOST_CONFIG(host));
	wmb(); /* drain writebuffer */
}

static int cdac_mmc_prepare_data(struct cdac_mmc_host *host,
		struct mmc_request *mrq) {
		
	struct mmc_data *data = mrq->data;

	int datalen = data->blocks * data->blksz;
	unsigned long reg_value;

	cdac_pr_info(DRIVER_NAME "cdac_mmc_prepare_data\n");
			
	host->mrq = mrq;
	
	//printk("No of Data Blocks req from Driver: 0x %lx",data->blocks); //cdac1
	cdac_printk("Blk Size from Driver: 0x %lx bytes",data->blksz);
	
	//printk("Data Blks:%d %d\n",data->blocks, data->blksz);

	if (data->flags & MMC_DATA_READ)
	{
		//cdac_printk("AAAAAAA/////////");
		host->flags |= HOST_F_RECV;
	}
	else
	{
		//cdac_printk("BBBBBBB/////////");
		host->flags |= HOST_F_XMIT;
	}

	//cdac_printk("CCCCCCCCc/////////");
	
	cdac_printk("host->mrq->stop ADDR:0x %lx",&(host->mrq->stop));
	if (host->mrq->stop){

	
		//printk("host->flags ADDR:0x %lx",&(host->flags));
	
	
		host->flags |= HOST_F_STOP;
	}
		
	//cdac_printk("DDDDDDDDD/////////");

/*	reg_value = __raw_readq(HOST_OP_MODE(host));
	
	cdac_printk("Before clearing OPMODE VAL: 0x %lx bytes",reg_value);
	
	/*reg_value &= 0xFFFFFFFF00FFFFFF;
	
	cdac_printk("After clearing OPMODE VAL: 0x %lx bytes",reg_value);

	if (data->blocks > 255) {

		reg_value = reg_value | (CDAC_MMC_OP_MODE_NUM_BLOCK(255))
				| (CDAC_MMC_OP_MODE_LEN_BLOCK(data->blksz));
	} else {

		reg_value = reg_value | (CDAC_MMC_OP_MODE_NUM_BLOCK(data->blocks))
				| (CDAC_MMC_OP_MODE_LEN_BLOCK(data->blksz));

	}

	reg_value = reg_value | ((UL)(1<<41)); // Total number of frames in FIFO to be interrupted.
	__raw_writeq(reg_value, HOST_OP_MODE(host));
	
	cdac_printk("After writing NEW OPMODE VAL: 0x %lx bytes",reg_value);
*/
	host->pio.index = 0;
	host->pio.offset = 0;
	host->pio.len = datalen;
	
	//cdac_printk("BBBBBBB/////////");

	if (host->flags & HOST_F_XMIT)
	{
		//IRQ_ON(host, SD_CONFIG_TH); ///Enable intr for Tx FIFO Empty
		cdac_pr_info(DRIVER_NAME "Tx Intr...\n");	
		IRQ_ON(host, CDAC_MMC_INTR_EN_WR_DATA_FIFO_EMPTY_INTR); //Write blocks transmitted
		cdac_pr_info(DRIVER_NAME "ON\n");	
	}
	else if (host->flags & HOST_F_RECV)
	{
		//printk("\n Prepare Data: Rx IRQ ON \n");
		//IRQ_ON(host, SD_CONFIG_NE);  ///Enable intr for Rx FIFO Not Empty
		cdac_pr_info(DRIVER_NAME "Rx Intr...\n");	
		IRQ_ON(host, CDAC_MMC_INTR_EN_NUM_BLK_AVL_BOOT_FIFO_INTR);
		cdac_pr_info(DRIVER_NAME "ON\n");	
	}
	/* IRQ_ON(host, SD_CONFIG_RA | SD_CONFIG_RF); */

	return 0;

	dataerr: dma_unmap_sg(mmc_dev(host->mmc), data->sg, data->sg_len,
			host->dma.dir);
	return -ETIMEDOUT;
}

/* This actually starts a command or data transaction */

//#endif
void cdac_mmc_reset_controller(struct cdac_mmc_host *host) {
cdac_printk("\n\r cdac_mmc_reset_controller start\n\r");
	unsigned long reg_value = 0;
	


	/* Change frequency to 400kHz */
	__raw_writeq(OP_FREQ_400KHz, HOST_OP_FREQ(host));
	cdac_pr_info(DRIVER_NAME ": Freq %lx \n",__raw_readq(HOST_OP_FREQ(host))); 	//HDG:OK
	/* Configure OP mode register */
	
	reg_value = (CDAC_MMC_OP_MODE_CMD_LINE(1UL)) | (CDAC_MMC_OP_MODE_NUM_BLOCK(0UL)) | (CDAC_MMC_OP_MODE_OPEN_ENDED_TRANSN(1UL))
			| (CDAC_MMC_OP_MODE_LEN_BLOCK(512UL)) | (CDAC_MMC_OP_MODE_TOT_FRAMES_TO_INRPT(1UL)) | (CDAC_MMC_OP_MODE_STOP_EMMC_CLK(1UL))			//HDG:OK
			| (CDAC_MMC_OP_MODE_BOOT_ACK_EN(1UL));
			
	/*reg_value = (CDAC_MMC_OP_MODE_CMD_LINE(1UL)) | (CDAC_MMC_OP_MODE_NUM_BLOCK(1UL))
			| (CDAC_MMC_OP_MODE_LEN_BLOCK(512UL)) | (CDAC_MMC_OP_MODE_TOT_FRAMES_TO_INRPT(1UL)) | (CDAC_MMC_OP_MODE_STOP_EMMC_CLK(1UL))			//HDG:OK
			| (CDAC_MMC_OP_MODE_BOOT_ACK_EN(1UL)) | CDAC_MMC_OP_MODE_DATA_TSFR(1UL) | CDAC_MMC_OP_MODE_DATA_BUS_WIDTH(2UL);*/


	//cdac_pr_info(DRIVER_NAME ":reg_value %lx \n",reg_value);

	__raw_writeq(reg_value, HOST_OP_MODE(host));				//HDG:OK

	//cdac_pr_info(DRIVER_NAME ":reg_value1 %lx \n",reg_value);
	//cdac_pr_info(DRIVER_NAME ": Freq %lx \n",__raw_readq(HOST_OP_FREQ(host)));
	//cdac_pr_info(DRIVER_NAME ": Freq 1%lx \n",__raw_readq(HOST_OP_FREQ(host)));
	//__raw_writeq(OP_FREQ_400KHz, HOST_OP_FREQ(host));
	//	cdac_pr_info(DRIVER_NAME ": Freq 11 %lx \n",__raw_readq(HOST_OP_FREQ(host)));
	//cdac_pr_info(DRIVER_NAME ":reg_value %lx \n",reg_value);
//UL reg_opmode = __raw_readq(HOST_OP_MODE(host));
	//cdac_pr_info(DRIVER_NAME ": Freq %lx \n",__raw_readq(HOST_OP_FREQ(host)));
	cdac_pr_info(DRIVER_NAME ": OPMODE %lx \n",__raw_readq(HOST_OP_MODE(host)));
	/* Configure Response timeout register */
	__raw_writeq(RSP_TIMEOUT_MAX, HOST_RSP_TIMEOUT(host));			//HDG:OK
	cdac_pr_info(DRIVER_NAME ": RSP_TO: %lx \n",__raw_readq(HOST_RSP_TIMEOUT(host)));
//	cdac_pr_info(DRIVER_NAME ": Freq %lx \n",__raw_readq(HOST_OP_FREQ(host)));
	/* Configure Write transaction timeout register */
	__raw_writeq(WR_TRANS_TIMEOUT_MAX, HOST_WR_TRANS_TIMEOUT(host));		//HDG:OK
	cdac_pr_info(DRIVER_NAME ": WR_TRANS_TO %lx \n",__raw_readq(HOST_WR_TRANS_TIMEOUT(host)));
	/* Configure Read transaction timeout register */
	__raw_writeq(RD_TRANS_TIMEOUT_MAX, HOST_RD_TRANS_TIMEOUT(host));		//HDG:OK
	cdac_pr_info(DRIVER_NAME ": RD_TRANS_TO %lx \n",__raw_readq(HOST_RD_TRANS_TIMEOUT(host)));
	
	gHostIEReg_val = ALL_INTERRUPTS_SET;
	__raw_writeq(ALL_INTERRUPTS_SET, HOST_IE(host));
	cdac_pr_info(DRIVER_NAME ":@@@@@@@@@@@@@@@@@@@@ IE 0x %lx \n",ALL_INTERRUPTS_SET);
	cdac_pr_info(DRIVER_NAME "gHostIEReg_val  0x %lx \n",gHostIEReg_val);


#ifndef AUX_REF
		/* Apply the clock */
	//	__raw_writeq(SD_ENABLE_CE, HOST_ENABLE(host));
	//	wmb(); /* drain writebuffer */
	//	mdelay(1);

	//	__raw_writeq(SD_ENABLE_R | SD_ENABLE_CE, HOST_ENABLE(host));
	//	wmb(); /* drain writebuffer */
	//	mdelay(5);

	//	__raw_writeq(~0, HOST_STATUS(host));
	//	wmb(); /* drain writebuffer */

	//	__raw_writeq(0, HOST_BLKSIZE(host));
	//	__raw_writeq(0x001fffff, HOST_TIMEOUT(host));
	//	wmb(); /* drain writebuffer */

	//	__raw_writeq(SD_CONFIG2_EN, HOST_CONFIG2(host));
	//	wmb(); /* drain writebuffer */

	//	__raw_writeq(SD_CONFIG2_EN | SD_CONFIG2_FF, HOST_CONFIG2(host));
	//	wmb(); /* drain writebuffer */
	//	mdelay(1);

	//	__raw_writeq(SD_CONFIG2_EN, HOST_CONFIG2(host));
	//	wmb(); /* drain writebuffer */

		/* Configure interrupts */
	//	__raw_writeq(cdac_MMC_INTERRUPTS, HOST_CONFIG(host));
	//	wmb(); /* drain writebuffer */
#endif
cdac_printk("\n\r cdac_mmc_reset_controller end\n\r");
}
//#ifdef CDAC
static void cdac_mmc_set_ios(struct mmc_host *mmc, struct mmc_ios *ios) {
	struct cdac_mmc_host *host = mmc_priv(mmc);
	UI config2;
	UL opmode_reg_value ;
	
	
	//printk(":cdac_mmc_set_ios\n"); //cdac1
	
	opmode_reg_value = __raw_readq(HOST_OP_MODE(host));

	if (ios->power_mode == MMC_POWER_OFF)
	{
		unsigned long opmode_reg_value = 0;
			

		opmode_reg_value &= ~(1 << 4); // Clears 4th bit
		opmode_reg_value &= ~(1 << 5); // Clears 5th bit
		opmode_reg_value |= ((UL)1 << 32); // Set Bit 32 for Device reset
		__raw_writeq(opmode_reg_value, HOST_OP_MODE(host));
		
		
		
		__raw_writeq(OP_FREQ_400KHz, HOST_OP_FREQ(host)); // Set EMMC freq to 400KHz
		//pr_info(DRIVER_NAME ": EMMC Freq %lx \n",__raw_readq(HOST_OP_FREQ(host))); 	//HDG:OK
		//pr_info(DRIVER_NAME ": EMMC OPMODE REG VAL  %lx \n",__raw_readq(HOST_OP_MODE(host))); 	//HDG:OK
		
		
		
		cdac_mmc_set_power(host, 0);
		//printk(":cdac_mmc_set_power: OFF\n");
		
	}
	else if (ios->power_mode == MMC_POWER_ON) {
		cdac_mmc_set_power(host, 1);
		//printk(":cdac_mmc_set_power: ON\n");
		
	}

	if (ios->clock && ios->clock != host->clock) {
		cdac_mmc_set_clock(host, ios->clock);
		host->clock = ios->clock;
		//printk("ios->clock=%ld\n",ios->clock);
	}

//	config2 = __raw_readq(HOST_CONFIG2(host));

	//opmode_reg_value = __raw_readq(HOST_OP_MODE(host));
	//opmode_reg_value &= ~(1 << 4); // Clears 4th bit
	//opmode_reg_value &= ~(1 << 5); // Clears 5th bit
	
	switch (ios->bus_width) {
	
	case MMC_BUS_WIDTH_8:
//		config2 |= SD_CONFIG2_BB;
		opmode_reg_value &= ~(1 << 4); // Clears 4th bit
		//opmode_reg_value &= ~((UL)7 << 4); // Clears Bits 4 to 7 to set Bus width to 1.
		opmode_reg_value |= (1 << 5); // Sets 5th bit sets Bust width to 8
		//printk("BW 8 set ios\n");
		__raw_writeq(opmode_reg_value, HOST_OP_MODE(host));

		break;
	case MMC_BUS_WIDTH_4:
//		config2 &= ~SD_CONFIG2_BB;
//		config2 |= SD_CONFIG2_WB;
		//printk("BW 4 set ios\n");
		break;
	case MMC_BUS_WIDTH_1:
		opmode_reg_value &= ~(1 << 4); // Clears 4th bit
		opmode_reg_value &= ~(1 << 5); // Clears 5th bit
//		config2 &= ~(SD_CONFIG2_WB | SD_CONFIG2_BB);
		//printk("BW 1 set ios\n");
		__raw_writeq(opmode_reg_value, HOST_OP_MODE(host));
		break;
	}
	
	//__raw_writeq(config2, HOST_CONFIG2(host));
	wmb(); /* drain writebuffer */
	
	//printk("\n Press key \n");
	/*while(sbi_console_getchar()== -1)
	{
		msleep(1000);
	}*/

}

//#define STATUS_TIMEOUT (SD_STATUS_RAT | SD_STATUS_DT)
//#define STATUS_DATA_IN  (SD_STATUS_NE)
//#define STATUS_DATA_OUT (SD_STATUS_TH)

/* 8bit memory DMA device */
//static dbdev_tab_t cdac_mmc_mem_dbdev = { .dev_id = DSCR_CMD0_ALWAYS,
//.dev_flags = DEV_FLAGS_ANYUSE, .dev_tsize = 0, .dev_devwidth = 8,
//	.dev_physaddr = 0x00000000, .dev_intlevel = 0, .dev_intpolarity = 0, };
static int memid;

static void cdac_mmc_dbdma_callback(int irq, void *dev_id) {
	struct cdac_mmc_host *host = (struct cdac_mmc_host*) dev_id;
	cdac_pr_info(DRIVER_NAME ":cdac_mmc_dbdma_callback\n");
	/* Avoid spurious interrupts */
	if (!host->mrq)
		return;

	if (host->flags & HOST_F_STOP)
		SEND_STOP(host);

	tasklet_schedule(&host->data_task);
}

static int cdac_mmc_dbdma_init(struct cdac_mmc_host *host) {
	struct resource *res;
	int txid, rxid;
	cdac_pr_info(DRIVER_NAME ":cdac_mmc_dbdma_init\n");
	res = platform_get_resource(host->pdev, IORESOURCE_DMA, 0);
	if (!res)
		return -ENODEV;
	txid = res->start;

	res = platform_get_resource(host->pdev, IORESOURCE_DMA, 1);
	if (!res)
		return -ENODEV;
	rxid = res->start;

	if (!memid)
		return -ENODEV;

	//host->tx_chan = cdac_xx_dbdma_chan_alloc(memid, txid,
	//	cdac_mmc_dbdma_callback, (void*) host);
	if (!host->tx_chan) {
		dev_err(&host->pdev->dev, "cannot allocate TX DMA\n");
		return -ENODEV;
	}

//	host->rx_chan = cdac_xx_dbdma_chan_alloc(rxid, memid,
	//		cdac_mmc_dbdma_callback, (void*) host);
	if (!host->rx_chan) {
		dev_err(&host->pdev->dev, "cannot allocate RX DMA\n");
		//	cdac_xx_dbdma_chan_free(host->tx_chan);
		return -ENODEV;
	}

	//cdac_xx_dbdma_set_devwidth(host->tx_chan, 8);
	//cdac_xx_dbdma_set_devwidth(host->rx_chan, 8);

	//cdac_xx_dbdma_ring_alloc(host->tx_chan, cdac_MMC_DESCRIPTOR_COUNT);
	//cdac_xx_dbdma_ring_alloc(host->rx_chan, cdac_MMC_DESCRIPTOR_COUNT);

	/* DBDMA is good to go */
	host->flags |= HOST_F_DMA | HOST_F_DBDMA;

	return 0;
}

static void cdac_mmc_dbdma_shutdown(struct cdac_mmc_host *host) {

		cdac_pr_info(DRIVER_NAME ":cdac_mmc_dbdma_shutdown\n");
	if (host->flags & HOST_F_DMA) {
		host->flags &= ~HOST_F_DMA;
		//	cdac_xx_dbdma_chan_free(host->tx_chan);
		//	cdac_xx_dbdma_chan_free(host->rx_chan);
	}
}

static void cdac_mmc_enable_sdio_irq(struct mmc_host *mmc, int en) {
	struct cdac_mmc_host *host = mmc_priv(mmc);
	
		cdac_pr_info(DRIVER_NAME ":cdac_mmc_enable_sdio_irq\n");

	//if (en)
	//IRQ_ON(host, SD_CONFIG_SI);
//	else
	//IRQ_OFF(host, SD_CONFIG_SI);
}
static int cdac_mmc_card_inserted(struct mmc_host *mmc) {
	struct cdac_mmc_host *host = mmc_priv(mmc);
	
	cdac_pr_info(DRIVER_NAME ":cdac_mmc_card_inserted\n");

//	if (host->platdata && host->platdata->card_inserted)
//		return !!host->platdata->card_inserted(host->mmc);

	return 1;
}

static int cdac_mmc_card_readonly(struct mmc_host *mmc) {
	struct cdac_mmc_host *host = mmc_priv(mmc);


	cdac_pr_info(DRIVER_NAME ":cdac_mmc_card_readonly\n");
	
//	if (host->platdata && host->platdata->card_readonly)
//		return !!host->platdata->card_readonly(mmc);

	return -ENOSYS;
}
static void cdac_mmc_request(struct mmc_host *mmc, struct mmc_request *mrq) {
	
	struct cdac_mmc_host *host = mmc_priv(mmc);
	struct mmc_command *cmd;
	int ret = 0;
	UL status = 0;
	unsigned long reg_value = 0;
	
	cmd = mrq->cmd;
	
	//pr_info(DRIVER_NAME ":cdac_mmc_request\n");

	WARN_ON(irqs_disabled());
	WARN_ON(host->status != HOST_S_IDLE);

	host->mrq = mrq;
	host->status = HOST_S_CMD;

	/* fail request immediately if no card is present */
	/*	if (0 == cdac_mmc_card_inserted(mmc)) {
	 mrq->cmd->error = -ENOMEDIUM;
	 cdac_mmc_finish_request(host);
	 return;
	 }*/

	if (mrq->data) 
	{
		
		//cdac_printk("Before clearing OPMODE VAL: 0x %lx bytes",reg_value);
		
		//reg_value &= E0001FFFFFFFFFFF;
		
		//cdac_printk("After clearing OPMODE VAL: 0x %lx bytes",reg_value);

		//if(mrq->data->blksz != 512)
		//printk("***Common\n");

		if (mrq->data->blocks > 65535) {
		
		printk(" Modify EMMC linux driver to support no of blocks > 65535\n");

			//reg_value = reg_value | (CDAC_MMC_OP_MODE_NUM_BLOCK(255))
			//		| (CDAC_MMC_OP_MODE_LEN_BLOCK(mrq->data->blksz));
		} else {
			reg_value = __raw_readq(HOST_OP_MODE(host));
			reg_value &= 0xE0001FFFFFFFFFFF; // Clears bit from 45 to 60. 
			reg_value = reg_value | (CDAC_MMC_OP_MODE_NUM_BLOCK(mrq->data->blocks))
					| (CDAC_MMC_OP_MODE_LEN_BLOCK(mrq->data->blksz));
			
			
			__raw_writeq(reg_value, HOST_OP_MODE(host));
			//printk("\n OPMODE VAL: 0x %lx ",reg_value);

		}



		
		//cdac_printk("After writing NEW OPMODE VAL: 0x %lx bytes",reg_value);
	
		if (mrq->data->flags & MMC_DATA_READ)
		{
		
			//printk("***READ\n");
		
			host->flags |= HOST_F_RECV;
			ret = cdac_mmc_prepare_data(host, mrq);
			if (!ret)
			{
			
				if(mrq->sbc)
				{
					//printk("*******HDG:SBC \n");
					command_complete_flag = 0;
					ret = cdac_mmc_send_command(host, 0, mrq->sbc, mrq->data);
					while(command_complete_flag == 0); //wait for the command to be completed
					//printk(" CMD SENT 1 :23 R\n");
				}
				command_complete_flag = 0;
				ret = cdac_mmc_send_command(host, 0, mrq->cmd, mrq->data);
				while(command_complete_flag == 0); //wait for the command to be completed
				
				//printk(" CMD SENT : R\n");
				
				if(cmd->opcode != 8)
				{
					if(mrq->sbc)
					{
						//printk(" ******CCC \n");
						
						do
						{
							status = __raw_readq(HOST_STATUS(host));
							if(status & CDAC_MMC_STATUS_RD_TRANSN_TIMEOUT_ERR)
								printk(" ******READ Txn Time OUT Err \n");
						}while(!(status & CDAC_MMC_STATUS_MUL_BLK_RD_CPLT));
					}
					else
					{
						//printk(" ******DDD \n");
						do
						{
							status = __raw_readq(HOST_STATUS(host));
							if(status & CDAC_MMC_STATUS_RD_TRANSN_TIMEOUT_ERR)
								printk(" ******READ Txn Time OUT Err \n");
						}while(!(status & CDAC_MMC_STATUS_SIN_BLK_RD_CPLT));
					}
					
					/*unsigned long response = 0;
					response =  (__raw_readq(HOST_LWR_RSP(host)));
					printk("\n LR 0x: %lx\n",response);
					response =  (__raw_readq(HOST_UPR_RSP(host)));
					printk("\n UR 0x: %lx\n",response);*/
				}
					
			}

		}
		else if (mrq->data->flags & MMC_DATA_WRITE)
		{
		
			//printk("***WRITE\n");
			//Enters here during write
	
			host->flags |= HOST_F_XMIT;
			
			//printk("host flags %x \n",host->flags);
			
			if(mrq->sbc)
			{
				//printk("*******HDG:SBC \n");
				command_complete_flag = 0;
				ret = cdac_mmc_send_command(host, 0, mrq->sbc, mrq->data);
				while(command_complete_flag == 0); //wait for the command to be completed
			}
			command_complete_flag = 0;
			ret = cdac_mmc_send_command(host, 0, mrq->cmd, mrq->data);
			while(command_complete_flag == 0); //wait for the command to be completed
			
			//printk(" CMD SENT : W\n");
			
			//printk("cdac_mmc_prepare_data  \n");
			ret = cdac_mmc_prepare_data(host, mrq);
			//printk("cdac_mmc_prepare_data 2  \n");
			
			if(mrq->sbc)
			{
				//printk(" ******AAA \n");
				UL status;
				do
				{
					status = __raw_readq(HOST_STATUS(host));
					if(status & CDAC_MMC_STATUS_WTRANS_TMOUT_ERR)
						printk(" ******WR Txn Time OUT Err \n");
						
				//printk(" ******MBWC NOT SET \n");
				}while(!(status & CDAC_MMC_STATUS_MUL_BLK_WR_CPLT));
				
			}
			else
			{
				//printk(" ******BBB \n");
				do
				{
					status = __raw_readq(HOST_STATUS(host));
					if(status & CDAC_MMC_STATUS_RD_TRANSN_TIMEOUT_ERR)
						printk(" ******WRITE Txn Time OUT Err \n");
						
				}while(!(status & CDAC_MMC_STATUS_SIN_BLK_WR_CPLT));
				//printk("cdac_mmc_prepare_data 3  \n");
			}
			
			/*unsigned long response = 0;
			response =  (__raw_readq(HOST_LWR_RSP(host)));
			printk("\n LR 0x: %lx\n",response);
			response =  (__raw_readq(HOST_UPR_RSP(host)));
			printk("\n UR 0x: %lx\n",response);*/
			
			
		}
	} else{
		command_complete_flag = 0;
		ret = cdac_mmc_send_command(host, 0, mrq->cmd, mrq->data);
		while(command_complete_flag == 0); //wait for the command to be completed
					//printk(" CMD SENT 3 : else\n");
		
	}


	if (ret) {
		mrq->cmd->error = ret;
		cdac_mmc_finish_request(host);
	}
}



static const struct mmc_host_ops cdac_mmc_ops = { 
	.request = cdac_mmc_request,
	.set_ios = cdac_mmc_set_ios, 
	.get_ro = cdac_mmc_card_readonly,
	.get_cd = cdac_mmc_card_inserted, 
	.enable_sdio_irq = cdac_mmc_enable_sdio_irq, 
};

	volatile int cdac_irq = 0;
	
static irqreturn_t cdac_mmc_irq(int irq, void *dev_id) {
	struct cdac_mmc_host *host = dev_id;
	u64 status,int_status = 0;

	cdac_irq = 1;

	spin_lock(&host->chip_lock);
	//printk("In ISR...");
	int_status = __raw_readq(HOST_INTERRUPT_STATUS(host));
	cdac_pr_info(DRIVER_NAME ": Interrupt Status %lx \n",int_status);
	//printk("Interrupt Status 0x %lx \n",int_status);

	// if (int_status & CDAC_MMC_INT_STATUS_CMD_COMPLETE) // HDG: Commented for testing Command Sent interrupt
	if (int_status & CDAC_MMC_INT_STATUS_CMD_SENT)
		cdac_mmc_cmd_complete(host);
		
		//cdac_pr_info(DRIVER_NAME ": isr return   \n");
		
//	if (!(status & SD_STATUS_I))
//		return IRQ_NONE;	/* not ours */

//	if (status & SD_STATUS_SI)	/* SDIO */
	//	mmc_signal_sdio_irq(host->mmc);

	/*if ((int_status & CDAC_MMC_INTR_STATUS_RSP_TMOUT))
		host->mrq->cmd->error = -ETIMEDOUT;
	else if (int_status & CDAC_MMC_INTR_STATUS_WRT_TMOUT)
		host->mrq->data->error = -ETIMEDOUT;
	else if (int_status & CDAC_MMC_INTR_STATUS_RRT_TMOUT)
		host->mrq->data->error = -ETIMEDOUT;*/

	/* In PIO mode, interrupts might still be enabled */
//		IRQ_OFF(host, SD_CONFIG_NE | SD_CONFIG_TH);
	/* IRQ_OFF(host, SD_CONFIG_TH | SD_CONFIG_RA | SD_CONFIG_RF); */
	//	tasklet_schedule(&host->finish_task);
//	}


	//else if (status & SD_STATUS_CR) {
	//if (host->status == HOST_S_CMD)
	//cdac_mmc_cmd_complete(host, status);

//	} else if (!(host->flags & HOST_F_DMA)) {

	//int_status = __raw_readq(HOST_INTERRUPT_STATUS(host));
	//cdac_pr_info(DRIVER_NAME ":II Interrupt Status %lx \n",int_status);
	
	cdac_printk("\n\r host flag:0x %x",host->flags);
	
	//printk("In ISR 2...");
	
	if ((host->flags & HOST_F_XMIT) && (int_status & CDAC_MMC_INTR_STATUS_WR_DATA_FIFO_EMPTY_INTR))
	{
		//printk("ISR....TX");
		
		cdac_pr_info(DRIVER_NAME ":host->pio.len: %ld Bytes tx\n", host->pio.len);
			cdac_mmc_send_pio(host);
			
	}
	else if ((host->flags & HOST_F_RECV) && (int_status & CDAC_MMC_INTR_STATUS_NO_BLK_AVL_B_FIFO_INTR))
	{
		//printk("ISR....RX");
		cdac_pr_info(DRIVER_NAME ":III Interrupt Status %lx \n",int_status);
		//host->pio.len =  int_status & CDAC_MMC_INTR_STATUS_WR_DATA_FIFO_EMPTY_INTR; // Updating the  number od blocks received during interrupt.
		
		//status = __raw_readq(HOST_STATUS(host));
		//cdac_pr_info(DRIVER_NAME ":Hh HOST_STATUS %lx \n", status);

		//printk("ISR....RX1\n");
		cdac_pr_info(DRIVER_NAME ":host->pio.len: %ld Bytes Received\n", host->pio.len);
		cdac_mmc_receive_pio(host);
	}
	
	cdac_printk("\n\r Over");
	//}else
	if (int_status & 0x203F3C70) {
		DBG("Unhandled status %8.8x\n", host->pdev->id, status);
	}

	//__raw_writeq(status, HOST_STATUS(host));
	wmb(); /* drain writebuffer */
	spin_unlock(&host->chip_lock);
		cdac_irq = 0;
	return IRQ_HANDLED;
}
//#endif

static int cdac_mmc_probe(struct platform_device *pdev) {


	struct mmc_host *mmc;
	struct cdac_mmc_host *host;
	struct resource *r;
	//struct device *dev = pdev->dev;
	int ret, iflag;
	u64 int_status;
	u32 dma_base=0;
	u32 dma_size=0;	



	
	cdac_printk("\n\r cdac_mmc_probe--start\n\r");

	mmc = mmc_alloc_host(sizeof(struct cdac_mmc_host), &pdev->dev);
	if (!mmc) {
		dev_err(&pdev->dev, "no memory for mmc_host\n");
		ret = -ENOMEM;
		goto out0;
	}

	host = mmc_priv(mmc);
	host->mmc = mmc;
	 
	host->platdata = pdev->dev.platform_data;
	host->pdev = pdev;
	ret = -ENODEV;

	r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!r) {
		dev_err(&pdev->dev, "no mmio defined\n");
		goto out1;
	}


	//for_each_available_child_of_node(np, child) {

	
	ret = of_property_read_u32(pdev->dev.of_node, "dma-base-addr",
					   &dma_base);
					   
	ret = of_property_read_u32(pdev->dev.of_node, "dma-addr-size",
					   &dma_size);				   
	
	
	spin_lock_init(&host->chip_lock);
	
	cdac_pr_info(DRIVER_NAME ": r->start %lx pdev->name %s\n", r->start, pdev->name);
	cdac_pr_info(DRIVER_NAME "dma_base %x\n", dma_base);
	cdac_pr_info(DRIVER_NAME "dma_size %x\n", dma_size);

	host->ioarea = request_mem_region(r->start, resource_size(r), pdev->name);
	if (!host->ioarea) {
		dev_err(&pdev->dev, "mmio already in use\n");
		goto out1;
	}

	host->iobase = ioremap(r->start, resource_size(r));
	
	
	cdac_pr_info(DRIVER_NAME " host->iobase %lx \n", host->iobase);

	if (!host->iobase) {
		dev_err(&pdev->dev, "cannot remap mmio\n");
		goto out2;
	}

	host->dmabase = ioremap(dma_base, dma_size);
	cdac_pr_info(DRIVER_NAME " host->dmabase %lx \n", host->dmabase);

	if (!host->dmabase) {
		dev_err(&pdev->dev, "cannot remap dma\n");
		goto out2a;
	}
	

	r = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
	if (!r) {
		dev_err(&pdev->dev, "no IRQ defined\n");
		goto out3;
	}

	host->irq = r->start;
	
	cdac_pr_info(DRIVER_NAME " host->irq %lx \n", host->irq);

	mmc->ops = &cdac_mmc_ops;			//karthika

	mmc->f_min = 450000;
	mmc->f_max = 24000000;

	mmc->max_blk_size = 512;
	mmc->max_blk_count = 16;

	mmc->ocr_avail = CDAC_MMC_OCR;
	mmc->caps |= (MMC_CAP_8_BIT_DATA | MMC_CAP_CMD23 | MMC_CAP_WAIT_WHILE_BUSY | MMC_CAP_MMC_HIGHSPEED |  MMC_CAP_DONE_COMPLETE \
	| MMC_CAP_UHS_SDR25 | MMC_CAP_UHS_SDR50 );
	
	mmc->caps2 |= (MMC_CAP2_NO_SD | MMC_CAP2_NO_SDIO);
	mmc->max_segs = CDAC_MMC_DESCRIPTOR_COUNT;
	
	//printk("MMC CAPS2 %lx \n",mmc->caps2);

	iflag = IRQF_SHARED; /* Au1100/Au1200: one int for both ctrls */

	//switch (alchemy_get_cputype()) {
	//case ALCHEMY_CPU_AU1100:
	//	mmc->max_seg_size = AU1100_MMC_DESCRIPTOR_SIZE;
	//	break;
	//case ALCHEMY_CPU_AU1200:
	//	mmc->max_seg_size = AU1200_MMC_DESCRIPTOR_SIZE;
	//	break;
	//case ALCHEMY_CPU_AU1300:
	//	iflag = 0; /* nothing is shared */
	//	mmc->max_seg_size = AU1200_MMC_DESCRIPTOR_SIZE;
	//	mmc->f_max = 52000000;
	//	if (host->ioarea->start == AU1100_SD0_PHYS_ADDR)
	//		mmc->caps |= MMC_CAP_8_BIT_DATA;
	//	break;
	//}

	//__raw_writeq(0, HOST_IE(host));

	//int_status = __raw_readq(HOST_INTERRUPT_STATUS(host));
	//__raw_writeq(0, HOST_IE(host));
	//cdac_pr_info(DRIVER_NAME " request_irq : IE 0");
	ret = request_irq(host->irq, cdac_mmc_irq, iflag, DRIVER_NAME, host);
	
	cdac_pr_info(DRIVER_NAME " request_irq : ret val: %lx \n",ret);
	
	if (ret) {
		dev_err(&pdev->dev, "cannot grab IRQ\n");
		goto out3;
	}

//	host->clk = clk_get(&pdev->dev, ALCHEMY_PERIPH_CLK);
	if (IS_ERR(host->clk)) {
		dev_err(&pdev->dev, "cannot find clock\n");
		ret = PTR_ERR(host->clk);
		goto out_irq;
	}

	ret = clk_prepare_enable(host->clk);
	if (ret) {
		dev_err(&pdev->dev, "cannot enable clock\n");
		goto out_clk;
	}

	host->status = HOST_S_IDLE;

	/* board-specific carddetect setup, if any */
//	if (host->platdata && host->platdata->cd_setup) {
	//	ret = host->platdata->cd_setup(mmc, 1);
	//if (ret) {
	//dev_warn(&pdev->dev, "board CD setup failed\n");
	//mmc->caps |= MMC_CAP_NEEDS_POLL;
	//}
	//} else
	//mmc->caps |= MMC_CAP_NEEDS_POLL;
	/* platform may not be able to use all advertised caps */
//	if (host->platdata)
	//	mmc->caps &= ~(host->platdata->mask_host_caps);
	tasklet_init(&host->data_task, cdac_mmc_tasklet_data, (unsigned long) host);

	tasklet_init(&host->finish_task, cdac_mmc_tasklet_finish,
			(unsigned long) host);
			
	Enable_DMAC(host);	// Enabling DMAC.


	cdac_mmc_reset_controller(host); // HDG: Initial controller values are set as per "eMMC_Primary_Init_HostController()" in baremetal pgm

	ret = mmc_add_host(mmc);
	if (ret) {
		dev_err(&pdev->dev, "cannot add mmc host\n");
		goto out6;
	}

	platform_set_drvdata(pdev, host);
	
	//mmc->card->quirks |= MMC_QUIRK_BROKEN_HPI;
	
	// HDG: Here cdac_mmc_ops() are called like "cdac_mmc_set_ios","cdac_mmc_set_power",cdac_mmc_set_clock etc

	cdac_pr_info(DRIVER_NAME ": MMC Controller %d set up at %lx"
	" (mode=%s)\n", pdev->id, host->iobase,
			host->flags & HOST_F_DMA ? "dma" : "pio");

	return 0; /* all ok */

	out6:
#ifdef CONFIG_LEDS_CLASS
		if (host->platdata && host->platdata->led)
			led_classdev_unregister(host->platdata->led);
		out5:
#endif
	//__raw_writeq(0, HOST_ENABLE(host));
	//__raw_writeq(0, HOST_CONFIG(host));
	//__raw_writeq(0, HOST_CONFIG2(host));
	//wmb(); /* drain writebuffer */

	if (host->flags & HOST_F_DBDMA)
		cdac_mmc_dbdma_shutdown(host);

	tasklet_kill(&host->data_task);
	tasklet_kill(&host->finish_task);

//	if (host->platdata && host->platdata->cd_setup
	//		&& !(mmc->caps & MMC_CAP_NEEDS_POLL))
	//host->platdata->cd_setup(mmc, 0);
	out_clk: clk_disable_unprepare(host->clk);
	clk_put(host->clk);
	out_irq: free_irq(host->irq, host);
	out3: iounmap((void*) host->dmabase);
	out2a: iounmap((void*) host->iobase);
	out2: release_resource(host->ioarea);
	kfree(host->ioarea);
	out1: mmc_free_host(mmc);
	out0: return ret;

}

static int cdac_mmc_remove(struct platform_device *pdev) {
	struct cdac_mmc_host *host = platform_get_drvdata(pdev);
	cdac_pr_info(DRIVER_NAME ":cdac_mmc_remove\n");
	
	return;

	if (host) {
		mmc_remove_host(host->mmc);

#ifdef CONFIG_LEDS_CLASS
			if (host->platdata && host->platdata->led)
				led_classdev_unregister(host->platdata->led);
#endif

		//	if (host->platdata && host->platdata->cd_setup
		//		&& !(host->mmc->caps & MMC_CAP_NEEDS_POLL))
		//host->platdata->cd_setup(host->mmc, 0);

		//	__raw_writeq(0, HOST_ENABLE(host));
		//	__raw_writeq(0, HOST_CONFIG(host));
		//	__raw_writeq(0, HOST_CONFIG2(host));
		//	wmb(); /* drain writebuffer */

		tasklet_kill(&host->data_task);
		tasklet_kill(&host->finish_task);

		if (host->flags & HOST_F_DBDMA)
			cdac_mmc_dbdma_shutdown(host);

		cdac_mmc_set_power(host, 0);

		clk_disable_unprepare(host->clk);
		clk_put(host->clk);

		free_irq(host->irq, host);
		iounmap((void*) host->iobase);
		release_resource(host->ioarea);
		kfree(host->ioarea);

		mmc_free_host(host->mmc);
	}
	return 0;
}

#ifdef CONFIG_PM
	static int cdac_mmc_suspend(struct platform_device *pdev, pm_message_t state)
	{
		struct cdac_mmc_host *host = platform_get_drvdata(pdev);

		//__raw_writeq(0, HOST_CONFIG2(host));
		//__raw_writeq(0, HOST_CONFIG(host));
		//__raw_writeq(0xffffffff, HOST_STATUS(host));
		//__raw_writeq(0, HOST_ENABLE(host));
		wmb(); /* drain writebuffer */

		return 0;
	}

	static int cdac_mmc_resume(struct platform_device *pdev)
	{
		struct cdac_mmc_host *host = platform_get_drvdata(pdev);

		cdac_mmc_reset_controller(host);

		return 0;
	}
#else
#define cdac_mmc_suspend NULL
#define cdac_mmc_resume NULL
#endif


static const struct of_device_id cdac_emmc_match[] = { { .type = "mmc",
		.compatible = "cdac,cdac_emmc" }, { } };
MODULE_DEVICE_TABLE( of, cdac_emmc_match);

static struct platform_driver cdac_mmc_driver = {

	.probe = cdac_mmc_probe,
	.remove = cdac_mmc_remove,
	.driver = {
		.name = "cdac_emmc",
                .owner = THIS_MODULE,
		.of_match_table = of_match_ptr(cdac_emmc_match),
	},
#ifdef CONFIG_PM
	.suspend = cdac_mmc_suspend,
	.resume = cdac_mmc_resume,
#endif
};


static int __init cdac_mmc_init(void)
{

//#ifdef DBDMA
	//if (has_dbdma()) {
		/* DSCR_CMD0_ALWAYS has a stride of 32 bits, we need a stride
		 * of 8 bits.  And since devices are shared, we need to create
		 * our own to avoid freaking out other devices.
		 */
		//memid = cdac_xx_ddma_add_device(&cdac_mmc_mem_dbdev);
		//if (!memid)
		//pr_err("cdac_mmc: cannot add memory dbdma\n");
	//}
//#endif
	return platform_driver_register(&cdac_mmc_driver);
}



static void __exit cdac_mmc_exit(void)
{
	cdac_pr_info(DRIVER_NAME ":cdac_mmc_exit\n");
//#ifdef DBDMA
	//if (has_dbdma() && memid)
	//cdac_xx_ddma_del_device(memid);
//#endif
	platform_driver_unregister(&cdac_mmc_driver);
}




/***********************DMA FUNCTIONS***********************/


/**************************************************
* Function name		: void Init_DMA_Channel_params(DMAtransfer_Type *gDMAtransfer,UL next_lli_addr,UC lli_master,UC lli_en_dis)
* returns						: Nil
* Created by				: Sreeju G R
* Date created			: 30/08/2019
* Description			: Create a LLI Table .
* Notes						:
**************************************************/

void Init_DMA_Ch_CtrlReg_params_sram_to_sram(UC dce, UC cie,UL src_data_width, UL dst_data_width, UC dai, UC sai, UC cbe, UC cms, US cts, UC cbs)
{
	int test=0;
	gDMAtransfer.Control.dword = 0;		// Initialise structure with 0 value.
	gDMAtransfer.LLI.dword = 0;				// Initialise structure with 0 value.

	gDMAtransfer.Control.Bits.DCE = dce;
	gDMAtransfer.Control.Bits.CIE = cie;
	gDMAtransfer.Control.Bits.SRC_DW = src_data_width;
	gDMAtransfer.Control.Bits.DST_DW = dst_data_width;   	// 000 : 8-bit source data, 001 : 16-bit source data, 010 : 32-bit source data, 011 : 64-bit source data, 100 : 128-bit source data
	gDMAtransfer.Control.Bits.DAI = dai;			// CHANNEL WAIT RESPONSE			:::: 0 : disabling wait state, 1 : enable  wait state
	gDMAtransfer.Control.Bits.SAI = sai;			// CHANNEL ADDRESS INCREMENT :::: 0 : disabling address increment, 1 : disabling address increment
	gDMAtransfer.Control.Bits.CBE = cbe;			// CHANNEL BURST ENABLE  ::::  0 : disabling burst transaction, 1 : enabling burst transaction
	gDMAtransfer.Control.Bits.CMS = cms;			// CHANNEL MASTER SELECTOR  :::: 00 : ACE to ACE transaction , 01 : ACE to AXI transaction, 10 : AXI to ACE transaction , 11 : AXI to AXI transaction
	gDMAtransfer.Control.Bits.CTS = cts;			// CHANNEL TRANSFER SIZE
	gDMAtransfer.Control.Bits.CBS = cbs;			// CHANNEL BURST SIZE  :::: 001 : BURST 2, 010 : BURST 4, 011 : BURST 8
	
	//printk("********* INIT DMA #############");

}

/**************************************************
* Function name		: Read_DMAC_Global_Status_Reg
* returns		: Nil
* Created by		: Sreeju G R
* Date created		: 19/08/2019
* Description		: Read the content of DMAC Global status register.
* Notes			:
**************************************************/

unsigned long  Read_DMAC_Global_Status_Reg(struct cdac_mmc_host *host)
{
		unsigned long  status = 0;
		status = __raw_readq(DMA_GLOBAL_STATUS_REG(host));
		return status;
}

/**************************************************
* Function name		: Enable_DMAC
* returns		: Nil
* Created by		: Sreeju G R
* Date created		: 19/08/2019
* Description		: Enable DMAController.
* Notes			: 
**************************************************/

void Enable_DMAC(struct cdac_mmc_host *host)
{
	cdac_pr_info(DRIVER_NAME ":Enabling DMAC....\n");
	DMAC_GlobalCtrl_Type gblCtrlReg;
	UL val=0,status = 0;
	gblCtrlReg.dword = 0;

	gblCtrlReg.Bits.DE = 1;

	gblCtrlReg.Bits.DIE = DMA_INTR_ENABLE;
	
	//DMAC_globalReg.CtrlReg = gblCtrlReg.dword;
	__raw_writeq(gblCtrlReg.dword, DMA_GLOBAL_CTRL_REG(host)); //writing Global control register
	__asm__ __volatile__ ("fence");
	
	while(val != 3)
	{
		val = __raw_readq(DMA_GLOBAL_CTRL_REG(host));
	}

	do
	{
		status = Read_DMAC_Global_Status_Reg(host); 	// Check if channel is active or not
	} while(((status & DMA_ACTIVE) != DMA_ACTIVE));
	cdac_pr_info(DRIVER_NAME "Done\n");
}

/**************************************************
* Function name		: Check_DMAC_transferDone
* returns						: Nil
* Created by				: Sreeju G R
* Date created			: 19/08/2019
* Description			: Check if DMA transfer completed.
* Notes			:
**************************************************/

void Check_DMAC_transferDone(struct cdac_mmc_host *host,UC channelNum)
{
		unsigned long status = 0;
		UL  test=0;

		//if(channelNum  == DMAC_CHANNEL0)
		if(channelNum  == CHANNEL0) //Channel 0
		{
			do
			{
				status = Read_DMAC_Global_Status_Reg(host); 	// Check if channel data transfer is done
				//Transmit_uart(" \n\r DMA Status Reg Val:");
				//disp_Rx_data_UL((UL) (status));
				//Rx_uart();
			} while(((status & CHK_CH0_DTD) != CHK_CH0_DTD)); 							// wait till channel is data transfer is complete.

			//gDMAFrameCount++;
		}
}



void eMMC_DisplayExtCSDdata(UI noOfBlks)
{
	UL *readPtr;
	UI i=0,j = 0;

	//Flush_Cache_data();


	readPtr = (UL*)0x91000000;

	cdac_printk("\n\r\n\r EXT CSD DATA.... ");
	cdac_printk("\n\r****************\n\r\n\r ");
	for(j=0;j<noOfBlks;j++)
	{

		for(i=0;i<(EMMC_BLK_LEN/8);i++)
		{
			cdac_printk("[");
			//cdac_printk("\n\r cdac_mmc_reset_controller start\n\r");
			cdac_pr_info(DRIVER_NAME "%d",j);
			cdac_printk(":");
			//disp_decimal(j+=7);
			cdac_printk("]");

			cdac_printk("		0x ");
			//disp_Rx_data_UL(*readPtr);
			cdac_printk("\n\r ");

			j++;

			readPtr++;
		}
	}
}


/*************************************************************/
module_init( cdac_mmc_init);
//module_init( cdac_dma_init);
module_exit( cdac_mmc_exit);
//module_exit( cdac_dma_exit);

MODULE_AUTHOR("HDG-CDAC-TVM");
MODULE_DESCRIPTION("MMC/SD driver for the CDAC");
MODULE_ALIAS("platform:cdac_mmc");

