PKG_NAME = perl-5.36.0
PKG_TAR = perl-5.36.0.tar.xz
PGK_UNTAG = ${PKG_NAME}/Configure
PKG_URL = https://www.cpan.org/src/5.0/perl-5.36.0.tar.xz
PKG_CONFIGURE = ${PKG_NAME}/Makefile
PKG_COMPILE = ${PKG_NAME}/perl
PKG_INSTALL = /usr/bin/perl

all: ${PKG_TAR}  ${PGK_UNTAG} ${PKG_CONFIGURE} ${PKG_COMPILE} ${PKG_INSTALL}
	
${PKG_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_SOURCE}
	wget ${PKG_URL} -P ${ROOT_SOURCE}	

${PGK_UNTAG}:
	@cd ${ROOT_SOURCE} && tar -xf ${PKG_TAR}

${PKG_CONFIGURE}:
	@cd ${PKG_NAME} && ./Configure -des                                        \
             -Dprefix=/usr                               \
             -Dvendorprefix=/usr                         \
             -Dprivlib=/usr/lib/perl5/5.36/core_perl     \
             -Darchlib=/usr/lib/perl5/5.36/core_perl     \
             -Dsitelib=/usr/lib/perl5/5.36/site_perl     \
             -Dsitearch=/usr/lib/perl5/5.36/site_perl    \
             -Dvendorlib=/usr/lib/perl5/5.36/vendor_perl \
             -Dvendorarch=/usr/lib/perl5/5.36/vendor_perl

${PKG_COMPILE}:
	${MAKE} -C ${PKG_NAME}

${PKG_INSTALL}:
	${MAKE} -C ${PKG_NAME} install
              	
clean:
	rm -rf 	${PKG_TAR} ${PKG_NAME}	
