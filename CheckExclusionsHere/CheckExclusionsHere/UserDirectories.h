#pragma once
#include "cGetEnvVarsWinExp.h"
#include <sstream>

class UserDirectories :
	public cGetEnvVarsWinExp
{

public:
	// Constructors and Desctructor
	UserDirectories() 
	{
		cGetEnvVarsWinExp();
	}

	~UserDirectories() {

	}
	void MakeKMSDirs();
	void MakePubDirs();
	void MakeNITUtilDirs();
	BOOL IsWow64(HANDLE process);
	bool IsX86Process(HANDLE process);
	BOOL Is64Bit();
	string GetUserDocumentsPath();
	string GetUserDownloadPath();
	BOOL IsWindowsVistaOrGreater();
	string GetSystemAACtDir();
	string GetSystemKMSDir();
	string GetSystemKMSAutoSDir();
	string GetNITBinPath();
	string GetNITElevationPath();
	string GetNITSYSUPPath();
	string GetNITProgDataDir();
	string GetPubPath();
	string GetNITUtilPath();
	string GetNITPub1Path();
	string GetZlovredPath();
	string GetRServer30Path();
	string GetValidWindowsVersion();
	string CheckWindowsLangID();
	string CheckWindowsServer();
	string GetWindowsVersionString();
	string GetMSIEXECPath();
	string GetOSInfo();
	void Get_OSVersion_Normal_Test();
	string GetCurrentExePath();
protected:
	DWORD dwMajorOS;
	DWORD dwMinorOS;
	DWORD dwBuildOS;
	WORD wSuiteMask;
	BYTE ucProductType;
	string s_name;
	string s_edition;
	DWORD dwPlatformOS;
	WCHAR szCSDVersion[128];
	// 0 - Antivirus is Absent 1 - Windows Defender 2 - Kaspersky Lab 3 - Others
	DWORD dwAntivirusPresent;
private:
	void Set_OSVersion_Normal();
	void Set_OSVersion_Name();
	void Set_OSVersion_Edition();
	// 0 - Not Corresponded 1 - Partially 2 - Full
	DWORD dwnit_oscorresponded;
	void Set_OSVersion_Corresponded_NIT();
	// 0 - Corresponded -1 - Partially Corresponded -2 - Not Corresponded
	int NIT_CheckProffesionalEdition();
	void SetAntivirusStatus();
public:
	string GetAntivirusName();
	void Get_Antivirus_Normal_Test();
protected:
	// 0 - No 1 - Yes
	DWORD dwIsWindowsServer;
};

