wget https://www.infodrom.org/projects/sysklogd/download/sysklogd-1.5.1.tar.gz

sed -i '/Error loading kernel symbols/{n;n;d}' ksym_mod.c
sed -i 's/union wait/int' syslogd.c

