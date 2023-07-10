OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}


PKG_NAME = coreutils-9.1
PKG_URL = https://ftp.gnu.org/gnu/coreutils/coreutils-9.1.tar.xz
COREUTILS_TAR = ${ROOT_SOURCE}/coreutils-9.1.tar.xz
COREUTILS__CONFIGURE = ${ROOT_BUILD}/coreutils/Makefile
COREUTILS__COMPILE = ${ROOT_DIR}/rootfs/usr/bin/ls

PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}

all:

temporary_tools: ${COREUTILS_TAR} ${PGK_SOURCE_DIR} ${COREUTILS__CONFIGURE} ${COREUTILS__COMPILE}

${COREUTILS_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_SOURCE}
	wget ${PKG_URL} -P ${ROOT_SOURCE}

${PGK_SOURCE_DIR}:
	@cd ${ROOT_SOURCE} && tar -xf coreutils-9.1.tar.xz	

${COREUTILS__CONFIGURE}:
	@mkdir -p ${ROOT_BUILD}/coreutils
	@cd ${ROOT_BUILD}/coreutils && ${PGK_SOURCE_DIR}/configure --prefix=/usr --host=${CONFIG_OS_ARCH_TARGET} --build=$(build-aux/config.guess) --enable-install-program=hostname --enable-no-install-program=kill,uptime
	
${COREUTILS__COMPILE}:
	${MAKE} -C ${ROOT_BUILD}/coreutils
	${MAKE} -C ${ROOT_BUILD}/coreutils DESTDIR=${ROOT_FS} install	
