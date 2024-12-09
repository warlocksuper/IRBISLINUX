PATH = $(shell printenv PATH):${ROOT_DIR}/scripts:${ROOT_DIR}/tools/pkg-build
export  PATH
PKG_VERSION = 1.2.15
PKG_NAME = sdl
PKG_URL = https://www.libsdl.org/release/SDL-1.2.15.tar.gz
PKG_TAR_FILE = SDL-${PKG_VERSION}.tar.gz
PGK_SOURCE_DIR = ${ROOT_SOURCE}/SDL-${PKG_VERSION}
PKG_DEBIAN_DEPANDS = "Depends: gobject-introspection(>=1.74.0), glib(>=2.74.5), graphite2(>=1.3.14), icu(>=72.1), freetype(>=2.13.0) "


PKG_DEBIAN_SECTION = "Section: libraries"

PKG_DEBIAN_DEST = "Description: The Simple DirectMedia Layer (SDL for short) is a cross-platform library designed to make it easy to write multimedia software, such as games and emulators."

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
all: BUILD_DIR  ${PKG_TAR} ${PGK_SOURCE_DIR} ${PKG_AUTORECONFIG}  PKG_CONFIGURE COMPILE ${PKG_MAKE_INTALL} ${PKG_BUILD_DIR_DEBIAN} 
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
	@cd ${PGK_SOURCE_DIR} && autoreconf -i

PKG_CONFIGURE:
	@cd ${PGK_SOURCE_DIR} && sed -e '/_XData32/s:register long:register _Xconst long:' -i src/video/x11/SDL_x11sym.h
	@cd ${PKG_BUILD_DIR} && ${PGK_SOURCE_DIR}/$(CONFIGURE)   --disable-static


include ${ROOT_DIR}/scripts/compile.mk

include ${ROOT_DIR}/scripts/build_dpkg.mk
	
else
all: 
	@echo "Уже собранно ${PKG_COMPLITE} ${PKG_NAME}"	
endif		
