#include "ergmac.h"

#include <asm/csr.h>

#include <linux/delay.h>

#include <linux/slab.h>





void Init_PHY_default_SAF_GMAC(void __iomem * gmac_base_vaddr) {



	UI ercnofig_val;

	UI intr_status;


	printk("Initializing ethernet.... \n");



	intr_status = readl(gmac_base_vaddr + ERGMAC_INTR_STATUS_REG); //clear if any pending intr is there

	__asm__ __volatile__ ("fence"); //To complete the write operation in O-O-O processor

	//cdac_writeword(gmac_base_vaddr, ERGMAC_CONFIG_REG, (0x54006780 | UNICAST | BROADCAST));



	//ercnofig_val = readl(gmac_base_vaddr + ERGMAC_CONFIG_REG);

	writel((0x54006780 | UNICAST | BROADCAST) ,(gmac_base_vaddr + ERGMAC_CONFIG_REG));

	mdelay(800);

	//writel((ercnofig_val | BROADCAST) ,(gmac_base_vaddr + ERGMAC_CONFIG_REG) );

	__asm__ __volatile__ ("fence"); //To complete the write operation in O-O-O processor



	//cdac_writeword(gmac_base_vaddr, ERGMAC_INTR_MASK_REG, 0xffffffff);

	writel(0xffffffff,(gmac_base_vaddr + ERGMAC_INTR_MASK_REG) );

	__asm__ __volatile__ ("fence"); //To complete the write operation in O-O-O processor



//	cdac_writeword(gmac_base_vaddr, ERGMAC_INTR_MASK_REG, ~((1 << 24)|(1 << 30)));// bit: 24==> Rx Interrupt,bit: 30==> Tx Interrupt

	writel(~((1 << 24)|(1 << 30)) ,(gmac_base_vaddr + ERGMAC_INTR_MASK_REG) );

	__asm__ __volatile__ ("fence"); //To complete the write operation in O-O-O processor



	intr_status = readl(gmac_base_vaddr + ERGMAC_INTR_STATUS_REG); //clear if any pending intr is there

	__asm__ __volatile__ ("fence"); //To complete the write operation in O-O-O processor

}



UI clear_supervisor_ext_intrpt(void __iomem * gmac_base_vaddr) {



	UI intr_status;



	//intr_status = readl(gmac_base_vaddr+ERGMAC_INTR_STATUS_REG);



	//printk("[C-DAC DEBUG] before sbi_clear_seip_set_meie@ergmac\n");

//	sbi_clear_seip_set_meie(); //clear seip, and set meie after supervisor ext. intr.

	//printk("[C-DAC DEBUG] after sbi_clear_seip_set_meie@ergmac\n");



//	sbi_clear_suip_set_muie();



	return intr_status;

}



void send_ethernet(volatile unsigned char *buf, void __iomem * gmac_base_vaddr, int length) {

	int i, tLen;

	unsigned int data;



	unsigned int *tx_memory;



	tx_memory=(unsigned int *)kmalloc(8000, GFP_KERNEL);



	memcpy(tx_memory, buf, length);



	if ((length % 4) != 0)

		tLen = (length / 4) + 1;

	else

		tLen = (length / 4);



	for (i = 0; i < tLen; i++) {

		/*while (1) {

			reg_val = readl(gmac_base_vaddr, ERGMAC_TX_DATA_FIFO_STATUS_REG);

			if ((reg_val & (1 << 15)) == 0)

				break; //Not full

		}*/

		data =tx_memory[i];//bigToLittle();

		//cdac_writeword(gmac_base_vaddr, ERGMAC_TX_DATA_FIFO, data);

		writel(data ,(gmac_base_vaddr + ERGMAC_TX_DATA_FIFO) );



	}

	__asm__ __volatile__ ("fence"); //To complete the write operation in O-O-O processor

	kfree(tx_memory);

	/*while (1) {

			reg_val = readl(gmac_base_vaddr, ERGMAC_TX_LENGTH_FIFO_STATUS_REG);

			if ((reg_val & (1 << 13)) == 0)

				break; //Not full

		}*/

	//cdac_writeword(gmac_base_vaddr, ERGMAC_TX_LENGTH_FIFO, length);

	writel(length ,(gmac_base_vaddr + ERGMAC_TX_LENGTH_FIFO) );



	__asm__ __volatile__ ("fence"); //To complete the write operation in O-O-O processor

}





int check_gmac_rx(void __iomem * gmac_base_vaddr) {

	UI reg_val;

	unsigned int length;



	reg_val = readl(gmac_base_vaddr + ERGMAC_RX_LENGTH_FIFO_STATUS_REG);

	if((reg_val & (1 << 11)) == 0)

	{//length fifo not empty

		length = readl(gmac_base_vaddr + ERGMAC_RX_LENGTH_FIFO);

		return length; //Length FIFO not empty

	}

	else

		return 0; //Length FIFO empty

}



int receive_ethernet(UC *buf, void __iomem * gmac_base_vaddr,unsigned int length) {

	UI i = 0, tLen = 0, data;

	unsigned int *rx_memory;



	rx_memory=(unsigned int *)kmalloc(8000, GFP_KERNEL);



	if ((length % 4) != 0)

		tLen = (length / 4) + 1;

	else

		tLen = (length / 4);



	for (i = 0; i < tLen; i++) {

		data = readl(gmac_base_vaddr + ERGMAC_RX_DATA_FIFO);

		rx_memory[i] = data ;//bigToLittle(data);

	}



	memcpy(buf, rx_memory, length);



	kfree(rx_memory);



	return length;

}



unsigned int bigToLittle(unsigned int x) {

	return (((x >> 24) & 0x000000ff) | ((x >> 8) & 0x0000ff00)

			| ((x << 8) & 0x00ff0000) | ((x << 24) & 0xff000000));

}
