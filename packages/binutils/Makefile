OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PKG_NAME = binutils-2.40
PKG_URL = https://sourceware.org/pub/binutils/releases/binutils-2.40.tar.xz
PKG_TAR_FILE = ${PKG_NAME}.tar.xz
PGK_BUILD_DIR = ${ROOT_BUILD}/binutils
PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}
PKG_TAR = ${ROOT_SOURCE}/${PKG_TAR_FILE}

BINUTILS_STAGE1_CONFIGURE = ${PGK_BUILD_DIR}/Makefile
BINUTILS_STAGE1_COMPILE = ${PGK_BUILD_DIR}/ld/.libs/libdep.so
BINUTILS_STAGE1_INSTALL = ${ROOT_DIR}/tools/${CONFIG_OS_ARCH_TARGET}/bin/ld


BINUTILS_STAGE2_CONFIGURE = ${ROOT_BUILD}/binutils_stage2/Makefile
BINUTILS_STAGE2_COMPILE = ${ROOT_BUILD}/binutils_stage2/binutils/elfedit
BINUTILS_STAGE2_INSTALL = ${ROOT_FS}/usr/lib/libctf.a



PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}


all:

stage1_tools: ${PKG_TAR} ${PGK_SOURCE_DIR} ${BINUTILS_STAGE1_CONFIGURE} ${BINUTILS_STAGE1_COMPILE} ${BINUTILS_STAGE1_INSTALL}

${PGK_SOURCE_DIR}:
	@cd ${ROOT_SOURCE} && tar -xf ${PKG_TAR_FILE}	

${PKG_TAR}:
	@mkdir -p ${ROOT_FS}g
	@mkdir -p ${ROOT_SOURCE}
	wget ${PKG_URL} -P ${ROOT_SOURCE}


${BINUTILS_STAGE1_CONFIGURE}:
	@mkdir -p ${PGK_BUILD_DIR}
	@cd ${PGK_BUILD_DIR} && ${PGK_SOURCE_DIR}/configure --prefix=${ROOT_DIR}/tools --with-sysroot=${ROOT_FS} --target=${CONFIG_OS_ARCH_TARGET} --disable-nls --enable-gprofng=no --disable-werror
	
${BINUTILS_STAGE1_COMPILE}:
	${MAKE} -C ${PGK_BUILD_DIR}

${BINUTILS_STAGE1_INSTALL}:
	${MAKE} -C ${PGK_BUILD_DIR} install
##	@cd ${ROOT_FS}	&& ln -sv usr/lib lib64		

	
temporary_tools: ${BINUTILS_TAR} ${BINUTILS_STAGE2_CONFIGURE} ${BINUTILS_STAGE2_COMPILE} ${BINUTILS_STAGE2_INSTALL}
		

${BINUTILS_STAGE2_CONFIGURE}:
	@mkdir -p ${ROOT_BUILD}/binutils_stage2
	@cd ${ROOT_BUILD}/binutils_stage2 && ${PGK_SOURCE_DIR}/configure --prefix=/usr --build=x86_64-pc-linux-gnu --host=${CONFIG_OS_ARCH_TARGET} --disable-nls --enable-shared --enable-gprofng=no --disable-werror --enable-64-bit-bfd
	
	
${BINUTILS_STAGE2_COMPILE}:
	${MAKE} -C ${ROOT_BUILD}/binutils_stage2
	
${BINUTILS_STAGE2_INSTALL}:
	${MAKE} -C ${ROOT_BUILD}/binutils_stage2 DESTDIR=${ROOT_FS} install		
