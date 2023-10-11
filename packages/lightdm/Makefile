https://github.com/CanonicalLtd/lightdm/releases/download/1.32.0/lightdm-1.32.0.tar.xz


depand libxklavier lightdm-gtk-greeter

sed -i s/systemd/eloging/ data/pam/*

Configure --libexecdir=/usr/lib/lightdm --localstatedir=/var --sbindir=/usr/bin --disable-static --disable-tests --with-greeter-user=lightdm --with-greeter-session=lightdm-gtk-greeter --docdir=/usr/share/doc/lightdm-1.32.0 

make

cp tests/src/lightdm-session /DPKG/usr/bin
sed -i 's/sh/bash --login/' DPKG/usr/bin/lightdm-session
rm -rf /etc/init