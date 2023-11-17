OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}



COPY_ROOTFS = ${ROOT_FS}/etc

PKG_VERSION = 1.12
PKG_NAME = make-ca
PKG_URL = https://github.com/lfs-book/make-ca/releases/download/v1.12/make-ca-1.12.tar.xz
PKG_TAR_FILE = ${PKG_NAME}-1.12.tar.xz
PKG_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}-${PKG_VERSION}


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

PKG_DPKG_FILE_PATH = ${PKG_BUILD_DIR}/${PKG_DPKG_FILE}
PKG_CONFIGURE = ${PGK_BUILD_DIR}/Makefile


all: ${PKG_BUILD_DIR_ALL} ${PKG_BUILD_DIR_DPKG} ${PKG_TAR} ${PKG_SOURCE_DIR} ${PKG_MAKE_INTALL} ${PKG_BUILD_DIR_DEBIAN}  ${PKG_DPKG_FILE_PATH}

${PKG_BUILD_DIR_ALL}:
	@mkdir -p ${PKG_BUILD_DIR_ALL}
	
${PKG_BUILD_DIR}:
	@mkdir -p ${PKG_BUILD_DIR}

${PKG_BUILD_DIR_DPKG}:
	@mkdir -p ${PKG_BUILD_DIR_DPKG}


${PKG_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_SOURCE}
	wget ${PKG_URL} -P ${ROOT_SOURCE}/
	wget http://www.cacert.org/certs/root.crt -P ${ROOT_SOURCE}/
	wget http://www.cacert.org/certs/class3.crt -P ${ROOT_SOURCE}/


${PKG_SOURCE_DIR}:
	@cd ${ROOT_SOURCE} && tar -xf ${PKG_TAR_FILE}

${PKG_CONFIGURE}:
	@mkdir -p ${PKG_BUILD_DIR}
	@cd ${PKG_BUILD_DIR} && ${PKG_SOURCE_DIR}/configure --prefix=/usr --sysconfdir=/etc --disable-static 

${PKG_COMPILE}:
	${MAKE} -C ${PKG_BUILD_DIR}


${PKG_MAKE_INTALL}:
	${MAKE} -C ${PKG_SOURCE_DIR} DESTDIR=${PKG_BUILD_DIR_DPKG} install
	install -vdm755 ${PKG_BUILD_DIR_DPKG}/etc/profile.d
	@cp pythoncerts.sh ${PKG_BUILD_DIR_DPKG}/etc/profile.d/
	install -vdm755 ${PKG_BUILD_DIR_DPKG}/etc/ssl/local
	install -vdm755 ${PKG_BUILD_DIR_DPKG}/usr/lib/systemd/system
	install -vm644  ${PKG_SOURCE_DIR}/systemd/* ${PKG_BUILD_DIR_DPKG}/usr/lib/systemd/system
	openssl x509 -in ${ROOT_SOURCE}/root.crt -text -fingerprint -setalias "CAcert Class 1 root" \
        -addtrust serverAuth -addtrust emailProtection -addtrust codeSigning \
        > ${PKG_BUILD_DIR_DPKG}/etc/ssl/local/CAcert_Class_1_root.pem 
	openssl x509 -in ${ROOT_SOURCE}/class3.crt -text -fingerprint -setalias "CAcert Class 3 root" \
        -addtrust serverAuth -addtrust emailProtection -addtrust codeSigning \
        > ${PKG_BUILD_DIR_DPKG}/etc/ssl/local/CAcert_Class_3_root.pem 

${PKG_BUILD_DIR_DEBIAN}:
	install -d ${PKG_BUILD_DIR_DPKG}/DEBIAN
	@echo "Package: ${PKG_NAME}" >> ${PKG_BUILD_DIR_DEBIAN}
	@echo "Architecture: amd64" >> ${PKG_BUILD_DIR_DEBIAN}
	@echo "Version: ${PKG_VERSION}" >> ${PKG_BUILD_DIR_DEBIAN}
	@echo "Provides: ${PKG_NAME}" >> ${PKG_BUILD_DIR_DEBIAN}
	@echo "Maintainer: Dmitry Lebedev <D.Lebedev@irbis.su>" >> ${PKG_BUILD_DIR_DEBIAN}
	@echo ${PKG_DEBIAN_SECTION} >> ${PKG_BUILD_DIR_DEBIAN}
	@echo ${PKG_DEBIAN_DEPANDS} >> ${PKG_BUILD_DIR_DEBIAN}
	@echo "Installed-Size: `du -s ${PKG_BUILD_DIR_DPKG} | cut -f1`" >> ${PKG_BUILD_DIR_DEBIAN}
	@echo ${PKG_DEBIAN_DEST} >> ${PKG_BUILD_DIR_DEBIAN}
	@cp postinst ${PKG_BUILD_DIR_DPKG}/DEBIAN/	
	
${PKG_DPKG_FILE_PATH}:
	sudo chown root:root -R ${PKG_BUILD_DIR_DPKG}
	@cd ${ROOT_DPKG_ARCH} && sudo dpkg-deb --build ${PKG_BUILD_DIR_DPKG} ${PKG_DPKG_FILE}