//
// Created by ne1mnn on 1/29/24.
//

#include <linux/kernel.h>
#include <linux/module.h>

#include "display_stat.h"

#define DISPLAY_STAT_AVG(count, value) ((count) == 0 ? 0 : (value) / (count))

struct device_stat volumes_stat;

static ssize_t volumes_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf) {
    return sprintf(
            buf,
            "read:\n"
            " reqs: %d\n"
            " avg size: %zu\n"
            "write:\n"
            " reqs: %d\n"
            " avg size: %zu\n"
            "total:\n"
            " reqs: %d\n"
            " avg size: %zu\n",
            volumes_stat.read.count,
            DISPLAY_STAT_AVG(volumes_stat.read.blocks_count, volumes_stat.read.blocks_total_size),
            volumes_stat.write.count,
            DISPLAY_STAT_AVG(volumes_stat.write.blocks_count, volumes_stat.write.blocks_total_size),
            volumes_stat.read.count + volumes_stat.write.count,
            DISPLAY_STAT_AVG(volumes_stat.read.blocks_count + volumes_stat.write.blocks_count,
                             volumes_stat.read.blocks_total_size + volumes_stat.write.blocks_total_size)
    );
}

static struct kobj_attribute volumes_attribute = __ATTR_RO(volumes);

static struct attribute *attrs[] = {
        &volumes_attribute.attr,
        NULL,
};

static struct attribute_group attr_group = {
        .name = "stat",
        .attrs = attrs,
};

int display_init(void) {
    struct kobject *module_kobj = &THIS_MODULE->mkobj.kobj;
    if (sysfs_create_group(module_kobj, &attr_group) < 0) {
        pr_err("dmp: Failed to create stat directory group\n");
        return -ENOMEM;
    }

    return 0;
}

void display_exit(void) {
    struct kobject *module_kobj = &THIS_MODULE->mkobj.kobj;
    sysfs_remove_group(module_kobj, &attr_group);
}