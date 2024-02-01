//
// Created by ne1mnn on 1/29/24.
//

#include <linux/bio.h>
#include <linux/device-mapper.h>

#include "dmp.h"
#include "display_stat.h"

struct dmp_target {
    struct dm_dev *dev;
};

static int dmp_target_ctr(struct dm_target *ti, unsigned int argc, char **argv) {
    printk(KERN_INFO ">> dmp_target_ctr");

    if (argc != 1) {
        printk(KERN_ERR "dmp: Error in constructor: Invalid argument count.\n");
        ti->error = "Invalid argument count";
        return -EINVAL;
    }

    struct dmp_target *dt = kmalloc(sizeof(struct dmp_target), GFP_KERNEL);
    if (dt == NULL) {
        printk(KERN_CRIT "dmp: Error in constructor: No memory.\n");
        ti->error = "No memory";
        return -ENOMEM;
    }

    int lookup_result = dm_get_device(ti, argv[0], dm_table_get_mode(ti->table), &dt->dev);
    if (lookup_result < 0) {
        printk(KERN_CRIT "dmp: Error in constructor: Device lookup failed.\n");
        printk(KERN_INFO "<< dmp_target_ctr");

        ti->error = "Device lookup failed";
        kfree(dt);
        return lookup_result;
    }

    ti->private = dt;

    printk(KERN_INFO "dmp: Created device %s (begin: %llu, len: %llu)", dt->dev->name, ti->begin, ti->len);
    printk(KERN_INFO "<< dmp_target_ctr");
    return 0;
}

static void dmp_target_dtr(struct dm_target *ti) {
    printk(KERN_INFO ">> dmp_target_dtr");

    struct dmp_target *dt = ti->private;
    dm_put_device(ti, dt->dev);
    kfree(dt);

    printk(KERN_INFO "<< dmp_target_dtr");
}

static int dmp_target_map(struct dm_target *ti, struct bio *bio) {
    struct dmp_target *dt = ti->private;

    printk(KERN_INFO ">> dmp_target_map (bio operation: %s, sectors: %llu-%llu (%u), lbs: %u, bi_size: %d, idx: %d)",
           (bio_op(bio) == REQ_OP_READ) ? "READ" :
           (bio_op(bio) == REQ_OP_WRITE) ? "WRITE" : "UNKNOWN",
           (unsigned long long) bio->bi_iter.bi_sector,
           (unsigned long long) (bio->bi_iter.bi_sector + bio_sectors(bio) - 1),
           bio_sectors(bio),
           bdev_logical_block_size(bio->bi_bdev), bio->bi_iter.bi_size, bio->bi_iter.bi_idx);

    struct request_stat *info = bio_data_dir(bio) == READ ? &volumes_stat.read : &volumes_stat.write;
    ++info->blocks_count;
    info->blocks_total_size += bio_sectors(bio) * queue_logical_block_size(bio->bi_bdev->bd_disk->queue);

    // map is executed for each block of bio, so count operation only on first block
    info->count += bio->bi_iter.bi_sector == 0;

    // remap io operation to another target to handle immediate writing or reading
    bio_set_dev(bio, dt->dev->bdev);

    printk(KERN_INFO "<< dmp_target_map");

    return DM_MAPIO_REMAPPED;
}

static struct target_type dmp_target = {
        .name = "dmp",
        .version = {1, 0, 0},
        .module = THIS_MODULE,
        .ctr = dmp_target_ctr,
        .dtr = dmp_target_dtr,
        .map = dmp_target_map,
};

int dmp_init(void) {
    int result = dm_register_target(&dmp_target);
    if (result < 0) {
        printk(KERN_ERR "dmp: Error in 'dm_register_target': %d\n", result);
        return result;
    }

    result = display_init();
    return result;
}

void dmp_exit(void) {
    display_exit();
    dm_unregister_target(&dmp_target);
}
