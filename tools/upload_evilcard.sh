#!/bin/bash

SOURCE_FILE=package/EvilCard.apk

scp -P 22000 $SOURCE_FILE mac@211.149.186.201:/home/mac/www/

SOURCE_FILE=package/EvilCard.ipa

scp -P 22000 $SOURCE_FILE mac@211.149.186.201:/home/mac/www/
