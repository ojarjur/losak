#!/bin/bash
ROOT_MESSAGE="You do not have the required permissions to install"
BIN_DIR="/usr/local/bin"

if [ ! -d "/usr/local/bin" ]; then BIN_DIR="/usr/bin"; fi
touch ${BIN_DIR}/losakc || ( echo $(ROOT_MESSAGE) && exit 1 )
if [ ! -d "/usr/local/losak" ]; then mkdir /usr/local/losak; fi
touch /usr/local/losak/compile.sh || ( echo $(ROOT_MESSAGE) && exit 1 )
cp -r ./* /usr/local/losak/.
sed -e "s/INSTALL_DIR=\"\.\"/INSTALL_DIR=\"\/usr\/local\/losak\"/" compile.sh > ${BIN_DIR}/losakc
chmod ugo+rx ${BIN_DIR}/losakc
