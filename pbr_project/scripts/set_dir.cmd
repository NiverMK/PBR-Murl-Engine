@echo off

if "!%1!"=="" (
	set DIR=%~dp0/%2
	if exist "!DIR!" (
		pushd "!DIR!"
		set %1=!CD!
		popd
	) else (
	    echo ***ERROR***: Cannot set %1, directory !DIR! does not exist.
	    echo Try to manually set variable $1 to a valid path.
	    exit /B 1
	)
)
