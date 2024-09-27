OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}


PKG_NAME = glibc-2.37
PKG_URL = https://ftp.gnu.org/gnu/glibc/glibc-2.37.tar.xz
PKG_TAR_FILE = ${PKG_NAME}.tar.xz
PGK_BUILD_DIR = ${ROOT_BUILD}/glibc


GLIBC_TAR = ${ROOT_SOURCE}/${PKG_TAR_FILE}
PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}

GLIBC_STAGE1_CONFIGURE = ${ROOT_BUILD}/glibc/Makefile
GLIBC_STAGE1_COMPILE = ${ROOT_BUILD}/glibc/libc.so
GLIBC_STAGE1_INSTALL = ${ROOT_FS}/usr/lib/ld-linux-x86-64.so.2

GLIBC_STAGE2_BUILD_DIR = ${ROOT_BUILD}/glibc_stage2
GLIBC_STAGE2_CONFIGURE = ${GLIBC_STAGE2_BUILD_DIR}/Makefile
GLIBC_STAGE2_COMPILE = ${GLIBC_STAGE2_BUILD_DIR}/libc.so
GLIBC_STAGE2_INSTALL = ${ROOT_FS}/usr/lib/ld-linux-x86-64.so.2_12 



export ARG_MAX=20480

all:

stage1_tools: ${GLIBC_TAR} ${PGK_SOURCE_DIR}  ${GLIBC_STAGE1_CONFIGURE} ${GLIBC_STAGE1_COMPILE} ${GLIBC_STAGE1_INSTALL}

${GLIBC_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_SOURCE}
	wget ${PKG_URL} -P ${ROOT_SOURCE}


${PGK_SOURCE_DIR}:
	@cd ${ROOT_SOURCE} && tar -xf ${PKG_TAR_FILE}
	@cp ${ROOT_DIR}/packages/glibc/glibc-2.37-fhs-1.patch  ${ROOT_SOURCE}/${PKG_NAME}/
	@cd ${ROOT_SOURCE}/${PKG_NAME} && patch -Np1 -i glibc-2.37-fhs-1.patch

${GLIBC_STAGE1_CONFIGURE}:
	@mkdir -p ${PGK_BUILD_DIR}
	@cp ${ROOT_DIR}/packages/glibc/configparms ${PGK_BUILD_DIR}/
	@cd ${PGK_BUILD_DIR} && ${ROOT_SOURCE}/${PKG_NAME}/configure --prefix=/usr --host=${CONFIG_OS_ARCH_TARGET} --build=$($ROOT_SOURCE/$PKG_NAME/scripts/config.guess) --enable-kernel=3.2 --with-headers=${ROOT_FS}/usr/include libc_cv_slibdir=/usr/lib --disable-static
	
${GLIBC_STAGE1_COMPILE}:
	${MAKE} -C ${PGK_BUILD_DIR}
	
${GLIBC_STAGE1_INSTALL}:
		${MAKE} -C ${PGK_BUILD_DIR} DESTDIR=${ROOT_FS} install	
		@cd ${ROOT_FS} && ln -sv usr/lib lib64
		
		
temporary_tools: ${GLIBC_STAGE2_CONFIGURE} ${GLIBC_STAGE1_COMPILE} ${GLIBC_STAGE2_INSTALL}

${GLIBC_STAGE2_CONFIGURE}:
	@mkdir -p ${GLIBC_STAGE2_BUILD_DIR}
	@cd ${GLIBC_STAGE2_BUILD_DIR} && ${PGK_SOURCE_DIR}/configure --prefix=/usr                            \
             --disable-werror                         \
             --enable-kernel=3.2                      \
             --enable-stack-protector=strong          \
             --with-headers=/usr/include              \
             libc_cv_slibdir=/usr/lib   --with-pkgversion="IRBIS libc"  --with-bugurl="https://support.irbis.su" --disable-static --build=x86_64-irbis-linux-gnu --disable-static
	
${GCC_STAGE2_COMPILE}:
	${MAKE} -C ${GLIBC_STAGE2_BUILD_DIR}
	
	
${GCC_STAGE2_INSTALL}:
	${MAKE} -C ${GLIBC_STAGE2_BUILD_DIR} DESTDIR=${ROOT_FS} install			
