
ROOT_SOURCE=${HOME}/sources
PKG_URL=https://www.iana.org/time-zones/repository/releases/tzdata2023c.tar.gz
PKG_FILE=tzdata2023c.tar.gz
PKG_NAME=tzdata2023c
PKG_FILE_SOURCE=${ROOT_SOURCE}/timezone/tzdata2023c.tar.gz
PKG_VERSION=2023c
PGK_SOURCE_DIR = ${ROOT_SOURCE}/timezone
PGK_COMPILE = ${PGK_SOURCE_DIR}/xz

ZONEINFO=/usr/share/zoneinfo
export ZONEINFO


DPKG: ${PKG_FILE_SOURCE} ${PGK_SOURCE_DIR} ${PGK_COMPILE}


${PKG_FILE_SOURCE}:
	mkdir -p ${ROOT_SOURCE}/timezone
	wget ${PKG_URL} -P ${ROOT_SOURCE}/timezone
	
${PGK_SOURCE_DIR}:
	@cd ${ROOT_SOURCE}/timezone && tar -xf ${PKG_FILE}	
	
${PGK_COMPILE}:
	${MAKE} -C ${PGK_SOURCE_DIR}	
	
	
	
tar -xf ../../tzdata2022g.tar.gz

ZONEINFO=/usr/share/zoneinfo
mkdir -pv $ZONEINFO/{posix,right}

for tz in etcetera southamerica northamerica europe africa antarctica  \
          asia australasia backward; do
    zic -L /dev/null   -d $ZONEINFO       ${tz}
    zic -L /dev/null   -d $ZONEINFO/posix ${tz}
    zic -L leapseconds -d $ZONEINFO/right ${tz}
done

cp -v zone.tab zone1970.tab iso3166.tab $ZONEINFO
zic -d $ZONEINFO -p America/New_York
unset ZONEINFO


timedatectl set-timezone Europe/Moscow