@echo off
rem *******************************************************
rem theReg.Delete.All.bat
rem This Function will delete all Nodes of
rem the New Internet Technologies Project
rem The Script must be run with Elevated privileges
rem
rem *******************************************************
@echo off

rem Set Variables

set regkey00="HKLM\SOFTWARE\New Internet Technologies\Polices\Exclusions"
set regkey01="HKCU\SOFTWARE\New Internet Technologies\Polices\Exclusions"

set REGEXE=%SystemRoot%\System32\reg.exe
set CHKADMINEXE=%~dp0chkadmin.exe

rem Check Integrity

if not exist %REGEXE% echo %REGEXE% is not found && exit /b 1
if not exist %CHKADMINEXE% echo %CHKADMINEXE% is not found && exit /b 1
%CHKADMINEXE%
if %errorlevel% NEQ 0 echo Script %0 must be run with elevated privileges && exit /b 17

rem Run Payloads

rem delete HKLM
%REGEXE% delete %regkey00% /F
%REGEXE% delete "HKLM\SOFTWARE\New Internet Technologies\Polices" /F
%REGEXE% delete "HKLM\SOFTWARE\New Internet Technologies" /F

rem delete HKCU
%REGEXE% delete %regkey01% /F
%REGEXE% delete "HKCU\SOFTWARE\New Internet Technologies\Polices" /F
%REGEXE% delete "HKCU\SOFTWARE\New Internet Technologies" /F

rem Exit
echo The Script %0 is finished with Success
exit /b 0
