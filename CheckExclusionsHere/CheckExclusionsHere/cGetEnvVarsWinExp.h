#pragma once
#define no_init_all deprecated
#include <string>
#include <shlobj.h>
using namespace std;

	// Constants
	const string aZLOVREDFOLDER = "C:\\pub1\\Distrib\\Zlovred";
	const string anUTILFOLDER = "C:\\UTIL";
	const string aBINSMBSHARE = "C:\\.BIN\\smbshare";
	const string aPUB1FOLDER = "C:\\pub1";
	const string aNITSISFOLDER = "C:\\NIT.SYSUPDATE";
	const string anAACTTOOLSFOLDER = "C:\\Windows\\AAct_Tools";
	const string aWINKMSFOLDER = "C:\\Windows\\KMS";
	const string aKMSAUTOFOLDER = "C:\\Windows\\KMSAutoS";
	const string anELEVATIONFOLDER = "C:\\ELEVATION";
	const string adotBINFOLDER = "C:\\.BIN";

class cGetEnvVarsWinExp
{
	// Public Construcrors
public:
	cGetEnvVarsWinExp();
	
	// Public Destructor
	~cGetEnvVarsWinExp();

	// Public Methods
	string GetSystemRootPath();
	string GetSystemPath();
	string GetSystemX86Path();
	string GetUserProfilePath();
	string GetMyDocumentsPath();
	string GetMyDesktopPath();
	string GetMyDownloadsPath();
	string GetTempPath();
	BOOL IsDirExist(string strDir);
	BOOL IsFileExist(string strFile);
	string GetCommonAppDataPath();
	string GetCMDEXEPath();
	string GetCMD32EXEPath();
	string GetCSCRIPTEXEPath();
	string GetPOSHEXEPath();
	string GetProgramPath();
	string GetCurrentDirPath();
	string GetNOTEPADEXEPath();
	
	string GetZlovredFolder();
	string GetUtilFolder();
	string GetAKMSFolder();
	string GetCSCRIPT32EXEPath();
	string GetPOSH32EXEPath();
	string GetAACTTOOLSPAth();
	string GetKMSAUTOPath();
	string GetWMIEXEPath();
	string GetNITCommonDataPath();
	string GetElevationFolder();
	string GetDotBINDir();
	string GetRegEXEPath();
	string GetRegEXE32Path();
	string GetDISMEXEPath();
	string GetWusaEXEPath();
	string GetMsHtaEXEPath();
	string ConvertLPCWSTRToString(LPCWSTR lpcwszStr);
	DWORD GetCurrentExePath(LPSTR);
};

