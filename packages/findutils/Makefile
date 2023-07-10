OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}


PKG_NAME = findutils-4.9.0
PKG_URL = https://ftp.gnu.org/gnu/findutils/findutils-4.9.0.tar.xz
PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}


FINDUTILS_TAR = ${ROOT_SOURCE}/findutils-4.9.0.tar.xz
FINDUTILS_PRE_CONFIGURE = ${ROOT_BUILD}/findutils/src/file
FINDUTILS_CONFIGURE = ${ROOT_BUILD}/findutils/Makefile
FINDUTILS_COMPILE = ${ROOT_BUILD}/findutils/find/find

FINDUTILS_INSTALL = ${ROOT_FS}/usr/bin/find

all:

temporary_tools: ${FINDUTILS_TAR} ${PGK_SOURCE_DIR} ${FINDUTILS_CONFIGURE} ${FINDUTILS_COMPILE} ${FINDUTILS_INSTALL}

${FINDUTILS_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_SOURCE}
	wget ${PKG_URL} -P ${ROOT_SOURCE}

${PGK_SOURCE_DIR}:
	@cd ${ROOT_SOURCE} && tar -xf findutils-4.9.0.tar.xz

${FINDUTILS_CONFIGURE}:
	@mkdir -p ${ROOT_BUILD}/findutils
	@cd ${ROOT_BUILD}/findutils && ${PGK_SOURCE_DIR}/configure --prefix=/usr --host=${CONFIG_OS_ARCH_TARGET} --build=$(build-aux/config.guess) --localstatedir=/var/lib/locate
	
${FINDUTILS_COMPILE}:
	${MAKE} -C ${ROOT_BUILD}/findutils

${FINDUTILS_INSTALL}:
	${MAKE} -C ${ROOT_BUILD}/findutils DESTDIR=${ROOT_FS} install
				
