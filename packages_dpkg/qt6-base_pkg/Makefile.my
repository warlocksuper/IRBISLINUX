## 
##  configure   /usr/bin/pwd
## sudo pip3 install html5lib
## -la -lb -lc
##


OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PATH = $(shell printenv PATH):${ROOT_DIR}/scripts
export  PATH

PKG_VERSION = 6.7.2
PKG_NAME = qt6-base
PKG_URL = https://qt-mirror.dannhauer.de/official_releases/qt/6.7/${PKG_VERSION}/single/qt-everywhere-src-${PKG_VERSION}.tar.xz
PKG_TAR_FILE = qt-everywhere-src-${PKG_VERSION}.tar.xz
PGK_SOURCE_DIR = ${ROOT_SOURCE}/qt-everywhere-src-${PKG_VERSION}
PKG_DEBIAN_DEPANDS = "Depends:  "


PKG_DEBIAN_SECTION = "Section: librares"

PKG_DEBIAN_DEST = "Description: The QCoro library provides set of tools to make use of C++20 coroutines with Qt."

PKG_DPKG_FILE = ${PKG_NAME}.${PKG_VERSION}.deb 

PKG_TAR = ${ROOT_SOURCE}/${PKG_TAR_FILE}
PKG_BUILD_DIR_ALL = ${ROOT_DIR}/build_dpkg
PKG_BUILD_DIR = ${PKG_BUILD_DIR_ALL}/${PKG_NAME}
PKG_BUILD_DIR_DPKG = ${PKG_BUILD_DIR}/DPKG
PKG_MAKE_INTALL = ${PKG_BUILD_DIR_DPKG}/usr
PKG_BUILD_DIR_DEBIAN = ${PKG_BUILD_DIR_DPKG}/DEBIAN/control



PKG_CONFIGURE = ${PGK_BUILD_DIR}/Makefile
PKG_DPKG_FILE_PATH = ${ROOT_DPKG_ARCH}/${PKG_DPKG_FILE}

#PKG_COMPILE_MAKE = ""
PKG_COMPILE_CMAKE = ""
#PKG_COMPILE_NINJA = ""
PKG_COMPILE_DIR = ${PKG_BUILD_DIR}  # может быть ${PGK_SOURCE_DIR} для компиляции в папке исходников или ${PKG_BUILD_DIR}  для компиляции в отдельном каталоги

#INTERFACE_INCLUDE_DIRECTORIES = /usr/include
CLANG_CONFIG_INCLUDE_DIRS =  /usr/include
export CLANG_CONFIG_INCLUDE_DIRS
#export INTERFACE_INCLUDE_DIRECTORIES

PKG_COMPILE_MAKE_ADD_OPT = -j1

.PHONY:  all, COMPILE, BUILD_DIR,  PKG_PERPARE ,PKG_CONFIGURE

PKG_COMPLITE =  $(shell pkg-exist ${PKG_DPKG_FILE_PATH})   ## определяет естьли собранный файл пакета если нет собираем

ifeq ($(strip "$(PKG_COMPLITE)"),$(strip "0  "))
all: BUILD_DIR  ${PKG_TAR} ${PGK_SOURCE_DIR}  PKG_CONFIGURE COMPILE ${PKG_MAKE_INTALL} PKG_MAKE_POST_INTALL ${PKG_BUILD_DIR_DEBIAN} 
	@echo ${PKG_DPKG_FILE_PATH}
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

PKG_PERPARE:
	patch -d ${PGK_SOURCE_DIR}/qtbase -p1 < qt6-base-cflags.patch # Use system CFLAGS
	patch -d ${PGK_SOURCE_DIR}/qtbase -p1 < qt6-base-nostrip.patch # Don't strip binaries with qmake
#	@cd ${ROOT_DPKG_ARCH} && git cherry-pick -n f05cf3f11f4e42e05d069b5d9249d4b9aff41ffe # Fix locale issues
#	@cd ${ROOT_DPKG_ARCH} && git cherry-pick -n a8ef8ea55014546e0e835cd0eacf694919702a11 # https://bugreports.qt.io/browse/QTBUG-124386
#	@cd ${ROOT_DPKG_ARCH} && git cherry-pick -n 062f701a11d2c46660f5c5edd73f245477918a47 # Fix dependencies in pc files
#	@cd ${ROOT_DPKG_ARCH} && git cherry-pick -n 5ee9da89af7efe31ac45858bf1eb04e5155a3b50 # Fix dependencies in pc files

PKG_CONFIGURE:
	@cd ${PKG_BUILD_DIR} && $(CMAKE)   -DCMAKE_BUILD_TYPE=RelWithDebInfo  -DINSTALL_BINDIR=lib/qt6/bin -DCMAKE_INCLUDE_PATH=/usr/include -DINTERFACE_INCLUDE_DIRECTORIES=/usr/include  \
    -DINSTALL_PUBLICBINDIR=usr/bin \
    -DINSTALL_LIBEXECDIR=lib/qt6 \
    -DINSTALL_DOCDIR=share/doc/qt6 \
    -DINSTALL_ARCHDATADIR=lib/qt6 \
    -DINSTALL_DATADIR=share/qt6 \
    -DINSTALL_INCLUDEDIR=include/qt6 \
    -DINSTALL_MKSPECSDIR=lib/qt6/mkspecs \
    -DINSTALL_EXAMPLESDIR=share/doc/qt6/examples \
    -DFEATURE_journald=ON \
    -DFEATURE_libproxy=ON \
    -DFEATURE_openssl_linked=ON \
    -DFEATURE_system_sqlite=ON \
    -DFEATURE_system_xcb_xinput=ON \
    -DFEATURE_no_direct_extern_access=ON \
    -DCMAKE_INTERPROCEDURAL_OPTIMIZATION=ON \
    -DCMAKE_MESSAGE_LOG_LEVEL=STATUS  ${PGK_SOURCE_DIR}


include ${ROOT_DIR}/scripts/compile.mk

PKG_MAKE_POST_INTALL:
	@rm -rf ${PKG_BUILD_DIR_DPKG}/usr/include/atk-1.0/atk/atk-autocleanups.h


include ${ROOT_DIR}/scripts/build_dpkg.mk
	
else
all: 
	@echo "Уже собранно ${PKG_COMPLITE} ${PKG_NAME}"	
endif		
