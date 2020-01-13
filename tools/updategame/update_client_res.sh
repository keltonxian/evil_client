#!/bin/bash

USER=kelton
HOST=127.0.0.1
PORT=8010
UH="$USER@$HOST"

rm g.zip

## b/game.lua : text lua
## g/game.lua : compiled version (binary) by luajit -b 

##./luajit -b b/game.lua g/game.lua
##./luajit -b b/lang_local.lua g/lang_local.lua

../encryptupdate/encrypt lua core game.lua
cp lua/lang_local.lua core/lang_local.lua

zip -r g.zip core

scp g.zip $UH:$TOMCAT_ROOT/webapps/evil/res/lua 
curl http://$HOST:$PORT/evil/patch.refresh

