
PKG_NAME = zlib-1.2.13
PKG_TAR = zlib-1.2.13.tar.xz
PGK_UNTAG = ${PKG_NAME}/configure
PKG_URL = https://zlib.net/zlib-1.2.13.tar.xz
PKG_CONFIGURE = ${PKG_NAME}/Makefile
PKG_COMPILE = ${PKG_NAME}/libz.a
PKG_INSTALL = /usr/lib/libz.a

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
