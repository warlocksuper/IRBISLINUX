OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PKG_NAME = ncurses-6.4
NCURSES_TAR = ${ROOT_DIR}/source/ncurses-6.4.tar.gz
NCURSES_CONFIGURE = ${ROOT_DIR}/build/ncurses/Makefile
NCURSES_COMPILE = ${ROOT_DIR}/rootfs/usr/bin/m4
TIC_COMPILE = ${ROOT_DIR}/build/ncurses/progs/tic
PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}


all:

temporary_tools: ${NCURSES_TAR} ${PGK_SOURCE_DIR}  ${TIC_COMPILE}  ${NCURSES_CONFIGURE} ${NCURSES_COMPILE}

${NCURSES_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_DIR}/source
	wget https://invisible-mirror.net/archives/ncurses/ncurses-6.4.tar.gz -P ${ROOT_SOURCE}


${PGK_SOURCE_DIR}:
	@cd ${ROOT_SOURCE} && tar -xf ncurses-6.4.tar.gz

${TIC_COMPILE}:
	@mkdir -p ${ROOT_DIR}/build/ncurses
	@cd ${ROOT_DIR}/build/ncurses && ${ROOT_SOURCE}/ncurses-6.4/configure
	${MAKE} -C ${ROOT_DIR}/build/ncurses/include
	${MAKE} -C ${ROOT_DIR}/build/ncurses/progs tic
	
${NCURSES_CONFIGURE}:
	@cd ${ROOT_DIR}/build/ncurses && ${ROOT_SOURCE}/ncurses-6.4/configure --prefix=/usr --host=${CONFIG_OS_ARCH_TARGET} --build=$(./config.guess) --mandir=/usr/share/man --with-manpage-format=normal --with-shared --without-normal --with-cxx-shared --without-debug --without-ada --disable-stripping --enable-widec
	
${NCURSES_COMPILE}:
	${MAKE} -C ${ROOT_DIR}/build/ncurses
	${MAKE} -C ${ROOT_DIR}/build/ncurses DESTDIR=${ROOT_FS} TIC_PATH=progs/tic install 
