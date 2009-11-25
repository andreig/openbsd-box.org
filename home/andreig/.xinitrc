#!/usr/local/bin/zsh
set -x
xset r rate 250 50
xset dpms
#xsetroot -fg \#000000 -bg \#222222 -mod 5 5 -cursor_name left_ptr
#xmodmap ~/.xmodmap
pkill xidle
xidle -delay 5 -sw -program "/usr/X11R6/bin/xlock -mode blank" -timeout 90 &
#wmsetbg /home/andreig/personal/pix/openbsd_wallpaper_1600x1200_mirrored.jpg
#wmsetbg /home/andreig/work/newciumegu/ciumegu-girl.gif
#display -window root /home/andreig/personal/pix/openbsd_wallpaper_1600x1200_mirrored.jpg RET
#pkill dzen2
#${HOME}/bin/header.sh &
#${HOME}/bin/weather.sh &
#${HOME}/bin/clock.sh &
#exec ${HOME}/bin/cflicker &
#exec ${HOME}/bin/notiflicker &
exec $HOME/bin/autocutsel -s PRIMARY &
exec wmii
