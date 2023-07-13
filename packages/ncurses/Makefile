OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PKG_NAME = ncurses-6.4
NCURSES_TAR = ${ROOT_SOURCE}/ncurses-6.4.tar.gz
PKG_URL = https://invisible-mirror.net/archives/ncurses/ncurses-6.4.tar.gz
NCURSES_CONFIGURE = ${ROOT_BUILD}/ncurses/Makefile
NCURSES_COMPILE = ${ROOT_DIR}/rootfs/usr/lib/libncurses.a
TIC_COMPILE = ${ROOT_BUILD}/ncurses/progs/tic
PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}


all:

temporary_tools: ${NCURSES_TAR} ${PGK_SOURCE_DIR}  ${TIC_COMPILE}  ${NCURSES_CONFIGURE} ${NCURSES_COMPILE}

${NCURSES_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_SOURCE}
	wget ${PKG_URL} -P ${ROOT_SOURCE}


${PGK_SOURCE_DIR}:
	@cd ${ROOT_SOURCE} && tar -xf ncurses-6.4.tar.gz

${TIC_COMPILE}:
	@mkdir -p ${ROOT_BUILD}/ncurses
	@cd ${ROOT_BUILD}/ncurses && ${ROOT_SOURCE}/ncurses-6.4/configure
	${MAKE} -C ${ROOT_BUILD}/ncurses/include
	${MAKE} -C ${ROOT_BUILD}/ncurses/progs tic
	
${NCURSES_CONFIGURE}:
	@cd ${ROOT_BUILD}/ncurses && ${ROOT_SOURCE}/ncurses-6.4/configure --prefix=/usr --host=${CONFIG_OS_ARCH_TARGET} --build=$(./config.guess) --mandir=/usr/share/man --with-manpage-format=normal --with-shared --without-normal --with-cxx-shared --without-debug --without-ada --disable-stripping --enable-widec
	
${NCURSES_COMPILE}:
	${MAKE} -C ${ROOT_BUILD}/ncurses
	${MAKE} -C ${ROOT_BUILD}/ncurses DESTDIR=${ROOT_FS} TIC_PATH=progs/tic install 
##	echo "INPUT(-lncursesw)" > ${ROOT_FS}/usr/lib/libncurses.so
