#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

#ifdef CONFIG_UNWINDER_ORC
#include <asm/orc_header.h>
ORC_HEADER;
#endif

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif



static const char ____versions[]
__used __section("__versions") =
	"\x1c\x00\x00\x00\xbf\x0a\x1c\xa2"
	"bio_associate_blkg\0\0"
	"\x18\x00\x00\x00\x54\x08\x71\x18"
	"dm_put_device\0\0\0"
	"\x10\x00\x00\x00\xba\x0c\x7a\x03"
	"kfree\0\0\0"
	"\x14\x00\x00\x00\xbb\x6d\xfb\xbd"
	"__fentry__\0\0"
	"\x10\x00\x00\x00\x7e\x3a\x2c\x12"
	"_printk\0"
	"\x20\x00\x00\x00\xd9\x64\x1c\x4e"
	"dm_unregister_target\0\0\0\0"
	"\x1c\x00\x00\x00\xb4\x00\x76\x5d"
	"sysfs_create_group\0\0"
	"\x1c\x00\x00\x00\xca\x39\x82\x5b"
	"__x86_return_thunk\0\0"
	"\x1c\x00\x00\x00\x89\x11\x10\x23"
	"sysfs_remove_group\0\0"
	"\x10\x00\x00\x00\xfd\xf9\x3f\x3c"
	"sprintf\0"
	"\x1c\x00\x00\x00\x94\x75\x72\xde"
	"dm_register_target\0\0"
	"\x1c\x00\x00\x00\x25\x93\x83\xbd"
	"dm_table_get_mode\0\0\0"
	"\x18\x00\x00\x00\x60\x6e\xe1\x3a"
	"kmalloc_trace\0\0\0"
	"\x18\x00\x00\x00\x56\x73\xf6\x1a"
	"dm_get_device\0\0\0"
	"\x18\x00\x00\x00\x62\x20\xf9\xa1"
	"kmalloc_caches\0\0"
	"\x18\x00\x00\x00\xb5\x28\xc2\x17"
	"module_layout\0\0\0"
	"\x00\x00\x00\x00\x00\x00\x00\x00";

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "3857081340D3A1079ACBF15");
