PATH = $(shell printenv PATH):${ROOT_DIR}/scripts:${ROOT_DIR}/tools/pkg-build/
export  PATH




_majorver=22
_minorver=0
_securityver=2
_updatever=9
pkgver=${_majorver}.${_minorver}.${_securityver}.u${_updatever}

PKG_VERSION = ${pkgver}
PKG_NAME =java-openjdk
pkgrel = 1

PKG_DPKG_FILE = ${PKG_NAME}-${PKG_VERSION}-${pkgrel}-amd64.deb 

PKG_BUILD_DIR = ${ROOT_DIR}/build_dpkg/${PKG_NAME}
PKG_BUILD_DIR_DPKG = ${PKG_BUILD_DIR}/DPKG


PKG_DPKG_FILE_PATH = ${ROOT_DPKG_ARCH}/${PKG_DPKG_FILE}


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
