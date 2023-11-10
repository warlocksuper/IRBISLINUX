export PATH=$PATH:/usr/sbin
export PYENV_ROOT="$HOME/.pyenv"
command -v pyenv > /dev/null || export PATH="$PYENV_ROOT/bin:$PATH"
eval "$(pyenv init -)"

export XDG_SESSION_TYPE=wayland

PS1="irbis \u@\w:"
