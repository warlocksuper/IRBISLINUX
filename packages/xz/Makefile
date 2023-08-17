OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PKG_NAME = xz-5.4.1
PKG_URL = https://tukaani.org/xz/xz-5.4.1.tar.xz
PKG_TAR_FILE = ${PKG_NAME}.tar.xz
PGK_BUILD_DIR = ${ROOT_BUILD}/xz
PKG_COMPILE = ${PGK_BUILD_DIR}/src/xz/xz-args.o
PGK_INSTALL = ${ROOT_FS}/usr/bin/xz

PKG_TAR = ${ROOT_SOURCE}/${PKG_TAR_FILE}



PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}
PKG_CONFIGURE = ${PGK_BUILD_DIR}/Makefile
PKG_CONFIGURE_DPKG = ${PGK_BUILD_DIR}/Makefile
PKG_COMPILE_DPKG = ${PGK_BUILD_DIR}/src/xz/xz-args.o
PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}
PGK_INSTALL_DPKG = ${PGK_BUILD_DIR}/DPKG/usr/bin/xz


all:

temporary_tools: ${PKG_TAR} ${PGK_SOURCE_DIR} ${PKG_CONFIGURE} ${PKG_COMPILE} ${PGK_INSTALL}

${PKG_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_SOURCE}
	wget ${PKG_URL} -P ${ROOT_SOURCE}/

${PGK_SOURCE_DIR}:
	@cd ${ROOT_SOURCE} && tar -xf ${PKG_TAR_FILE}
		
${PKG_CONFIGURE}:
	@mkdir -p ${PGK_BUILD_DIR}
	@cd ${PGK_BUILD_DIR} && ${PGK_SOURCE_DIR}/configure --prefix=/usr --host=${CONFIG_OS_ARCH_TARGET}
	
${PKG_COMPILE}:
	${MAKE} -C ${PGK_BUILD_DIR}

${PGK_INSTALL}:
	${MAKE} -C ${PGK_BUILD_DIR} DESTDIR=${ROOT_FS} install
	
dpkg:	${PKG_TAR} ${PGK_SOURCE_DIR} ${PKG_CONFIGURE_DPKG} ${PKG_COMPILE} ${PGK_INSTALL_DPKG}

		
				
${PKG_CONFIGURE_DPKG}:
	@cd ${PGK_BUILD_DIR} && ${PGK_SOURCE_DIR}/configure --prefix=/usr --sysconfdir=/etc --disable-static	
	
${PGK_INSTALL_DPKG}:
	@mkdir -p ${PGK_BUILD_DIR}/DPKG
	${MAKE} -C ${PGK_BUILD_DIR} DESTDIR=${PGK_BUILD_DIR}/DPKG install
	TOTALSIZE=$(du -sb $PGK_BUILD_DIR/DPKG | cut -f1)
	@mkdir -p ${PGK_BUILD_DIR}/DPKG/DEBIAN
	echo "print total size "$(du -sb $PGK_BUILD_DIR/DPKG | cut -f1) >> ${PGK_BUILD_DIR}/DPKG/DEBIAN/control			
