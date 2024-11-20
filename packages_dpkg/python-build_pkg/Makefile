OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PATH = $(shell printenv PATH):${ROOT_DIR}/scripts:${ROOT_DIR}/tools/pkg-build/:/home/warlock/.local/bin/
export  PATH
PKG_VERSION = 1.2.1
PKG_NAME = python-build
PKG_TAR_FILE = ${PKG_NAME}-${PKG_VERSION}.tar.gz
PKG_URL = https://downloads.sourceforge.net/project/omxil/omxil/Bellagio%200.9.3/${PKG_TAR_FILE}

PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}-${PKG_VERSION}
PKG_AUTORECONF = ${PGK_SOURCE_DIR}/configure
PKG_DEBIAN_DEPANDS = "Depends: glibc(>=2.37.1), python(>=3.12.4), yaml(>=0.2.5), python-flaky, python-virtualenv "


PKG_DEBIAN_SECTION = "Section: python"

PKG_DEBIAN_DEST = "Description: Python bindings for YAML, using fast libYAML library."

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

${PKG_BUILD_DIR_DEBIAN}:
	@cd ${PKG_BUILD_DIR} && ${ROOT_DIR}/scripts/makepkg  --dpkg ${ROOT_DPKG_ARCH} -i -d --skipchecksums --skipinteg --skippgpcheck

include ${ROOT_DIR}/scripts/compile.mk

#include ${ROOT_DIR}/scripts/build_dpkg.mk
	
else
all: 
	@echo "Уже собранно ${PKG_COMPLITE} ${PKG_NAME}"	
endif		
