OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}


PATH = $(shell printenv PATH):${ROOT_DIR}/scripts
export  PATH

PKG_VERSION = 1.2.11
PKG_NAME = alsa-lib
PKG_URL = https://www.alsa-project.org/files/pub/lib/alsa-lib-${PKG_VERSION}.tar.bz2
PKG_TAR_FILE = ${PKG_NAME}-${PKG_VERSION}.tar.bz2
PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}-${PKG_VERSION}
PKG_DEBIAN_DEPANDS = "Depends: systemd(>=254) "


PKG_DEBIAN_SECTION = "Section: libraries"

PKG_DEBIAN_DEST = "Description: The ALSA Library package contains the ALSA library used by programs (including ALSA Utilities) requiring access to the ALSA sound interface."

PKG_COMPILE = ${PGK_BUILD_DIR}/icccm/.libs/libxcb-icccm.so


PKG_DPKG_FILE = ${PKG_NAME}.${PKG_VERSION}.deb 

PKG_TAR = ${ROOT_SOURCE}/${PKG_TAR_FILE}
PKG_BUILD_DIR_ALL = ${ROOT_DIR}/build_dpkg
PKG_BUILD_DIR = ${PKG_BUILD_DIR_ALL}/${PKG_NAME}
PKG_BUILD_DIR_DPKG = ${PKG_BUILD_DIR}/DPKG
PKG_MAKE_INTALL = ${PKG_BUILD_DIR_DPKG}/usr
PKG_BUILD_DIR_DEBIAN = ${PKG_BUILD_DIR_DPKG}/DEBIAN/control


PKG_CONFIGURE = ${PGK_BUILD_DIR}/Makefile
PKG_DPKG_FILE_PATH = ${PKG_BUILD_DIR}/${PKG_DPKG_FILE}


PKG_COMPILE_MAKE = ""
#PKG_COMPILE_NINJA = ""
PKG_COMPILE_DIR = ${PGK_SOURCE_DIR}  # может быть ${PGK_SOURCE_DIR} для компиляции в папке исходников или ${PKG_BUILD_DIR}  для компиляции в отдельном каталоги


PKG_DEB_NAME = libasound2
PKG_BUILD_DEB_DIR = ${PKG_BUILD_DIR_ALL}/${PKG_DEB_NAME}
PKG_ORIG = ${PKG_NAME}(>=${PKG_VERSION})
PKG_DPKG_DEB_FILE = ${PKG_DEB_NAME}.${PKG_VERSION}.deb 

.PHONY:  all, COMPILE, BUILD_DIR, PKG_CONFIGURE

PKG_COMPLITE =  $(shell pkg-exist ${PKG_DPKG_FILE_PATH})   ## определяет естьли собранный файл пакета если нет собираем

ifeq ($(strip "$(PKG_COMPLITE)"),$(strip "0  "))
all: BUILD_DIR  ${PKG_TAR} ${PGK_SOURCE_DIR} PKG_CONFIGURE COMPILE ${PKG_MAKE_INTALL} PKG_MAKE_POST_INTALL ${PKG_BUILD_DIR_DEBIAN} PKG_BUILD_DEB_DIR_DEBIAN
	@echo ${PKG_DPKG_FILE_PATH}
	sudo chown root:root -R ${PKG_BUILD_DIR_DPKG}
	@cd ${ROOT_DPKG_ARCH} && sudo dpkg-deb --build ${PKG_BUILD_DIR_DPKG} ${PKG_DPKG_FILE}
	sudo dpkg -i ${ROOT_DPKG_ARCH}/${PKG_DPKG_FILE}
ifdef PKG_ORIG
	sudo chown root:root -R ${PKG_BUILD_DEB_DIR_DPKG}
	@cd ${ROOT_DPKG_ARCH} && sudo dpkg-deb --build ${PKG_BUILD_DEB_DIR_DPKG} ${PKG_DPKG_DEB_FILE}
	sudo dpkg -i ${ROOT_DPKG_ARCH}/${PKG_DPKG_DEB_FILE}
endif	
	
BUILD_DIR:
	@mkdir -p ${PKG_BUILD_DIR_DPKG}
	@mkdir -p ${ROOT_SOURCE}


${PKG_TAR}:
	wget ${PKG_URL} -P ${ROOT_SOURCE}/


${PGK_SOURCE_DIR}:
	@cd ${ROOT_SOURCE} && tar -xf ${PKG_TAR_FILE}

PKG_CONFIGURE:
	@cd ${PGK_SOURCE_DIR} && .$(CONFIGURE) --localstatedir=/var --without-debug
	@cd ${PGK_SOURCE_DIR} && sed -i -e 's/ -shared / -Wl,-O1,--as-needed\0/g' libtool


include ${ROOT_DIR}/scripts/compile.mk

PKG_MAKE_POST_INTALL:
##	@rm -rf ${PKG_BUILD_DIR_DPKG}/usr/include/atk-1.0/atk/atk-autocleanups.h


include ${ROOT_DIR}/scripts/build_dpkg.mk
	
include ${ROOT_DIR}/scripts/build_dpkg_deb.mk
	
else
all: 
	@echo "Уже собранно ${PKG_COMPLITE} ${PKG_NAME}"	
endif

		
