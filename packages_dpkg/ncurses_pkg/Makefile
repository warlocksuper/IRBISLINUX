OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PATH = $(shell printenv PATH):${ROOT_DIR}/scripts:${ROOT_DIR}/tools/pkg-build/
export  PATH
PKG_VERSION = 6.5
PKG_NAME = ncurses

pkgrel = 3

PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}-${PKG_VERSION}



PKG_DPKG_FILE = ${PKG_NAME}-${PKG_VERSION}-${pkgrel}-amd64.deb 

PKG_BUILD_DIR_ALL = ${ROOT_DIR}/build_dpkg
PKG_BUILD_DIR = ${PKG_BUILD_DIR_ALL}/${PKG_NAME}
PKG_BUILD_DIR_DPKG = ${PKG_BUILD_DIR}/DPKG
PKG_BUILD_DIR_DEBIAN = ${PKG_BUILD_DIR_DPKG}/DEBIAN/control

PKG_DPKG_FILE_PATH = ${ROOT_DPKG_ARCH}/${PKG_DPKG_FILE}


PKG_COMPILE_MAKE = ""
#PKG_COMPILE_NINJA = ""
PKG_COMPILE_DIR = ${PGK_SOURCE_DIR}  # может быть ${PGK_SOURCE_DIR} для компиляции в папке исходников или ${PKG_BUILD_DIR}  для компиляции в отдельном каталоги
PKG_CONFIGURE = ${PKG_COMPILE_DIR}/Makefile


.PHONY:  all, BUILD_DIR, COPYSOURCE, PKG_BUILD_DIR_DEBIAN

PKG_COMPLITE =  $(shell pkg-exist ${PKG_DPKG_FILE_PATH})   ## определяет естьли собранный файл пакета если нет собираем

ifeq ($(strip "$(PKG_COMPLITE)"),$(strip "0  "))
all: BUILD_DIR COPYSOURCE PKG_BUILD_DIR_DEBIAN

	
	
BUILD_DIR:
	@mkdir -p ${ROOT_SOURCE}
	@mkdir -p ${PKG_BUILD_DIR}

COPYSOURCE:
	cp src/* ${PKG_BUILD_DIR}/

PKG_BUILD_DIR_DEBIAN:
	cd ${PKG_BUILD_DIR} && ${ROOT_DIR}/scripts/makepkg -I ${ROOT_DPKG_ARCH} -i -d --skipchecksums --skipinteg --skippgpcheck


include ${ROOT_DIR}/scripts/compile.mk

include ${ROOT_DIR}/scripts/build_dpkg.mk
	
else
all: 
	@echo "Уже собранно ${PKG_COMPLITE} ${PKG_NAME}"	
endif		
