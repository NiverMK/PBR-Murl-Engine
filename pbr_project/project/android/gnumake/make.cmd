@echo off

setlocal enableextensions enabledelayedexpansion

call "../../../scripts/set_env.cmd"

call "%MURL_ENGINE_ROOT%/common/project/android/gnumake/make.cmd" "%MURL_MODULE_ROOT%/project/common/gnumake/project_pbr_project.mk" %*

endlocal
