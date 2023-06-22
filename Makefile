OS_VERSION = 0
OS_SUBVERSION = 0
OS_PATHLEVELVERSION = 0

ROOT_DIR = ${PWD}

OS_CONFIG = .config
ifeq (,$(wildcard $(OS_CONFIG)))
	include ${OS_CONFIG}
endif

all: ${OS_CONFIG} tools


${OS_CONFIG}: menuconfig

tools:
	${MAKE} -C tools

packages:
	${MAKE} -C packages

menuconfig:
	conf/mconf Kconfig	


