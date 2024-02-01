ls -al /dev/mapper/*
sudo dmsetup create zero1 --table "0 128 zero"
sudo dmsetup create dmp1 --table "0 128 dmp /dev/mapper/zero1"
sudo dmsetup remove dmp1

cat /sys/module/dmp/stat/volumes
sudo dd of=/dev/null if=/dev/mapper/dmp1 bs=4k count=1
sudo dd if=/dev/random of=/dev/mapper/dmp1 bs=4k count=1

sudo insmod dmp.ko
sudo rmmod dmp

sudo dmesg
sudo dmesg -C

sudo dd if=/dev/zero of=block_device_file bs=1M count=1
sudo losetup /dev/loop0 block_device_file
sudo dmsetup create dmp1 --table "0 128 dmp /dev/loop0"
sudo losetup -d /dev/loop0
