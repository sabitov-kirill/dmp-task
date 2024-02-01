# dmp-task

Созданный модуль (`Device Mapper Proxy`) является прокси чтения и записи блочного устройства, выполняя функции

- Подсчета количества записей чтения/записей
- Подсчета количества всех запросов
- Подсчета среднего размер блоков при чтении/записи
- Подсчета средний размер всех блоков

## Build module

Модуль тестировался и собирался на `Ubuntu Server 23.10`, версия ядра `6.5.0-15-generic`

Зависимости сборки:

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

Тестирование:

```shell
$ mkdir build
$ cd build
$ cmake ..
$ make dmp dmp_test
$ sudo sh ./dmp_test
```

## Замечание

Хотя данная версия и является стабильной, но тестирование модуля рекомендуется выполнять на виртуальной машине (
VirtualBox, qemu).