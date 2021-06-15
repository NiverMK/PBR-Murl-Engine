@echo off
set MURL_ENGINE_ROOT=../../../../../../murl
set MURL_MODULE_ROOT=../../..

call "%MURL_ENGINE_ROOT%/common/project/emscripten/gnumake/make.cmd" "%MURL_MODULE_ROOT%/project/common/gnumake/project_pbr_project.mk" %*
