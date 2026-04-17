@echo off
rem *******************************************************
rem nit.INit.Run.bat
rem This Function will check the Integrity and Run payloads
rem The Script must be run with Elevated privileges
rem
rem *******************************************************
@echo off

rem Set Variables

rem Set Files

set REGEXE=%SystemRoot%\System32\reg.exe
set CHKADMINEXE=%~dp0chkadmin.exe
set CHECKEXCLUSIONSHEREEXE=%~dp0CheckExclusionsHere.exe
set FINDEXE=%SystemRoot%\system32\find.exe
set CSCRIPTEXE=%SystemRoot%\system32\cscript.exe
set WSCRIPTEXE=%SystemRoot%\system32\wscript.exe

set BATFILE001=%~dp0theReg.NIT.Check.VC14.Install.bat
set BATFILE002=%~dp0theReg.NIT.Init.All.bat
set BATFILE003=%~dp0theReg.Delete.All.bat
set BATFILE004=%~dp0theReg.toCopyAndRun.bat
set BATFILE005=%~dp0theReg.NIT.toFolderCopy.bat
set ErrorMessageWSF000=%~dp0ErrorMessage.wsf

rem Check Integrity

if not exist %REGEXE% echo %REGEXE% is not found && exit /b 1
if not exist %FINDEXE% echo %FINDEXE% is not found && exit /b 1
if not exist %CSCRIPTEXE% echo %CSCRIPTEXE% is not found && exit /b 1
if not exist %WSCRIPTEXE% echo %WSCRIPTEXE% is not found && exit /b 1
if not exist %BATFILE001% echo %BATFILE001% is not found && exit /b 1
if not exist %BATFILE002% echo %BATFILE002% is not found && exit /b 1
if not exist %BATFILE003% echo %BATFILE003% is not found && exit /b 1
if not exist %BATFILE004% echo %BATFILE004% is not found && exit /b 1
if not exist %BATFILE005% echo %BATFILE005% is not found && exit /b 1
if not exist %ErrorMessageWSF000% echo %ErrorMessageWSF000% is not found && exit /b 1
if not exist %CHKADMINEXE% echo %CHKADMINEXE% is not found && exit /b 1
if not exist %CHECKEXCLUSIONSHEREEXE% echo %CHECKEXCLUSIONSHEREEXE% is not found && exit /b 1
%CHKADMINEXE%
if %errorlevel% NEQ 0 echo Script %0 must be run with elevated privileges && exit /b 17

rem Check OS Bits
%REGEXE% Query "HKLM\Hardware\Description\System\CentralProcessor\0" | %FINDEXE% /i "x86" > NUL && set OSArch=x86 || set OSArch=amd64

if %OSArch%==x86 echo This is a 32bit operating system
if %OSArch%==amd64 echo This is a 64bit operating system

if not %OSArch%==amd64 echo Windows Architecture is not an amd64 && exit /b 2

rem Run Payloads

call %BATFILE001%
if %errorlevel% NEQ 0 echo Error VC++ Check && exin /b 2

call %BATFILE002%
if %errorlevel% NEQ 0 echo Can't Create registry keys && exit /b 2

call %BATFILE005%
if %errorlevel% EQU 0 GOTO End
echo Error! Some Exclusions are not Cheched. Please Send exclusions on site.
%WSCRIPTEXE% //NoLogo %ErrorMessageWSF000%
exit /b 2

rem Exit
:END
echo The Script %0 is finished with Success. All Exclusions are Checked.
exit /b 0
