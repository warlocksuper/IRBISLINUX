OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PKG_NAME = file-5.44
PKG_URL = https://astron.com/pub/file/file-5.44.tar.gz
PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}
FILE_TAR = ${ROOT_SOURCE}/file-5.44.tar.gz
FILE_PRE_CONFIGURE = ${ROOT_BUILD}/file/src/file
FILE_CONFIGURE = ${ROOT_BUILD}/file/Makefile
FILE_COMPILE = ${ROOT_BUILD}/file/src/.libs/file

FILE_INSTALL = ${ROOT_FS}/usr/bin/file

all:

temporary_tools: ${FILE_TAR} ${PGK_SOURCE_DIR}  ${FILE_CONFIGURE} ${FILE_COMPILE} ${FILE_INSTALL}

${FILE_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_SOURCE}
	wget ${PKG_URL} -P ${ROOT_SOURCE}

${PGK_SOURCE_DIR}:
	@cd ${ROOT_SOURCE} && tar -xf file-5.44.tar.gz	


${FILE_PRE_CONFIGURE}:
	@mkdir -p ${ROOT_BUILD}/file
	@cd ${ROOT_BUILD}/file && ${PGK_SOURCE_DIR}/configure --disable-bzlib  --disable-libseccomp --disable-xzlib --disable-zlib
	${MAKE} -C ${ROOT_BUILD}/file

${FILE_CONFIGURE}:
	@mkdir -p ${ROOT_BUILD}/file
	@cd ${ROOT_BUILD}/file && ${PGK_SOURCE_DIR}/configure --prefix=/usr --host=${CONFIG_OS_ARCH_TARGET} --build=$(./config.guess)
	
${FILE_COMPILE}:
	${MAKE} -C ${ROOT_BUILD}/file

${FILE_INSTALL}:
	${MAKE} -C ${ROOT_BUILD}/file DESTDIR=${ROOT_FS} install
				
