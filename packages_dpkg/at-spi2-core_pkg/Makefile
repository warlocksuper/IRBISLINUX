OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}


PKG_VERSION = 2.48.3
PKG_NAME = at-spi2-core
PKG_URL = https://download.gnome.org/sources/at-spi2-core/2.48/at-spi2-core-2.48.3.tar.xz
PKG_TAR_FILE = ${PKG_NAME}-${PKG_VERSION}.tar.xz
PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}-${PKG_VERSION}
PKG_DEBIAN_DEPANDS = "Depends: glib(>=2.74.5), dbus(>=1.14.6.1), libx11(>=1.8.4), libxtst(>=1.2.4), libxi(>=1.8) "


PKG_DEBIAN_SECTION = "Section: librares"

PKG_DEBIAN_DEST = "Description: The At-Spi2 Core package contains a comprehensive accessibility framework for the Assistive Technologies available on the GNOME platform. This includes a set of interfaces which are implemented by other toolkits and applications."

PKG_DPKG_FILE = ${PKG_NAME}.${PKG_VERSION}.deb 

PKG_TAR = ${ROOT_SOURCE}/${PKG_TAR_FILE}
PKG_BUILD_DIR_ALL = ${ROOT_DIR}/build_dpkg
PKG_BUILD_DIR = ${PKG_BUILD_DIR_ALL}/${PKG_NAME}
PKG_BUILD_DIR_DPKG = ${PKG_BUILD_DIR}/DPKG
PKG_MAKE_INTALL = ${PKG_BUILD_DIR_DPKG}/usr
PKG_BUILD_DIR_DEBIAN = ${PKG_BUILD_DIR_DPKG}/DEBIAN/control

PKG_DPKG_FILE_PATH = ${PKG_BUILD_DIR}/${PKG_DPKG_FILE}

PKG_CONFIGURE = ${PGK_BUILD_DIR}/Makefile


#PKG_COMPILE_MAKE = ""
PKG_COMPILE_NINJA = ""
PKG_COMPILE_DIR = ${PKG_BUILD_DIR}  # может быть ${PGK_SOURCE_DIR} для компиляции в папке исходников или ${PKG_BUILD_DIR}  для компиляции в отдельном каталоги




.PHONY:  all, COMPILE, BUILD_DIR, PKG_CONFIGURE

PKG_COMPLITE =  $(shell if [ -f "${PKG_DPKG_FILE_PATH}" ]; then echo "1"; else echo "0"; fi ) ## определяет естьли собранный файл пакета если нет собираем

ifeq ($(strip $(PKG_COMPLITE)),$(strip 0))
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
	@cd ${PKG_BUILD_DIR} && $(MESON)  -Dsystemd_user_dir=/usr/lib/systemd/system ${PGK_SOURCE_DIR}


include ${ROOT_DIR}/scripts/compile.mk

PKG_MAKE_POST_INTALL:
	@rm -rf ${PKG_BUILD_DIR_DPKG}/usr/include/atk-1.0/atk/atk-autocleanups.h


include ${ROOT_DIR}/scripts/build_dpkg.mk
	
else
all: 
	@echo "Уже собранно ${PKG_COMPLITE} ${PKG_NAME}"	
endif		
