// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (C) 2020 C-DAC
 */
#define pr_fmt(fmt) "plic: " fmt
#include <linux/interrupt.h>
#include <linux/io.h>
#include <linux/irq.h>
#include <linux/irqchip.h>
#include <linux/irqdomain.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_irq.h>
#include <linux/platform_device.h>
#include <linux/spinlock.h>
#include <linux/delay.h>

/*
 * This driver implements a version of the RISC-V PLIC with the actual layout
 * specified in chapter 8 of the SiFive U5 Coreplex Series Manual:
 *
 * The largest number supported by devices marked as 'sifive,plic-1.0.0', is
 * 1024, of which device 0 is defined as non-existent by the RISC-V Privileged
 * Spec.
 */

#define MAX_DEVICES			1024
#define MAX_CONTEXTS		15872

#define RAW_INTR 			0x00
#define INTR_EN 			0x18
#define INTR_STATUS 		0x20


static void __iomem *plic_regs;

struct plic_handler {
	bool			present;
	int			ctxid;
};
static DEFINE_PER_CPU(struct plic_handler, plic_handlers);

static DEFINE_RAW_SPINLOCK(plic_toggle_lock);

static inline void plic_toggle(int ctxid, int hwirq, int enable) // For enabling the plic corresponding to 'hwirq'
{
	u32 intr_en;
	intr_en = readl(plic_regs + INTR_EN);
	//printk("[C-DAC DEBUG] @plic_toggle  : %x \n", enable);
	if(enable)
		intr_en |= BIT_ULL(hwirq);
	else
		intr_en &= ~(BIT_ULL(hwirq));

	raw_spin_lock(&plic_toggle_lock);
	writel(intr_en, plic_regs + INTR_EN);
	__asm__ volatile ("fence");
	raw_spin_unlock(&plic_toggle_lock);
}
static inline void plic_irq_toggle(struct irq_data *d, int enable)
{
	u32 intr_en;

	intr_en = readl(plic_regs + INTR_EN);
	//printk("[C-DAC DEBUG] @plic_irq_toggle : %d --> %x \n", d->hwirq, enable);
	if(enable)
		intr_en |= BIT_ULL(d->hwirq);
	else
		intr_en &= ~(BIT_ULL(d->hwirq));

	writel(intr_en, plic_regs + INTR_EN);
	//intr_en = readq(plic_regs + INTR_EN);
	//printk("[C-DAC DEBUG] @plic_en_reg : %lx \n", intr_en);
}

static void plic_irq_enable(struct irq_data *d)
{
	plic_irq_toggle(d, 1);
}

static void plic_irq_disable(struct irq_data *d)
{
	plic_irq_toggle(d, 0);
}

static struct irq_chip plic_chip = {
	.name		= "CDAC PLIC",
	/*
	 * There is no need to mask/unmask PLIC interrupts.  They are "masked"
	 * by reading claim and "unmasked" when writing it back.
	 */
	.irq_enable	= plic_irq_enable,
	.irq_disable	= plic_irq_disable,
};

static int plic_irqdomain_map(struct irq_domain *d, unsigned int irq,
			      irq_hw_number_t hwirq)
{
	irq_set_chip_and_handler(irq, &plic_chip, handle_simple_irq);
	irq_set_chip_data(irq, NULL);
	irq_set_noprobe(irq);
	return 0;
}

static const struct irq_domain_ops plic_irqdomain_ops = {
	.map		= plic_irqdomain_map,
	.xlate		= irq_domain_xlate_onecell,
};

static struct irq_domain *plic_irqdomain;

/*
 * Handling an interrupt is a two-step process: first you claim the interrupt
 * by reading the claim register, then you complete the interrupt by writing
 * that source ID back to the same claim register.  This automatically enables
 * and disables the interrupt, so there's nothing else to do.
 */
