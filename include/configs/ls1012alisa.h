/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright 2019 HU&CO
 */

#ifndef __LS1012ALISA_H__
#define __LS1012ALISA_H__

#include "ls1012a_common.h"

/* DDR */
#define CONFIG_DIMM_SLOTS_PER_CTLR	1
#define CONFIG_CHIP_SELECTS_PER_CTRL	1
#define SYS_SDRAM_SIZE_512		0x20000000
#define SYS_SDRAM_SIZE_1024		0x40000000
#define CONFIG_CHIP_SELECTS_PER_CTRL	1
#define CONFIG_CMD_MEMINFO
#define CONFIG_CMD_MEMTEST
#define CONFIG_SYS_MEMTEST_START	0x80000000
#define CONFIG_SYS_MEMTEST_END		0x9fffffff

#undef BOOT_TARGET_DEVICES
#define BOOT_TARGET_DEVICES(func) \
	func(MMC, mmc, 0) \
	func(USB, usb, 0)

#undef CONFIG_ENV_OFFSET
#define CONFIG_ENV_OFFSET              0x1D0000
#undef FSL_QSPI_FLASH_SIZE
#define FSL_QSPI_FLASH_SIZE            SZ_16M
#undef CONFIG_ENV_SECT_SIZE
#define CONFIG_ENV_SECT_SIZE		0x10000 /*64 KB*/
#undef CONFIG_ENV_SIZE
#define CONFIG_ENV_SIZE			0x10000 /*64 KB*/

/*  MMC  */
#ifdef CONFIG_MMC
#define CONFIG_FSL_ESDHC
#define CONFIG_SYS_FSL_MMC_HAS_CAPBLT_VS33
#endif

#define CONFIG_PCIE1		/* PCIE controller 1 */

#define CONFIG_PCI_SCAN_SHOW

#undef CONFIG_EXTRA_ENV_SETTINGS
#define CONFIG_EXTRA_ENV_SETTINGS		\
	"verify=no\0"				\
	"fdt_high=0xffffffffffffffff\0"		\
	"initrd_high=0xffffffffffffffff\0"	\
	"fdt_addr=0x00f00000\0"			\
	"kernel_addr=0x01000000\0"		\
	"kernel_size_sd=0x16000\0"		\
	"kernelhdr_size_sd=0x10\0"		\
	"kernel_addr_sd=0x8000\0"		\
	"kernelhdr_addr_sd=0x4000\0"		\
	"kernelheader_addr=0x1fc000\0"		\
	"kernelheader_addr=0x1fc000\0"		\
	"scriptaddr=0x80000000\0"		\
	"scripthdraddr=0x80080000\0"		\
	"fdtheader_addr_r=0x80100000\0"		\
	"kernelheader_addr_r=0x80200000\0"	\
	"kernelheader_size=0x40000\0"		\
	"kernel_addr_r=0x81000000\0"		\
	"fdt_addr_r=0x90000000\0"		\
	"load_addr=0x96000000\0"		\
	"kernel_size=0x2800000\0"		\
	"kernelheader_size=0x40000\0"		\
	"console=ttyS1,115200\0"		\
	BOOTENV					\

#undef CONFIG_BOOTCOMMAND
#define CONFIG_BOOTCOMMAND "pfe stop; run distro_bootcmd;"

#define CONFIG_CMD_MEMINFO
#define CONFIG_CMD_MEMTEST
#define CONFIG_SYS_MEMTEST_START	0x80000000
#define CONFIG_SYS_MEMTEST_END		0x9fffffff

#include <asm/fsl_secure_boot.h>
#include <asm/fsl_secure_boot.h>
#endif /* __LS1012ALISA_H__ */
