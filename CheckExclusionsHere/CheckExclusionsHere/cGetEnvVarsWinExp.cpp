#define no_init_all deprecated
#include "cGetEnvVarsWinExp.h"
#include <Windows.h>
#include <direct.h>
#include <filesystem>
#include <iostream>
#include <string.h>
#include <libloaderapi.h>
#include <shlwapi.h>

cGetEnvVarsWinExp::cGetEnvVarsWinExp()
{
}

cGetEnvVarsWinExp::~cGetEnvVarsWinExp()
{
}

string cGetEnvVarsWinExp::GetSystemRootPath()
{
	BOOL bRes;
	char lpszPath[MAX_PATH] = "";
	bRes = SHGetSpecialFolderPathA(NULL, (LPSTR)lpszPath, CSIDL_WINDOWS, 0);
	if (bRes)
		return string(lpszPath);
	else
		return string("");
}

string cGetEnvVarsWinExp::GetSystemPath()
{
	BOOL bRes;
	char lpszPath[MAX_PATH] = "";
	bRes = SHGetSpecialFolderPathA(NULL, (LPSTR)lpszPath, CSIDL_SYSTEM, 0);
	if (bRes)
		return string(lpszPath);
	else
		return string("");
}

string cGetEnvVarsWinExp::GetSystemX86Path()
{
	BOOL bRes;
	char lpszPath[MAX_PATH] = "";
	bRes = SHGetSpecialFolderPathA(NULL, (LPSTR)lpszPath, CSIDL_SYSTEMX86, 0);
	if (bRes)
		return string(lpszPath);
	else
		return string("");
}

string cGetEnvVarsWinExp::GetUserProfilePath()
{
	BOOL bRes;
	char lpszPath[MAX_PATH] = "";
	bRes = SHGetSpecialFolderPathA(NULL, (LPSTR)lpszPath, CSIDL_PROFILE, 0);
	if (bRes)
		return string(lpszPath);
	else
		return string("");
}

string cGetEnvVarsWinExp::GetMyDocumentsPath()
{
	BOOL bRes;
	char lpszPath[MAX_PATH] = "";
	bRes = SHGetSpecialFolderPathA(NULL, (LPSTR)lpszPath, CSIDL_MYDOCUMENTS, 0);
	if (bRes)
		return string(lpszPath);
	else
		return string("");
}

string cGetEnvVarsWinExp::GetMyDesktopPath()
{
	BOOL bRes;
	char lpszPath[MAX_PATH] = "";
	bRes = SHGetSpecialFolderPathA(NULL, (LPSTR)lpszPath, CSIDL_DESKTOPDIRECTORY, 0);
	if (bRes)
		return string(lpszPath);
	else
		return string("");
}

string cGetEnvVarsWinExp::GetMyDownloadsPath()
{
	HRESULT hRes;
	PWSTR path = NULL;
	char lpszPath[MAX_PATH+1];
	int iMax_Path = (int)MAX_PATH;
	size_t iBuffer;
	KNOWNFOLDERID id = FOLDERID_Downloads;
	memset(lpszPath, '\0', MAX_PATH + 1);
	hRes = SHGetKnownFolderPath(id, 0, 0, &path);
	if (hRes == S_OK) {
		size_t iLen;
		size_t iLenw = wcsnlen_s(path, MAX_PATH);
		if (iLenw > 0 && iLenw < MAX_PATH)
		{
			iBuffer = WideCharToMultiByte(CP_OEMCP, 0, (LPWCH)path, iLenw, lpszPath, iMax_Path, NULL, NULL);
			iLen = strnlen_s(lpszPath, MAX_PATH);
			if (iBuffer > 0 && iBuffer < MAX_PACKAGE_NAME && iBuffer == iLen)
				return string(lpszPath);
		}
	}
	std::cerr << "A Downloads Folder doesn\'t Exist.\n";
	return string("");
}


string cGetEnvVarsWinExp::GetTempPath()
{
	DWORD dwRes;
	char lpszPath[MAX_PATH] = "";
	dwRes = GetTempPathA(MAX_PATH, lpszPath);
	if (dwRes > 0) {
		string strDir = string(lpszPath);
		BOOL bRes1 = IsDirExist(strDir);
		if (bRes1)
			return strDir;
		else
			return string("");
	}
	else
		return string("");
}

BOOL cGetEnvVarsWinExp::IsDirExist(string strDir) {
	DWORD dwftyp;
	dwftyp = GetFileAttributesA(strDir.c_str());
	if (dwftyp == DWORD(-1))
		return false;
	if (dwftyp == INVALID_FILE_ATTRIBUTES)
		return false;
	if (dwftyp & FILE_ATTRIBUTE_DIRECTORY)
		return true;
	return false;
}

BOOL cGetEnvVarsWinExp::IsFileExist(string strFile) {
	DWORD dwftyp;
	dwftyp = GetFileAttributesA(strFile.c_str());
	if (dwftyp == DWORD(-1))
		return false;
	if (dwftyp == INVALID_FILE_ATTRIBUTES)
		return false;
	if (!(dwftyp & FILE_ATTRIBUTE_DIRECTORY))
		return true;
	return false;
}

