/*
 * drivers/net/ethernet/cdac/ermac/cdac_gmac.c
 *
 * Authors: Sreenadh S <sreenadh@cdac.in>, Anoop Varghese <vanoop@cdac.in>
 *
 * Copyright (C) 2020 C-DAC Thiruvananthapuram.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#define pr_fmt(fmt) KBUILD_MODNAME ": " fmt

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/interrupt.h>
#include <linux/errno.h>
#include <linux/ioport.h>
#include <linux/crc32.h>
#include <linux/platform_device.h>
#include <linux/spinlock.h>
#include <linux/ethtool.h>
#include <linux/stddef.h>
#include <linux/mii.h>
#include <linux/clk.h>
#include <linux/workqueue.h>
#include <linux/netdevice.h>
#include <linux/etherdevice.h>
#include <linux/skbuff.h>
#include <linux/phy.h>
#include <linux/dma-mapping.h>
#include <linux/of.h>
#include <linux/of_net.h>
#include <linux/of_irq.h>
#include <linux/of_platform.h>
#include <linux/of_address.h>
#include <linux/types.h>
#include <linux/irqdomain.h>
#include <linux/spinlock.h>
#include <linux/io.h>

#include "cdac_mac.h"
#include "ermac.h"
#include <asm/csr.h>

#define MODNAME 		"cdac_mac"
#define DRV_NAME        "cdac_mac"
#define DRV_VERSION 	"1.00"
#define DRV_DESC        "CDAC ERMAC driver"

#define DEBUG

#define ENET_MAXF_SIZE 		1536
#define ENET_RX_DESC 		48
#define ENET_TX_DESC 		16

#define NAPI_WEIGHT 		0

#define NO_IRQ	((unsigned int)(-1))

void __iomem *			gDma_base;

/*
 * powerdown register definitions
 */
#define CDAC_POWERDOWN_MACAHB			(1 << 31)

/*
 * MAC support functions
 */
static void __cdac_set_mac(struct net_device *ndev, u8 *mac) {
	unsigned int mac_addr;
	struct dev_priv *priv = netdev_priv(ndev);

	mac_addr = mac[0] << 8 | mac[1] ;
	writel(mac_addr,(priv->net_base+ERMAC_ADDR_HIGH_REG));
	mac_addr = mac[2] << 24 | mac[3] << 16 |mac[4] << 8 | mac[5];
	writel(mac_addr,(priv->net_base+ERMAC_ADDR_LOW_REG));
	netdev_dbg(ndev, "Ethernet MAC address %pM\n", mac);
}

static void __cdac_get_mac(struct net_device *ndev, u8 *mac) {
	unsigned int mac_addr;
	struct dev_priv *priv = netdev_priv(ndev);

	mac_addr =  readl((priv->net_base+ERMAC_ADDR_HIGH_REG));
	mac[0] = (mac_addr >> 8) & 0xff;
	mac[1] = mac_addr & 0xff;
	mac_addr = readl((priv->net_base+ERMAC_ADDR_LOW_REG));
	mac[2] = mac_addr >> 24;
	mac[3] = (mac_addr >> 16) & 0xff;
	mac[4] = (mac_addr >> 8) & 0xff;
	mac[5] = mac_addr & 0xff;
}

static void __cdac_params_setup(struct net_device *ndev) {
	//printk("*********__cdac_params_setup \n");
}

static void __cdac_eth_reset(struct net_device *ndev) {
	//printk("*********__cdac_eth_reset \n");

}

static int __cdac_mii_mngt_reset(struct dev_priv *priv) {
	//printk("*********__cdac_mii_mngt_reset \n");

	return 0;
}

static void cdac_eth_enable_int(void __iomem *regbase) {
	//printk("*********cdac_eth_enable_int \n");

}

//static void cdac_eth_disable_int(void __iomem *regbase) {
	//printk("*********cdac_eth_disable_int \n");

//}

static void __cdac_eth_init(struct net_device *ndev) {
	struct dev_priv *priv = netdev_priv(ndev);
	__cdac_params_setup(ndev);
	smp_wmb();
	Init_PHY_default_SAF_GMAC(priv->net_base);
	cdac_eth_enable_int((void __iomem *)(priv->net_base));
}

