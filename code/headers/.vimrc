set nu rnu hls is nosol ts=4 sw=4 ch=2 sc
filetype indent plugin on
syntax on
ca Hash w !cpp -dD -P -fpreprocessed \| tr -d '[:space:]' \
\| md5sum \| cut -c-6
