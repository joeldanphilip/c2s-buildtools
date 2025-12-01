/*
 * C-DAC Pulse Width Modulation Controller
 *
 * Copyright (C) 2020 C-DAC Thiruvananthapuram.
 *
 */
#include <linux/clk.h>
#include <linux/delay.h>
#include <linux/err.h>
#include <linux/io.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/platform_device.h>
#include <linux/pwm.h>
#include <linux/slab.h>

/* The following is global registers for PWM controller */
#define GLOBAL_CONTROL_REG			0x80
#define GLOBAL_PWM_ENABLE			BIT(0)
#define GLOBAL_INTR_ENABLE			BIT(1)
#define GLOBAL_INTR_PENDING			GENMASK(9, 2)

/* The following register is PWM channel related registers */
#define PWM_CH_CONTROL_REG			0x00
#define PWM_CH_MODE					GENMASK(1, 0)
#define PWM_CH_ALIGN				GENMASK(2, 3)
#define PWM_CH_INTR_ENABLE			BIT(4)
#define PWM_CH_OUTPUT				BIT(5)
#define PWM_CH_COUNT				GENMASK(21, 6)

#define PWM_CH_STATUS_REG			0x04
#define PWM_CH_STATUS				BIT(0)
#define PWM_CH_INTR_PENDING			BIT(1)

#define PWM_CH_PERIOD_REG			0x08
#define PWM_CH_DUTY_REG				0x0C // ON/OFF register as per documentation.

/* PWM Mode Values */
#define PWM_IDLE					0x0
#define PWM_ONE_SHORT				0x1
#define PWM_CONTINUOUS				0x2

#define PWM_LEFT_ALIGN				0x0
#define PWM_RIGHT_ALIGN				0x1

/*
 * Max and Min value for duty and period
 */
#define PWM_MIN_PERIOD				0x2
#define PWM_MAX_PERIOD				0xFFFFFFFF
#define PWM_MIN_DUTY				0x1
#define PWM_MAX_DUTY				(PWM_MAX_PERIOD - 1)

#define PWM_CH_REG_SIZE				0x10
#define PRD_MAX_CHANNELS			8
#define SEC_IN_NS					1000000000


struct cdac_pwm_chip {
	struct pwm_chip chip;
	struct clk *clk;
	void __iomem *base;

	unsigned int updated_pwms;
	/* ISR is cleared when read, ensure only one thread does that */
	struct mutex isr_lock;
};

static inline struct cdac_pwm_chip *to_cdac_pwm_chip(struct pwm_chip *chip)
{
	return container_of(chip, struct cdac_pwm_chip, chip);
}


static inline u32 cdac_pwm_readl(struct cdac_pwm_chip *chip,
				  unsigned int offset)
{
	return readl(chip->base + offset);
}

static inline void cdac_pwm_writel(struct cdac_pwm_chip *chip,
				    unsigned int offset, unsigned int val)
{
	writel(val, chip->base + offset);
}

static unsigned int ns_to_cycle(struct cdac_pwm_chip *cdac_pwm, unsigned int nano_secs){
	unsigned int cycles = (nano_secs * clk_get_rate(cdac_pwm->clk))/SEC_IN_NS ;
	return cycles;
}
static int cdac_pwm_apply(struct pwm_chip *chip, struct pwm_device *pwm,
			    const struct pwm_state *state)
{
	struct cdac_pwm_chip *cdac_pwm = to_cdac_pwm_chip(chip);
	struct pwm_state prev_state;
	unsigned int cycle_period, cycle_duty;
	u32 ctrl_reg;
	int ret;
        
        //pr_err("state->period ::> %d\n",state->period);
        //pr_err("state->duty_cycle ::> %d\n",state->duty_cycle);
        //pr_err("state->enabled ::> %d\n",state->enabled);
        //pr_err("state->polarity ::> %d\n",state->polarity);
        
	pwm_get_state(pwm, &prev_state);
	ns_to_cycle(cdac_pwm, state->period);

	if(prev_state.period != state->period){
		//cycle_period = ns_to_cycle(cdac_pwm, state->period);
		cdac_pwm_writel(cdac_pwm, ((pwm->hwpwm * PWM_CH_REG_SIZE)+PWM_CH_PERIOD_REG), state->period);
	}

	if(prev_state.duty_cycle != state->duty_cycle){
		//cycle_duty = ns_to_cycle(cdac_pwm, state->duty_cycle);
		cdac_pwm_writel(cdac_pwm, ((pwm->hwpwm * PWM_CH_REG_SIZE)+PWM_CH_DUTY_REG), state->duty_cycle);
	}
	if (state->polarity == PWM_POLARITY_NORMAL){
			ctrl_reg = (PWM_CH_ALIGN | (PWM_LEFT_ALIGN << 2));
	}
	else{
			ctrl_reg = (PWM_CH_ALIGN | (PWM_RIGHT_ALIGN << 2));
	}
	//pr_err("state->enabled ::> %d\n",state->enabled);
	if(state->enabled){
		//pr_err("state->enabled 1(ON):::::::::::::>\n");
		ctrl_reg = (PWM_CH_MODE & PWM_CONTINUOUS);
	}else
	{
		//pr_err("state->enabled 0(OFF):::::::::::::>\n");
		ctrl_reg = (PWM_CH_MODE & PWM_IDLE);
	}
	
	//pr_err("ctrl_reg ::> 0x%lx\n",ctrl_reg);
	
	cdac_pwm_writel(cdac_pwm, ((pwm->hwpwm * PWM_CH_REG_SIZE)+PWM_CH_CONTROL_REG), 0);
	cdac_pwm_writel(cdac_pwm, ((pwm->hwpwm * PWM_CH_REG_SIZE)+PWM_CH_CONTROL_REG), ctrl_reg);
	cdac_pwm_writel(cdac_pwm, GLOBAL_CONTROL_REG, 0);
	cdac_pwm_writel(cdac_pwm, GLOBAL_CONTROL_REG, GLOBAL_PWM_ENABLE);
	return 0;
}

