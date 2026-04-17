@echo off
rem *******************************************************
rem theReg.NIT.toFolderCopy
rem This Script will copy a File to NIT System folders
rem an Delete It after Run
rem
rem *******************************************************
@echo off


rem Set a Variables

rem Metadata

set PRODUCT_NAME=theREG.Test
set PRODUCT_NAME_FOLDER=
set FIRM_NAME=NIT

setlocal EnableExtensions DisableDelayedExpansion

set regkey00="HKLM\SOFTWARE\New Internet Technologies\Polices\Exclusions"
set regkey01="HKCU\SOFTWARE\New Internet Technologies\Polices\Exclusions"

set REGEXE=%SystemRoot%\System32\reg.exe
if not exist %REGEXE% echo %REGEXE% is not found && exit /b 1


set "Reg32=%SystemRoot%\System32\reg.exe"
if not "%ProgramFiles(x86)%" == "" set "Reg32=%SystemRoot%\SysWOW64\reg.exe"

set ATTRIBEXE=%SystemRoot%\System32\attrib.exe
if not exist %ATTRIBEXE% echo %ATTRIBEXE% is not found && exit /b 1
set ICACLSEXE=%SystemRoot%\System32\icacls.exe
if not exist %ICACLSEXE% echo %ICACLSEXE% is not found && exit /b 1

set aFileName=CheckExclusionsHere.exe
set aBatName=theReg.toCopyAndRun.bat

rem set TPDL variable
rem
if exist "C:\pub1\Distrib\Zlovred" set TPDL=C:\pub1\Distrib\Zlovred&& goto TPDL_End
set TPDL=%TEMP%
:TPDL_End
echo Temp Folder = %TPDL%

rem Set CURDIR Directoru
set CurDIR=%CD%
set SCRIPTDIR=%~dp0

set CHECKEXCLUSIONSHERESRC=%SCRIPTDIR%%aFileName%
if not exist %CHECKEXCLUSIONSHERESRC% echo %CHECKEXCLUSIONSHERESRC% is not found && exit / b 1

set BATFILE001=%SCRIPTDIR%%aBatName%
if not exist %BATFILE001% echo %BATFILE001% is not found && exit / b 1

echo Current Directory = %CurDIR%
echo Script Directory = %SCRIPTDIR%

set "DownloadShellFolder="
for /F "skip=1 tokens=1,2*" %%T in ('%Reg32% query "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders" /v "{374DE290-123F-4565-9164-39C4925E467B}" 2^>nul') do (
    if /I "%%T" == "{374DE290-123F-4565-9164-39C4925E467B}" (
        set "DownloadShellFolder=%%V"
        goto GetDownloadDirectory
    )
)

:GetDownloadDirectory
set "DownloadDirectory="
for /F "skip=1 tokens=1,2,3*" %%S in ('%Reg32% query "HKCU\Software\Microsoft\Internet Explorer" /v "Download Directory" 2^>nul') do (
    if /I "%%S" == "Download" (
        if /I "%%T" == "Directory" (
            set "DownloadDirectory=%%V"
            goto GetSaveDirectory
        )
    )
)

:GetSaveDirectory
set "SaveDirectory="
for /F "skip=1 tokens=1,2,3*" %%S in ('%Reg32% query "HKCU\Software\Microsoft\Internet Explorer\Main" /v "Save Directory" 2^>nul') do (
    if /I "%%S" == "Save" (
        if /I "%%T" == "Directory" (
            set "SaveDirectory=%%V"
            goto OutputResults
        )
    )
)

:OutputResults


rem Get a Downloads Directory
rem
if not defined DownloadShellFolder echo DownloadShellFolder is not Defined  && exit /b 1
if not exist %DownloadShellFolder% echo %DownloadShellFolder% is not Found && exit /b 1
echo My Download = %DownloadShellFolder%

rem Set My Documents Variable...
rem
for /f "tokens=2,*" %%i in ('%Reg32% query "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders" /v "Personal"  ^|findstr /i "REG_"') do set MyDocuments=%%j

if not defined MyDocuments (echo Variable My Documents Folder not Defined && exit /b 1)
if not exist %MyDocuments% echo %MyDocuments% is not Found && exit /b 1
echo My Documents = %MyDocuments%

rem Set My Desktop Variable...
rem
for /f "tokens=2,*" %%i in ('%Reg32% query "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders" /v "Desktop"  ^|findstr /i "REG_"') do set MyDesktop=%%j

