setlocal EnableDelayedExpansion
@echo off
REM ***Adapt the following variables ********************************

set MURL_KEY_FILE=murl_release.keystore
set MURL_KEY_ALIAS=murl_key
set MURL_KEY_PWD=

REM ***Notice*** The following characters must be escaped if 
REM used as part of e.g. the password
REM
REM % escape with %%
REM ^ escape with ^^
REM & escape with ^&
REM < escape with ^<
REM > escape with ^>
REM | escape with ^|
REM ; escape with ^;
REM = escape with ^=
REM ( escape with ^(
REM ) escape with ^)
REM ! escape with ^^!
REM [ escape with \[
REM ] escape with \]
REM " escape with \"
REM
REM *****************************************************************

if "%MURL_KEY_PWD%"=="" (
echo *** Error *** No keystore password specified! 
echo Please specify a keystore password !
echo Set the environment variable MURL_KEY_PWD ^(edit the script and add the line "set MURL_KEY_PWD=myPassword"^).
exit /B 1
)

echo Starting keytool with: 
echo - Alias: %MURL_KEY_ALIAS%
echo - Password: %MURL_KEY_PWD%
echo.

REM keytool is part of the Java JRE / Java JDK. Ensure that your path variable has the java bin directory included.
keytool -genkey -v -keystore %MURL_KEY_FILE% -alias %MURL_KEY_ALIAS% -keyalg RSA -keysize 2048 -validity 10000 -storepass %MURL_KEY_PWD%
IF ERRORLEVEL 1 ( 
exit /B 1
) else (
echo.
echo Warning: Keep the keystore file you generated in a safe, secure place. 
echo You must use the same key to sign future versions of your application. 
echo If you republish your app with a new key, Google Play will consider it as a new app.
echo For further information visit http://developer.android.com/tools/publishing/app-signing.html
)
echo set MURL_KEY_FILE="%%~dp0%MURL_KEY_FILE%" > "%~dp0set_key_env.cmd"
echo set MURL_KEY_ALIAS=%MURL_KEY_ALIAS% >> "%~dp0set_key_env.cmd"
echo set MURL_KEY_PWD=%MURL_KEY_PWD% >> "%~dp0set_key_env.cmd"


REM Creating the shell script file with line feeds only (not with CR-LF) is a bit tricky!
REM see http://www.dostips.com/forum/viewtopic.php?f=3&t=4213
REM Creating a Newline variable (the two blank lines are required!)
set NL=^


set line1=#^^!/bin/bash
set line2=MURL_KEY_FILE="$(pwd)/%MURL_KEY_FILE%"
set line3=MURL_KEY_ALIAS=%MURL_KEY_ALIAS%
set line4=MURL_KEY_PWD=%MURL_KEY_PWD%

call :createSub
> txt.tmp (echo(!line1!!NL!!line2!!NL!!line3!!NL!!line4!!NL!!sub!)
copy txt.tmp /a "%~dp0set_key_env.sh" /b > nul
del txt.tmp
exit /b

:createSub
copy nul sub.tmp /a > nul
for /F %%a in (sub.tmp) DO (
   set "sub=%%a"
)
del sub.tmp
exit /b