static void __cdac_eth_shutdown(struct net_device *ndev) {
	/* Reset ethernet and power down PHY */
	__cdac_eth_reset(ndev);
}

/*
 * MAC<--->PHY support functions
 */
static int cdac_mii_read(struct mii_bus *bus, int phy_id, int phyreg) {
	int lps = 0;
	unsigned int mdio_op_reg;
	struct dev_priv *priv = bus->priv;
	writel(MII_READ_DATA_CMD(phy_id, phyreg),(priv->net_base + ERMAC_MII_MNGMNT_CNTRL_REG));
	//printk("[C-DAC DEBUG] @cdac_mii_read   : %x.\n", MII_READ_DATA_CMD(phy_id, phyreg));
	while (1) {
		mdio_op_reg = readl((priv->net_base + ERMAC_MII_MNGMNT_CNTRL_REG));
		//printk("%lx\n",mdio_op_reg);
		if ((mdio_op_reg & PHY_BUSY_BIT) == 0)
			break; //read OK
	}
	lps = readl((priv->net_base+ERMAC_MII_READ_DATA_REG)); //phy reg data
	//printk("[C-DAC DEBUG] @cdac_mii_read exit, lps : %x.\n",lps);
	lps = lps >> 8;
	return lps;
}


/*static int cdac_phyreg_read(int phy_id, int phyreg) {

	int lps = 0;
	unsigned int mdio_op_reg;

	cdac_writeword(0, ERMAC_MII_MNGMNT_CNTRL_REG, (MDIO_READ_COMMAND | (phy_id << 26) |(phyreg << 21)));
	while (1) {

		mdio_op_reg = readl(0, ERMAC_MII_MNGMNT_CNTRL_REG);
		if (mdio_op_reg & (1 << 31))
			break; //read OK
	}

	lps = readl(0, ERMAC_MII_READ_DATA_REG); //phy reg data

	return lps;
}*/


static int cdac_mii_write(struct mii_bus *bus, int phy_id, int phyreg,	u16 phydata) {
/*	unsigned int mdio_op_reg;

	cdac_writeword(bus->priv->net_base, ERMAC_MDIO_WRITE_DATA_REG, phydata); //data to write
	cdac_writeword(bus->priv->net_base, ERMAC_MII_MNGMNT_CNTRL_REG, (MDIO_WRITE_COMMAND | (phy_id << 26) |( phyreg << 21))); //command for write
	__asm__ __volatile__ ("fence"); //To complete the read fifo operation in O-O-O processor
	 while (1){
		 mdio_op_reg = readl(priv->net_base,ERMAC_MII_MNGMNT_CNTRL_REG);
		 if(mdio_op_reg & (1 << 31))
			break; //PHY reg write OK
	 }*/
	return 0;
}

static int cdac_mii_reset(struct mii_bus *bus) {
	//printk("*********cdac_mii_reset \n");

	return __cdac_mii_mngt_reset((struct dev_priv *) bus->priv);
}

static void cdac_handle_link_change(struct net_device *ndev) {
	struct phy_device *phydev = ndev->phydev;
	unsigned long flags;
	struct dev_priv *priv = netdev_priv(ndev);

	bool status_change = false;

	spin_lock_irqsave(&priv->chip_lock, flags);

	if (phydev->link) {
		if ((priv->speed != phydev->speed)
				|| (priv->duplex != phydev->duplex)) {
			priv->speed = phydev->speed;
			priv->duplex = phydev->duplex;
			status_change = true;
		}
	}

	if (phydev->link != priv->link) {
		if (!phydev->link) {
			priv->speed = 0;
			priv->duplex = -1;
		}
		priv->link = phydev->link;

		status_change = true;
	}

	spin_unlock_irqrestore(&priv->chip_lock, flags);

	if (status_change) {
		if (phydev->link) {
			netdev_info(ndev, "link up (%d/%s)\n",
			       phydev->speed,
			       DUPLEX_FULL == phydev->duplex ? "Full" : "Half");
			//netif_carrier_on(ndev);
		}
		else {
			netdev_info(ndev, "link down\n");
			//netif_carrier_off(ndev);
		}
		__cdac_params_setup(ndev);
	}
}

