OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PKG_VERSION = 5.15.17
PKG_NAME = qtwebengine
PKG_URL =  https://anduin.linuxfromscratch.org/BLFS/qtwebengine/qtwebengine-5.15.17.tar.xz
PKG_TAR_FILE = ${PKG_NAME}-${PKG_VERSION}.tar.xz
PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}-${PKG_VERSION}
PKG_DEBIAN_DEPANDS = "Depends: "
PKG_DEBIAN_SECTION = "Section: net"
PKG_DEBIAN_DEST = "Description: WebKitEnginer is an open source web browser engine. WebKit's HTML and JavaScript code began as a branch of the KHTML and KJS libraries from KDE. As part of KDE framework KHTML was based on Qt but during their porting efforts Apple's engineers made WebKit toolkit independent. QtWebKit is a project aiming at porting this fabulous engine back to Qt."
PKG_DPKG_FILE = ${PKG_NAME}.${PKG_VERSION}.deb
QTWEBENGINE_ROOT = /usr


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

PKG_COMPLITE =  $(shell pkg-exist ${PKG_DPKG_FILE_PATH})  ## определяет естьли собранный файл пакета если нет собираем

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
#	cd ${ROOT_SOURCE} && git clone ${PKG_URL} 


${PGK_SOURCE_DIR}:
	@cd ${ROOT_SOURCE} && tar -xf ${PKG_TAR_FILE}
	cd ${PGK_SOURCE_DIR} && patch -Np1 -i ${PKG_PRG_DIR}/${PKG_NAME}_pkg/qtwebengine-5.15.17-build_fixes-2.patch
	cd ${PGK_SOURCE_DIR} && patch -Np1 -i ${PKG_PRG_DIR}/${PKG_NAME}_pkg/qtwebengine-5.15.17-ffmpeg5_fixes-1.patch
	cd ${PGK_SOURCE_DIR} && mkdir -pv .git src/3rdparty/chromium/.git
	cd ${PGK_SOURCE_DIR} && sed -e '/^MODULE_VERSION/s/5.*/5.15.12/' -i .qmake.conf
	cd ${PGK_SOURCE_DIR} && sed -e '/link_pulseaudio/s/false/true/' -i src/3rdparty/chromium/media/media_options.gni
	cd ${PGK_SOURCE_DIR} && sed -e 's/xmlError/const xmlError/' -i src/3rdparty/chromium/third_party/blink/renderer/core/xml/xslt_processor.h -i src/3rdparty/chromium/third_party/blink/renderer/core/xml/xslt_processor_libxslt.cc    

####//find -type f -name "*.pr[io]" | xargs sed -i -e 's|INCLUDEPATH += |&$${QTWEBENGINE_ROOT}/include |'
    
    
    


PKG_CONFIGURE:
	@cd ${PKG_BUILD_DIR} &&  qmake ${PGK_SOURCE_DIR} 

include ${ROOT_DIR}/scripts/compile.mk

include ${ROOT_DIR}/scripts/build_dpkg.mk

else
all: 
	@echo "Уже собранно '${PKG_COMPLITE}' ${PKG_NAME}"	
endif	
