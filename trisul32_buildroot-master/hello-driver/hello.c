// hello.c - Simple Hello World Linux Kernel Module
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init hello_init(void)
{
    pr_info("Hello, RISC-V World! Kernel module loaded.\n");
    return 0;
}

static void __exit hello_exit(void)
{
    pr_info("Goodbye, RISC-V World! Kernel module unloaded.\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Out-of-tree Hello World driver for RISC-V Linux");
MODULE_VERSION("1.0");
