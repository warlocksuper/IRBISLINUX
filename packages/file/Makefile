OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

FILE_TAR = ${ROOT_DIR}/source/file-5.44.tar.gz
FILE_PRE_CONFIGURE = ${ROOT_DIR}/build/file/src/file
FILE_CONFIGURE = ${ROOT_DIR}/build/file/Makefile
FILE_COMPILE = ${ROOT_DIR}/build/file/src/.libs/file

FILE_INSTALL = ${ROOT_FS}/usr/bin/file

all:

temporary_tools: ${FILE_TAR} ${FILE_CONFIGURE} ${FILE_COMPILE} ${FILE_INSTALL}

${FILE_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_DIR}/source
	wget https://astron.com/pub/file/file-5.44.tar.gz -P ${ROOT_DIR}/source/
	@cd ${ROOT_DIR}/source && tar -xf file-5.44.tar.gz

${FILE_PRE_CONFIGURE}:
	@mkdir -p ${ROOT_DIR}/build/file
	@cd ${ROOT_DIR}/build/file && ${ROOT_DIR}/source/file-5.44/configure --disable-bzlib  --disable-libseccomp --disable-xzlib --disable-zlib
	${MAKE} -C ${ROOT_DIR}/build/file

${FILE_CONFIGURE}:
	@mkdir -p ${ROOT_DIR}/build/file
	@cd ${ROOT_DIR}/build/file && ${ROOT_DIR}/source/file-5.44/configure --prefix=/usr --host=${CONFIG_OS_ARCH}-pc-linux-gnu --build=$((./config.guess)
	
${FILE_COMPILE}:
	${MAKE} -C ${ROOT_DIR}/build/file

${FILE_INSTALL}:
	${MAKE} -C ${ROOT_DIR}/build/file DESTDIR=${ROOT_DIR}/rootfs install
				
