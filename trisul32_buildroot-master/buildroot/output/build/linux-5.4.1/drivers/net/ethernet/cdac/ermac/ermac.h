#include <linux/io.h>

#include <asm/sbi.h>



typedef unsigned long 	UL;

typedef unsigned int 	UI;

typedef unsigned char 	UC;

typedef unsigned short 	US;



#define PHY_READ_BIT		0x01

#define PHY_WRITE_BIT		0x00

#define PHY_BUSY_BIT		0x01

#define	MII_READ_DATA_CMD(PHY_ADDR, REG_ADDR)	(PHY_ADDR << 2) | (PHY_READ_BIT << 1) | (PHY_BUSY_BIT << 0) | (REG_ADDR << 7)

#define	MII_WRITE_DATA_CMD(PHY_ADDR, REG_ADDR)	(PHY_ADDR << 2) | (PHY_WRITE_BIT << 1) | (PHY_BUSY_BIT << 0) | (REG_ADDR << 7)



#define ERMAC_TX_DATA_FIFO                	0xEC

#define ERMAC_TX_LENGTH_FIFO              	0xE8

#define ERMAC_TX_STATUS_FIFO              	0xFC



#define ERMAC_RX_DATA_FIFO                	0xF4

#define ERMAC_RX_LENGTH_FIFO              	0xF0

#define ERMAC_RX_STATUS_FIFO              	0xF8



#define ERMAC_CNTRL_REG                  	0x00

#define	DUPLEX								BIT(0)

#define	TX_ENABLE							BIT(2)

#define	RX_ENABLE							BIT(4)

#define	UNICAST_BROADCAST					BIT(15)

#define	PROMISCUS							BIT(17)



#define ERMAC_ADDR_HIGH_REG               	0x18

#define ERMAC_ADDR_LOW_REG                	0x14



#define ERMAC_SRC_FLT_ADDRH_REG           	0x38

#define ERMAC_SRC_FLT_ADDRL_REG           	0x3C

#define ERMAC_MII_MNGMNT_CNTRL_REG          0x2C



#define ERMAC_MII_READ_DATA_REG				0x88



#define ERMAC_TX_DATA_FIFO_STATUS_REG     	0xCC

#define ERMAC_TX_LENGTH_FIFO_STATUS_REG   	0xC4

#define ERMAC_TX_STATUS_FIFO_STATUS_REG   	0xBC



#define ERMAC_RX_DATA_FIFO_STATUS_REG     	0xC8

#define ERMAC_RX_LENGTH_FIFO_STATUS_REG   	0xC0

#define RX_LENGTH_FIFO_EMTY					BIT(2)



#define ERMAC_RX_STATUS_FIFO_STATUS_REG   	0xB8



#define ERMAC_INTR_EN_REG               	0x28

#define RX_CMP_INTR 						BIT(0)

#define TX_CMP_INTR							BIT(31)



#define ERMAC_INTR_STATUS_REG             	0x24

#define RX_INTR_STAT						BIT(0)

#define TX_INTR_STAT						BIT(31)



void Init_PHY_default_SAF_GMAC(void __iomem * gmac_base_vaddr);

void send_ethernet(volatile unsigned char *buf, void __iomem * gmac_base_vaddr, int length);

int receive_ethernet(UC *buf, void __iomem * gmac_base_vaddr,unsigned int length);

unsigned int bigToLittle(unsigned int x);

unsigned int cdac_readword_fn(void __iomem * dev_base, unsigned long off);

int check_gmac_rx(void __iomem * gmac_base_vaddr);
