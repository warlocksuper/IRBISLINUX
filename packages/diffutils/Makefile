OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PKG_NAME = diffutils-3.9
PKG_URL = https://ftp.gnu.org/gnu/diffutils/diffutils-3.9.tar.xz

DIFF_TAR = ${ROOT_SOURCE}/diffutils-3.9.tar.xz
DIFF_CONFIGURE = ${ROOT_DIR}/build/diffutils/Makefile
DIFF_COMPILE = ${ROOT_DIR}/rootfs/usr/bin/diff

PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}

all:

temporary_tools: ${DIFF_TAR}  ${PGK_SOURCE_DIR}  ${DIFF_CONFIGURE} ${DIFF_COMPILE}

${DIFF_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_SOURCE}
	wget ${PKG_URL} -P ${ROOT_SOURCE}/
	@cd ${ROOT_SOURCE} && tar -xf diffutils-3.9.tar.xz

${PGK_SOURCE_DIR}:
	@cd ${ROOT_SOURCE} && tar -xf diffutils-3.9.tar.xz

${DIFF_CONFIGURE}:
	@mkdir -p ${ROOT_BUILD}/diffutils
	@cd ${ROOT_BUILD}/diffutils && ${PGK_SOURCE_DIR}/configure --prefix=/usr --host=${CONFIG_OS_ARCH_TARGET}
	
${DIFF_COMPILE}:
	${MAKE} -C ${ROOT_BUILD}/diffutils
	${MAKE} -C ${ROOT_BUILD}/diffutils DESTDIR=${ROOT_FS} install	
	
	
dpkg:
	./configure --prefix=/usr --sysconfdir=/etc	
	
