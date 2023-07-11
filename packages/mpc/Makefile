OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PKG_NAME = mpc-1.3.1
PKG_URL = https://ftp.gnu.org/gnu/mpc/mpc-1.3.1.tar.gz
PKG_TAR_FILE = ${PKG_NAME}.tar.gz
PGK_BUILD_DIR = ${ROOT_BUILD}/mpc

PKG_TAR = ${ROOT_SOURCE}/${PKG_TAR_FILE}



PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}
PKG_CONFIGURE = ${PGK_BUILD_DIR}/Makefile


PKG_COMPILE = ${PGK_BUILD_DIR}/src/.libs/libmpc.a
PGK_INSTALL = ${ROOT_FS}/usr/lib/libmpc.a

PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}

LD_LIBRARY_PATH = ${ROOT_FS}/usr/lib

export


all:

temporary_tools: ${PKG_TAR} ${PGK_SOURCE_DIR} ${PKG_CONFIGURE} ${PKG_COMPILE} ${PGK_INSTALL}

${PKG_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_SOURCE}
	wget ${PKG_URL} -P ${ROOT_SOURCE}/
	@cd ${ROOT_SOURCE} && tar -xf ${PKG_TAR_FILE}

${PGK_SOURCE_DIR}:
	@cd ${ROOT_SOURCE} && tar -xf ${PKG_TAR_FILE}

${PKG_CONFIGURE}:
	@mkdir -p ${PGK_BUILD_DIR}
	@cd ${PGK_BUILD_DIR} && ${PGK_SOURCE_DIR}/configure --prefix=/usr --host=${CONFIG_OS_ARCH_TARGET} --target=${CONFIG_OS_ARCH_TARGET} --build=x86_64-pc-linux-gnu --exec-prefix=/usr --sysconfdir=/etc --localstatedir=/var --disable-gtk-doc --disable-gtk-doc-html --disable-doc --disable-docs --disable-documentation --with-xmlto=no --with-fop=no --disable-dependency-tracking --enable-ipv6 --disable-nls --disable-static --enable-shared --with-gmp-include=${ROOT_FS}/usr/include --with-gmp-lib=${ROOT_FS}/usr/lib --with-sysroot=${ROOT_FS} 
	
${PKG_COMPILE}:
	${MAKE} -C ${PGK_BUILD_DIR}

${PGK_INSTALL}:
	${MAKE} -C ${PGK_BUILD_DIR} DESTDIR=${ROOT_FS} install
				
