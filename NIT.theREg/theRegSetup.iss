; -- theRegSetup.iss --
;
; This script Create Installator and deinstallator of the
; NIT theREg Admin Packages

[Setup]
AppName=NIT theReg Exclusions Setup
AppVersion=1.0.0.0
AllowRootDirectory=yes
AllowCancelDuringInstall=yes
ArchitecturesAllowed=x64os
Compression=lzma2/max
DefaultDirName=c:\pub1\Util\NIT.theReg
;MinVersion=0,10.0
MinVersion=0,6.1sp1
SetupLogging=yes
UsePreviousAppDir=yes
DisableStartupPrompt=yes
Output=yes
OutputDir=.\Output
OutputBaseFilename=theRegSetup
AllowNoIcons=True
AppPublisher=New Internet Technologies Inc.
RestartApplications=False
UserInfoPage=True
VersionInfoVersion=1.0.0.0
VersionInfoCompany=New Internet Technologies Inc.
VersionInfoTextVersion=Version 1.0.0.0
VersionInfoProductName=theRegSetup
VersionInfoProductVersion=1.0.0.0
AppPublisherURL=http://file.netip4.ru/
SolidCompression=True
LicenseFile=.\LICENSE.md

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

[Registry]

[UninstallRun]
Filename: "{app}\theReg.Delete.All.bat"; Flags: skipifdoesntexist runhidden

[Run]
Filename: "{app}\nit.Init.Run.bat"; WorkingDir: "{app}"; Flags: postinstall runhidden