static int cdac_mii_probe(struct net_device *ndev) {
	struct dev_priv *priv = netdev_priv(ndev);
	struct phy_device *phydev = phy_find_first(priv->mii_bus);

	if (!phydev) {
		netdev_err(ndev, "no PHY found\n");
		return -ENODEV;
	}

	//printk("*********cdac_mii_probe \n");

	/* Attach to the PHY */
	//if (cdac_phy_interface_mode(&priv->pdev->dev) == PHY_INTERFACE_MODE_GMII)
	//	netdev_info(ndev, "using GMII interface\n");
	//else

	netdev_info(ndev, "using MII interface\n");
	phydev = phy_connect(ndev, phydev_name(phydev), &cdac_handle_link_change, PHY_INTERFACE_MODE_MII);

	if (IS_ERR(phydev)) {
		netdev_err(ndev, "Could not attach to PHY\n");
		return PTR_ERR(phydev);
	}

	/* mask with MAC supported features */
	//phydev->supported &= PHY_BASIC_FEATURES;
	linkmode_and(phydev->supported, phydev->supported, PHY_BASIC_FEATURES);

	//phydev->advertising = phydev->supported;
	linkmode_copy(phydev->advertising, phydev->supported);

	phy_attached_info(phydev);

	return 0;
}

static int cdac_mii_init(struct net_device *ndev) {
	int err;
	struct dev_priv *priv = netdev_priv(ndev);
	int i;
	const char *mode;
	err = -ENXIO;
	priv->mii_bus = mdiobus_alloc();
	if (!priv->mii_bus) {
		err = -ENOMEM;
		goto err_out;
	}

	priv->mii_bus->name = "cdac_mii_bus";
	priv->mii_bus->read = &cdac_mii_read;
	priv->mii_bus->write = &cdac_mii_write;
	priv->mii_bus->reset = &cdac_mii_reset;

	snprintf(priv->mii_bus->id, MII_BUS_ID_SIZE, "%s-%x", priv->pdev->name,
			priv->pdev->id);
	priv->mii_bus->priv = priv;
	priv->mii_bus->parent = &priv->pdev->dev;


	for (i = 0; i < PHY_MAX_ADDR; i++)
		priv->mii_bus->irq[i] = PHY_POLL;


	mode = of_get_property(priv->pdev->dev.of_node, "platform", NULL);
	//if (mode && !strcmp(mode, "htg_virtex7"))
	//	priv->mii_bus->phy_mask = ~(1 << 3);// used phy


	platform_set_drvdata(priv->pdev, priv->mii_bus);

	if (mdiobus_register(priv->mii_bus))
		goto err_out_unregister_bus;
	if (cdac_mii_probe(priv->ndev) != 0)
		goto err_out_unregister_bus;

	return 0;

	err_out_unregister_bus: mdiobus_unregister(priv->mii_bus);
	mdiobus_free(priv->mii_bus);
	err_out: return err;
}

static void __cdac_handle_xmit(struct net_device *ndev) {
	//struct dev_priv *priv = netdev_priv(ndev);
	//int skblen;

	/*skblen=priv->tx_len[priv->tx_intr_index];
	priv->tx_intr_index++;
	if(priv->tx_intr_index==100)
		priv->tx_intr_index=0;

	ndev->stats.tx_bytes += skblen;*/
	//printk("*********__cdac_handle_xmit\n");
	ndev->stats.tx_packets++;
}


static int __cdac_handle_recv(struct net_device *ndev, int budget) {
	struct dev_priv *priv = netdev_priv(ndev);
	int rx_done = 0;
	unsigned int len = 0;
	struct sk_buff *skb;
	//printk("*********__cdac_handle_recv\n");
	while(1) {

		if ((len = check_gmac_rx(priv->net_base)) == 0) {
			return 0;
		}

		/* Packet is good */
		skb = netdev_alloc_skb(ndev, (len+2));
		if (!skb) {
			ndev->stats.rx_dropped++;
		} else {
			skb_reserve(skb, 2);
			receive_ethernet(skb->data, priv->net_base, len);
			skb_put(skb, len);
			skb->protocol = eth_type_trans(skb, ndev);
			netif_rx(skb);
			ndev->stats.rx_packets++;
			ndev->stats.rx_bytes += len;
		}
	}

	return rx_done;
}

