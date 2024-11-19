## https://www.python.org/ftp/python/3.6.3/Python-3.6.3.tgz
OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PKG_NAME = Python-3.11.2
PKG_URL = https://www.python.org/ftp/python/3.11.2/Python-3.11.2.tar.xz
PKG_TAR_FILE = ${PKG_NAME}.tar.xz
PGK_BUILD_DIR = ${ROOT_BUILD}/python
PKG_COMPILE = ${PGK_BUILD_DIR}/python
PGK_INSTALL = ${ROOT_FS}/usr/bin/python3.11

PKG_TAR = ${ROOT_SOURCE}/${PKG_TAR_FILE}



PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}
PKG_CONFIGURE = ${PGK_BUILD_DIR}/Makefile

PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}



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
	@cd ${PGK_BUILD_DIR} && ${PGK_SOURCE_DIR}/configure --prefix=/usr --host=${CONFIG_OS_ARCH_TARGET} --build=x86_64-pc-linux-gnu --enable-shared --without-ensurepip --with-build-python=python3.11 --disable-ipv6 ac_cv_buggy_getaddrinfo=no ac_cv_file__dev_ptmx=yes ac_cv_file__dev_ptc=no

${PKG_COMPILE}:
	${MAKE} -C ${PGK_BUILD_DIR}

${PGK_INSTALL}:
	${MAKE} -C ${PGK_BUILD_DIR} DESTDIR=${ROOT_FS} install
              	
clean:
	rm -rf 	${PGK_BUILD_DIR}
	
	
	
dpkg:
	./configure --prefix=/usr --sysconfdir=/etc --runstatedir=/run --enable-shared --enable-optimizations --with-system-ffi	--enable-ipv6 --with-ensurepip=upgrade	
