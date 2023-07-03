
PKG_NAME = perl-5.36.0
PKG_TAR = perl-5.36.0.tar.xz
PGK_UNTAG = ${PKG_NAME}/configure
PKG_URL = https://www.cpan.org/src/5.0/perl-5.36.0.tar.xz



all: ${PKG_TAR}  ${PGK_UNTAG}
	
${PKG_TAR}:
	wget https://www.cpan.org/src/5.0/perl-5.36.0.tar.xz	

${PGK_UNTAG}:
	tar -xf ${PKG_TAR}
	
clean:
	rm -rf 	${PKG_TAR} ${PKG_NAME}	
