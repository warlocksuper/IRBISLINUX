OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PATH = $(shell printenv PATH):${ROOT_DIR}/scripts:${ROOT_DIR}/tools/pkg-build/
export  PATH


PKG_VERSION = 1.12
PKG_NAME = make-ca
PKG_URL = https://github.com/lfs-book/make-ca/releases/download/v1.12/make-ca-1.12.tar.xz
PKG_TAR_FILE = ${PKG_NAME}-1.12.tar.xz
PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}-${PKG_VERSION}


PKG_DEBIAN_SECTION = "Section: security"
PKG_DEBIAN_DEPANDS = "Depends: p11-kit(>=0.24.1) "
PKG_DEBIAN_DEST = "Description: Public Key Infrastructure (PKI) is a method to validate the authenticity of an otherwise unknown entity across untrusted networks. PKI works by establishing a chain of trust, rather than trusting each individual host or entity explicitly. In order for a certificate presented by a remote entity to be trusted, that certificate must present a complete chain of certificates that can be validated using the root certificate of a Certificate Authority (CA) that is trusted by the local machine."


PKG_COMPILE = ${PGK_BUILD_DIR}/make


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
all: BUILD_DIR  ${PKG_TAR} ${PGK_SOURCE_DIR} PKG_CONFIGURE COMPILE ${PKG_MAKE_INTALL} ${PKG_BUILD_DIR_DEBIAN}
	install -vdm755 ${PKG_BUILD_DIR_DPKG}/etc/profile.d
	@cp pythoncerts.sh ${PKG_BUILD_DIR_DPKG}/etc/profile.d/
	install -vdm755 ${PKG_BUILD_DIR_DPKG}/etc/ssl/local
	install -vdm755 ${PKG_BUILD_DIR_DPKG}/usr/lib/systemd/system
	install -vm644  ${PGK_SOURCE_DIR}/systemd/* ${PKG_BUILD_DIR_DPKG}/usr/lib/systemd/system
	openssl x509 -in ${ROOT_SOURCE}/root.crt -text -fingerprint -setalias "CAcert Class 1 root" \
        -addtrust serverAuth -addtrust emailProtection -addtrust codeSigning \
        > ${PKG_BUILD_DIR_DPKG}/etc/ssl/local/CAcert_Class_1_root.pem 
	openssl x509 -in ${ROOT_SOURCE}/class3.crt -text -fingerprint -setalias "CAcert Class 3 root" \
        -addtrust serverAuth -addtrust emailProtection -addtrust codeSigning \
        > ${PKG_BUILD_DIR_DPKG}/etc/ssl/local/CAcert_Class_3_root.pem  
	sudo chown root:root -R ${PKG_BUILD_DIR_DPKG}
	@cd ${ROOT_DPKG_ARCH} && sudo dpkg-deb --build ${PKG_BUILD_DIR_DPKG} ${PKG_DPKG_FILE}
	sudo dpkg -i ${ROOT_DPKG_ARCH}/${PKG_DPKG_FILE}
	
	
BUILD_DIR:
	@mkdir -p ${PKG_BUILD_DIR_DPKG}
	@mkdir -p ${ROOT_SOURCE}


${PKG_TAR}:
	wget ${PKG_URL} -P ${ROOT_SOURCE}/
	wget http://www.cacert.org/certs/root.crt -P ${ROOT_SOURCE}/
	wget http://www.cacert.org/certs/class3.crt -P ${ROOT_SOURCE}/


${PGK_SOURCE_DIR}:
	@cd ${ROOT_SOURCE} && tar -xf ${PKG_TAR_FILE}

PKG_CONFIGURE:
#	@cd ${PKG_BUILD_DIR} && ${PKG_SOURCE_DIR}/configure --prefix=/usr --sysconfdir=/etc --disable-static 


include ${ROOT_DIR}/scripts/compile.mk

include ${ROOT_DIR}/scripts/build_dpkg.mk
	
else
all: 
	@echo "Уже собранно ${PKG_COMPLITE} ${PKG_NAME}"	
endif		
