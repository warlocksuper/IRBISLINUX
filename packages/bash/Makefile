OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PKG_NAME = bash-5.2.15
BASH_TAR = ${ROOT_SOURCE}/bash-5.2.15.tar.gz
PKG_URL = https://ftp.gnu.org/gnu/bash/bash-5.2.15.tar.gz 
BASH_CONFIGURE = ${ROOT_BUILD}/bash/Makefile
BASH_COMPILE = ${ROOT_BUILD}/bash/bash
BASH_INSTALL = ${ROOT_FS}/usr/bin/bash

PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}

all:

temporary_tools: ${BASH_TAR} ${PGK_SOURCE_DIR}  ${BASH_CONFIGURE} ${BASH_COMPILE} ${BASH_INSTALL}

${BASH_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_SOURCE}
	wget ${PKG_URL} -P ${ROOT_SOURCE}/

${PGK_SOURCE_DIR}:
	@cd ${ROOT_SOURCE} && tar -xf bash-5.2.15.tar.gz

${BASH_CONFIGURE}:
	@mkdir -p ${ROOT_BUILD}/bash
	@cd ${ROOT_BUILD}/bash && ${PGK_SOURCE_DIR}/configure --prefix=/usr --host=${CONFIG_OS_ARCH_TARGET} --build=$(sh support/config.guess) --without-bash-malloc
	
${BASH_COMPILE}:
	${MAKE} -C ${ROOT_BUILD}/bash
	
	
${BASH_INSTALL}:
	@mkdir -p ${ROOT_FS}/bin
	${MAKE} -C ${ROOT_BUILD}/bash DESTDIR=${ROOT_FS}/ install
	@cd ${ROOT_FS}/bin && ln -sfv ../usr/bin/bash sh
	@cd ${ROOT_FS}/bin && ln -sfv ../usr/bin/bash bash	
