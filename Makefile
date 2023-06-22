OS_VERSION = 0
OS_SUBVERSION = 0
OS_PATHLEVELVERSION = 0

ROOT_DIR = ${PWD}

OS_CONFIG = .config
ifeq (,$(wildcard $(OS_CONFIG)))
	include ${OS_CONFIG}
endif

all: ${OS_CONFIG}


${OS_CONFIG}: menuconfig packages

packages:
	${MAKE} -C packages

menuconfig:
	IConfig/mconf Kconfig	


