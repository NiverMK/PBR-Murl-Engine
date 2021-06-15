#!/bin/bash
export MURL_ENGINE_ROOT=../../../../..
export MURL_MODULE_ROOT=../../../..

$MURL_ENGINE_ROOT/common/project/emscripten/gnumake/make.sh $MURL_MODULE_ROOT/project/common/gnumake/bsp_test_app/project_pbr_project.mk $*
