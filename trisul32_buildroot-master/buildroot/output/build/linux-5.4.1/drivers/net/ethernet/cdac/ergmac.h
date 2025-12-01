#ifndef MAC_H

#define MAC_H



#include <linux/io.h>

#include <asm/sbi.h>



typedef unsigned long UL;



typedef unsigned int UI;

typedef unsigned char UC;

typedef unsigned short US;





struct ether_header {

	UC ether_dhost[6]; /* destination eth addr	*/

	UC ether_shost[6]; /* source ether addr	*/

	US ether_type; /* packet type ID field	*/

	US id;

	UI packet_no;

}__attribute__ ((__packed__));



#define GMAC_BASE_ADDR		0x2000000



#define	MDIO_WRITE_COMMAND	0x000D0001

#define MDIO_READ_COMMAND	0x00150001



#define cdac_writeword(dev_base,off,val) sbi_write_32_periph((GMAC_BASE_ADDR + off), val);//__raw_writel(val, dev_base + off); __asm__ __volatile__ ("fence w,o" : : : "memory")

#define cdac_readword(dev_base,off)      sbi_read_32_periph((GMAC_BASE_ADDR + off));//__raw_readl(dev_base + off); __asm__ __volatile__ ("fence i,r" : : : "memory")



#define		TX_ENABLE		1<<30

#define		RX_ENABLE		1<<28

#define		PHY_ENABLE		1<<26

#define		SA_FILTER		1<<19

#define		PROMISCUS		1<<18

#define		MULTICAST		1<<17

#define		BROADCAST		1<<16

#define		UNICAST			1<<15

#define		JUMBOFRAME		1<<22





#define		MII_READ_DATA	0x1F

#define		MII_WRITE_DATA	0x1D



//GMAC Registers

#define ERGMAC_BASE_ADDRESS    0x02000000



#define ERGMAC_TX_DATA_FIFO                0xFC

#define ERGMAC_TX_LENGTH_FIFO              0xF8

#define ERGMAC_TX_STATUS_FIFO              0xF4

#define ERGMAC_RX_DATA_FIFO                0xF0



#define ERGMAC_RX_LENGTH_FIFO              0xEC

#define ERGMAC_RX_STATUS_FIFO              0xE8

#define ERGMAC_CONFIG_REG                  0xE4

#define ERGMAC_ADDR_HIGH_REG               0xE0



#define ERGMAC_ADDR_LOW_REG                0xDC

#define ERGMAC_FLOW_CTRL_CONFG_REG         0xD8



#define ERGMAC_SRC_FLT_ADDRH_REG           0xC8

#define ERGMAC_SRC_FLT_ADDRL_REG           0xC4

#define ERGMAC_MDIO_OPERATION_REG          0xC0



#define ERGMAC_MDIO_WRITE_DATA_REG         0xBC

#define ERGMAC_MDIO_READ_DATA_REG	   0xB8

#define ERGMAC_TX_DATA_FIFO_STATUS_REG     0xB4

#define ERGMAC_TX_LENGTH_FIFO_STATUS_REG   0xB0



#define ERGMAC_TX_STATUS_FIFO_STATUS_REG   0xAC

#define ERGMAC_RX_DATA_FIFO_STATUS_REG     0xA8

#define ERGMAC_RX_LENGTH_FIFO_STATUS_REG   0xA4

#define ERGMAC_RX_STATUS_FIFO_STATUS_REG   0xA0



#define ERGMAC_INTR_MASK_REG               0x08

#define ERGMAC_INTR_STATUS_REG             0x04



void Init_PHY_default_SAF_GMAC(void __iomem * gmac_base_vaddr);

void send_ethernet(volatile unsigned char *buf, void __iomem * gmac_base_vaddr, int length);

int receive_ethernet(UC *buf, void __iomem * gmac_base_vaddr,unsigned int length);

unsigned int bigToLittle(unsigned int x);

unsigned int cdac_readword_fn(void __iomem * dev_base, unsigned long off);

int check_gmac_rx(void __iomem * gmac_base_vaddr);

UI clear_supervisor_ext_intrpt(void __iomem * dev_base);





#endif
