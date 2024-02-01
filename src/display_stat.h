//
// Created by ne1mnn on 1/29/24.
//

#ifndef DMP_TASK_DISPLAY_STAT_H
#define DMP_TASK_DISPLAY_STAT_H

struct request_stat {
    unsigned int count;
    unsigned int blocks_count;
    size_t blocks_total_size;
};

struct device_stat {
    struct request_stat read;
    struct request_stat write;
};

extern struct device_stat volumes_stat;

int display_init(void);

void display_exit(void);

int display_device_stat_node_ctr(const char *name, struct device_stat *stat);

void display_device_stat_node_dtr(struct device_stat *stat);

#endif //DMP_TASK_DISPLAY_STAT_H