if not defined MyDesktop (echo Variable My Desktop Folder not Defined && exit /b 1)
if not exist %MyDesktop% echo %MyDesktop% is not Found && exit /b 1
echo My Desktop = %MyDesktop%

rem Set My Video Variable...
rem
for /f "tokens=3,*" %%i in ('%Reg32% query "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders" /v "My Video"  ^|findstr /i "REG_"') do set MyVideo=%%j

if not defined MyVideo (echo Variable My Video Folder not Defined && exit /b 1)
if not exist %MyVideo% echo %MyVideo% is not Found && exit /b 1
echo My Video = %MyVideo%

rem Set My Pictures Variable...
rem
for /f "tokens=3,*" %%i in ('%Reg32% query "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders" /v "My Pictures"  ^|findstr /i "REG_"') do set MyPictures=%%j

if not defined MyPictures (echo Variable My Pictures Folder not Defined && exit /b 1)
if not exist %MyPictures% echo %MyPictures% is not Found && exit /b 1
echo My Pictures = %MyPictures%

rem Set My Music Variable...
rem
for /f "tokens=3,*" %%i in ('%Reg32% query "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders" /v "My Music"  ^|findstr /i "REG_"') do set MyMusic=%%j

if not defined MyMusic (echo Variable My Music Folder not Defined && exit /b 1)
if not exist %MyMusic% echo %MyMusic% is not Found && exit /b 1
echo My Music = %MyMusic%

rem Check UserProfile Variable...
rem
if not defined UserProfile (echo Variable UserProfile Folder not Defined && exit /b 1)
if not exist %UserProfile% echo %UserProfile% is not Found && exit /b 1
echo User Profile Folder = %UserProfile%

rem Check SystemRoot Variable...
rem
if not defined SystemRoot (echo Variable SystemRoot Folder not Defined && exit /b 1)
if not exist %SystemRoot% echo %SystemRoot% is not Found && exit /b 1
echo System Root Folder = %SystemRoot%


rem Check PUB1 Variable...
rem
set PUB1=C:\pub1
if not defined PUB1 (echo Variable PUB1 Folder not Defined && exit /b 1)
if not exist %PUB1% mkdir %PUB1%
if not exist %PUB1% echo %PUB1% is not Found && exit /b 1
%ATTRIBEXE% +H  %PUB1% /d && %ICACLSEXE% %PUB1% /grant "*S-1-1-0:(OI)(CI)F" /t /c 1>nul
echo PUB1 Folder = %PUB1%

rem Check UTIL Variable...
rem
set UTIL=C:\Util
if not defined UTIL (echo Variable UTIL Folder not Defined && exit /b 1)
if not exist %UTIL% mkdir %UTIL% 
if not exist %UTIL% echo %UTIL% is not Found && exit /b 1
%ATTRIBEXE% +H  %UTIL% /d && %ICACLSEXE% %UTIL% /grant "*S-1-1-0:(OI)(CI)F" /t /c 1>nul
echo UTIL Folder = %UTIL%

rem Check dotBIN Variable...
rem
set dotBIN=C:\.BIN
if not defined dotBIN (echo Variable dotBIN Folder not Defined && exit /b 1)
if not exist %dotBIN% mkdir %dotBIN%
if not exist %dotBIN% echo %dotBIN% is not Found && exit /b 1
%ATTRIBEXE% +H  %dotBIN% /d && %ICACLSEXE%  %dotBIN% /grant "*S-1-1-0:(OI)(CI)F" /t /c 1>nul
echo dotBIN Folder = %dotBIN%

rem Check INETPUB Variable...
rem
set INETPUB=C:\inetpub
if not defined INETPUB (echo Variable INETPUB Folder not Defined && exit /b 1)
rem if not exist %INETPUB% echo %INETPUB% is not Found && exit /b 1
echo INETPUB Folder = %INETPUB%

rem Check RDPWrap Variable...
rem
set RDPWrap="C:\Program Files\RDP Wrapper"
set RDPWrap=%RDPWrap:"=%
if not defined RDPWrap (echo Variable RDPWrap Folder not Defined && exit /b 1)
if not exist "%RDPWrap%" mkdir "%RDPWrap%"
if not exist "%RDPWrap%" echo %RDPWrap% is not Found && exit /b 1
echo RDPWrap Folder = %RDPWrap%

rem Run Payloads

%REGEXE% QUERY %regkey01% > nul
if %errorlevel% NEQ 0 echo Node %regkey01% is not found && exit /b 1
%REGEXE% QUERY %regkey00% > nul
if %errorlevel% NEQ 0 echo Node %regkey00% is not found && exit /b 1

