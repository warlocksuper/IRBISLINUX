OS_VERSION = 0
OS_SUBVERSION = 0
OS_PATHLEVELVERSION = 0


ROOT_DIR = ${PWD}
ROOT_FS = ${PWD}/rootfs
ROOT_BUILD = ${PWD}/build
ROOT_SOURCE = ${PWD}/source
ROOT_TOOLS = ${ROOT_FS}/tools
ROOT_DPKG_ARCH = ${ROOT_DIR}/DPKG
PKG_BUILD_DIR_ALL = ${ROOT_DIR}/build_dpkg
#PATH = $(shell printenv PATH):${ROOT_TOOLS}/bin:${ROOT_FS}/usr/bin
PATH=/usr/bin:/usr/sbin:/bin:/sbin:/usr/libexec
OS_CONFIG = ./.config
ifeq (,$(wildcard $(OS_CONFIG)))
	include ${OS_CONFIG}
else
CONFIG_OS_ARCH = "x86_64"
CONFIG_OS_VENDOR = "irbis"	
endif

CONFIGURE = /configure --prefix=/usr --sysconfdir=/etc --localstatedir=/var --runstatedir=/run 
MESON = meson --prefix=/usr --sysconfdir=/etc --buildtype=release --localstatedir=/var --runstatedir=/run  
CMAKE = cmake -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Release 

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


packagesdpkg: ${ROOT_DPKG_ARCH}  aliases
	${MAKE} -C packages_dpkg


aliases:
	alias IConfigure='/configure --prefix=/usr --sysconfdir=/etc --localstatedir=/var --runstatedir=/run '
	alias dpkg-build='dpkg-deb --build DPKG '
	alias meson-configure='meson --prefix=/usr --sysconfdir=/etc --buildtype=release --localstatedir=/var --runstatedir=/run  '


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


create_repo:
	@cd ${ROOT_DPKG_ARCH} && dpkg-scanpackages -m . > Packages
	@cd ${ROOT_DPKG_ARCH} && cat Packages | gzip -9 > Packages.gz
	@cd ${ROOT_DPKG_ARCH} && cat Packages | bzip2 -9 > Packages.bz2
	
	

		
