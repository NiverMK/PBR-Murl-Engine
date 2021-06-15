#!/bin/bash

. ../../../scripts/set_env.sh

$MURL_ENGINE_ROOT/common/project/android/gnumake/make.sh $MURL_MODULE_ROOT/project/common/gnumake/project_pbr_project.mk $*
