OS_VERSION = 0
OS_SUBVERSION = 0
OS_PATHLEVELVERSION = 0

ROOT_DIR = ${PWD}
ROOT_FS = ${PWD}/rootfs
OS_CONFIG = ./.config
ifeq (,$(wildcard $(OS_CONFIG)))
	include ${OS_CONFIG}
endif

export

all: tools_dir temporary_tools


${OS_CONFIG}: menuconfig

tools_dir:
	${MAKE} -C tools

temporary_tools:
	${MAKE} -C packages temporary_tools

packages:
	${MAKE} -C packages

menuconfig:
	echo ${ROOT_DIR}
	conf/mconf Kconfig	


