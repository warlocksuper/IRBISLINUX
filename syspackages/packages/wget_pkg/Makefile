
PKG_NAME = wget-1.21.3
PKG_TAR = wget-1.21.3.tar.gz
PGK_UNTAG = ${PKG_NAME}/configure
PKG_URL = https://ftp.gnu.org/gnu/wget/wget-1.21.3.tar.gz
PKG_CONFIGURE = ${PKG_NAME}/Makefile
PKG_COMPILE = ${PKG_NAME}/wget
PKG_INSTALL = /usr/bin/wget

all: ${PKG_TAR}  ${PGK_UNTAG} ${PKG_CONFIGURE} ${PKG_COMPILE} ${PKG_INSTALL}
	
${PKG_TAR}:
	wget ${PKG_URL}	

${PGK_UNTAG}:
	tar -xf ${PKG_TAR}

${PKG_CONFIGURE}:
	@cd ${PKG_NAME} && ./configure --prefix=/usr 

${PKG_COMPILE}:
	${MAKE} -C ${PKG_NAME}

${PKG_INSTALL}:
	${MAKE} -C ${PKG_NAME} install
              	
clean:
	rm -rf 	${PKG_TAR} ${PKG_NAME}	
