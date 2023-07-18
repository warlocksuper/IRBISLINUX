OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PKG_NAME = perl-5.36.0
PKG_URL = https://www.cpan.org/src/5.0/perl-5.36.0.tar.xz
PKG_TAR_FILE = ${PKG_NAME}.tar.xz

PKG_COMPILE = ${PGK_SOURCE_DIR}/perl
PGK_INSTALL = ${ROOT_FS}/usr/bin/perl

PKG_TAR = ${ROOT_SOURCE}/${PKG_TAR_FILE}

PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}
PGK_BUILD_DIR = ${PGK_SOURCE_DIR}
PKG_CONFIGURE = ${PGK_BUILD_DIR}/Makefile

PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}



all: 

temporary_tools: ${PKG_TAR} ${PGK_SOURCE_DIR} ${PKG_CONFIGURE} ${PKG_COMPILE} ${PGK_INSTALL}
	
${PKG_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_SOURCE}
	wget ${PKG_URL} -P ${ROOT_SOURCE}	

${PGK_SOURCE_DIR}:
	@cd ${ROOT_SOURCE} && tar -xf ${PKG_TAR_FILE}
	
	
${PKG_CONFIGURE}:
	@mkdir -p ${PGK_BUILD_DIR}
	@cd ${PGK_SOURCE_DIR} && CC=${CONFIG_OS_ARCH_TARGET}-gcc ./Configure -des                                        \
             -Dprefix=/usr                               \
             -Dvendorprefix=/usr                         \
             -Dprivlib=/usr/lib/perl5/5.36/core_perl     \
             -Darchlib=/usr/lib/perl5/5.36/core_perl     \
             -Dsitelib=/usr/lib/perl5/5.36/site_perl     \
             -Dsitearch=/usr/lib/perl5/5.36/site_perl    \
             -Dvendorlib=/usr/lib/perl5/5.36/vendor_perl \
             -Dvendorarch=/usr/lib/perl5/5.36/vendor_perl

${PKG_COMPILE}:
	${MAKE} -C ${PGK_SOURCE_DIR}

${PGK_INSTALL}:
	${MAKE} -C ${PGK_SOURCE_DIR} DESTDIR=${ROOT_FS} install
              	
clean:
	rm -rf 	${PGK_SOURCE_DIR}	
