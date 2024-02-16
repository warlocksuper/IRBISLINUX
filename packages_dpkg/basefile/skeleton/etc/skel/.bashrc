export PATH=$PATH:/usr/sbin:/usr/libexec

if [ -f "/etc/bashrc" ] ; then
  source /etc/bashrc
fi

export XDG_RUNTIME_DIR=/run/user/$(id -u)

export XDG_SESSION_TYPE=x11
export GDK_BACKEND=x11

export GI_TYPELIB_PATH=/usr/lib/girepository-1.0
PS1="irbis \u@\w:"

export LANG=ru_RU.UTF-8
export PKG_CONFIG_PATH=/usr/lib/pkgconfig
export CPPFLAGS=-I/usr/include
export LDFLAGS=-L/usr/lib
export LD_LIBRARY_PATH=/usr/lib
