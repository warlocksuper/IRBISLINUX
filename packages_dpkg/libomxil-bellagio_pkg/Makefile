OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PATH = $(shell printenv PATH):${ROOT_DIR}/scripts:${ROOT_DIR}/tools/pkg-build/
export  PATH
PKG_VERSION = 0.9.3-5
PKG_NAME = libomxil-bellagio
PKG_TAR_FILE = ${PKG_NAME}-${PKG_VERSION}.tar.gz
PKG_URL = https://downloads.sourceforge.net/project/omxil/omxil/Bellagio%200.9.3/${PKG_TAR_FILE}

PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}-${PKG_VERSION}
PKG_AUTORECONF = ${PGK_SOURCE_DIR}/configure
PKG_DEBIAN_DEPANDS = "Depends:  "


PKG_DEBIAN_SECTION = "Section: system"

PKG_DEBIAN_DEST = "Description: An opensource implementation of the OpenMAX Integration Layer API."

PKG_DPKG_FILE = ${PKG_NAME}-${PKG_VERSION}-amd64.deb 

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
PKG_COMPILE_DIR = ${PGK_SOURCE_DIR}  # может быть ${PGK_SOURCE_DIR} для компиляции в папке исходников или ${PKG_BUILD_DIR}  для компиляции в отдельном каталоги
PKG_CONFIGURE = ${PKG_COMPILE_DIR}/Makefile

export CFLAGS+=' -fcommon'

.PHONY:  all, BUILD_DIR, COPYSOURCE

PKG_COMPLITE =  $(shell pkg-exist ${PKG_DPKG_FILE_PATH})   ## определяет естьли собранный файл пакета если нет собираем

ifeq ($(strip "$(PKG_COMPLITE)"),$(strip "0  "))
all: BUILD_DIR COPYSOURCE ${PKG_BUILD_DIR_DEBIAN} 

	
	
BUILD_DIR:
	@mkdir -p ${ROOT_SOURCE}
	@mkdir -p ${PKG_BUILD_DIR}

COPYSOURCE:
	cp PKGSRC ${PKG_BUILD_DIR}/
	cp fedora-fixes.patch ${PKG_BUILD_DIR}/

${PKG_BUILD_DIR_DEBIAN}:
	@cd ${PKG_BUILD_DIR} && ${ROOT_DIR}/scripts/makepkg -I ${ROOT_DPKG_ARCH} -i

${PKG_TAR}:
	wget ${PKG_URL} -P ${ROOT_SOURCE}/


${PGK_SOURCE_DIR}:
	@cd ${ROOT_SOURCE} && tar -xf ${PKG_TAR_FILE}

${PKG_AUTORECONF}:
	cd ${PGK_SOURCE_DIR} && patch -Np1 -i ${PKG_PRG_DIR }/${PKG_NAME}_pkg/fedora-fixes.patch
#	cd ${PGK_SOURCE_DIR} && sed -e 's/-Werror//' -i configure.ac
	cd ${PGK_SOURCE_DIR} && autoreconf -fiv


${PKG_CONFIGURE}:
	@cd ${PGK_SOURCE_DIR} && ./$(CONFIGURE) --disable-static --docdir=/usr/share/doc/libomxil-bellagio
#	@cd ${PGK_SOURCE_DIR} && qmake PREFIX=${PKG_BUILD_DIR_DPKG}/usr LIBDIR=${PKG_BUILD_DIR_DPKG}/usr/lib CMAKE_CONFIG_PATH=${PKG_BUILD_DIR_DPKG}/usr 


include ${ROOT_DIR}/scripts/compile.mk

include ${ROOT_DIR}/scripts/build_dpkg.mk
	
else
all: 
	@echo "Уже собранно ${PKG_COMPLITE} ${PKG_NAME}"	
endif		
