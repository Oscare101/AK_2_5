#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/moduleparam.h>
#include <linux/types.h>

MODULE_AUTHOR("Fedortsev Kyryl IO-81");
MODULE_DESCRIPTION("Hello world!");
MODULE_LICENSE("Dual BSD/GPL");

static uint number = 1;
module_param(number, uint, 0);
MODULE_PARM_DESC(number, " How many times to print \"Hello world!\"");

static int __init hello_init(void)
{
	uint i = 0;
	
	printk(KERN_INFO "number: %d\n", number);
	
	if(number == 0) {
		printk(KERN_WARNING "Parameter = 0");
	} else if(number >= 5 && number <= 10) {
		printk(KERN_WARNING "Parameter is between [5,10]");
	} else if(number > 10){
		printk(KERN_ERR "Parameter is higher than 10");
		return -EINVAL;
	}
	
	for(i = 0; i < number; i++){
		printk(KERN_INFO "Hello world!\n");
	}
	return 0;
}

static void __exit hello_exit(void)
{
	/* Do nothing here right now */
}

module_init(hello_init);
module_exit(hello_exit);
