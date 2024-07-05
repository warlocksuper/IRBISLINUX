OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PATH = $(shell printenv PATH):${ROOT_DIR}/scripts:${ROOT_DIR}/tools/pkg-build/
export  PATH

PKG_VERSION = 14.1.0
PKG_NAME = gcc
PKG_URL = https://ftp.gnu.org/gnu/gcc/gcc-${PKG_VERSION}/gcc-${PKG_VERSION}.tar.gz 
##http://mirror.linux-ia64.org/gnu/gcc/releases/gcc-12.3.0/gcc-12.3.0.tar.gz
PKG_TAR_FILE = ${PKG_NAME}-${PKG_VERSION}.tar.gz
PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}-${PKG_VERSION}
PKG_DEBIAN_DEPANDS = "Depends: basefile(>=0.3), diffutils(>=3.9), libisl "


PKG_DEBIAN_SECTION = "Section: system"

PKG_DEBIAN_DEST = "Description: The GCC package contains the GNU compiler collection, which includes the C and C++ compilers."

PKG_COMPILE = ${PGK_BUILD_DIR}/brotli


PKG_DPKG_FILE = ${PKG_NAME}.${PKG_VERSION}.deb 

PKG_TAR = ${ROOT_SOURCE}/${PKG_TAR_FILE}
PKG_BUILD_DIR_ALL = ${ROOT_DIR}/build_dpkg
PKG_BUILD_DIR = ${PKG_BUILD_DIR_ALL}/${PKG_NAME}
PKG_BUILD_DIR_DPKG = ${PKG_BUILD_DIR}/DPKG
PKG_MAKE_INTALL = ${PKG_BUILD_DIR_DPKG}/usr
PKG_BUILD_DIR_DEBIAN = ${PKG_BUILD_DIR_DPKG}/DEBIAN/control

PKG_CONFIGURE = ${PGK_BUILD_DIR}/Makefile
PKG_DPKG_FILE_PATH = ${ROOT_DPKG_ARCH}/${PKG_DPKG_FILE}


PKG_COMPILE_MAKE = " all-gcc"
#PKG_COMPILE_NINJA = ""
PKG_COMPILE_DIR = ${PKG_BUILD_DIR}  # может быть ${PGK_SOURCE_DIR} для компиляции в папке исходников или ${PKG_BUILD_DIR}  для компиляции в отдельном каталоги

CC = gcc 
CXX = g++ 

export CC CXX

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
	@mkdir -p ${PKG_BUILD_DIR}
	@cd ${PGK_SOURCE_DIR}  && sed -i 's@\./fixinc\.sh@-c true@' gcc/Makefile.in
	@cd ${PGK_SOURCE_DIR}  && sed -i '/m64=/s/lib64/lib/' gcc/config/i386/t-linux64   
	@cd ${PKG_BUILD_DIR} && ${PGK_SOURCE_DIR}/configure --prefix=/usr --libdir=/usr/lib  \
	--enable-languages=ada,c,c++,fortran,go,lto,m2,objc,obj-c++,rust  --with-pkgversion="IRBIS LINUX 14.1.0" --enable-libada   \
      --enable-bootstrap \
      --libexecdir=/usr/lib \
      --mandir=/usr/share/man \
      --infodir=/usr/share/info \
      --with-bugurl=https://support.irbis.su \
      --with-build-config=bootstrap-lto \
      --with-linker-hash-style=gnu \
      --with-system-zlib \
      --enable-__cxa_atexit \
      --enable-cet=auto \
      --enable-checking=release \
      --enable-clocale=gnu \
      --enable-default-pie \
      --enable-default-ssp \
      --enable-gnu-indirect-function \
      --enable-gnu-unique-object \
      --enable-libstdcxx-backtrace \
      --enable-link-serialization=1 \
      --enable-linker-build-id \
      --enable-lto \
      --enable-plugin \
      --enable-shared \
      --enable-threads=posix \
      --disable-libssp --disable-multilib   \
      --disable-libstdcxx-pch \
      --disable-werror 

include ${ROOT_DIR}/scripts/compile.mk

include ${ROOT_DIR}/scripts/build_dpkg.mk
	
else
all: 
	@echo "Уже собранно ${PKG_COMPLITE} ${PKG_NAME}"	
endif		