/*static int cdac_eth_poll(struct napi_struct *napi, int budget) {
	struct dev_priv
	*priv = container_of(napi, struct dev_priv, napi);
	struct net_device *ndev = priv->ndev;
	int rx_done = 0;
	//struct netdev_queue *txq = netdev_get_tx_queue(ndev, 0);

	//printk("*********cdac_eth_poll %d \n", budget);

	//__netif_tx_lock(txq, smp_processor_id());
	//__cdac_handle_xmit(ndev);
	//__netif_tx_unlock(txq);
	rx_done = __cdac_handle_recv(ndev, budget);

	//if (rx_done < budget) {
	//napi_complete_done(napi, rx_done);
	//cdac_eth_enable_int(priv->net_base);
	//}

	return rx_done;
}*/

int gIntrflag = 0;

static irqreturn_t __cdac_eth_interrupt(int irq, void *dev_id) {
	struct net_device *ndev = dev_id;
	struct dev_priv *priv = netdev_priv(ndev);
	UI intr_status;
	//printk("*********__cdac_eth_interrupt\n");
	spin_lock(&priv->chip_lock);

	intr_status = readl(priv->net_base + ERMAC_INTR_STATUS_REG); //to clear gmac interrupt
	//__asm__ volatile ("fence");

	if (intr_status & TX_INTR_STAT) {
		//printk("*********__cdac_handle_xmit [%x]\n", intr_status);
		__cdac_handle_xmit(ndev);
	}

	if (intr_status & RX_INTR_STAT) {
		//printk("*********__cdac_handle_recv [%x]\n", intr_status);
		__cdac_handle_recv(ndev, 0);
	}
//	printk("[C-DAC DEBUG] before sbi_clear_seip_set_meie@cdac_gmac\n");
	//sbi_clear_seip_set_meie(); //clear seip, and set meie after supervisor ext. intr.
  //printk("[C-DAC DEBUG] after sbi_clear_seip_set_meie@cdac_gmac\n");
	//sbi_clear_suip_set_muie();


	spin_unlock(&priv->chip_lock);

	//printk("********* __cdac_eth_interrupt finished\n");
	return IRQ_HANDLED;
}

#ifdef CONFIG_NET_POLL_CONTROLLER
/*static void cdac_gmac_poll(struct net_device *ndev)
 {
 unsigned long flags;
 printk("*********cdac_gmac_poll?????????????? \n");
 //local_irq_save(flags);
 //__cdac_eth_interrupt(0, ndev);
 //local_irq_restore(flags);
 }*/
#endif

static int cdac_eth_close(struct net_device *ndev) {
	unsigned long flags;
	struct dev_priv *priv = netdev_priv(ndev);

	if (netif_msg_ifdown(priv))
		dev_dbg(&priv->pdev->dev, "shutting down %s\n", ndev->name);

	//napi_disable(&priv->napi);

	//del_timer_sync(&priv->timer);

	netif_stop_queue(ndev);

	if (ndev->phydev)
		phy_stop(ndev->phydev);

	spin_lock_irqsave(&priv->chip_lock, flags);
	__cdac_eth_reset(ndev);

	free_irq(ndev->irq, ndev);

	//netif_carrier_off(ndev);
	spin_unlock_irqrestore(&priv->chip_lock, flags);

	return 0;
}

static int cdac_eth_hard_start_xmit(struct sk_buff *skb,
		struct net_device *ndev) {
	struct dev_priv *priv = netdev_priv(ndev);
	unsigned long flags;
	//unsigned int tx_status;

	spin_lock_irqsave(&priv->chip_lock, flags);

	/*tx_status = readl(priv->net_base, ERMAC_TX_DATA_FIFO_STATUS_REG);
	tx_status = (tx_status & 0x7ff) * 4;	//bytes in tx fifo
	tx_status = 8000 - tx_status; //free space  in tx fifo*/

	/*if (skb->len > tx_status) {
		// This function should never be called when there are no
		// buffers
		printk("*********netif_stop_queue : \n");
		netif_stop_queue(ndev);
		spin_unlock_irqrestore(&priv->chip_lock, flags);
		WARN(1, "BUG! TX request when no free TX buffers!\n");
		return NETDEV_TX_BUSY;
	}*/

	send_ethernet(skb->data, priv->net_base, skb->len);

	ndev->stats.tx_bytes += skb->len;

	/*priv->tx_len[priv->tx_index] = skb->len;
	priv->tx_index++;
	if(priv->tx_index == 100)
		priv->tx_index = 0;

	tx_status = readl(0, ERMAC_TX_DATA_FIFO_STATUS_REG);
	tx_status = (tx_status & 0x7ff) * 4;		//bytes in tx fifo
	tx_status = 8000 - tx_status; //free space  in tx fifo*/

	/*if (skb->len > tx_status) {
		/ //This function should never be called when there are no
		// buffers
		printk("*********netif_stop_queue : \n");
		netif_stop_queue(ndev);
	}*/

	wmb();
	/* drain writebuffer */
	dev_kfree_skb_any(skb);

	spin_unlock_irqrestore(&priv->chip_lock, flags);

	return NETDEV_TX_OK;
}

