@echo off
rem *******************************************************
rem theReg.NIT.Init.All.bat
rem This Function will create some Nodes and parameters of
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

rem Create HKLM
%REGEXE% add "HKLM\SOFTWARE\New Internet Technologies" /F
%REGEXE% add "HKLM\SOFTWARE\New Internet Technologies\Polices" /F
%REGEXE% add %regkey00% /F

rem Create HKCU
%REGEXE% add "HKCU\SOFTWARE\New Internet Technologies" /F
%REGEXE% add "HKCU\SOFTWARE\New Internet Technologies\Polices" /F
%REGEXE% add %regkey01% /F

rem Set HKLM Keys
%REGEXE% QUERY %regkey00%
if %errorlevel% NEQ 0 echo Node %regkey00% is not found && exit /b 1
%REGEXE% add %regkey00% /v SystemRoot /t REG_DWORD /d 0 /f 
rem %REGEXE% add %regkey00% /v pub1 /t REG_DWORD /d 0 /f 
rem %REGEXE% add %regkey00% /v util /t REG_DWORD /d 0 /f 
rem %REGEXE% add %regkey00% /v dotbin /t REG_DWORD /d 0 /f 
%REGEXE% add %regkey00% /v wwwroot /t REG_DWORD /d 0 /f 

rem Set HKCU Keys
%REGEXE% QUERY %regkey01%
if %errorlevel% NEQ 0 echo Node %regkey01% is not found && exit /b 1
%REGEXE% add %regkey01% /v MyDocuments /t REG_DWORD /d 0 /f 
%REGEXE% add %regkey01% /v MyDownloads /t REG_DWORD /d 0 /f 
%REGEXE% add %regkey01% /v MyDesktop /t REG_DWORD /d 0 /f 

rem Exit
echo The Script %0 is finished with Success
exit /b 0
