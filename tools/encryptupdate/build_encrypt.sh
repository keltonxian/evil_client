#!/bin/bash

gcc xor_encrypt.c -o encrypt

#./encrypt version.lua
#./encrypt ../updategame/b g game.lua
#./encrypt ../updategame/b g lang_local.lua
./encrypt b g game.lua
./encrypt b g lang_local.lua
./encrypt b g logic.lua
./encrypt b g lang_zh.lua
#echo $#
#echo $1
#for i in $#;
#for((i=1;i<=$#;i++));
#do
#	echo $i;
#done


#i=0
#ARGC=$#
#while [ $i -lt $ARGC ]
#do
#	echo $1
#	shift
#	i=`expr $i + 1`
#done
