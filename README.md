# dmp-task

## Build module
Модуль тестировался и собирался на `Ubuntu Server 23.10`, версия ядра `6.5.0-15-generic`

Зависимости:
```shell
$ sudo apt-get install build-essential linux-headers-`uname -r` cmake
```

Сборка:
```shell
$ mkdir build
$ cd build
$ cmake ..
$ make
```

Загрузка модуля:
```shell
$ sudo insmod dmp-task.ko
$ sudo rmmod dmp-task
```