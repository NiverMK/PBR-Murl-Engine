#!/bin/bash

. ../../../scripts/set_env.sh

$MURL_ENGINE_ROOT/common/project/linux/gnumake/generic/make.sh $MURL_MODULE_ROOT/project/common/gnumake/project_pbr_project.mk $*