static void plic_handle_irq(struct pt_regs *regs)
{
	//printk("[C-DAC DEBUG] @plic_handle_irq \n");
	struct plic_handler *handler = this_cpu_ptr(&plic_handlers);
	irq_hw_number_t hwirq;
	u32 intr_status;
	int i, irq;

	WARN_ON_ONCE(!handler->present);

	csr_clear(sie, SIE_SEIE);
        __asm__ volatile ("fence");
	intr_status = readl(plic_regs + INTR_STATUS);
	for(i=0;i<32;i++){
		if((intr_status >> i) & 1)
			hwirq = i;
		else
			continue;

		//printk("[C-DAC DEBUG] hw_irq=%d \n", hwirq);
		irq= irq_find_mapping(plic_irqdomain, hwirq);
		//printk("[C-DAC DEBUG] irq=%d \n", irq);
		if (unlikely(irq <= 0))
			pr_warn_ratelimited("can't find mapping for hwirq %lu\n",
					hwirq);
		else
			generic_handle_irq(irq);
			//printk("[C-DAC DEBUG] generic_handle_irq over \n");
	}

	__asm__ volatile ("fence");
	csr_set(sie, SIE_SEIE);
}

/*
 * Walk up the DT tree until we find an active RISC-V core (HART) node and
 * extract the cpuid from it.
 */
static int plic_find_hart_id(struct device_node *node)
{
	for (; node; node = node->parent) {
		if (of_device_is_compatible(node, "riscv"))
			return riscv_of_processor_hartid(node);
	}

	return -1;
}

static int __init plic_init(struct device_node *node,
		struct device_node *parent)
{
	int error = 0, nr_handlers, nr_mapped = 0, i;
	u32 nr_irqs;

	if (plic_regs) {
		pr_warn("PLIC already present.\n");
		return -ENXIO;
	}

	plic_regs = of_iomap(node, 0);
	if (WARN_ON(!plic_regs))
		return -EIO;

	error = -EINVAL;
	of_property_read_u32(node, "riscv,ndev", &nr_irqs);
	if (WARN_ON(!nr_irqs))
		goto out_iounmap;

	nr_handlers = of_irq_count(node);
	if (WARN_ON(!nr_handlers))
		goto out_iounmap;
	if (WARN_ON(nr_handlers < num_possible_cpus()))
		goto out_iounmap;

	error = -ENOMEM;
	plic_irqdomain = irq_domain_add_linear(node, nr_irqs + 1,
			&plic_irqdomain_ops, NULL);
	if (WARN_ON(!plic_irqdomain))
		goto out_iounmap;

	for (i = 0; i < nr_handlers; i++) {
		struct of_phandle_args parent;
		struct plic_handler *handler;
		irq_hw_number_t hwirq;
		int cpu;

		if (of_irq_parse_one(node, i, &parent)) {
			pr_err("failed to parse parent for context %d.\n", i);
			continue;
		}

		/* skip context holes */
		if (parent.args[0] == -1)
			continue;

		cpu = plic_find_hart_id(parent.np);
		if (cpu < 0) {
			pr_warn("failed to parse hart ID for context %d.\n", i);
			continue;
		}

		handler = per_cpu_ptr(&plic_handlers, cpu);
		handler->present = true;
		handler->ctxid = i;

		/* priority must be > threshold to trigger an interrupt */
		//writel(0, plic_hart_offset(i) + CONTEXT_THRESHOLD);
		for (hwirq = 1; hwirq < nr_irqs; hwirq++)
			plic_toggle(i, hwirq, 0);
		nr_mapped++;
	}

	pr_info("mapped %d interrupts to %d (out of %d) handlers.\n",
		nr_irqs, nr_mapped, nr_handlers);
	set_handle_irq(plic_handle_irq);
	return 0;

out_iounmap:
	iounmap(plic_regs);
	return error;
}

IRQCHIP_DECLARE(cdac_plic,"cdac,plic-1.0.0",plic_init);
IRQCHIP_DECLARE(riscv_plic0, "riscv,plic0", plic_init);	/* for legacy systems	*/
