OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PATH = $(shell printenv PATH):${ROOT_DIR}/scripts:${ROOT_DIR}/tools/pkg-build
export  PATH
PKG_VERSION = 8.3.10
PKG_NAME = php
PKG_URL = https://php.net/distributions/${PKG_NAME}-${PKG_VERSION}.tar.xz
PKG_TAR_FILE = ${PKG_NAME}-${PKG_VERSION}.tar.xz
PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}-${PKG_VERSION}
PKG_DEBIAN_DEPANDS = "Depends:  "
#PKG_BUILD_REPLACES = "  "

PKG_DEBIAN_SECTION = "Section: internet"

PKG_DEBIAN_DEST = "Description: A general-purpose scripting language that is especially suited to web development."

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




.PHONY:  all, COMPILE, BUILD_DIR, PKG_CONFIGURE

PKG_COMPLITE =  $(shell pkg-exist ${PKG_DPKG_FILE_PATH})   ## определяет естьли собранный файл пакета если нет собираем

ifeq ($(strip "$(PKG_COMPLITE)"),$(strip "0  "))
all: BUILD_DIR  ${PKG_TAR} ${PGK_SOURCE_DIR} PKG_CONFIGURE COMPILE ${PKG_MAKE_INTALL} ${PKG_BUILD_DIR_DEBIAN} 
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
	@cd ${PKG_BUILD_DIR} && ${PGK_SOURCE_DIR}/$(CONFIGURE)  --sbindir=/usr/bin  --sysconfdir=/etc/php --localstatedir=/var --with-layout=GNU --with-config-file-path=/etc/php --with-config-file-scan-dir=/etc/php/conf.d --disable-rpath --mandir=/usr/share/man --disable-gcc-global-regs --enable-static=no --with-apxs2
#	@cd ${PGK_SOURCE_DIR} && qmake PREFIX=${PKG_BUILD_DIR_DPKG}/usr LIBDIR=${PKG_BUILD_DIR_DPKG}/usr/lib CMAKE_CONFIG_PATH=${PKG_BUILD_DIR_DPKG}/usr 


COMPILE:
	@cd ${PKG_COMPILE_DIR} && make ${PKG_COMPILE_MAKE_ADD_OPT} -j1


${PKG_MAKE_INTALL}:
	@cd ${PKG_BUILD_DIR} && make INSTALL_ROOT=${PKG_BUILD_DIR_DPKG}  install-{modules,cli,build,headers,programs,pharcmd}
	install -d ${PKG_BUILD_DIR_DPKG}/usr/lib/httpd/modules/
	install -d ${PKG_BUILD_DIR_DPKG}/etc/httpd/conf/extra/
	install -D -m755 "${PKG_BUILD_DIR}/libs/libphp.so" "${PKG_BUILD_DIR_DPKG}/usr/lib/httpd/modules/libphp.so"
	install -D -m644 apache.conf ${PKG_BUILD_DIR_DPKG}/etc/httpd/conf/extra/php_module.conf


include ${ROOT_DIR}/scripts/build_dpkg.mk
	
else
all: 
	@echo "Уже собранно ${PKG_COMPLITE} ${PKG_NAME}"	
endif		
