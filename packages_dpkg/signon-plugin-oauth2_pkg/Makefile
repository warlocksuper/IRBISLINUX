OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PATH = $(shell printenv PATH):${ROOT_DIR}/scripts

QMAKE_CXXFLAGS = -werror

export  PATH QMAKE_CXXFLAGS
PKG_VERSION = 0.25
PKG_NAME = signon-plugin-oauth2
PKG_URL = https://gitlab.com/nicolasfella/signon-plugin-oauth2/-/archive/VERSION_${PKG_VERSION}/${PKG_NAME}-VERSION_${PKG_VERSION}.tar.bz2
PKG_TAR_FILE = ${PKG_NAME}-VERSION_${PKG_VERSION}.tar.bz2
PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}-VERSION_${PKG_VERSION}
PKG_DEBIAN_DEPANDS = "Depends: signond(>=8.61)"


PKG_DEBIAN_SECTION = "Section: librares"

PKG_DEBIAN_DEST = "Description: This plugin for the Accounts-SSO SignOn daemon handles the OAuth 1.0 and 2.0 authentication protocols.."

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
PKG_COMPILE_DIR = ${PGK_SOURCE_DIR}  # может быть ${PGK_SOURCE_DIR} для компиляции в папке исходников или ${PKG_BUILD_DIR}  для компиляции в отдельном каталоги




.PHONY:  all, COMPILE, BUILD_DIR, PKG_CONFIGURE

PKG_COMPLITE =  $(shell pkg-exist ${PKG_DPKG_FILE_PATH})   ## определяет естьли собранный файл пакета если нет собираем

ifeq ($(strip "$(PKG_COMPLITE)"),$(strip "0  "))
all: BUILD_DIR  ${PKG_TAR} ${PGK_SOURCE_DIR} PKG_CONFIGURE COMPILE ${PKG_MAKE_INTALL} PKG_MAKE_POST_INTALL ${PKG_BUILD_DIR_DEBIAN} 
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
	@cd ${PGK_SOURCE_DIR} && qmake PREFIX=/usr LIBDIR=/usr/lib
	
 # PREFIX=${PKG_BUILD_DIR_DPKG}/usr LIBDIR=${PKG_BUILD_DIR_DPKG}/usr/lib CMAKE_CONFIG_PATH=${PKG_BUILD_DIR_DPKG}/usr 


include ${ROOT_DIR}/scripts/compile.mk

PKG_MAKE_POST_INTALL:
	@cd ${PKG_COMPILE_DIR} && make install

include ${ROOT_DIR}/scripts/build_dpkg.mk
	
else
all: 
	@echo "Уже собранно ${PKG_COMPLITE} ${PKG_NAME}"	
endif		
