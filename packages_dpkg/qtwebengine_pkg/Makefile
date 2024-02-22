OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PKG_VERSION = 6.7.0
PKG_NAME = qtwebengine
PKG_URL =  http://code.qt.io/qt/qtwebengine.git
PKG_TAR_FILE = v${PKG_VERSION}.tar.gz
PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}
PKG_DEBIAN_DEPANDS = "Depends: "
PKG_DEBIAN_SECTION = "Section: net"
PKG_DEBIAN_DEST = "Description: WebKitEnginer is an open source web browser engine. WebKit's HTML and JavaScript code began as a branch of the KHTML and KJS libraries from KDE. As part of KDE framework KHTML was based on Qt but during their porting efforts Apple's engineers made WebKit toolkit independent. QtWebKit is a project aiming at porting this fabulous engine back to Qt."
PKG_DPKG_FILE = ${PKG_NAME}.${PKG_VERSION}.deb



PKG_TAR = ${ROOT_SOURCE}/${PKG_TAR_FILE}

PKG_BUILD_DIR = ${PKG_BUILD_DIR_ALL}/${PKG_NAME}
PKG_BUILD_DIR_DPKG = ${PKG_BUILD_DIR}/DPKG
PKG_MAKE_INTALL = ${PKG_BUILD_DIR_DPKG}/usr
PKG_BUILD_DIR_DEBIAN = ${PKG_BUILD_DIR_DPKG}/DEBIAN/control

PKG_DPKG_FILE_PATH = ${ROOT_DPKG_ARCH}/${PKG_DPKG_FILE}

PKG_COMPILE_MAKE = ""
#PKG_COMPILE_NINJA = ""
PKG_COMPILE_DIR = ${PKG_BUILD_DIR}  # может быть ${PGK_SOURCE_DIR} для компиляции в папке исходников или ${PKG_BUILD_DIR}  для компиляции в отдельном каталоги


.PHONY:  all, COMPILE, BUILD_DIR, PKG_CONFIGURE

PKG_COMPLITE =  $(shell if [ -f "${PKG_DPKG_FILE_PATH}" ]; then echo "1"; else echo "0"; fi ) ## определяет естьли собранный файл пакета если нет собираем

ifeq ($(strip $(PKG_COMPLITE)),$(strip 0))
all: BUILD_DIR  PKG_TAR PGK_SOURCE_DIR PKG_CONFIGURE COMPILE ${PKG_MAKE_INTALL} ${PKG_BUILD_DIR_DEBIAN} 
	sudo chown root:root -R ${PKG_BUILD_DIR_DPKG}
	@cd ${ROOT_DPKG_ARCH} && sudo dpkg-deb --build ${PKG_BUILD_DIR_DPKG} ${PKG_DPKG_FILE}
	sudo dpkg -i ${ROOT_DPKG_ARCH}/${PKG_DPKG_FILE}

BUILD_DIR:
	@mkdir -p ${PKG_BUILD_DIR_DPKG}
	@mkdir -p ${ROOT_SOURCE}

PKG_TAR:
#	cd ${ROOT_SOURCE} && git clone ${PKG_URL} 


PGK_SOURCE_DIR:
#	@cd ${ROOT_SOURCE} && tar -xf ${PKG_TAR_FILE}

PKG_CONFIGURE:
	@cd ${PKG_BUILD_DIR} &&  $(CMAKE) ${PGK_SOURCE_DIR}

include ${ROOT_DIR}/scripts/compile.mk

include ${ROOT_DIR}/scripts/build_dpkg.mk

else
all: 
	@echo "Уже собранно ${PKG_COMPLITE} ${PKG_NAME}"	
endif	
