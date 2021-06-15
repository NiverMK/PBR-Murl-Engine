#!/bin/bash
# Copyright 2015 Spraylight GmbH

. ./set_env.sh

generate_atlas()
{
    if [ $1 ]
    then
        echo "Generating Atlas" $1
        if [ $2 ]
        then
            $MURL_ATLAS_GENERATOR --config $1.xml --attribute $2 -q
        else
            $MURL_ATLAS_GENERATOR --config $1.xml -q
        fi
        return 0
    else
        echo "script parameter missing"
    fi
}

generate_atlas atlas_config

echo "Done."
