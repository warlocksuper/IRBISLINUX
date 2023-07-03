OS_VERSION = 0
OS_SUBVERSION = 0
OS_PATHLEVELVERSION = 0


ROOT_DIR = ${PWD}
ROOT_FS = ${PWD}/rootfs
ROOT_BUILD = ${PWD}/build
ROOT_SOURCE = ${PWD}/source
PATH = $(shell printenv PATH):${PWD}/tools/bin:${PWD}/rootfs/usr/bin
OS_CONFIG = ./.config
ifeq (,$(wildcard $(OS_CONFIG)))
	include ${OS_CONFIG}
else
CONFIG_OS_ARCH = "x86_64"
CONFIG_OS_VENDOR = "irbis"	
endif

## OS_ARCH_TARGET = ${CONFIG_OS_ARCH}-${CONFIG_OS_VENDOR}-linux-gnu

export

all: os_packages_make


${OS_CONFIG}: menuconfig

tools_dir:
	${MAKE} -C tools

os_packages_make:
	${MAKE} -C packages

menuconfig:
	conf/mconf Kconfig	
