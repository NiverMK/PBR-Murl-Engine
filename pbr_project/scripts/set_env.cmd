@echo off

call "%~dp0/set_dir.cmd" MURL_ENGINE_ROOT ../../../../murl
call "%~dp0/set_dir.cmd" MURL_MODULE_ROOT ..

call "%MURL_ENGINE_ROOT%/common/scripts/set_env.cmd"