static int cdac_set_mac_address(struct net_device *ndev, void *p) {
	struct sockaddr *addr = p;
	struct dev_priv *priv = netdev_priv(ndev);
	unsigned long flags;

	if (!is_valid_ether_addr(addr->sa_data))
		return -EADDRNOTAVAIL;
	memcpy(ndev->dev_addr, addr->sa_data, ETH_ALEN);

	spin_lock_irqsave(&priv->chip_lock, flags);

	/* Set station address */
	__cdac_set_mac(ndev, ndev->dev_addr);

	spin_unlock_irqrestore(&priv->chip_lock, flags);

	return 0;
}

//static void cdac_eth_set_multicast_list(struct net_device *ndev) {

	//printk("*********cdac_eth_set_multicast_list \n");

/*#ifdef __USED_CDAC

	struct dev_priv *priv = netdev_priv(ndev);
	struct netdev_hw_addr_list *mcptr = &ndev->mc;
	struct netdev_hw_addr *ha;
	u32 tmp32, hash_val, hashlo, hashhi;
	unsigned long flags;

	spin_lock_irqsave(&priv->chip_lock, flags);

	// Set station address //
	__cdac_set_mac(pldat, ndev->dev_addr);

	tmp32 = CDAC_RXFLTRW_ACCEPTUBROADCAST | CDAC_RXFLTRW_ACCEPTPERFECT;

	if (ndev->flags & IFF_PROMISC)
	tmp32 |= CDAC_RXFLTRW_ACCEPTUNICAST |
	CDAC_RXFLTRW_ACCEPTUMULTICAST;
	if (ndev->flags & IFF_ALLMULTI)
	tmp32 |= CDAC_RXFLTRW_ACCEPTUMULTICAST;

	if (netdev_hw_addr_list_count(mcptr))
	tmp32 |= CDAC_RXFLTRW_ACCEPTUMULTICASTHASH;

//	writel(tmp32, CDAC_ENET_RXFILTER_CTRL(pldat->net_base));

	// Set initial hash table //
	hashlo = 0x0;
	hashhi = 0x0;

	// 64 bits : multicast address in hash table //
	netdev_hw_addr_list_for_each(ha, mcptr) {
		hash_val = (ether_crc(6, ha->addr) >> 23) & 0x3F;

		if (hash_val >= 32)
		hashhi |= 1 << (hash_val - 32);
		else
		hashlo |= 1 << hash_val;
	}

	//writel(hashlo, CDAC_ENET_HASHFILTERL(pldat->net_base));
	//writel(hashhi, CDAC_ENET_HASHFILTERH(pldat->net_base));

	spin_unlock_irqrestore(&priv->chip_lock, flags);

#endif //__USED_CDAC*/

//}

static int cdac_eth_ioctl(struct net_device *ndev, struct ifreq *req, int cmd) {
	//printk("*********cdac_eth_ioctl \n");

	struct phy_device *phydev = ndev->phydev;

	if (!netif_running(ndev))
		return -EINVAL;

	if (!phydev)
		return -ENODEV;

	return phy_mii_ioctl(phydev, req, cmd);
}

