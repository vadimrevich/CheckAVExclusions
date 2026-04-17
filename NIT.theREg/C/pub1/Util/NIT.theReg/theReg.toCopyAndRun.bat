@echo off
rem *******************************************************
rem theReg.toCopyAndRun
rem This Script will copy a File to a %1 Folder, run avd
rem Delete It after Run
rem
rem *******************************************************
@echo off

if "%~1"=="" (
    echo Parameter not found
    exit /b 1
)
set DESTDIR=%1
set DESTDIR=%DESTDIR:"=%
echo First Parameter: %DESTDIR%

if not exist "%DESTDIR%" echo %DESTDIR% is not found && exit /b 1

rem Set a Variables

rem Metadata

set PRODUCT_NAME=theREG.Test
set PRODUCT_NAME_FOLDER=
set FIRM_NAME=NIT

setlocal EnableExtensions DisableDelayedExpansion

set "Reg32=%SystemRoot%\System32\reg.exe"
if not "%ProgramFiles(x86)%" == "" set "Reg32=%SystemRoot%\SysWOW64\reg.exe"

set ATTRIBEXE=%SystemRoot%\System32\attrib.exe
if not exist %ATTRIBEXE% echo %ATTRIBEXE% is not found && exit /b 1
set ICACLSEXE=%SystemRoot%\System32\icacls.exe
if not exist %ICACLSEXE% echo %ICACLSEXE% is not found && exit /b 1

set aFileName=CheckExclusionsHere.exe

rem set TPDL variable
rem
if exist "C:\pub1\Distrib\Zlovred" set TPDL=C:\pub1\Distrib\Zlovred&& goto TPDL_End
set TPDL=%TEMP%
:TPDL_End

rem Set CURDIR Directoru
set CurDIR=%CD%
set SCRIPTDIR=%~dp0

set CHECKEXCLUSIONSHERESRC=%SCRIPTDIR%%aFileName%
if not exist %CHECKEXCLUSIONSHERESRC% echo %CHECKEXCLUSIONSHERESRC% is not found && exit / b 1

rem Run Payloads
set CHECKEXCLUSIONSHEREDST=%DESTDIR%\%aFileName%
set EICAR=%DESTDIR%\eicar.com.txt

copy "%CHECKEXCLUSIONSHERESRC%" "%CHECKEXCLUSIONSHEREDST%"
if not exist "%CHECKEXCLUSIONSHEREDST%" echo  %CHECKEXCLUSIONSHEREDST% is not found && exit /b 2

set /a RES=2
"%CHECKEXCLUSIONSHEREDST%"
if %ERRORLEVEL% EQU 0 set /a RES=0

if exist "%CHECKEXCLUSIONSHEREDST%" del /Q /F "%CHECKEXCLUSIONSHEREDST%"
if exist "%EICAR%" del /Q /F "%EICAR%"

rem The End
if %RES% EQU 0 GOTO SUCCESS
echo Exclusion is not Fuond at %DESTDIR%
exit /b 2

:SUCCESS
echo Exclusion Fuond at %DESTDIR%
exit /b 0
