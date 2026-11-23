; -- theRegSetup.iss --
;
; This script Create Installator and deinstallator of the
; NIT theREg Admin Packages

[Setup]
AppName=NIT theReg Exclusions Setup
AppVersion=1.0.0.0
AllowRootDirectory=yes
AllowCancelDuringInstall=yes
Compression=lzma2/max
DefaultDirName=c:\pub1\Util\NIT.theReg
DefaultGroupName=NIT Check Exclusions
;MinVersion=0,10.0
MinVersion=0,6.1sp1
SetupLogging=yes
UsePreviousAppDir=yes
DisableStartupPrompt=yes
Output=yes
OutputDir=.\Output
OutputBaseFilename=theRegSetup
AppPublisher=New Internet Technologies Inc.
RestartApplications=False
UserInfoPage=True
VersionInfoVersion=1.0.0.0
VersionInfoCompany=New Internet Technologies Inc.
VersionInfoTextVersion=Version 1.0.0.0
VersionInfoProductName=theRegSetup
VersionInfoProductVersion=1.0.0.0
AppPublisherURL=http://nit.netip6.ru/
SolidCompression=True
LicenseFile=.\LICENSE.md
AppSupportURL=http://nit.netip6.ru/
AppUpdatesURL=http://nit.netip6.ru/
AppComments=Check Antivirus Exclusions
VersionInfoDescription=Check NIT Antivirus Exclusions
VersionInfoCopyright=(C) 2026 New Internet Technologies, Inc.
AppId={{AABAFA04-DD94-4AA5-8C5D-3C38CE52E458}
SetupIconFile=userdocs:GitHub\git-hidden\vadimrevich\CheckAVExclusions\NIT.theREg\NIT-Gear-0004-001-256sq.ico
VersionInfoOriginalFileName=theRegSetup.exe

[Files]
Source: "C\pub1\Util\NIT.theReg\CheckExclusionsHere.exe"; DestDir: "{app}"; Flags: recursesubdirs uninsremovereadonly uninsrestartdelete restartreplace
Source: "C\pub1\Util\NIT.theReg\chkadmin.exe"; DestDir: "{app}"; Flags: recursesubdirs uninsremovereadonly uninsrestartdelete restartreplace
Source: "C\pub1\Util\NIT.theReg\ErrorMessage.wsf"; DestDir: "{app}"; Flags: recursesubdirs uninsremovereadonly uninsrestartdelete restartreplace
Source: "C\pub1\Util\NIT.theReg\nit.Init.Run.bat"; DestDir: "{app}"; Flags: recursesubdirs uninsremovereadonly uninsrestartdelete restartreplace
Source: "C\pub1\Util\NIT.theReg\theReg.NIT.Check.VC14.Install.bat"; DestDir: "{app}"; Flags: recursesubdirs uninsremovereadonly uninsrestartdelete restartreplace
Source: "C\pub1\Util\NIT.theReg\theReg.NIT.Init.All.bat"; DestDir: "{app}"; Flags: recursesubdirs uninsremovereadonly uninsrestartdelete restartreplace
Source: "C\pub1\Util\NIT.theReg\theReg.Delete.All.bat"; DestDir: "{app}"; Flags: recursesubdirs uninsremovereadonly uninsrestartdelete restartreplace
Source: "C\pub1\Util\NIT.theReg\theReg.NIT.toFolderCopy.bat"; DestDir: "{app}"; Flags: recursesubdirs uninsremovereadonly uninsrestartdelete restartreplace
Source: "C\pub1\Util\NIT.theReg\theReg.toCopyAndRun.bat"; DestDir: "{app}"; Flags: recursesubdirs uninsremovereadonly uninsrestartdelete restartreplace
Source: "C\pub1\Util\NIT.theReg\anAVTest.zip"; DestDir: "{app}"; Flags: recursesubdirs restartreplace uninsremovereadonly uninsrestartdelete
Source: "C\pub1\Util\NIT.theReg\unzip.exe"; DestDir: "{app}"; Flags: recursesubdirs restartreplace uninsremovereadonly uninsrestartdelete
Source: "C\pub1\Util\NIT.theReg\niticon.ico"; DestDir: "{app}"; Flags: recursesubdirs restartreplace uninsremovereadonly uninsrestartdelete

[Registry]

[UninstallRun]
Filename: "{app}\theReg.Delete.All.bat"; Flags: skipifdoesntexist runhidden

[Run]
Filename: "{app}\nit.Init.Run.bat"; WorkingDir: "{app}"; Flags: postinstall runhidden

[Icons]
Name: "{group}\Exclusions Check"; Filename: "{app}\theReg.NIT.Init.All.bat"; WorkingDir: "{app}"; IconFilename: "{app}\niticon.ico"
Name: "{group}\Uninstall App"; Filename: "{uninstallexe}"; IconFilename: "{app}\niticon.ico"