OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PATH = $(shell printenv PATH):${ROOT_DIR}/scripts
export  PATH
PKG_VERSION = 1.79.2
PKG_NAME = docbook-xsl
PKG_URL = https://github.com/docbook/xslt10-stylesheets/archive/refs/tags/snapshot/2020-06-03.tar.gz


PKG_TAR_FILE = 2020-06-03.tar.gz
PGK_SOURCE_DIR = ${ROOT_SOURCE}/xslt10-stylesheets-snapshot-2020-06-03/
PKG_DEBIAN_DEPANDS = "Depends:  "
#PKG_BUILD_REPLACES = "  "

PKG_DEBIAN_SECTION = "Section: system"

PKG_DEBIAN_DEST = "Description: XML stylesheets for Docbook-xml transformations."

PKG_DPKG_FILE = ${PKG_NAME}.${PKG_VERSION}.deb 

PKG_TAR = ${ROOT_SOURCE}/${PKG_TAR_FILE}
PKG_BUILD_DIR_ALL = ${ROOT_DIR}/build_dpkg
PKG_BUILD_DIR = ${PKG_BUILD_DIR_ALL}/${PKG_NAME}
PKG_BUILD_DIR_DPKG = ${PKG_BUILD_DIR}/DPKG
PKG_MAKE_INTALL = ${PKG_BUILD_DIR_DPKG}/usr
PKG_BUILD_DIR_DEBIAN = ${PKG_BUILD_DIR_DPKG}/DEBIAN/control

export  PKG_BUILD_DIR_DPKG PKG_VERSION PKG_NAME PGK_SOURCE_DIR

PKG_CONFIGURE = ${PGK_BUILD_DIR}/Makefile
PKG_DPKG_FILE_PATH = ${ROOT_DPKG_ARCH}/${PKG_DPKG_FILE}

PKG_COMPILE_MAKE = ""
#PKG_COMPILE_NINJA = ""
PKG_COMPILE_DIR = ${PGK_SOURCE_DIR}  # может быть ${PGK_SOURCE_DIR} для компиляции в папке исходников или ${PKG_BUILD_DIR}  для компиляции в отдельном каталоги




.PHONY:  all, COMPILE, BUILD_DIR, PKG_CONFIGURE

PKG_COMPLITE =  $(shell pkg-exist ${PKG_DPKG_FILE_PATH})   ## определяет естьли собранный файл пакета если нет собираем

ifeq ($(strip "$(PKG_COMPLITE)"),$(strip "0  "))
all: BUILD_DIR  ${PKG_TAR} ${PGK_SOURCE_DIR} PKG_CONFIGURE ${PKG_MAKE_INTALL} ${PKG_BUILD_DIR_DEBIAN} 
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

PKG_CONFIGURE:
	./package
#	@cd ${PKG_BUILD_DIR} && ${PGK_SOURCE_DIR}/$(CONFIGURE)  --disable-static  --sysconfdir=/etc  --libdir=/usr/lib  --runstatedir=/run  --disable-chfn-chsh --disable-login --disable-nologin --disable-su --disable-setpriv  --disable-runuser --disable-pylibmount --disable-static --without-python ADJTIME_PATH=/var/lib/hwclock/adjtime --docdir=/usr/share/doc/util-linux-2.39.3
#	@cd ${PGK_SOURCE_DIR} && qmake PREFIX=${PKG_BUILD_DIR_DPKG}/usr LIBDIR=${PKG_BUILD_DIR_DPKG}/usr/lib CMAKE_CONFIG_PATH=${PKG_BUILD_DIR_DPKG}/usr 


#include ${ROOT_DIR}/scripts/compile.mk

include ${ROOT_DIR}/scripts/build_dpkg.mk
	
else
all: 
	@echo "Уже собранно ${PKG_COMPLITE} ${PKG_NAME}"	
endif		
