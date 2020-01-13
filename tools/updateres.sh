#!/bin/bash

WWW_PATH=~/www
LOGIC_FILE=logic.lua 
LANG_FILE=lang_zh.lua 
SLIST_FILE=slist.txt 

echo Update: $LOGIC_FILE and $LANG_FILE
rm -rf $WWW_PATH/res
mkdir $WWW_PATH/res
mkdir $WWW_PATH/res/lua

cp $LOGIC_FILE $WWW_PATH/res/lua/
cp $LANG_FILE $WWW_PATH/res/lua/
cp $SLIST_FILE $WWW_PATH/res/

cd $WWW_PATH
rm res.zip
zip -r res.zip res

## REV_STR="$Rev: 249 $"

REV=`grep 'REV_STR=' $WWW_PATH/res/lua/$LOGIC_FILE`
REV=`echo $REV | sed 's/REV_STR="$Rev: //g'`
REV=`echo $REV | sed 's/ $"//g'`
echo $REV > $WWW_PATH/version
