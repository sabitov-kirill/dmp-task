//
// Created by ne1mnn on 1/29/24.
//

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sabitov Kirill");
MODULE_VERSION("0.01");

int dmp_init(void) {
    printk(KERN_INFO "Hello, World!\n");
    return 0;
}

void dmp_exit(void) { printk(KERN_INFO "Goodbye!\n"); }

module_init(dmp_init);
module_exit(dmp_exit);