static int cdac_eth_open(struct net_device *ndev) {

	struct dev_priv *priv = netdev_priv(ndev);
	int err;

	if (netif_msg_ifup(priv))
		dev_dbg(&priv->pdev->dev, "enabling %s\n", ndev->name);

	/* Suspended PHY makes CDAC ethernet core block, so resume now */
	//phy_resume(ndev->phydev);

	/* Reset and initialize */
	__cdac_eth_reset(ndev);

	/* Setup error IRQ handler */
	err = request_irq(ndev->irq, __cdac_eth_interrupt, 0, ndev->name, ndev);
	if (err) {
		printk(KERN_ERR "%s: failed to request IRQ %d\n",
		       ndev->name, ndev->irq);
		return err;
	}

	__cdac_eth_init(ndev);
//	printk("eth open 1 ok \n");

	priv->tx_index=0;
	priv->tx_intr_index=0;

	/* schedule a link state check */
	phy_start(ndev->phydev);
//	printk("eth open 2 ok \n");

	//priv->timer.expires = jiffies;

	//add_timer(&priv->timer);

	netif_start_queue(ndev);

//	printk("eth open 3 ok \n");

	//napi_enable(&priv->napi);

	return 0;
}

/*
 * Ethtool ops
 */
static void cdac_eth_ethtool_getdrvinfo(struct net_device *ndev,
		struct ethtool_drvinfo *info) {
	strlcpy(info->driver, MODNAME, sizeof(info->driver));
	strlcpy(info->version, DRV_VERSION, sizeof(info->version));
	strlcpy(info->bus_info, dev_name(ndev->dev.parent), sizeof(info->bus_info));
}

static u32 cdac_eth_ethtool_getmsglevel(struct net_device *ndev) {
	struct dev_priv *priv = netdev_priv(ndev);

	return priv->msg_enable;
}

static void cdac_eth_ethtool_setmsglevel(struct net_device *ndev, u32 level) {
	struct dev_priv *priv = netdev_priv(ndev);

	priv->msg_enable = level;
}

static const struct ethtool_ops cdac_eth_ethtool_ops = { .get_drvinfo =
		cdac_eth_ethtool_getdrvinfo, .get_msglevel =
		cdac_eth_ethtool_getmsglevel, .set_msglevel =
		cdac_eth_ethtool_setmsglevel, .get_link = ethtool_op_get_link,
		.get_link_ksettings = phy_ethtool_get_link_ksettings,
		.set_link_ksettings = phy_ethtool_set_link_ksettings, };

static const struct net_device_ops cdac_netdev_ops = {
		.ndo_open = cdac_eth_open, .ndo_stop = cdac_eth_close, .ndo_start_xmit =
				cdac_eth_hard_start_xmit,
//	.ndo_set_rx_mode	= cdac_eth_set_multicast_list,
		.ndo_do_ioctl = cdac_eth_ioctl, .ndo_set_mac_address =
				cdac_set_mac_address, .ndo_validate_addr = eth_validate_addr,
/*#ifdef CONFIG_NET_POLL_CONTROLLER
 .ndo_poll_controller	 = cdac_gmac_poll,
 #endif*/
};

/*static void cdac_riscv_mask_irq(struct irq_data *d) {
	//printk("cdac_riscv_mask_irq\n");

}

static void cdac_riscv_unmask_irq(struct irq_data *d) {
	//printk("cdac_riscv_unmask_irq\n");

}

static struct irq_chip cdac_riscv_irq_chip = { .irq_ack = cdac_riscv_mask_irq,
		.irq_mask = cdac_riscv_mask_irq, .irq_unmask = cdac_riscv_unmask_irq,
		.name = "gmac_irq" };*/

//static void cdac_eth_timer(struct timer_list *t) {

	/*struct dev_priv	  *priv = from_timer(priv, t, timer);
	struct net_device *dev = priv->ndev;

	//struct net_device *dev = (struct net_device *) data;
	//struct dev_priv *priv = netdev_priv(dev);
	struct phy_device *phydev=dev->phydev;

	unsigned int lnkstat, carrier;
	unsigned long flags;

	spin_lock_irqsave(&priv->chip_lock, flags);
	lnkstat = cdac_phyreg_read(3, 1);
	lnkstat = 1;//(lnkstat >> 2) & 1;// Linkup bit
	printk("%d: link stat\n", lnkstat);
	spin_unlock_irqrestore(&priv->chip_lock, flags);
	//phydev->link;//1;
	//read_ireg(dev->base_addr, ISALED0) & ISALED0_LNKST;

	carrier = netif_carrier_ok(dev);

	printk("%d:  carrier\n", carrier);

	if (lnkstat && !carrier) {
		netif_carrier_on(dev);
		printk("%s: link up\n", dev->name);
	} else if (!lnkstat && carrier) {
		netif_carrier_off(dev);
		printk("%s: link down\n", dev->name);
	}

	mod_timer(&priv->timer, jiffies + msecs_to_jiffies(2000));

	//printk("cdac_eth_timer:time_out=%lx\n", (jiffies + msecs_to_jiffies(500)));*/
