@echo off
rem *******************************************************
rem toZip.bat
rem This script will make the %ARCH% zip archive 
rem with password %PASS%
rem *******************************************************
@echo off

rem Set Variables

set ZIPEXE=c:\UTIL\zip.exe
set PASS=szbeck
set ARCH=anAVTest.zip

rem Check Integrity
if not exist %ZIPEXE% echo The file %ZIPEXE% is not found && exit /b 1
if exist %~dp0%ARCH% DEL /Q /F %~dp0%ARCH% 

rem unzip -P %PASS%

rem %ZIPEXE% -r %ARCH% ./
%ZIPEXE% -r -P %PASS% %ARCH% ./

