OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PKG_NAME = gawk-5.2.1
PKG_URL = https://ftp.gnu.org/gnu/gawk/gawk-5.2.1.tar.xz
GAWK_TAR = ${ROOT_SOURCE}/gawk-5.2.1.tar.xz
## GAWK_PRE_CONFIGURE = ${ROOT_DIR}/build/findutils/src/file
GAWK_CONFIGURE = ${ROOT_BUILD}/gawk/Makefile
GAWK_COMPILE = ${ROOT_BUILD}/gawk/gawk

GAWK_INSTALL = ${ROOT_FS}/usr/bin/gawk
PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}


all:

temporary_tools: ${GAWK_TAR} ${PGK_SOURCE_DIR} ${GAWK_CONFIGURE} ${GAWK_COMPILE} ${GAWK_INSTALL}

${GAWK_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_SOURCE}
	wget ${PKG_URL} -P ${ROOT_SOURCE}/
	@cd ${ROOT_SOURCE} && tar -xf gawk-5.2.1.tar.xz

${PGK_SOURCE_DIR}:
	@cd ${ROOT_SOURCE} && tar -xf gawk-5.2.1.tar.xz	

${GAWK_CONFIGURE}:
	@mkdir -p ${ROOT_BUILD}/gawk
	@cd ${ROOT_BUILD}/gawk && ${ROOT_SOURCE}/gawk-5.2.1/configure --prefix=/usr --host=${CONFIG_OS_ARCH_TARGET} --build=$(build-aux/config.guess)
	
${GAWK_COMPILE}:
	${MAKE} -C ${ROOT_BUILD}/gawk

${GAWK_INSTALL}:
	${MAKE} -C ${ROOT_BUILD}/gawk DESTDIR=${ROOT_FS} install
				
