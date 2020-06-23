#!/bin/sh

SUM='cat log'
NEW='md5sum testfile | cut -d " " -f 1'

if [ "$SUM" != "$NEW" ]
then
	md5sum log | cut -d " " -f 1 > log
	echo "File modified" | mail -s "File_notification" root
fi

