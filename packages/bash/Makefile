OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

BASH_TAR = ${ROOT_DIR}/source/bash-5.2.15.tar.gz
BASH_CONFIGURE = ${ROOT_DIR}/build/bash/Makefile
BASH_COMPILE = ${ROOT_DIR}/rootfs/usr/bin/bash

all:

temporary_tools: ${BASH_TAR}  ${BASH_CONFIGURE} ${BASH_COMPILE}

${BASH_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_DIR}/source
	wget https://ftp.gnu.org/gnu/bash/bash-5.2.15.tar.gz -P ${ROOT_DIR}/source/
	@cd ${ROOT_DIR}/source && tar -xf bash-5.2.15.tar.gz

${BASH_CONFIGURE}:
	@mkdir -p ${ROOT_DIR}/build/bash
	@cd ${ROOT_DIR}/build/bash && ${ROOT_DIR}/source/bash-5.2.15/configure --prefix=/usr --host=${CONFIG_OS_ARCH}-pc-linux-gnu --build=$(sh support/config.guess) --without-bash-malloc
	
${BASH_COMPILE}:
	${MAKE} -C ${ROOT_DIR}/build/bash
	${MAKE} -C ${ROOT_DIR}/build/bash DESTDIR=${ROOT_DIR}/rootfs install
	@cd ${ROOT_FS}/bin && ln -sv ../usr/bin/bash sh
	@cd ${ROOT_FS}/bin && ln -sv ../usr/bin/bash bash	
