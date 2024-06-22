OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PATH = $(shell printenv PATH):${ROOT_DIR}/scripts:${ROOT_DIR}/tools/pkg-build/
export  PATH

PKG_VERSION = 2.39
PKG_NAME = glibc32
PKG_URL =  https://ftp.gnu.org/gnu/glibc/glibc-2.39.tar.xz
PKG_TAR_FILE = glibc-${PKG_VERSION}.tar.xz
PGK_SOURCE_DIR = ${ROOT_SOURCE}/glibc-${PKG_VERSION}
PKG_DEBIAN_DEPANDS = "Depends:  "
PKG_DEBIAN_SECTION = "Section: system"
PKG_DEBIAN_DEST = "Description: The Glibc 32bit  package contains the main C library. This library provides the basic routines for allocating memory, searching directories, opening and closing files, reading and writing files, string handling, pattern matching, arithmetic, and so on."
#PKG_BUILD_REPLACES = " "


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


PKG_COMPILE_MAKE = ""
#PKG_COMPILE_NINJA = ""
PKG_COMPILE_DIR = ${PKG_BUILD_DIR}  # может быть ${PGK_SOURCE_DIR} для компиляции в папке исходников или ${PKG_BUILD_DIR}  для компиляции в отдельном каталоги

CC = gcc -m32 
CXX = g++ -m32 
CFLAGS = -O2 -march=i686
CXXFLAGS = -O2 -march=i686

export CC CXX




.PHONY:  all, COMPILE, BUILD_DIR, PKG_CONFIGURE

PKG_COMPLITE =  $(shell pkg-exist ${PKG_DPKG_FILE_PATH})   ## определяет естьли собранный файл пакета если нет собираем

ifeq ($(strip "$(PKG_COMPLITE)"),$(strip "0  "))
all: BUILD_DIR  ${PKG_TAR} ${PGK_SOURCE_DIR} PKG_CONFIGURE COMPILE ${PKG_MAKE_INTALL} PRE_INSTALL ${PKG_BUILD_DIR_DEBIAN} 
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
	@cd ${PKG_BUILD_DIR} &&  ${PGK_SOURCE_DIR}/$(CONFIGURE)  --host=i686-pc-linux-gnu --build=i686-pc-linux-gnu \
        --libdir=/usr/lib32 \
        --libexecdir=/usr/lib32 \
        --with-headers=/usr/include
      --with-bugurl=https://support.irbis.su \
      --enable-bind-now \
      --enable-fortify-source \
      --enable-kernel=4.4 \
      --enable-multi-arch \
      --enable-stack-protector=strong \
      --enable-systemtap \
      --disable-nscd \
      --disable-profile \
      --disable-werror


include ${ROOT_DIR}/scripts/compile.mk

PRE_INSTALL:
	@rm -rf ${PKG_BUILD_DIR_DPKG}/{etc,sbin,usr/{bin,sbin,share},var}
	@find ${PKG_BUILD_DIR_DPKG}/usr/include -type f -not -name '*-32.h' -delete
	install -d ${PKG_BUILD_DIR_DPKG}/usr/lib
	install -Dm644 lib32-glibc.conf ${PKG_BUILD_DIR_DPKG}/etc/ld.so.conf.d/lib32-glibc.conf	
#	ln -s ../lib32/ld-linux.so.2 ${PKG_BUILD_DIR_DPKG}/usr/lib/



include ${ROOT_DIR}/scripts/build_dpkg.mk

else
all: 
	@echo "Уже собранно ${PKG_COMPLITE} ${PKG_NAME}"	
endif	
