#!/bin/bash
# Copyright 2015 Spraylight GmbH

. ./set_env.sh

make_package()
{
    if [ $1 ]
    then
        echo "Packing Resources" $1
        $MURL_RESOURCE_PACKER --input_package $1.murlres --output_package $1.murlpkg
        return 0
    else
        echo "parameter missing"
    fi
}

pushd ../data/packages
make_package main
cp $MURL_ENGINE_ROOT/common/data/packages/startup.murlpkg .
popd

echo "Done."
