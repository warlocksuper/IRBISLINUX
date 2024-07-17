OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PATH = $(shell printenv PATH):${ROOT_DIR}/scripts
export  PATH

PKG_VERSION = 18.1.8
PKG_NAME = llvm
PKG_BASE_URL = https://github.com/llvm/llvm-project/releases/download/llvmorg-${PKG_VERSION}
PKG_URL = ${PKG_BASE_URL}/llvm-${PKG_VERSION}.src.tar.xz
PKG_URL2 = ${PKG_BASE_URL}/third-party-${PKG_VERSION}.src.tar.xz
PKG_URL3 = ${PKG_BASE_URL}/cmake-${PKG_VERSION}.src.tar.xz
PKG_TAR_FILE = ${PKG_NAME}-${PKG_VERSION}.src.tar.xz
PKG_TAR_FILE2 = third-party-${PKG_VERSION}.src.tar.xz
PKG_TAR_FILE3 = cmake-${PKG_VERSION}.src.tar.xz
PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}-${PKG_VERSION}.src
PKG_DEBIAN_DEPANDS = "Depends:  "


PKG_DEBIAN_SECTION = "Section: misc"

PKG_DEBIAN_DEST = "Description: Compiler infrastructure and LLVM runtime libraries."

PKG_DPKG_FILE = ${PKG_NAME}.${PKG_VERSION}.deb 

PKG_TAR = ${ROOT_SOURCE}/${PKG_TAR_FILE}
PKG_BUILD_DIR_ALL = ${ROOT_DIR}/build_dpkg
PKG_BUILD_DIR = ${PKG_BUILD_DIR_ALL}/${PKG_NAME}
PKG_BUILD_DIR_DPKG = ${PKG_BUILD_DIR}/DPKG
PKG_MAKE_INTALL = ${PKG_BUILD_DIR_DPKG}/usr
PKG_BUILD_DIR_DEBIAN = ${PKG_BUILD_DIR_DPKG}/DEBIAN/control

PKG_DPKG_FILE_PATH = ${ROOT_DPKG_ARCH}/${PKG_DPKG_FILE}

PKG_CONFIGURE = ${PGK_BUILD_DIR}/Makefile


#PKG_COMPILE_MAKE = ""
PKG_COMPILE_NINJA = ""
PKG_COMPILE_DIR = ${PKG_BUILD_DIR}  # может быть ${PGK_SOURCE_DIR} для компиляции в папке исходников или ${PKG_BUILD_DIR}  для компиляции в отдельном каталоги




.PHONY:  all, COMPILE, BUILD_DIR, PKG_CONFIGURE

PKG_COMPLITE =  $(shell pkg-exist ${PKG_DPKG_FILE_PATH})   ## определяет естьли собранный файл пакета если нет собираем

ifeq ($(strip "$(PKG_COMPLITE)"),$(strip "0  "))
all: BUILD_DIR  ${PKG_TAR} ${PGK_SOURCE_DIR} PKG_CONFIGURE COMPILE ${PKG_MAKE_INTALL} PKG_MAKE_POST_INTALL ${PKG_BUILD_DIR_DEBIAN} 
	@echo ${PKG_DPKG_FILE_PATH}
	sudo chown root:root -R ${PKG_BUILD_DIR_DPKG}
	@cd ${ROOT_DPKG_ARCH} && sudo dpkg-deb --build ${PKG_BUILD_DIR_DPKG} ${PKG_DPKG_FILE}
	sudo dpkg -i ${ROOT_DPKG_ARCH}/${PKG_DPKG_FILE}
	
	
BUILD_DIR:
	@mkdir -p ${PKG_BUILD_DIR_DPKG}
	@mkdir -p ${ROOT_SOURCE}


${PKG_TAR}:
	wget ${PKG_URL} -P ${ROOT_SOURCE}/
	wget ${PKG_URL2} -P ${ROOT_SOURCE}/
	wget ${PKG_URL3} -P ${ROOT_SOURCE}/


${PGK_SOURCE_DIR}:
	@cd ${ROOT_SOURCE} && tar -xf ${PKG_TAR_FILE}
	@cd ${ROOT_SOURCE} && tar -xf ${PKG_TAR_FILE2}
	@cd ${ROOT_SOURCE} && tar -xf ${PKG_TAR_FILE3}

PKG_CONFIGURE:
	@cd ${PKG_BUILD_DIR} && $(CMAKE)  -G Ninja  -DLLVM_INCLUDE_BENCHMARKS=OFF  \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_DOCDIR=share/doc \
    -DCMAKE_INSTALL_PREFIX=/usr \
    -DCMAKE_SKIP_RPATH=ON \
    -DLLVM_BINUTILS_INCDIR=/usr/include \
    -DLLVM_BUILD_DOCS=ON \
    -DLLVM_BUILD_LLVM_DYLIB=ON \
    -DBUILD_SHARED_LIBS=ON \
    -DLLVM_BUILD_TESTS=ON \
    -DLLVM_ENABLE_BINDINGS=OFF \
    -DLLVM_ENABLE_FFI=ON \
    -DLLVM_ENABLE_RTTI=ON \
    -DLLVM_ENABLE_SPHINX=ON \
    -DLLVM_INSTALL_GTEST=ON \
    -DLLVM_INSTALL_UTILS=ON \
    -DLLVM_LINK_LLVM_DYLIB=OFF \
    -DLLVM_USE_PERF=ON \
    -DSPHINX_WARNINGS_AS_ERRORS=OFF ${PGK_SOURCE_DIR}


include ${ROOT_DIR}/scripts/compile.mk

PKG_MAKE_POST_INTALL:
	@rm -rf ${PKG_BUILD_DIR_DPKG}/usr/include/atk-1.0/atk/atk-autocleanups.h


include ${ROOT_DIR}/scripts/build_dpkg.mk
	
else
all: 
	@echo "Уже собранно ${PKG_COMPLITE} ${PKG_NAME}"	
endif		