//}

/*struct riscv_irq_data {
	struct irq_chip chip;
	struct irq_domain *domain;
	int hart;
	char name[20];
};
DEFINE_PER_CPU(struct riscv_irq_data, extern riscv_irq_data);*/

static int cdac_eth_drv_probe(struct platform_device *pdev) {
	struct resource gmac_resource;
	struct net_device *ndev;
	struct dev_priv *priv;
	struct phy_device *phydev;
	struct device_node *np = pdev->dev.of_node;
	int irq, ret = 0;
	if (of_get_property(np, "disabled", NULL) || !of_device_is_available(np))
		return -ENODEV;

	/* Allocate net driver data structure */
	ndev = alloc_etherdev(sizeof(struct dev_priv));
	if (!ndev) {
		dev_err(&pdev->dev, "could not allocate device.\n");
		ret = -ENOMEM;
		goto err_exit;
	}
	SET_NETDEV_DEV(ndev, &pdev->dev);
	priv = netdev_priv(ndev);
	priv->pdev = pdev;
	priv->ndev = ndev;

	spin_lock_init(&priv->chip_lock);
	irq =  irq_of_parse_and_map(np, 0);
	if (irq == NO_IRQ) {
		printk(KERN_ERR "%s: Can't map main interrupt\n", np->full_name);
		goto err_out_free_dev;
	}

	ndev->irq = irq;

	/* Map EMAC regs */
	if (of_address_to_resource(np, 0, &gmac_resource)) {
		printk(KERN_ERR "%s: Can't get registers address\n",
		       np->full_name);
		goto err_irq_unmap;
	}

	//priv->net_base = ioremap(gmac_resource.start, resource_size(&gmac_resource));
	priv->net_base = ioremap_nocache(gmac_resource.start, resource_size(&gmac_resource));

	if (priv->net_base == NULL) {
		printk(KERN_ERR "%s: Can't map device registers!\n",  np->full_name);
		ret = -ENOMEM;
		goto err_irq_unmap;
	}
	ndev->base_addr = (unsigned long)priv->net_base;
	/* Setup driver functions */
	ndev->netdev_ops = &cdac_netdev_ops;
	ndev->ethtool_ops = &cdac_eth_ethtool_ops;
	ndev->watchdog_timeo = msecs_to_jiffies(10000);
	netdev_dbg(ndev, "IO address space     :%pR\n", &gmac_resource);
	netdev_dbg(ndev, "IO address size      :%lld\n", resource_size(&gmac_resource));
	netdev_dbg(ndev, "IO address (mapped)  :0x%ld\n", (long int)priv->net_base);
	netdev_dbg(ndev, "IRQ number           :%d\n", ndev->irq);

	/* Get MAC address from current HW setting (POR state is all zeros) */
	__cdac_get_mac(ndev, ndev->dev_addr);
	if (!is_valid_ether_addr(ndev->dev_addr)) {
		const char *macaddr = of_get_mac_address(pdev->dev.of_node);
		if (macaddr)
			memcpy(ndev->dev_addr, macaddr, ETH_ALEN);
	}
	if (!is_valid_ether_addr(ndev->dev_addr))
		eth_hw_addr_random(ndev);

	/* Reset the ethernet controller */
	__cdac_eth_reset(ndev);
	/* then shut everything down to save power */
	__cdac_eth_shutdown(ndev);

	/* Set default parameters */
	priv->msg_enable = NETIF_MSG_LINK;

	/* Force an MII interface reset and clock setup */
	__cdac_mii_mngt_reset(priv);

	/* Force default PHY interface setup in chip, this will probably be
	 changed by the PHY driver */
	priv->link = 0;
	priv->speed = 100;
	priv->duplex = DUPLEX_FULL;
	__cdac_params_setup(ndev);

	//netif_napi_add(ndev, &priv->napi, cdac_eth_poll, NAPI_WEIGHT);

	ret = register_netdev(ndev);
	if (ret) {
		dev_err(&pdev->dev, "Cannot register net device, aborting.\n");
		goto err_out_iounmap;
	}
	platform_set_drvdata(pdev, ndev);
	ret = cdac_mii_init(ndev);
	if (ret)
		goto err_out_unregister_netdev;

	netdev_info(ndev, "CDAC mac at 0x%08llx irq %d\n", gmac_resource.start, ndev->irq);
	phydev = ndev->phydev;

	device_init_wakeup(&pdev->dev, 1);
	device_set_wakeup_enable(&pdev->dev, 1);
	return 0;

	err_out_unregister_netdev:
		 unregister_netdev(ndev);
	err_out_iounmap:
		 iounmap((volatile void *)(priv->net_base));
	err_irq_unmap:
		irq_dispose_mapping(irq);
	err_out_free_dev:
		free_netdev(ndev);
	err_exit:
	pr_err("%s: not found (%d).\n", MODNAME, ret);

	return ret;
}

