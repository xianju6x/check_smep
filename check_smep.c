#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

static int hello_init(void)
{
	long ret;
	__asm__ (
			"mov %%cr4, %%rax\n\t"
			: "=a" (ret));

	printk(KERN_ALERT"SMAP(bit21) is %ld\n", (ret>>21)&1 );
	printk(KERN_ALERT"SMEP(bit20) is %ld\n", (ret>>20)&1 );
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "eixt\n");
}

module_init(hello_init);
module_exit(hello_exit);