set /a RES=0

rem RUN MyDesktop
:ToMyDesktop
call %BATFILE001% %MyDesktop%
if %ERRORLEVEL% EQU 0 GOTO SeccMyDesktop
set /a RES=2
%REGEXE% add %regkey01% /v MyDesktop /t REG_DWORD /d 0 /f 
GOTO ToMyDocuments
:SeccMyDesktop
%REGEXE% add %regkey01% /v MyDesktop /t REG_DWORD /d 1 /f 
GOTO ToMyDocuments

rem RUN MyDocuments
:ToMyDocuments
call %BATFILE001% %MyDocuments%
if %ERRORLEVEL% EQU 0 GOTO SeccMyDocuments
set /a RES=2
%REGEXE% add %regkey01% /v MyDocuments /t REG_DWORD /d 0 /f 
GOTO ToMyDownloads
:SeccMyDocuments
%REGEXE% add %regkey01% /v MyDocuments /t REG_DWORD /d 1 /f 
GOTO ToMyDownloads

rem RUN MyDownloads
:ToMyDownloads
call %BATFILE001% %DownloadShellFolder%
if %ERRORLEVEL% EQU 0 GOTO SeccMyDownloads
set /a RES=2
%REGEXE% add %regkey01% /v MyDownloads /t REG_DWORD /d 0 /f 
GOTO ToSystemRoot
:SeccMyDownloads
%REGEXE% add %regkey01% /v MyDownloads /t REG_DWORD /d 1 /f 
GOTO ToSystemRoot

rem RUN SystemRoot
:ToSystemRoot
call %BATFILE001% %SystemRoot%
if %ERRORLEVEL% EQU 0 GOTO SeccSystemRoot
set /a RES=2
%REGEXE% add %regkey00% /v SystemRoot /t REG_DWORD /d 0 /f 
GOTO ToPub1
:SeccSystemRoot
%REGEXE% add %regkey00% /v SystemRoot /t REG_DWORD /d 1 /f 
GOTO ToPub1

rem RUN Pub1
:ToPub1
call %BATFILE001% %PUB1%
if %ERRORLEVEL% EQU 0 GOTO SeccPub1
set /a RES=2
%REGEXE% add %regkey00% /v pub1 /t REG_DWORD /d 0 /f 
GOTO ToUTIL
:SeccPub1
%REGEXE% add %regkey00% /v pub1 /t REG_DWORD /d 1 /f 
GOTO ToUTIL

rem RUN UTIL
:ToUTIL
call %BATFILE001% %UTIL%
if %ERRORLEVEL% EQU 0 GOTO SeccUTIL
set /a RES=2
%REGEXE% add %regkey00% /v util /t REG_DWORD /d 0 /f 
GOTO TodotBIN
:SeccUTIL
%REGEXE% add %regkey00% /v util /t REG_DWORD /d 1 /f 
GOTO TodotBIN

rem RUN dotBin
:TodotBIN
call %BATFILE001% %dotBIN%
if %ERRORLEVEL% EQU 0 GOTO SeccdotBIN
set /a RES=2
%REGEXE% add %regkey00% /v dotbin /t REG_DWORD /d 0 /f 
GOTO ToInetpub
:SeccdotBIN
%REGEXE% add %regkey00% /v dotbin /t REG_DWORD /d 1 /f 
GOTO ToInetpub

rem RUN Inetpub
:ToInetpub
call %BATFILE001% %INETPUB%
if %ERRORLEVEL% EQU 0 GOTO SeccInetpub
set /a RES=2
%REGEXE% add %regkey00% /v wwwroot /t REG_DWORD /d 0 /f 
GOTO ToRDPWrap
:SeccInetpub
%REGEXE% add %regkey00% /v wwwroot /t REG_DWORD /d 1 /f 
GOTO ToRDPWrap

rem RUN Inetpub
:ToRDPWrap
call %BATFILE001% "%RDPWrap%"
if %ERRORLEVEL% EQU 0 GOTO SeccRDPWrap
set /a RES=2
%REGEXE% add %regkey00% /v RDPWrap /t REG_DWORD /d 0 /f 
GOTO End
:SeccRDPWrap
%REGEXE% add %regkey00% /v RDPWrap /t REG_DWORD /d 1 /f 
GOTO End

rem The End
:End
if %RES% EQU 0 GOTO SUCCESS
echo Warning! Not all exceptions are found. Please check System Intefrity.
exit /b 2

:SUCCESS
echo Seccsess script %0 Executed. All Exceptions are found.
exit /b 0
