OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

BASH_TAR = ${ROOT_DIR}/source/bash-5.2.15.tar.gz
BASH_CONFIGURE = ${ROOT_DIR}/build/bash/Makefile
BASH_COMPILE = ${ROOT_DIR}/build/bash/bash
BASH_INSTALL = ${ROOT_DIR}/rootfs/usr/bin/bash

PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}

all:

temporary_tools: ${BASH_TAR} ${PGK_SOURCE_DIR}  ${BASH_CONFIGURE} ${BASH_COMPILE} ${BASH_INSTALL}

${BASH_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_DIR}/source
	wget https://ftp.gnu.org/gnu/bash/bash-5.2.15.tar.gz -P ${ROOT_DIR}/source/



${PGK_SOURCE_DIR}:
	@cd ${ROOT_SOURCE} && tar -xf bash-5.2.15.tar.gz

${BASH_CONFIGURE}:
	@mkdir -p ${ROOT_DIR}/build/bash
	@cd ${ROOT_DIR}/build/bash && ${ROOT_DIR}/source/bash-5.2.15/configure --prefix=/usr --host=${CONFIG_OS_ARCH_TARGET} --build=$(sh support/config.guess) --without-bash-malloc
	
${BASH_COMPILE}:
	${MAKE} -C ${ROOT_DIR}/build/bash
	
	
${BASH_INSTALL}:
	@mkdir -p ${ROOT_FS}/bin
	${MAKE} -C ${ROOT_DIR}/build/bash DESTDIR=${ROOT_DIR}/rootfs install
	@cd ${ROOT_FS}/bin && ln -sv ../usr/bin/bash sh
	@cd ${ROOT_FS}/bin && ln -sv ../usr/bin/bash bash	