static const struct pwm_ops cdac_pwm_ops = {
	.apply = cdac_pwm_apply,
	.owner = THIS_MODULE,
};



static const struct platform_device_id cdac_pwm_devtypes[] = {
	{
		.name = "cdac-pwm",
	}, {
		/* sentinel */
	},
};
MODULE_DEVICE_TABLE(platform, cdac_pwm_devtypes);

static const struct of_device_id cdac_pwm_dt_ids[] = {
	{
		.compatible = "cdac,cdac-pwm",
	}, {
		/* sentinel */
	},
};
MODULE_DEVICE_TABLE(of, cdac_pwm_dt_ids);




static int cdac_pwm_probe(struct platform_device *pdev)
{
	struct cdac_pwm_chip *cdac_pwm;
	struct resource *res;
	int ret;
	//pr_err("Inside cdac_pwm_probe:::::::::::::::::::::::::::::::::::::::::::::::::::>1\n");
	cdac_pwm = devm_kzalloc(&pdev->dev, sizeof(*cdac_pwm), GFP_KERNEL);
	if (!cdac_pwm)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	cdac_pwm->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(cdac_pwm->base))
		return PTR_ERR(cdac_pwm->base);

	cdac_pwm->clk = devm_clk_get(&pdev->dev, "pwm_clock");
	if (IS_ERR(cdac_pwm->clk))
		return PTR_ERR(cdac_pwm->clk);

	ret = clk_prepare(cdac_pwm->clk);
	if (ret) {
		dev_err(&pdev->dev, "failed to prepare PWM clock\n");
		return ret;
	}

	cdac_pwm->chip.dev = &pdev->dev;
	cdac_pwm->chip.ops = &cdac_pwm_ops;

	if (pdev->dev.of_node) {
		cdac_pwm->chip.of_xlate = of_pwm_xlate_with_flags;
		cdac_pwm->chip.of_pwm_n_cells = 3;
	}

	cdac_pwm->chip.base = 0;
	cdac_pwm->chip.npwm = PRD_MAX_CHANNELS;
	cdac_pwm->updated_pwms = 0;
	mutex_init(&cdac_pwm->isr_lock);

	ret = pwmchip_add(&cdac_pwm->chip);
	if (ret < 0) {
		dev_err(&pdev->dev, "failed to add PWM chip %d\n", ret);
		goto unprepare_clk;
	}

	/* Enabling PWM */
	cdac_pwm_writel(cdac_pwm, GLOBAL_CONTROL_REG, GLOBAL_PWM_ENABLE);
	dev_info(&pdev->dev,"C-DAC PWM Controller at 0x%08lx \n", (unsigned int)cdac_pwm->base);
	//pr_err("C-DAC PWM Controller at 0x%08lx \n", (unsigned int)cdac_pwm->base);

	platform_set_drvdata(pdev, cdac_pwm);

	return ret;

unprepare_clk:
	clk_unprepare(cdac_pwm->clk);
	return ret;
}

static int cdac_pwm_remove(struct platform_device *pdev)
{
	struct cdac_pwm_chip *cdac_pwm = platform_get_drvdata(pdev);

	clk_unprepare(cdac_pwm->clk);
	mutex_destroy(&cdac_pwm->isr_lock);

	return pwmchip_remove(&cdac_pwm->chip);
}

static struct platform_driver cdac_pwm_driver = {
	.driver = {
		.name = "cdac-pwm",
		.of_match_table = of_match_ptr(cdac_pwm_dt_ids),
	},
	.id_table = cdac_pwm_devtypes,
	.probe = cdac_pwm_probe,
	.remove = cdac_pwm_remove,
};
module_platform_driver(cdac_pwm_driver);

MODULE_ALIAS("platform:cdac-pwm");
MODULE_DESCRIPTION("C-DAC Thiruvananthapuram PWM Driver");
MODULE_AUTHOR("Anoop Varghese <vanoop@cdac.in>");
MODULE_LICENSE("GPL v2");
