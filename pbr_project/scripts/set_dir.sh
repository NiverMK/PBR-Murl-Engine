#!/bin/bash 

if [ ! -n "$(eval echo \$$1)" ] ; then
	DIR="$(dirname "${BASH_SOURCE[0]}")/$2"
	if [ -d $DIR ]; then
		export $1=$(cd $DIR && pwd)
	else
	    echo "***ERROR***: Cannot set $1, directory $DIR does not exist."
	    echo "Try to manually set variable $1 to a valid path."
	    exit 1
	fi
fi

