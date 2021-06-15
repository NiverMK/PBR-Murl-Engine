@echo off

setlocal enableextensions enabledelayedexpansion

call "./set_env.cmd"

%MURL_ATLAS_GENERATOR% -q --config atlas_config.xml

endlocal
