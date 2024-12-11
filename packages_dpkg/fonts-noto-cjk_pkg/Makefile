PATH = $(shell printenv PATH):${ROOT_DIR}/scripts:${ROOT_DIR}/tools/pkg-build
export  PATH
PKG_VERSION = 20201206
PKG_NAME = fonts-noto-cjk
PKG_URL = https://github.com/notofonts/noto-cjk/archive/refs/tags/v20201206-cjk.tar.gz
PKG_TAR_FILE = v${PKG_VERSION}-cjk.tar.gz
PGK_SOURCE_DIR = ${ROOT_SOURCE}/noto-cjk-20201206-cjk
PKG_DEBIAN_DEPANDS = "Depends:  "
#PKG_BUILD_REPLACES = "  "
## noto-cjk-20201206-cjk
PKG_DEBIAN_SECTION = "Section: fonts"

PKG_DEBIAN_DEST = "Description: Google Noto CJK fonts."

PKG_DPKG_FILE = ${PKG_NAME}.${PKG_VERSION}.deb 

PKG_TAR = ${ROOT_SOURCE}/${PKG_TAR_FILE}
PKG_BUILD_DIR_ALL = ${ROOT_DIR}/build_dpkg
PKG_BUILD_DIR = ${PKG_BUILD_DIR_ALL}/${PKG_NAME}
PKG_BUILD_DIR_DPKG = ${PKG_BUILD_DIR}/DPKG
PKG_MAKE_INTALL = ${PKG_BUILD_DIR_DPKG}/usr
PKG_BUILD_DIR_DEBIAN = ${PKG_BUILD_DIR_DPKG}/DEBIAN/control



PKG_CONFIGURE = ${PGK_BUILD_DIR}/Makefile
PKG_DPKG_FILE_PATH = ${ROOT_DPKG_ARCH}/${PKG_DPKG_FILE}

PKG_COMPILE_MAKE = ""
#PKG_COMPILE_NINJA = ""
PKG_COMPILE_DIR = ${PKG_BUILD_DIR}  # может быть ${PGK_SOURCE_DIR} для компиляции в папке исходников или ${PKG_BUILD_DIR}  для компиляции в отдельном каталоги
PKG_AUTORECONFIG = ${PGK_SOURCE_DIR}/configure



.PHONY:  all, COMPILE, BUILD_DIR, PKG_CONFIGURE

PKG_COMPLITE =  $(shell pkg-exist ${PKG_DPKG_FILE_PATH})   ## определяет естьли собранный файл пакета если нет собираем

ifeq ($(strip "$(PKG_COMPLITE)"),$(strip "0  "))
all: BUILD_DIR  ${PKG_TAR} ${PGK_SOURCE_DIR} ${PKG_AUTORECONFIG}  PKG_MAKE_INTALL ${PKG_BUILD_DIR_DEBIAN} 
	@cd ${ROOT_DPKG_ARCH} && fakeroot -- dpkg-deb --build ${PKG_BUILD_DIR_DPKG} ${PKG_DPKG_FILE}
	sudo dpkg -i ${ROOT_DPKG_ARCH}/${PKG_DPKG_FILE}
	
	
BUILD_DIR:
	@mkdir -p ${PKG_BUILD_DIR_DPKG}
	@mkdir -p ${ROOT_SOURCE}


${PKG_TAR}:
	wget ${PKG_URL} -P ${ROOT_SOURCE}/


${PGK_SOURCE_DIR}:
	@cd ${ROOT_SOURCE} && tar -xf ${PKG_TAR_FILE}

${PKG_AUTORECONFIG}:
#	@cd ${PGK_SOURCE_DIR} && autoreconf -i

PKG_CONFIGURE:
	@cd ${PKG_BUILD_DIR} && ${PGK_SOURCE_DIR}/$(CONFIGURE)  

PKG_MAKE_INTALL:
	install -d ${PKG_BUILD_DIR_DPKG}/usr/share/fonts/noto-cjk
	install -Dm644 ${PGK_SOURCE_DIR}/* -t ${PKG_BUILD_DIR_DPKG}/usr/share/fonts/noto-cjk/

#include ${ROOT_DIR}/scripts/compile.mk

include ${ROOT_DIR}/scripts/build_dpkg.mk
	
else
all: 
	@echo "Уже собранно ${PKG_COMPLITE} ${PKG_NAME}"	
endif		
