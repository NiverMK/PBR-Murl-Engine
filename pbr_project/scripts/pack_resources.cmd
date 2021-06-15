@echo off

setlocal enableextensions enabledelayedexpansion
rem switch to script directory is necessary if called as Pre-Build Event!
cd "%~dp0"
call set_env.cmd

%MURL_RESOURCE_PACKER% -ip ..\data\packages\main.murlres -op ..\data\packages\main.murlpkg

endlocal