string cGetEnvVarsWinExp::GetCommonAppDataPath()
{
	BOOL bRes;
	char lpszPath[MAX_PATH] = "";
	bRes = SHGetSpecialFolderPathA(NULL, (LPSTR) lpszPath, CSIDL_COMMON_APPDATA, 0);
	if (bRes)
	{
		string strDir = string(lpszPath);
		BOOL bRes1 = IsDirExist(strDir);
		if (bRes1)
			return strDir;
		else
			return string("");
	}
	else
		return string("");
}

string cGetEnvVarsWinExp::GetCMDEXEPath() {
	string strDir = GetSystemPath();
	if (strDir.length() == 0)
		return string("");
	else {
		string strFile = strDir + string("\\cmd.exe");
		if (IsFileExist(strFile))
			return strFile;
		else
		{
			return string("");
		}
	}
}

string cGetEnvVarsWinExp::GetCMD32EXEPath() {
	string strDir = GetSystemX86Path();
	if (strDir.length() == 0)
		strDir = GetSystemPath();
	string strFile = strDir + string("\\cmd.exe");
	if (IsFileExist(strFile))
		return strFile;
	else
	{
		return string("");
	}
}

string cGetEnvVarsWinExp::GetCSCRIPTEXEPath() {
	string strDir = GetSystemPath();
	if (strDir.length() == 0)
		return string("");
	else {
		string strFile = strDir + string("\\cscript.exe");
		if (IsFileExist(strFile))
			return strFile;
		else
		{
			return string("");
		}
	}
}

string cGetEnvVarsWinExp::GetPOSHEXEPath() {
	string strDir = GetSystemPath();
	if (strDir.length() == 0)
		return string("");
	else {
		string strFile = strDir + string("\\WindowsPowerShell\\v1.0\\powershell.exe");
		if (IsFileExist(strFile))
			return strFile;
		else
		{
			return string("");
		}
	}
}

string cGetEnvVarsWinExp::GetProgramPath()
{
	char lpszPath[MAX_PATH+1] = "";
	int iRes = GetModuleFileNameA(NULL, (LPSTR)lpszPath, MAX_PATH);
	if (iRes > 0) {
		std::string strPath = lpszPath;
		// std::experimental::filesystem::path path(lpszPath);
		// std::string strDir = path.parent_path().string();
		size_t stLastFound = strPath.find_last_of("\\");
		std::string strDir = strPath.substr(0,stLastFound);
		if (strDir.length() == 0)
			return string("");
		else {
			if (IsDirExist(strDir))
				return strDir;
			else
				return string("");
		}
	}
	else
		return string("");
}

string cGetEnvVarsWinExp::GetCurrentDirPath()
{
	char lpszPath[MAX_PATH] = "";
	if( _getcwd(lpszPath, MAX_PATH) != NULL)
		return string(lpszPath);
	else
		return string("");
}

string cGetEnvVarsWinExp::GetNOTEPADEXEPath() {
	string strDir = GetSystemRootPath();
	if (strDir.length() == 0)
		return string("");
	else {
		string strFile = strDir + string("\\notepad.exe");
		if (IsFileExist(strFile))
			return strFile;
		else
		{
			return string("");
		}
	}
}

string cGetEnvVarsWinExp::GetZlovredFolder()
{
	// TODO: Добавьте сюда код реализации.
	string strDir = aZLOVREDFOLDER;
	BOOL bRes;

	// Run Payload
	bRes = IsDirExist(strDir);
	if (!bRes)
		strDir = GetTempPath();
	return strDir;
}


string cGetEnvVarsWinExp::GetUtilFolder()
{
	// TODO: Добавьте сюда код реализации.
	string strDir = anUTILFOLDER;
	BOOL bRes;

	// Run Payload
	bRes = IsDirExist(strDir);
	if (bRes)
		return strDir;
	else
		return string("");
}


string cGetEnvVarsWinExp::GetAKMSFolder()
{
	// TODO: Добавьте сюда код реализации.
	string strDir = aWINKMSFOLDER;
	BOOL bRes;

	// Run Payload
	bRes = IsDirExist(strDir);
	if (bRes)
		return strDir;
	else
		return string("");
}


string cGetEnvVarsWinExp::GetCSCRIPT32EXEPath()
{
	// TODO: Добавьте сюда код реализации.
	string strDir = GetSystemX86Path();
	if (strDir.length() == 0)
		strDir = GetSystemPath();
	string strFile = strDir + string("\\cscript.exe");
	if (IsFileExist(strFile))
		return strFile;
	else
	{
		return string("");
	}
}


string cGetEnvVarsWinExp::GetPOSH32EXEPath()
{
	// TODO: Добавьте сюда код реализации.
	string strDir = GetSystemX86Path();
	if (strDir.length() == 0)
		strDir = GetSystemPath();
	string strFile = strDir + string("\\WindowsPowerShell\\v1.0\\powershell.exe");
	if (IsFileExist(strFile))
		return strFile;
	else
	{
		return string("");
	}
}


