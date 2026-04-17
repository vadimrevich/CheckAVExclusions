@echo off
rem *******************************************************
rem theReg.NIT.Check.VC14.Install
rem This Function will will check if
rem VC++ Redustrubutible 14 is installed
rem The Script must be run with Elevated privileges
rem
rem *******************************************************
@echo off

rem Set Variables

set regkey00="HKLM\SOFTWARE\New Internet Technologies\Polices\Exclusions"
set regkey01="HKCU\SOFTWARE\New Internet Technologies\Polices\Exclusions"
set regVCNode00="HKLM\SOFTWARE\Microsoft\VisualStudio\14.0\VC\Runtimes\X64"
set regVCNode01="HKLM\SOFTWARE\WOW6432Node\Microsoft\VisualStudio\14.0\VC\Runtimes\X64"
set regVCNode02="HKLM\SOFTWARE\WOW6432Node\Microsoft\VisualStudio\14.0\VC\Runtimes\X86"

set REGEXE=%SystemRoot%\System32\reg.exe
set CHKADMINEXE=%~dp0chkadmin.exe
set FINDEXE=%SystemRoot%\system32\find.exe

rem Check Integrity

if not exist %REGEXE% echo %REGEXE% is not found && exit /b 1
if not exist %FINDEXE% echo %FINDEXE% is not found && exit /b 1
if not exist %CHKADMINEXE% echo %CHKADMINEXE% is not found && exit /b 1
%CHKADMINEXE%
rem if %errorlevel% NEQ 0 echo Script %0 must be run with elevated privileges && exit /b 17

rem Check OS Bits
%REGEXE% Query "HKLM\Hardware\Description\System\CentralProcessor\0" | %FINDEXE% /i "x86" > NUL && set OSArch=x86 || set OSArch=amd64

if %OSArch%==x86 echo This is a 32bit operating system
if %OSArch%==amd64 echo This is a 64bit operating system

if not %OSArch%==amd64 echo Windows Architecture is not an amd64 && exit /b 2

rem Run Payloads

%REGEXE% QUERY %regVCNode00% > NUL
if %errorlevel% NEQ 0 echo Microsoft VC++ 2015 Redistributable is not installed && exit /b 2

%REGEXE% QUERY %regVCNode01% > NUL
if %errorlevel% NEQ 0 echo Microsoft VC++ 2015 Redistributable is not installed && exit /b 2

%REGEXE% QUERY %regVCNode02% > NUL
if %errorlevel% NEQ 0 echo Microsoft VC++ 2015 Redistributable is not installed && exit /b 2

rem Exit
echo The Script %0 is finished with Success
exit /b 0
