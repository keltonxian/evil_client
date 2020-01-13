#!/bin/bash

USER=mac
## HOST=t3.17kapai.com
HOST=114.215.133.1
UH="$USER@$HOST"

rm g.zip

## b/game.lua : text lua
## g/game.lua : compiled version (binary) by luajit -b 

##./luajit -b b/game.lua g/game.lua
##./luajit -b b/lang_local.lua g/lang_local.lua
../encryptupdate/encrypt b g game.lua
cp b/lang_local.lua g/lang_local.lua

zip -r g.zip g

scp g.zip $UH:/home/mac/www/patch 
curl http://$HOST:8899/s/patch.refresh

