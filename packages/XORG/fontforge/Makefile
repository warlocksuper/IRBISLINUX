
PKG_TAR_DIR = /root/fontforge-20230101.tar.xz

cmake ../CMakeLists.txt   -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Release -DENABLE_X11=OFF -DENABLE_GUI=OFF -DENABLE_LIBSPIRO=OFF    -Wno-dev


all: ${PKG_TAR_DIR}

${PKG_TAR_DIR}:
    wget https://github.com/fontforge/fontforge/releases/download/20230101/fontforge-20230101.tar.xz -P /root/
##    @cd /root/ && tar -xf fontforge-20230101.tar.xz
