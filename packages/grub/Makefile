depends efibootmgr

https://ftp.gnu.org/gnu/grub/grub-2.06.tar.xz


https://www.linuxfromscratch.org/patches/blfs/11.3/grub-2.06-upstream_fixes-1.patch
patch -Np1 -i grub-2.06-upstream_fixes-1.patch


./configure --prefix=/usr --sysconfdir=/etc --disable-efiemu --disable-werror

https://unifoundry.com/pub/unifont/unifont-15.0.01/font-builds/unifont-15.0.01.pcf.gz
 
make install
mv -v /etc/bash_completion.d/grub /usr/share/bash-completion/completions

### efi
Configures --disable-efiemu --enable-grub-mkfont --with-platform=efi --target=x86_64 --disable-werror
