//
// Created by ne1mnn on 1/29/24.
//

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

#include "dmp.h"

MODULE_LICENSE("GPL");
MODULE_VERSION("0.01");

int dmp_module_init(void) { return dmp_init(); }

void dmp_module_exit(void) { dmp_exit(); }

module_init(dmp_module_init);
module_exit(dmp_module_exit);