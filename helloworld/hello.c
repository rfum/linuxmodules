#define MODULE
#define LINUX
#define __KERNEL__

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int init_hello(void)
{
	printk("<1>Hello world 1.\n");
	return 0;
}

static void cleanup_hello(void)
{
	printk(KERN_ALERT "Goodbye sweet life");
}
MODULE_LICENSE("GPL");

module_init(init_hello);
module_exit(cleanup_hello);