static int cdac_eth_drv_remove(struct platform_device *pdev) {
	struct net_device *ndev = platform_get_drvdata(pdev);
	struct dev_priv *priv = netdev_priv(ndev);

	unregister_netdev(ndev);
	iounmap((volatile void *)(priv->net_base));
	mdiobus_unregister(priv->mii_bus);
	mdiobus_free(priv->mii_bus);
	free_netdev(ndev);

	return 0;
}

#ifdef CONFIG_PM
static int cdac_eth_drv_suspend(struct platform_device *pdev,
		pm_message_t state)
{
	struct net_device *ndev = platform_get_drvdata(pdev);
	struct netdata_local *pldat = netdev_priv(ndev);

	if (device_may_wakeup(&pdev->dev))
	enable_irq_wake(ndev->irq);

	if (ndev) {
		if (netif_running(ndev)) {
			netif_device_detach(ndev);
			__cdac_eth_shutdown(pldat);
			clk_disable_unprepare(pldat->clk);

			/*
			 * Reset again now clock is disable to be sure
			 * EMC_MDC is down
			 */
			__cdac_eth_reset(pldat);
		}
	}

	return 0;
}

static int cdac_eth_drv_resume(struct platform_device *pdev)
{
	struct net_device *ndev = platform_get_drvdata(pdev);
	struct netdata_local *pldat;

	if (device_may_wakeup(&pdev->dev))
	disable_irq_wake(ndev->irq);

	if (ndev) {MODULE_DEVICE_TABLE(of, cdac_dma_match);
			/* Enable interface clock */
			clk_enable(pldat->clk);

			/* Reset and initialize */
			__cdac_eth_reset(pldat);
			__cdac_eth_init(pldat);

			netif_device_attach(ndev);
		}
	}

	return 0;
}
#endif

#ifdef CONFIG_OF
static const struct of_device_id cdac_gmac_match[] = {
	{
		.type		= "network",
		.compatible 	= "cdac,cdac_mac"
	},
	{}
};

MODULE_DEVICE_TABLE(of, cdac_gmac_match);
#endif

static struct platform_driver cdac_gmac_driver = {
	.probe = cdac_eth_drv_probe,
	.remove = cdac_eth_drv_remove,
	.driver = {
		.name = "cdac_mac",
                .owner = THIS_MODULE,
		.of_match_table = of_match_ptr(cdac_gmac_match),
	},
#ifdef CONFIG_PM
	.suspend = cdac_eth_drv_suspend,
	.resume = cdac_eth_drv_resume,
#endif

};

static int __init cdac_gmac_init(void)
{
	int rc;

	printk(KERN_INFO DRV_DESC ", version " DRV_VERSION "\n");

	rc = platform_driver_register(&cdac_gmac_driver);
	if (rc)
		goto err;

	return 0;

 err:
	return rc;
}

static void __exit cdac_gmac_exit(void)
{
	platform_driver_unregister(&cdac_gmac_driver);

}

module_init(cdac_gmac_init);
module_exit(cdac_gmac_exit);

MODULE_AUTHOR("Sreenadh S <sreenadh@cdac.in>, Anoop Varghese <vanoop@cdac.in>");
MODULE_DESCRIPTION("CDAC Ethernet Driver");
MODULE_LICENSE("GPL");
