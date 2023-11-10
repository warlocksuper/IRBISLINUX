OS_VERSION = 0
OS_SUBVERSION = 0
OS_PATHLEVELVERSION = 0


ROOT_DIR = ${PWD}
ROOT_FS = ${PWD}/rootfs
ROOT_BUILD = ${PWD}/build
ROOT_SOURCE = ${PWD}/source
ROOT_TOOLS = ${ROOT_FS}/tools
ROOT_DPKG_ARCH = ${ROOT_DIR}/DPKG
PATH = $(shell printenv PATH):${ROOT_TOOLS}/bin:${ROOT_FS}/usr/bin
OS_CONFIG = ./.config
ifeq (,$(wildcard $(OS_CONFIG)))
	include ${OS_CONFIG}
else
CONFIG_OS_ARCH = "x86_64"
CONFIG_OS_VENDOR = "irbis"	
endif

## OS_ARCH_TARGET = ${CONFIG_OS_ARCH}-${CONFIG_OS_VENDOR}-linux-gnu

export

all: tools_dir temporary_tools


tools_dir:
	${MAKE} -C tools

temporary_tools:
	${MAKE} -C packages temporary_tools

packages:
	${MAKE} -C packages

menuconfig: ${OS_CONFIG}
	echo ${ROOT_DIR}
	conf/mconf Kconfig	


menudpkg: ${OS_CONFIG}
		echo ${ROOT_DIR}
		conf/mconf packages_dpkg/Kconfig

${OS_CONFIG}:
	echo "" > ${ROOT_DIR}/.config



clean:
	rm -rf build rootfs/* tools/${CONFIG_OS_ARCH}-pc-linux-gnu tools/bin/* tools/include/* tools/lib/* tools/libexec/* tools/share 


packagesdpkg: ${ROOT_DPKG_ARCH} 
	${MAKE} -C packages_dpkg

${ROOT_DPKG_ARCH}:
	@mkdir -p ${ROOT_DPKG_ARCH}

basefile:
	${MAKE} -C packages/basefile stage1_tools
	
binutils_stage1_tools: basefile
	 ${MAKE} -C packages/binutils stage1_tools
	 
gcc_stage1_tools:	 
	${MAKE} -C packages/gcc stage1_tools	 

linux_stage1_tools:	 
	${MAKE} -C packages/linux stage1_tools	 
	
glibc_stage1_tools:	
	${MAKE} -C packages/glibc stage1_tools
	
libstdc++_stage1_tools:
	${MAKE} -C packages/libstdc++ stage1_tools	
	
busybox:
	${MAKE} -C packages/busybox temporary_tools	
