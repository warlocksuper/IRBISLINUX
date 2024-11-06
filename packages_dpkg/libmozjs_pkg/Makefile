OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PATH = $(shell printenv PATH):${ROOT_DIR}/scripts:${ROOT_DIR}/tools/pkg-build:/home/warlock/.cargo/bin/
export  PATH
PKG_VERSION = 0.128.4
PKG_NAME = libmozjs
PKG_URL =  https://archive.mozilla.org/pub/firefox/releases/128.4.0esr/source/firefox-128.4.0esr.source.tar.xz
PKG_TAR_FILE = firefox-128.4.0esr.source.tar.xz
PGK_SOURCE_DIR = ${ROOT_SOURCE}/firefox-128.4.0
PKG_DEBIAN_DEPANDS = "Depends:  "
#PKG_BUILD_REPLACES = "  "

PKG_DEBIAN_SECTION = "Section: library"

PKG_DEBIAN_DEST = "Description: mozjs."

PKG_DPKG_FILE = ${PKG_NAME}.${PKG_VERSION}.deb 

PKG_TAR = ${ROOT_SOURCE}/${PKG_TAR_FILE}
PKG_BUILD_DIR_ALL = ${ROOT_DIR}/build_dpkg
PKG_BUILD_DIR = ${PKG_BUILD_DIR_ALL}/${PKG_NAME}
PKG_BUILD_DIR_DPKG = ${PKG_BUILD_DIR}/DPKG
PKG_MAKE_INTALL = ${PKG_BUILD_DIR_DPKG}/usr
PKG_BUILD_DIR_DEBIAN = ${PKG_BUILD_DIR_DPKG}/DEBIAN/control



PKG_CONFIGURE = ${PGK_BUILD_DIR}/Makefile
PKG_DPKG_FILE_PATH = ${ROOT_DPKG_ARCH}/${PKG_DPKG_FILE}


#PKG_COMPILE_CARGO=""
PKG_COMPILE_MAKE = ""
#PKG_COMPILE_NINJA = ""
PKG_COMPILE_DIR = ${PKG_BUILD_DIR}  # может быть ${PGK_SOURCE_DIR} для компиляции в папке исходников или ${PKG_BUILD_DIR}  для компиляции в отдельном каталоги
PKG_AUTORECONFIG = ${PGK_SOURCE_DIR}/configure



.PHONY:  all, COMPILE, BUILD_DIR, PKG_CONFIGURE

PKG_COMPLITE =  $(shell pkg-exist ${PKG_DPKG_FILE_PATH})   ## определяет естьли собранный файл пакета если нет собираем

ifeq ($(strip "$(PKG_COMPLITE)"),$(strip "0  "))
all: BUILD_DIR  ${PKG_TAR} ${PGK_SOURCE_DIR} PKG_CONFIGURE COMPILE ${PKG_MAKE_INTALL} ${PKG_BUILD_DIR_DEBIAN}
	rm ${PKG_BUILD_DIR_DPKG}/usr/lib/libjs_static.ajs 
	sudo chown root:root -R ${PKG_BUILD_DIR_DPKG}
	@cd ${ROOT_DPKG_ARCH} && sudo dpkg-deb --build ${PKG_BUILD_DIR_DPKG} ${PKG_DPKG_FILE}
	sudo dpkg -i ${ROOT_DPKG_ARCH}/${PKG_DPKG_FILE}
	
	
BUILD_DIR:
	@mkdir -p ${PKG_BUILD_DIR_DPKG}
	@mkdir -p ${ROOT_SOURCE}


${PKG_TAR}:
	wget ${PKG_URL} -P ${ROOT_SOURCE}/


${PGK_SOURCE_DIR}:
	@cd ${ROOT_SOURCE} && tar -xf ${PKG_TAR_FILE}

${PKG_AUTORECONFIG}:
	@cd ${PGK_SOURCE_DIR} && autoreconf -i

PKG_CONFIGURE:
	@cd ${PKG_BUILD_DIR} && ${PGK_SOURCE_DIR}/js/src/configure --prefix=/usr --disable-jemalloc --with-system-zlib --with-intl-api --disable-debug --enable-optimize


include ${ROOT_DIR}/scripts/compile.mk

include ${ROOT_DIR}/scripts/build_dpkg.mk
	
else
all: 
	@echo "Уже собранно ${PKG_COMPLITE} ${PKG_NAME}"	
endif		
