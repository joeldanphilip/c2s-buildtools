#include "ermac.h"

#include <asm/csr.h>

#include <linux/delay.h>

#include <linux/slab.h>



//__asm__ __volatile__ ("fence"); //To complete the write operation in O-O-O processor



void Init_PHY_default_SAF_GMAC(void __iomem *gmac_base_vaddr)

{

	UI intr_status;



	printk("Initializing ethernet.... \n");

	intr_status = readl(

		gmac_base_vaddr +

		ERMAC_INTR_STATUS_REG); //clear if any pending intr is there

	writel((0x800000F0 | UNICAST_BROADCAST | DUPLEX | TX_ENABLE | RX_ENABLE | PROMISCUS),

	       (gmac_base_vaddr + ERMAC_CNTRL_REG));

	mdelay(800);

	writel(0, (gmac_base_vaddr + ERMAC_INTR_EN_REG));

	writel((TX_CMP_INTR | RX_CMP_INTR),

	       (gmac_base_vaddr + ERMAC_INTR_EN_REG));

	intr_status = readl(

		gmac_base_vaddr +

		ERMAC_INTR_STATUS_REG); //clear if any pending intr is there

}



void send_ethernet(volatile unsigned char *buf, void __iomem *gmac_base_vaddr,

		   int length)

{

	int i, tLen;

	unsigned int data;

	unsigned int *tx_memory;



	//printk("[C-DAC DEBUG] @send_ethernet : %x --> %d \n", gmac_base_vaddr, length);

	tx_memory = (unsigned int *)kmalloc(8000, GFP_KERNEL);

	memcpy(tx_memory, (unsigned int *) buf, length);



	if ((length % 4) != 0)

		tLen = (length / 4) + 1;

	else

		tLen = (length / 4);



	for (i = 0; i < tLen; i++) {

		data = bigToLittle(tx_memory[i]); //tx_memory[i];

		writel(data, (gmac_base_vaddr + ERMAC_TX_DATA_FIFO));

	}

	kfree(tx_memory);

	writel(length, (gmac_base_vaddr + ERMAC_TX_LENGTH_FIFO));

}



int check_gmac_rx(void __iomem *gmac_base_vaddr)

{

	UI reg_val;

	unsigned int length;



	reg_val = readl(gmac_base_vaddr + ERMAC_RX_LENGTH_FIFO_STATUS_REG);

	if ((reg_val & RX_LENGTH_FIFO_EMTY) == 0) { //length fifo not empty

		length = readl(gmac_base_vaddr + ERMAC_RX_LENGTH_FIFO);

		return length; //Length FIFO not empty

	} else

		return 0; //Length FIFO empty

}



int receive_ethernet(UC *buf, void __iomem *gmac_base_vaddr,

		     unsigned int length)

{

	UI i = 0, tLen = 0, data;

	unsigned int *rx_memory;



	rx_memory = (unsigned int *)kmalloc(8000, GFP_KERNEL);



	if ((length % 4) != 0)

		tLen = (length / 4) + 1;

	else

		tLen = (length / 4);

	for (i = 0; i < tLen; i++) {

		data = readl(gmac_base_vaddr + ERMAC_RX_DATA_FIFO);

		rx_memory[i] = bigToLittle(data); //data ;

	}

	memcpy(buf, rx_memory, length);



	kfree(rx_memory);



	return length;

}



unsigned int bigToLittle(unsigned int x)

{

	return (((x >> 24) & 0x000000ff) | ((x >> 8) & 0x0000ff00) |

		((x << 8) & 0x00ff0000) | ((x << 24) & 0xff000000));

}
