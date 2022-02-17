#
#  Edit History:
#
#

case $LOGNAME in
        root)   PS1="!# " ;;
        *)      PS1="[$USER|:\$PWD]$ " ;;
esac
export PS1

export APP_DIR=$HOME/github/cbase

export CDPATH=.:$APP_DIR:$APP_DIR/src:~
export PATH=$PATH:$APP_DIR/bin:$APP_DIR/sbin:/usr/local/indent/bin

#export LC_ALL=zh_CN.GBK
#export LC_LANG=zh_CN.GBK
#export LANG=zh_CN.GBK


export CC=gcc

# set core environment
ulimit -S -c unlimited > /dev/null 2>&1

export LD_LIBRARY_PATH=$APP_DIR/extlib/ext_lib/lib:$APP_DIR/lib:$LD_LIBRARY_PATH