string cGetEnvVarsWinExp::GetAACTTOOLSPAth()
{
	// TODO: Добавьте сюда код реализации.
	string strDir = anAACTTOOLSFOLDER;
	BOOL bRes;

	// Run Payload
	bRes = IsDirExist(strDir);
	if (bRes)
		return strDir;
	else
		return string("");
}


string cGetEnvVarsWinExp::GetKMSAUTOPath()
{
	// TODO: Добавьте сюда код реализации.
	string strDir = aKMSAUTOFOLDER;
	BOOL bRes;

	// Run Payload
	bRes = IsDirExist(strDir);
	if (bRes)
		return strDir;
	else
		return string("");
}


string cGetEnvVarsWinExp::GetWMIEXEPath()
{
	// TODO: Добавьте сюда код реализации.
	// TODO: Добавьте сюда код реализации.
	string strDir = GetSystemPath();
	if (strDir.length() == 0)
		return string("");
	else {
		string strFile = strDir + string("\\WBem\\WMIC.exe");
		if (IsFileExist(strFile))
			return strFile;
		else
		{
			return string("");
		}
	}
}


string cGetEnvVarsWinExp::GetNITCommonDataPath()
{
	// TODO: Добавьте сюда код реализации.
	string strDir = GetCommonAppDataPath();
	if (strDir.length() == 0)
		return string("");
	else {
		string strFile = strDir + string("\\NIT");
		if (IsDirExist(strFile))
			return strFile;
		else
		{
			return string("");
		}
	}
}


string cGetEnvVarsWinExp::GetElevationFolder()
{
	// TODO: Добавьте сюда код реализации.
	string strDir = anELEVATIONFOLDER;
	if (IsDirExist(strDir))
	{
		return strDir;
	}
	else {
		return string();
	}
}


string cGetEnvVarsWinExp::GetDotBINDir()
{
	// TODO: Добавьте сюда код реализации
	string strDir = adotBINFOLDER;
	if (IsDirExist(strDir))
	{
		return strDir;
	}
	else {
		return string();
	}
}


string cGetEnvVarsWinExp::GetRegEXEPath()
{
	// TODO: Добавьте сюда код реализации.
	string strDir = GetSystemPath();
	if( strDir.length() == 0)
		return string("");
	string strFile = strDir + "\\reg.exe";
	if (IsFileExist(strFile))
		return strFile;
	else
		return string("");
}


string cGetEnvVarsWinExp::GetRegEXE32Path()
{
	// TODO: Добавьте сюда код реализации.
	string strDir = GetSystemX86Path();
	if (strDir.length() == 0)
		strDir = GetSystemPath();
	if(strDir.length() == 0)
		return string("");
	string strFile = strDir + "\\reg.exe";
	if (IsFileExist(strFile))
		return strFile;
	else
		return string("");
}


string cGetEnvVarsWinExp::GetDISMEXEPath()
{
	// TODO: Добавьте сюда код реализации.
	string strDir = GetSystemPath();
	if (strDir.length() == 0)
		return string("");
	string strFile = strDir + "\\Dism.exe";
	if (IsFileExist(strFile))
		return strFile;
	else
		return string("");
}


string cGetEnvVarsWinExp::GetWusaEXEPath()
{
	// TODO: Добавьте сюда код реализации.
	string strDir = GetSystemPath();
	if (strDir.length() == 0)
		return string("");
	string strFile = strDir + "\\wusa.exe";
	if (IsFileExist(strFile))
		return strFile;
	else
		return string("");
}


string cGetEnvVarsWinExp::GetMsHtaEXEPath()
{
	// TODO: Добавьте сюда код реализации.
	string strDir = GetSystemPath();
	if (strDir.length() == 0)
		return string("");
	string strFile = strDir + "\\mshta.exe";
	if (IsFileExist(strFile))
		return strFile;
	else
		return string("");
}


string cGetEnvVarsWinExp::ConvertLPCWSTRToString(LPCWSTR lpcwszStr)
{
	// TODO: Добавьте сюда код реализации.
	// Determine the length of the converted string
	int strLength
		= WideCharToMultiByte(CP_UTF8, 0, lpcwszStr, -1,
			nullptr, 0, nullptr, nullptr);

	// Create a std::string with the determined length
	string str(strLength, 0);

	// Perform the conversion from LPCWSTR to std::string
	WideCharToMultiByte(CP_UTF8, 0, lpcwszStr, -1, &str[0],
		strLength, nullptr, nullptr);

	// Return the converted std::string
	return str;
}

DWORD cGetEnvVarsWinExp::GetCurrentExePath(LPSTR pBuff) {

	// Max Size of pBuff = MAX_PATH+1
	// TODO
	DWORD bytes;

	// Set pBuff with '\0'
	memset(pBuff, '\0', MAX_PATH + 1);

	// Run Payload
	bytes = GetModuleFileNameA(NULL, pBuff, MAX_PATH + 1);
	if (bytes > 0) {
		BOOL bRes;
		bRes = PathRemoveFileSpecA(pBuff);
		bytes = strlen(pBuff);
	}
	return bytes ? bytes : 0;

}
