#pragma warning(disable : 4996)
#define no_init_all deprecated
#include "UserDirectories.h"
#include <Windows.h>
#include <iostream>
// #include <processthreadsapi.h>
// #include <versionhelpers.h>
#include <WinNls.h>
#include <sstream>
#include <winnt.h>
// #include <wow64apiset.h>
#include <tchar.h>
#include <string>
#include <atlbase.h>
#include <WbemIdl.h>
#pragma comment(lib, "wbemuuid.lib")// Link to WMI library. (Can do in library includes instead)
#include <comutil.h>
#pragma comment(lib, "comsuppw.lib")

using namespace std;

void UserDirectories::MakeKMSDirs() {
	string strDir;
	BOOL bRes;
	strDir = GetSystemRootPath();
	if (strDir.length() > 0) {
		strDir = GetSystemRootPath() + string("\\AAct_Tools");
		if (!IsDirExist(strDir)) {
			bRes = CreateDirectoryA(strDir.c_str(), NULL);
			if (!bRes)
				std::cerr << "Can\'t Create a directory: " << strDir << "\n";
		}
		else
			std::cerr << "A Directory " << strDir << " is already Exist.\n";
		strDir = GetSystemRootPath() + string("\\AAct_Tools\\AAct_files");
		if (!IsDirExist(strDir)) {
			bRes = CreateDirectoryA(strDir.c_str(), NULL);
			if (!bRes)
				std::cerr << "Can\'t Create a directory: " << strDir << "\n";
		}
		else
			std::cerr << "A Directory " << strDir << " is already Exist.\n";
		strDir = GetSystemRootPath() + string("\\KMS");
		if (!IsDirExist(strDir)) {
			bRes = CreateDirectoryA(strDir.c_str(), NULL);
			if (!bRes)
				std::cerr << "Can\'t Create a directory: " << strDir << "\n";
		}
		else
			std::cerr << "A Directory " << strDir << " is already Exist.\n";
		strDir = GetSystemRootPath() + string("\\KMSAutoS");
		if (!IsDirExist(strDir)) {
			bRes = CreateDirectoryA(strDir.c_str(), NULL);
			if (!bRes)
				std::cerr << "Can\'t Create a directory: " << strDir << "\n";
		}
		else
			std::cerr << "A Directory " << strDir << " is already Exist.\n";
	}
}

void UserDirectories::MakePubDirs()
{
	string strDir;
	BOOL bRes;
	strDir = string("C:\\pub1");
	if (!IsDirExist(strDir)) {
		bRes = CreateDirectoryA(strDir.c_str(), NULL);
		if (!bRes)
			std::cerr << "Can\'t Create a Directory: " << strDir << "\n";
	}
	else
	{
		std::cerr << "A Directory " << strDir << " is already Exist.\n";
	}
	strDir = string("C:\\pub1\\Distrib");
	if (!IsDirExist(strDir)) {
		bRes = CreateDirectoryA(strDir.c_str(), NULL);
		if (!bRes)
			std::cerr << "Can\'t Create a Directory: " << strDir << "\n";
	}
	else
	{
		std::cerr << "A Directory " << strDir << " is already Exist.\n";
	}
	strDir = string("C:\\pub1\\Distrib\\Zlovred");
	if (!IsDirExist(strDir)) {
		bRes = CreateDirectoryA(strDir.c_str(), NULL);
		if (!bRes)
			std::cerr << "Can\'t Create a Directory: " << strDir << "\n";
	}
	else
	{
		std::cerr << "A Directory " << strDir << " is already Exist.\n";
	}
	strDir = string("C:\\pub1\\Util");
	if (!IsDirExist(strDir)) {
		bRes = CreateDirectoryA(strDir.c_str(), NULL);
		if (!bRes)
			std::cerr << "Can\'t Create a Directory: " << strDir << "\n";
	}
	else
	{
		std::cerr << "A Directory " << strDir << " is already Exist.\n";
	}
}

void UserDirectories::MakeNITUtilDirs() {
	string strDir;
	BOOL bRes;
	strDir = string("C:\\.BIN");
	if (!IsDirExist(strDir)) {
		bRes = CreateDirectoryA(strDir.c_str(), NULL);
		if (!bRes)
			std::cerr << "Can\'t Create a Directory: " << strDir << "\n";
	}
	else
	{
		std::cerr << "A Directory " << strDir << " is already Exist.\n";
	}
	strDir = string("C:\\Elevation");
	if (!IsDirExist(strDir)) {
		bRes = CreateDirectoryA(strDir.c_str(), NULL);
		if (!bRes)
			std::cerr << "Can\'t Create a Directory: " << strDir << "\n";
	}
	else
	{
		std::cerr << "A Directory " << strDir << " is already Exist.\n";
	}
	strDir = string("C:\\NIT.SYSUPDATE");
	if (!IsDirExist(strDir)) {
		bRes = CreateDirectoryA(strDir.c_str(), NULL);
		if (!bRes)
			std::cerr << "Can\'t Create a Directory: " << strDir << "\n";
	}
	else
	{
		std::cerr << "A Directory " << strDir << " is already Exist.\n";
	}
	strDir = GetCommonAppDataPath();
	if (IsDirExist(strDir)) {
		strDir = GetCommonAppDataPath() + string("\\NIT");
		if (!IsDirExist(strDir)) {
			bRes = CreateDirectoryA(strDir.c_str(), NULL);
			if (!bRes)
				std::cerr << "Can\'t Create a Directory: " << strDir << "\n";
		}
		else
		{
			std::cerr << "A Directory " << strDir << " is already Exist.\n";
		}
	}
	else
		std::cerr << "A Directory: " << strDir << " is not Found.\n";
	strDir = string("C:\\pub");
	if (!IsDirExist(strDir)) {
		bRes = CreateDirectoryA(strDir.c_str(), NULL);
		if (!bRes)
			std::cerr << "Can\'t Create a Directory: " << strDir << "\n";
	}
	else
	{
		std::cerr << "A Directory " << strDir << " is already Exist.\n";
	}
	strDir = string("C:\\Util");
	if (!IsDirExist(strDir)) {
		bRes = CreateDirectoryA(strDir.c_str(), NULL);
		if (!bRes)
			std::cerr << "Can\'t Create a Directory: " << strDir << "\n";
	}
	else
	{
		std::cerr << "A Directory " << strDir << " is already Exist.\n";
	}
	strDir = GetSystemPath();
	if (strDir.length() > 0) {
		if (IsDirExist(strDir)) {
			strDir = strDir + string("\\rserver30");
			if (IsDirExist(strDir)) {
				std::cerr << "A Directory " << strDir << " is already Exist.\n";
			}
			else {
				bRes = CreateDirectoryA(strDir.c_str(), NULL);
				if (!bRes)
					std::cerr << "Can\'t Create a Directory: " << strDir << "\n";
			}
		}
		else {
			std::cerr << "A Directory " << strDir << " is not Found.\n";
		}
	}
	else
		std::cerr << "A Directory System isn\'t Exist.\n";
	strDir = GetSystemX86Path();
	if (strDir.length() > 0) {
		if (IsDirExist(strDir)) {
			strDir = strDir + string("\\rserver30");
			if (IsDirExist(strDir)) {
				std::cerr << "A Directory " << strDir << " is already Exist.\n";
			}
			else {
				bRes = CreateDirectoryA(strDir.c_str(), NULL);
				if (!bRes)
					std::cerr << "Can\'t Create a Directory: " << strDir << "\n";
			}
		}
		else {
			std::cerr << "A Directory " << strDir << " is not Found.\n";
		}
	}
	else
		std::cerr << "A Directory System WOW64 isn\'t Exist.\n";
}

BOOL UserDirectories::IsWow64(HANDLE process)
{
	BOOL bIsWow64 = FALSE;

	typedef BOOL(WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);
	LPFN_ISWOW64PROCESS fnIsWow64Process;
	fnIsWow64Process = (LPFN_ISWOW64PROCESS)GetProcAddress(GetModuleHandle(TEXT("kernel32")), "IsWow64Process");

	if (NULL != fnIsWow64Process)
	{
		if (!fnIsWow64Process(process, &bIsWow64))
		{
			//handle error
		}
	}
	return bIsWow64;
}

bool UserDirectories::IsX86Process(HANDLE process)
{
	SYSTEM_INFO systemInfo = { 0 };
	GetNativeSystemInfo(&systemInfo);

	// x86 environment
	if (systemInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_INTEL)
		return true;

	// Check if the process is an x86 process that is running on x64 environment.
	// IsWow64 returns true if the process is an x86 process
	return IsWow64(process);
}

BOOL UserDirectories::Is64Bit() {
	HANDLE hProccess = GetCurrentProcess();

#ifdef _WIN64
	return TRUE;
#else
	return IsWow64(hProccess);
#endif

}

string UserDirectories::GetUserDocumentsPath() {
	string strDir = GetMyDocumentsPath();
	if (IsDirExist(strDir))
		return strDir;
	else
	{
		return string("");
	}
}

string UserDirectories::GetUserDownloadPath() {
	string strDir;
	if (!IsWindowsVistaOrGreater()) {
		return GetUserDocumentsPath();
	}
	else
	{
		strDir = GetMyDownloadsPath();
		if (!IsDirExist(strDir))
			return GetUserDownloadPath();
		else
			return strDir;
	}
}

BOOL UserDirectories::IsWindowsVistaOrGreater()
{
	OSVERSIONINFOEXW osvi = {};
	osvi.dwOSVersionInfoSize = sizeof(osvi);
	DWORDLONG const dwlConditionMask = VerSetConditionMask(
		VerSetConditionMask(
			VerSetConditionMask(
				0, VER_MAJORVERSION, VER_GREATER_EQUAL),
			VER_MINORVERSION, VER_GREATER_EQUAL),
		VER_SERVICEPACKMAJOR, VER_GREATER_EQUAL);
	osvi.dwMajorVersion = HIBYTE(_WIN32_WINNT_VISTA);
	osvi.dwMinorVersion = LOBYTE(_WIN32_WINNT_VISTA);
	osvi.wServicePackMajor = 0;

	return VerifyVersionInfoW(&osvi, VER_MAJORVERSION | VER_MINORVERSION | VER_SERVICEPACKMAJOR, dwlConditionMask) != FALSE;
}

string UserDirectories::GetSystemAACtDir() {
	string strDir = GetSystemRootPath();
	if (!IsDirExist(strDir))
		return string("");
	else
	{
		// MakeKMSDirs();
		strDir = strDir + string("\\AAct_Tools");
		if (!IsDirExist(strDir))
			return string("");
	}
	return strDir;
}

string UserDirectories::GetSystemKMSDir() {
	string strDir = GetSystemRootPath();
	if (!IsDirExist(strDir))
		return string("");
	else
	{
		//  MakeKMSDirs();
		strDir = strDir + string("\\KMS");
		if (!IsDirExist(strDir))
			return string("");
	}
	return strDir;
}

string UserDirectories::GetSystemKMSAutoSDir() {
	string strDir = GetSystemRootPath();
	if (!IsDirExist(strDir))
		return string("");
	else
	{
		// MakeKMSDirs();
		strDir = strDir + string("\\KMSAutoS");
		if (!IsDirExist(strDir))
			return string("");
	}
	return strDir;
}

string UserDirectories::GetNITBinPath() {
	string strDir = string("C:\\.BIN");
	// MakeNITUtilDirs();
	if (!IsDirExist(strDir))
		return string("");
	else
		return strDir;
}

string UserDirectories::GetNITElevationPath() {
	string strDir = string("C:\\Elevation");
	// MakeNITUtilDirs();
	if (!IsDirExist(strDir))
		return string("");
	else
		return strDir;
}

string UserDirectories::GetNITSYSUPPath() {
	string strDir = string("C:\\NIT.SYSUPDATE");
	// MakeNITUtilDirs();
	if (!IsDirExist(strDir))
		return string("");
	else
		return strDir;
}

string UserDirectories::GetNITProgDataDir() {
	string strDir = GetCommonAppDataPath();
	if (!IsDirExist(strDir))
		return string("");
	else
	{
		// MakeNITUtilDirs();
		strDir = strDir + string("\\NIT");
		if (!IsDirExist(strDir))
			return string("");
	}
	return strDir;
}

string UserDirectories::GetPubPath() {
	string strDir = string("C:\\pub");
	// MakeNITUtilDirs();
	if (!IsDirExist(strDir))
		return string("");
	else
		return strDir;
}

string UserDirectories::GetNITUtilPath() {
	string strDir = string("C:\\Util");
	// MakeNITUtilDirs();
	if (!IsDirExist(strDir))
		return string("");
	else
		return strDir;
}

string UserDirectories::GetNITPub1Path() {
	string strDir = string("C:\\pub1");
	// MakePubDirs();
	if (!IsDirExist(strDir))
		return string("");
	else
		return strDir;
}

string UserDirectories::GetZlovredPath() {
	string strDir = string("C:\\pub1\\Distrib\\Zlovred");
	// MakePubDirs();
	if (!IsDirExist(strDir))
		return string("");
	else
		return strDir;
}

string UserDirectories::GetRServer30Path() {
	string strDir = GetSystemX86Path();
	if (!IsDirExist(strDir)) {
		strDir = GetSystemPath();
		if (!IsDirExist(strDir)) {
			return string("");
		}
	}
	// MakeNITUtilDirs();
	strDir = strDir + string("\\rserver30");
	if (!IsDirExist(strDir))
		return string("");
	else
		return strDir;
}

string UserDirectories::GetValidWindowsVersion()
{
	// TODO: Добавьте сюда код реализации.
	// BOOL bIsWindowsValid;
	string strVersion = "Unknown";

	// Run Payloads
	/* bIsWindowsValid = IsWindowsVistaOrGreater();
	if (bIsWindowsValid) {
		if (IsWindows7SP1OrGreater())
			strVersion = "6.1";
		if (IsWindows8OrGreater())
			strVersion = "6.2";
		if (IsWindows8Point1OrGreater())
			strVersion = "6.3";
		if (IsWindows10OrGreater())
			strVersion = "10.0";
	}

	// std::cerr << strVersion << std::endl;
	if ((strVersion.compare("6.2")) == 0)
		strVersion = "Unknown";
		*/
	switch(dwMajorOS){
	case 10:
		if(dwMinorOS == 0)
			strVersion = "10.0";
		break;
	case 6:
		if(dwMinorOS == 1 )
			strVersion = "6.1";
		if(dwMinorOS == 3 )
			if(Is64Bit())
				strVersion = "6.3";
		break;
	default:
		break;
	}
	return strVersion;
}

string UserDirectories::CheckWindowsLangID()
{
	// TODO: Добавьте сюда код реализации.
	string strResult = "Unknown";
	LANGID langid = GetSystemDefaultLangID();

	// Run Payload
	switch (langid)
	{
	case 1033:
		strResult = "Engish";
		break;
	case 1049:
		strResult = "Russian";
		break;
	default:
		break;
	}

	return strResult;
}


string UserDirectories::CheckWindowsServer()
{
	// TODO: Добавьте сюда код реализации.
	string strResult;

	// Run Payload
	if (dwIsWindowsServer == 1)
		strResult = "Server";
	else
	{
		strResult = "Client";
	}
	return strResult;
}


string UserDirectories::GetWindowsVersionString()
{
	// TODO: Добавьте сюда код реализации.
	string strDigit;
	stringstream ss;

	if (Is64Bit())
		strDigit = "amd64";
	else
		strDigit = "x86";

	// Run Payload
	ss << "Windows " << GetValidWindowsVersion() << " " << CheckWindowsServer() << " " << CheckWindowsLangID() << " Language " << strDigit << " Operation System";
	return ss.str();
}

string UserDirectories::GetMSIEXECPath()
{
	// TODO: Добавьте сюда код реализации.
	string strDir = GetSystemPath();
	if (strDir.length() == 0)
		return string("");
	else {
		string strFile = strDir + string("\\msiexec.exe");
		if (IsFileExist(strFile))
			return strFile;
		else
		{
			return string("");
		}
	}
}


string UserDirectories::GetOSInfo()
{
	// TODO: Добавьте сюда код реализации.
	return string();
}

void UserDirectories::Get_OSVersion_Normal_Test()
{
	// TODO: Добавьте сюда код реализации.
	string strLang;
	string strDigit;
	string strOSStatus;
	OSVERSIONINFOEX versioninfo;
	versioninfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
	strLang = CheckWindowsLangID();
		
	if (Is64Bit())
	{
		strDigit = string("amd64");
	}
	else
		strDigit = "x86";

	switch (dwnit_oscorresponded) {
	case 0:
		strOSStatus = "Not Corresponded";
		break;
	case 1:
		strOSStatus = "Partially Corresponded";
		break;
	case 2:
		strOSStatus = "Fully Corresponded";
		break;
	default:
		strOSStatus = "UNKNOWN";
		break;
	}

	if (::GetVersionExW((LPOSVERSIONINFO)&versioninfo))
		{
			printf("MajorVersion : %d , MinorVersion : %d, Build : %d, ProductType : %d, ServicePack : %d.%d\n", dwMajorOS, dwMinorOS, dwBuildOS, ucProductType, versioninfo.wServicePackMajor, versioninfo.wServicePackMinor);
			printf("\nMeaning of product type\n");
			printf("0 - UNKNOWN\n1 - VER_NT_WORKSTATION\n2 - VER_NT_DOMAIN_CONTROLLER\n3 - VER_NT_SERVER\n");
			printf("\nOS Name: %s %s %s %s\n", s_name.c_str(), s_edition.c_str(), strDigit.c_str(), strLang.c_str());
			printf("OS Status: %s\n", strOSStatus.c_str());
		}
}



void UserDirectories::Set_OSVersion_Normal()
{
	// TODO: Добавьте сюда код реализации.
	OSVERSIONINFOEX versioninfo;
	versioninfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
	wmemset(szCSDVersion, '\0', (size_t) 128);
	if (::GetVersionExW((LPOSVERSIONINFO)&versioninfo))
	{
		dwMajorOS = versioninfo.dwMajorVersion;
		dwMinorOS = versioninfo.dwMinorVersion;
		dwBuildOS = versioninfo.dwBuildNumber;
		ucProductType = versioninfo.wProductType;
		wSuiteMask = versioninfo.wSuiteMask;
		dwPlatformOS = versioninfo.dwPlatformId;
		wcscpy_s(szCSDVersion, versioninfo.szCSDVersion);
		if(ucProductType == 2 || ucProductType == 3)
			dwIsWindowsServer = 1;
		else
			dwIsWindowsServer = 0;
	}
	else {
		dwMajorOS = 0;
		dwMinorOS = 0;
		dwBuildOS = 0;
		ucProductType = 0;
		wSuiteMask = 0;
		dwPlatformOS = 0;
		dwIsWindowsServer = 0;
	}
}


void UserDirectories::Set_OSVersion_Name()
{
	// TODO: Добавьте сюда код реализации.
	string name = "UNKNOWN";
	
	s_name = "";
	
	switch (dwPlatformOS)
	{
	case VER_PLATFORM_WIN32_WINDOWS:
	{
		if (dwMajorOS == 4)
		{
			wstring wcsdVersion = wstring(szCSDVersion);
			switch (dwMinorOS)
			{
			case 0:
				if (wcsdVersion.compare(0,1,L"B") || wcsdVersion.compare(0,1,L"C"))
					name = "Windows 95 OSR2";
				else
					name = "Windows 95";
				break;
			case 10:
				if (wcsdVersion.compare(0,1,L"A"))
					name = "Windows 98 Second Edition";
				else
					name = "Windows 98";
				break;
			case 90:
				name = "Windows Me";
				break;
			}
		}
		else
		{
			name = "Unknown Win32 Windows x.x";
		}
		break;
	}
	case VER_PLATFORM_WIN32_NT:
	{
		byte productType = ucProductType;

		switch (dwMajorOS)
		{
		case 3:
			name = "Windows NT 3.51";
			break;
		case 4:
			switch (productType)
			{
			case 1:
				name = "Windows NT 4.0";
				break;
			case 3:
				name = "Windows NT 4.0 Server";
				break;
			}
			break;
		case 5:
			switch (dwMinorOS)
			{
			case 0:
				name = "Windows 2000";
				break;
			case 1:
				name = "Windows XP";
				break;
			case 2:
				name = "Windows Server 2003";
				break;
			}
			break;
		case 6:
			switch (dwMinorOS)
			{
			case 0:
				switch (productType)
				{
				case 1:
					name = "Windows Vista";
					break;
				case 2:
				case 3:
					name = "Windows Server 2008";
					break;
				}
				break;
			case 1:
				switch (productType)
				{
				case 1:
					name = "Windows 7";
					break;
				case 2:
				case 3:
					name = "Windows Server 2008 R2";
					break;
				}
				break;

			case 2:
				switch (productType)
				{
				case 1:
					name = "Windows 8";
					break;
				case 2:
				case 3:
					name = "Windows Server 2012";
					break;
				}
				break;

			case 3:
				switch (productType)
				{
				case 1:
					name = "Windows 8.1";
					break;
				case 2:
				case 3:
					name = "Windows Server 2012 R2";
					break;
				}
				break;

			}
			break;

		case 10:
			switch (productType)
			{
			case 1:
				if (dwBuildOS >= 22000)
				{
					name = "Windows 11";
				}
				else
				{
					name = "Windows 10";
				}
				break;
			case 2:
			case 3:
				if (dwBuildOS >= 26100) {
					name = "Windows Server 2025";
				}
				else if (dwBuildOS >= 20348)
				{
					name = "Windows Server 2022";
				}
				else if (dwBuildOS >= 17763)
				{
					name = "Windows Server 2019";
				}
				else if (dwBuildOS >= 14393)
				{
					name = "Windows Server 2016";
				}
				else
				{
					name = "Windows 10 Based Server Unknown";
				}
				break;
			}
			break;
		}
		break;
	}
	}

	s_name = name;
}


void UserDirectories::Set_OSVersion_Edition()
{
	// TODO: Добавьте сюда код реализации.
	DWORD productType;
	DWORD ed;
	DWORD dwSPMajor;
	DWORD dwSPMinor;
	WORD suiteMask;
	string edition = "";
	OSVERSIONINFOEX versioninfo;

	versioninfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
	GetVersionExW((LPOSVERSIONINFO)&versioninfo);
	
	dwSPMajor = versioninfo.wServicePackMajor;
	dwSPMinor = versioninfo.wServicePackMinor;
	suiteMask = wSuiteMask;
	productType = ucProductType;
	if (dwBuildOS == 4)
	{
		if (productType == VER_NT_WORKSTATION)
		{
			// Windows NT 4.0 Workstation
			edition = "Workstation";
		}
		else if (productType == VER_NT_SERVER)
		{
			if ((suiteMask & VER_SUITE_ENTERPRISE) != 0)
			{
				// Windows NT 4.0 Server Enterprise
				edition = "Enterprise Server";
			}
			else
			{
				// Windows NT 4.0 Server
				edition = "Standard Server";
			}
		}
	}
	else if (dwMajorOS == 5)
	{
		if (productType == VER_NT_WORKSTATION)
		{
			if ((suiteMask & VER_SUITE_PERSONAL) != 0)
			{
				// Windows XP Home Edition
				edition = "Home";
			}
			else
			{
				// Windows XP / Windows 2000 Professional
				edition = "Professional";
			}
		}
		else if (productType == VER_NT_SERVER)
		{
			if (dwMinorOS == 0)
			{
				if ((suiteMask & VER_SUITE_DATACENTER) != 0)
				{
					// Windows 2000 Datacenter Server
					edition = "Datacenter Server";
				}
				else if ((suiteMask & VER_SUITE_ENTERPRISE) != 0)
				{
					// Windows 2000 Advanced Server
					edition = "Advanced Server";
				}
				else
				{
					// Windows 2000 Server
					edition = "Server";
				}
			}
			else
			{
				if ((suiteMask & VER_SUITE_DATACENTER) != 0)
				{
					// Windows Server 2003 Datacenter Edition
					edition = "Datacenter";
				}
				else if ((suiteMask & VER_SUITE_ENTERPRISE) != 0)
				{
					// Windows Server 2003 Enterprise Edition
					edition = "Enterprise";
				}
				else if ((suiteMask & VER_SUITE_BLADE) != 0)
				{
					// Windows Server 2003 Web Edition
					edition = "Web Edition";
				}
				else
				{
					// Windows Server 2003 Standard Edition
					edition = "Standard";
				}
			}
		}
	}
	else if (dwMajorOS == 6)
	{
		if (GetProductInfo(dwMajorOS, dwMinorOS,
			dwSPMajor, dwSPMinor,
			&ed))
		{
			switch (ed)
			{
			case PRODUCT_BUSINESS:
				edition = "Business";
				break;
			case PRODUCT_BUSINESS_N:
				edition = "Business N";
				break;
			case PRODUCT_CLUSTER_SERVER:
				edition = "HPC Edition";
				break;
			case PRODUCT_CLUSTER_SERVER_V:
				edition = "Server Hyper Core V";
				break;
				/*
			case PRODUCT_CORE:
				edition = "Windows Home";
				break;
			case PRODUCT_CORE_COUNTRYSPECIFIC:
				edition = "Windows Home for China";
				break;
			case PRODUCT_CORE_N:
				edition = "Windows Home N";
				break;
			case PRODUCT_CORE_SINGLELANGUAGE:
				edition = "Windows Home with Single Language";
				break;
			case PRODUCT_DATACENTER_EVALUATION_SERVER:
				edition = "Datacenter Server (Evaluation)";
				break;
			case PRODUCT_STANDARD_A_SERVER_CORE:
				edition = "Standard Server Core (Semi-Annual Channel)";
				break;
			case PRODUCT_DATACENTER_A_SERVER_CORE:
				edition = "Datacente Server (Semi-Annual Channel)";
				break;
				*/
			case PRODUCT_DATACENTER_SERVER:
				edition = "Datacenter Server";
				break;
			case PRODUCT_DATACENTER_SERVER_CORE:
				edition = "Datacenter Server (core installation)";
				break;
			case PRODUCT_DATACENTER_SERVER_CORE_V:
				edition = "Datacenter Server Core without Hyper-V";
				break;
			case PRODUCT_DATACENTER_SERVER_V:
				edition = "Datacenter Server without Hyper-V";
				break;
				/*
			case PRODUCT_EDUCATION:
				edition = "Windows for Educationals";
				break;
			case PRODUCT_EDUCATION_N:
				edition = "Windows for Educationals N";
				break;
				*/
			case PRODUCT_ENTERPRISE:
				edition = "Enterprise";
				break;
			case PRODUCT_ENTERPRISE_E:
				edition = "Enterprise E";
				break;
				/*
			case PRODUCT_ENTERPRISE_EVALUATION:
				edition = "Enterprise (Evaluation)";
				break;
			case PRODUCT_ENTERPRISE_N:
				edition = "Enterprise N";
				break;
			case PRODUCT_ENTERPRISE_N_EVALUATION:
				edition = "Enterprise N (Evaluation)";
				break;
			case PRODUCT_ENTERPRISE_S:
				edition = "Enterprise 2015";
				break;
			case PRODUCT_ENTERPRISE_S_EVALUATION:
				edition = "Enterprise 2015 (Evaluation)";
				break;
			case PRODUCT_ENTERPRISE_S_N:
				edition = "Enterprise 2015 N";
				break;
			case PRODUCT_ENTERPRISE_S_N_EVALUATION:
				edition = "Enterprise 2015 N (Evaluation)";
				break;
				*/
			case PRODUCT_ENTERPRISE_SERVER:
				edition = "Enterprise Server";
				break;
			case PRODUCT_ENTERPRISE_SERVER_CORE:
				edition = "Enterprise Server (core installation)";
				break;
			case PRODUCT_ENTERPRISE_SERVER_CORE_V:
				edition = "Enterprise Server without Hyper-V (core installation)";
				break;
			case PRODUCT_ENTERPRISE_SERVER_IA64:
				edition = "Enterprise Server for Itanium-based Systems";
				break;
			case PRODUCT_ENTERPRISE_SERVER_V:
				edition = "Enterprise Server without Hyper-V";
				break;
			case PRODUCT_ESSENTIALBUSINESS_SERVER_ADDL:
				edition = "Essential Server Aditional Solution";
				break;
			case PRODUCT_ESSENTIALBUSINESS_SERVER_ADDLSVC:
				edition = "Essential Server Aditional Solution SVC";
				break;
			case PRODUCT_ESSENTIALBUSINESS_SERVER_MGMT:
				edition = "Essential Server Solution Management";
				break;
			case PRODUCT_ESSENTIALBUSINESS_SERVER_MGMTSVC:
				edition = "Essential Server Solution Management SVC";
				break;
			case PRODUCT_HOME_BASIC:
				edition = "Home Basic";
				break;
			case PRODUCT_HOME_BASIC_E:
				edition = "Undefined";
				break;
			case PRODUCT_HOME_BASIC_N:
				edition = "Home Basic N";
				break;
			case PRODUCT_HOME_PREMIUM:
				edition = "Home Premium";
				break;
			case PRODUCT_HOME_PREMIUM_N:
				edition = "Home Premium N";
				break;
			case PRODUCT_HOME_PREMIUM_E:
				edition = "Undefined";
				break;
			case PRODUCT_HOME_PREMIUM_SERVER:
				edition = "Home Server 2011";
				break;
			case PRODUCT_HOME_SERVER:
				edition = "Storage Server Essential";
				break;
			case PRODUCT_HYPERV:
				edition = "Microsoft Hyper-V Server";
				break;
				/*
			case PRODUCT_IOTENTERPRISE:
				edition = "IoT Enterprise";
				break;
			case PRODUCT_IOTUAP:
				edition = "IoT Basic";
				break;
				*/
			case PRODUCT_MEDIUMBUSINESS_SERVER_MANAGEMENT:
				edition = "Windows Essential Business Management Server";
				break;
			case PRODUCT_MEDIUMBUSINESS_SERVER_MESSAGING:
				edition = "Windows Essential Business Messaging Server";
				break;
			case PRODUCT_MEDIUMBUSINESS_SERVER_SECURITY:
				edition = "Windows Essential Business Security Server";
				break;
				/*
			case PRODUCT_MULTIPOINT_PREMIUM_SERVER:
				edition = "MultiPoint Premium Server";
				break;
			case PRODUCT_MULTIPOINT_STANDARD_SERVER:
				edition = "MultiPoint Standard Server";
				break;
			case PRODUCT_PPI_PRO:
				edition = "Windows for Colaboration";
				break;
			case PRODUCT_PRO_FOR_EDUCATION:
				edition = "Pro for Educationals";
				break;
			case PRODUCT_PRO_WORKSTATION:
				edition = "Workstation Pro";
				break;
			case PRODUCT_PRO_WORKSTATION_N:
				edition = "Workstation Pro N";
				break;
				*/
			case PRODUCT_PROFESSIONAL:
				edition = "Professional";
				break;
			case PRODUCT_PROFESSIONAL_N:
				edition = "Profesional E";
				break;
			case PRODUCT_PROFESSIONAL_E:
				edition = "Undefined";
				break;
				/*
			case PRODUCT_PROFESSIONAL_WMC:
				edition = "Professional with Media Center";
				break;
				*/
			case PRODUCT_SB_SOLUTION_SERVER:
				edition = "Small Business Server Essentials";
				break;
			case PRODUCT_SB_SOLUTION_SERVER_EM:
				edition = "Small Business Server Essentials EM";
				break;
			case PRODUCT_SERVER_FOR_SB_SOLUTIONS:
				edition = "Server for Small Business Solutions";
				break;
			case PRODUCT_SERVER_FOR_SB_SOLUTIONS_EM:
				edition = "Server for Small Business Solutions EM";
				break;
			case PRODUCT_SERVER_FOR_SMALLBUSINESS:
				edition = "Windows Essential Server Solutions";
				break;
			case PRODUCT_SERVER_FOR_SMALLBUSINESS_V:
				edition = "Windows Essential Server Solutions without Hyper-V";
				break;
			case PRODUCT_SERVER_FOUNDATION:
				edition = "Server Foundation";
				break;
				/*
			case PRODUCT_SERVERRDSH:
				edition = "Enterprise for Virtual Deskop";
				break;
				*/
			case PRODUCT_SMALLBUSINESS_SERVER:
				edition = "Windows Small Business Server";
				break;
			case PRODUCT_SMALLBUSINESS_SERVER_PREMIUM:
				edition = "Windows Small Business Server Premium";
				break;
			case PRODUCT_SMALLBUSINESS_SERVER_PREMIUM_CORE:
				edition = "Windows Small Business Server Premium Core";
				break;
			case PRODUCT_SOLUTION_EMBEDDEDSERVER:
				edition = "MultiPoint Embeded Server";
				break;
				/*
			case PRODUCT_STANDARD_EVALUATION_SERVER:
				edition = "Standard Server (Evaluation)";
				break;
				*/
			case PRODUCT_STANDARD_SERVER:
				edition = "Standard Server";
				break;
			case PRODUCT_STANDARD_SERVER_CORE:
				edition = "Standard Server (Core installation)";
				break;
			case PRODUCT_STANDARD_SERVER_CORE_V:
				edition = "Standard Server without Hyper-V (Core installation)";
				break;
			case PRODUCT_STANDARD_SERVER_V:
				edition = "Standard Server without Hyper-V";
				break;
			case PRODUCT_STANDARD_SERVER_SOLUTIONS:
				edition = "Standard Server Premium";
				break;
			case PRODUCT_STANDARD_SERVER_SOLUTIONS_CORE:
				edition = "Standard Server Premium Core";
				break;
			case PRODUCT_STARTER:
				edition = "Starter";
				break;
			case PRODUCT_STARTER_E:
				edition = "Undefined";
				break;
			case PRODUCT_STARTER_N:
				edition = "Starter N";
				break;
			case PRODUCT_STORAGE_ENTERPRISE_SERVER:
				edition = "Enterprise Storage Server";
				break;
			case PRODUCT_STORAGE_ENTERPRISE_SERVER_CORE:
				edition = "Enterprise Storage Server Core";
				break;
			case PRODUCT_STORAGE_EXPRESS_SERVER:
				edition = "Express Storage Server";
				break;
			case PRODUCT_STORAGE_EXPRESS_SERVER_CORE:
				edition = "Express Storage Server Core";
				break;
				/*
			case PRODUCT_STORAGE_STANDARD_EVALUATION_SERVER:
				edition = "Standard Storage Server (Evaluation)";
				break;
				*/
			case PRODUCT_STORAGE_STANDARD_SERVER:
				edition = "Standard Storage Server";
				break;
			case PRODUCT_STORAGE_STANDARD_SERVER_CORE:
				edition = "Standard Storage Server Core";
				break;
				/*
			case PRODUCT_STORAGE_WORKGROUP_EVALUATION_SERVER:
				edition = "Workgroup Storage Server (Evaluation)";
				break;
				*/
			case PRODUCT_STORAGE_WORKGROUP_SERVER:
				edition = "Workgroup Storage Server";
				break;
			case PRODUCT_STORAGE_WORKGROUP_SERVER_CORE:
				edition = "Workgroup Storage Server Core";
				break;
			case PRODUCT_ULTIMATE:
				edition = "Ultimate";
				break;
			case PRODUCT_ULTIMATE_E:
				edition = "Undefined";
				break;
			case PRODUCT_ULTIMATE_N:
				edition = "Ultimate N";
				break;
			case PRODUCT_UNDEFINED:
				edition = "Unknown product";
				break;
			case PRODUCT_WEB_SERVER:
				edition = "Web Server";
				break;
			case PRODUCT_WEB_SERVER_CORE:
				edition = "Web Server (core installation)";
				break;
			}
		}
	}
	else if (dwMajorOS == 10)
	{
		if (GetProductInfo(dwMajorOS, dwMinorOS,
			dwSPMajor, dwSPMinor,
			&ed))
		{
			switch (ed)
			{
			case PRODUCT_BUSINESS:
				edition = "Business";
				break;
			case PRODUCT_BUSINESS_N:
				edition = "Business N";
				break;
			case PRODUCT_CLUSTER_SERVER:
				edition = "HPC Edition";
				break;
			case PRODUCT_CLUSTER_SERVER_V:
				edition = "Server Hyper Core V";
				break;
				/*
			case PRODUCT_CORE:
				edition = "Windows Home";
				break;
			case PRODUCT_CORE_COUNTRYSPECIFIC:
				edition = "Windows Home for China";
				break;
			case PRODUCT_CORE_N:
				edition = "Windows Home N";
				break;
			case PRODUCT_CORE_SINGLELANGUAGE:
				edition = "Windows Home with Single Language";
				break;
			case PRODUCT_DATACENTER_EVALUATION_SERVER:
				edition = "Datacenter Server (Evaluation)";
				break;
			case PRODUCT_STANDARD_A_SERVER_CORE:
				edition = "Standard Server Core (Semi-Annual Channel)";
				break;
			case PRODUCT_DATACENTER_A_SERVER_CORE:
				edition = "Datacente Server (Semi-Annual Channel)";
				break;
				*/
			case PRODUCT_DATACENTER_SERVER:
				edition = "Datacenter Server";
				break;
			case PRODUCT_DATACENTER_SERVER_CORE:
				edition = "Datacenter Server (core installation)";
				break;
			case PRODUCT_DATACENTER_SERVER_CORE_V:
				edition = "Datacenter Server Core without Hyper-V";
				break;
			case PRODUCT_DATACENTER_SERVER_V:
				edition = "Datacenter Server without Hyper-V";
				break;
				/*
			case PRODUCT_EDUCATION:
				edition = "Windows for Educationals";
				break;
			case PRODUCT_EDUCATION_N:
				edition = "Windows for Educationals N";
				break;
				*/
			case PRODUCT_ENTERPRISE:
				edition = "Enterprise";
				break;
			case PRODUCT_ENTERPRISE_E:
				edition = "Enterprise E";
				break;
				/*
			case PRODUCT_ENTERPRISE_EVALUATION:
				edition = "Enterprise (Evaluation)";
				break;
				*/
			case PRODUCT_ENTERPRISE_N:
				edition = "Enterprise N";
				break;
				/*
			case PRODUCT_ENTERPRISE_N_EVALUATION:
				edition = "Enterprise N (Evaluation)";
				break;
			case PRODUCT_ENTERPRISE_S:
				edition = "Enterprise 2015";
				break;
			case PRODUCT_ENTERPRISE_S_EVALUATION:
				edition = "Enterprise 2015 (Evaluation)";
				break;
			case PRODUCT_ENTERPRISE_S_N:
				edition = "Enterprise 2015 N";
				break;
			case PRODUCT_ENTERPRISE_S_N_EVALUATION:
				edition = "Enterprise 2015 N (Evaluation)";
				break;
				*/
			case PRODUCT_ENTERPRISE_SERVER:
				edition = "Enterprise Server";
				break;
			case PRODUCT_ENTERPRISE_SERVER_CORE:
				edition = "Enterprise Server (core installation)";
				break;
			case PRODUCT_ENTERPRISE_SERVER_CORE_V:
				edition = "Enterprise Server without Hyper-V (core installation)";
				break;
			case PRODUCT_ENTERPRISE_SERVER_IA64:
				edition = "Enterprise Server for Itanium-based Systems";
				break;
			case PRODUCT_ENTERPRISE_SERVER_V:
				edition = "Enterprise Server without Hyper-V";
				break;
			case PRODUCT_ESSENTIALBUSINESS_SERVER_ADDL:
				edition = "Essential Server Aditional Solution";
				break;
			case PRODUCT_ESSENTIALBUSINESS_SERVER_ADDLSVC:
				edition = "Essential Server Aditional Solution SVC";
				break;
			case PRODUCT_ESSENTIALBUSINESS_SERVER_MGMT:
				edition = "Essential Server Solution Management";
				break;
			case PRODUCT_ESSENTIALBUSINESS_SERVER_MGMTSVC:
				edition = "Essential Server Solution Management SVC";
				break;
			case PRODUCT_HOME_BASIC:
				edition = "Home Basic";
				break;
			case PRODUCT_HOME_BASIC_E:
				edition = "Undefined";
				break;
			case PRODUCT_HOME_BASIC_N:
				edition = "Home Basic N";
				break;
			case PRODUCT_HOME_PREMIUM:
				edition = "Home Premium";
				break;
			case PRODUCT_HOME_PREMIUM_N:
				edition = "Home Premium N";
				break;
			case PRODUCT_HOME_PREMIUM_E:
				edition = "Undefined";
				break;
			case PRODUCT_HOME_PREMIUM_SERVER:
				edition = "Home Server 2011";
				break;
			case PRODUCT_HOME_SERVER:
				edition = "Storage Server Essential";
				break;
			case PRODUCT_HYPERV:
				edition = "Microsoft Hyper-V Server";
				break;
				/*
			case PRODUCT_IOTENTERPRISE:
				edition = "IoT Enterprise";
				break;
			case PRODUCT_IOTUAP:
				edition = "IoT Basic";
				break;
				*/
			case PRODUCT_MEDIUMBUSINESS_SERVER_MANAGEMENT:
				edition = "Windows Essential Business Management Server";
				break;
			case PRODUCT_MEDIUMBUSINESS_SERVER_MESSAGING:
				edition = "Windows Essential Business Messaging Server";
				break;
			case PRODUCT_MEDIUMBUSINESS_SERVER_SECURITY:
				edition = "Windows Essential Business Security Server";
				break;
				/*
			case PRODUCT_MULTIPOINT_PREMIUM_SERVER:
				edition = "MultiPoint Premium Server";
				break;
			case PRODUCT_MULTIPOINT_STANDARD_SERVER:
				edition = "MultiPoint Standard Server";
				break;
			case PRODUCT_PPI_PRO:
				edition = "Windows for Colaboration";
				break;
			case PRODUCT_PRO_FOR_EDUCATION:
				edition = "Pro for Educationals";
				break;
			case PRODUCT_PRO_WORKSTATION:
				edition = "Workstation Pro";
				break;
			case PRODUCT_PRO_WORKSTATION_N:
				edition = "Workstation Pro N";
				break;
				*/
			case PRODUCT_PROFESSIONAL:
				edition = "Professional";
				break;
			case PRODUCT_PROFESSIONAL_N:
				edition = "Profesional E";
				break;
			case PRODUCT_PROFESSIONAL_E:
				edition = "Undefined";
				break;
				/*
			case PRODUCT_PROFESSIONAL_WMC:
				edition = "Professional with Media Center";
				break;
				*/
			case PRODUCT_SB_SOLUTION_SERVER:
				edition = "Small Business Server Essentials";
				break;
			case PRODUCT_SB_SOLUTION_SERVER_EM:
				edition = "Small Business Server Essentials EM";
				break;
			case PRODUCT_SERVER_FOR_SB_SOLUTIONS:
				edition = "Server for Small Business Solutions";
				break;
			case PRODUCT_SERVER_FOR_SB_SOLUTIONS_EM:
				edition = "Server for Small Business Solutions EM";
				break;
			case PRODUCT_SERVER_FOR_SMALLBUSINESS:
				edition = "Windows Essential Server Solutions";
				break;
			case PRODUCT_SERVER_FOR_SMALLBUSINESS_V:
				edition = "Windows Essential Server Solutions without Hyper-V";
				break;
			case PRODUCT_SERVER_FOUNDATION:
				edition = "Server Foundation";
				break;
				/*
			case PRODUCT_SERVERRDSH:
				edition = "Enterprise for Virtual Deskop";
				break;
				*/
			case PRODUCT_SMALLBUSINESS_SERVER:
				edition = "Windows Small Business Server";
				break;
			case PRODUCT_SMALLBUSINESS_SERVER_PREMIUM:
				edition = "Windows Small Business Server Premium";
				break;
			case PRODUCT_SMALLBUSINESS_SERVER_PREMIUM_CORE:
				edition = "Windows Small Business Server Premium Core";
				break;
			case PRODUCT_SOLUTION_EMBEDDEDSERVER:
				edition = "MultiPoint Embeded Server";
				break;
				/*
			case PRODUCT_STANDARD_EVALUATION_SERVER:
				edition = "Standard Server (Evaluation)";
				break;
				*/
			case PRODUCT_STANDARD_SERVER:
				edition = "Standard Server";
				break;
			case PRODUCT_STANDARD_SERVER_CORE:
				edition = "Standard Server (Core installation)";
				break;
			case PRODUCT_STANDARD_SERVER_CORE_V:
				edition = "Standard Server without Hyper-V (Core installation)";
				break;
			case PRODUCT_STANDARD_SERVER_V:
				edition = "Standard Server without Hyper-V";
				break;
			case PRODUCT_STANDARD_SERVER_SOLUTIONS:
				edition = "Standard Server Premium";
				break;
			case PRODUCT_STANDARD_SERVER_SOLUTIONS_CORE:
				edition = "Standard Server Premium Core";
				break;
			case PRODUCT_STARTER:
				edition = "Starter";
				break;
			case PRODUCT_STARTER_E:
				edition = "Undefined";
				break;
			case PRODUCT_STARTER_N:
				edition = "Starter N";
				break;
			case PRODUCT_STORAGE_ENTERPRISE_SERVER:
				edition = "Enterprise Storage Server";
				break;
			case PRODUCT_STORAGE_ENTERPRISE_SERVER_CORE:
				edition = "Enterprise Storage Server Core";
				break;
			case PRODUCT_STORAGE_EXPRESS_SERVER:
				edition = "Express Storage Server";
				break;
			case PRODUCT_STORAGE_EXPRESS_SERVER_CORE:
				edition = "Express Storage Server Core";
				break;
				/*
			case PRODUCT_STORAGE_STANDARD_EVALUATION_SERVER:
				edition = "Standard Storage Server (Evaluation)";
				break;
				*/
			case PRODUCT_STORAGE_STANDARD_SERVER:
				edition = "Standard Storage Server";
				break;
			case PRODUCT_STORAGE_STANDARD_SERVER_CORE:
				edition = "Standard Storage Server Core";
				break;
				/*
			case PRODUCT_STORAGE_WORKGROUP_EVALUATION_SERVER:
				edition = "Workgroup Storage Server (Evaluation)";
				break;
				*/
			case PRODUCT_STORAGE_WORKGROUP_SERVER:
				edition = "Workgroup Storage Server";
				break;
			case PRODUCT_STORAGE_WORKGROUP_SERVER_CORE:
				edition = "Workgroup Storage Server Core";
				break;
			case PRODUCT_ULTIMATE:
				edition = "Ultimate";
				break;
			case PRODUCT_ULTIMATE_E:
				edition = "Undefined";
				break;
			case PRODUCT_ULTIMATE_N:
				edition = "Ultimate N";
				break;
			case PRODUCT_UNDEFINED:
				edition = "Unknown product";
				break;
			case PRODUCT_WEB_SERVER:
				edition = "Web Server";
				break;
			case PRODUCT_WEB_SERVER_CORE:
				edition = "Web Server (core installation)";
				break;
			}
		}
	}
	else {
		edition = "Unknown";
	}
	s_edition = edition;
}


void UserDirectories::Set_OSVersion_Corresponded_NIT()
{
	// TODO: Добавьте сюда код реализации.
	dwnit_oscorresponded = 0;

	if (dwMajorOS < 6) {
		dwnit_oscorresponded = 0;
		return;
	}
	if (dwMajorOS == 6) {
		switch (dwMinorOS)
		{
		case 0:
		case 2:
			dwnit_oscorresponded = 0;
			break;
		case 1:
			dwnit_oscorresponded = 2 + NIT_CheckProffesionalEdition();
		case 3:
			if (Is64Bit()) {
				dwnit_oscorresponded = 2 + NIT_CheckProffesionalEdition();
			}
			else {
				dwnit_oscorresponded = 0;
			}
			break;
		default:
			dwnit_oscorresponded = 0;
			break;
		}
		return;
	}
	if (dwMajorOS == 10 && dwMinorOS == 0) {
		dwnit_oscorresponded = 2 + NIT_CheckProffesionalEdition();
		return;
	}
	return;
}


// 0 - Corresponded -1 - Partially Corresponded -2 - Not Corresponded
int UserDirectories::NIT_CheckProffesionalEdition()
{
	int iRes = -1;
	size_t found;
	// TODO: Добавьте сюда код реализации.
	string strcorr001 = "Professional";
	string strcorr002 = "Enterprise";
	string strcorr003 = "Ultimate";
	string strcorr004 = "Standard";
	string strcorr005 = "Datacenter";
	string strcorr006 = "Pro";
	string strnone001 = "Basic";
	string strnone002 = "Base";
	string strnone003 = "Starter";

	found = s_edition.find(strcorr001);
	if (found != std::string::npos)
		iRes = 0;

	found = s_edition.find(strcorr002);
	if (found != std::string::npos)
		iRes = 0;

	found = s_edition.find(strcorr003);
	if (found != std::string::npos)
		iRes = 0;

	found = s_edition.find(strcorr004);
	if (found != std::string::npos)
		iRes = 0;

	found = s_edition.find(strcorr005);
	if (found != std::string::npos)
		iRes = 0;

	found = s_edition.find(strcorr006);
	if (found != std::string::npos)
		iRes = 0;

	found = s_edition.find(strnone001);
	if (found != std::string::npos)
		iRes = -2;

	found = s_edition.find(strnone002);
	if (found != std::string::npos)
		iRes = -2;

	found = s_edition.find(strnone003);
	if (found != std::string::npos)
		iRes = -2;

	return iRes;
}


string UserDirectories::GetAntivirusName()
{
	// TODO: Добавьте сюда код реализации.
	// LPCWSTR ant_name;
	std::string antivirus_name;
	if (dwIsWindowsServer == 1) {
		return string("ERROR! No Instance(s) Available.");
	}
	if (dwMajorOS < 6) {
		return string("ERROR! No Instance(s) Available.");
	}
	HRESULT hr = ::CoInitializeSecurity(NULL, -1, NULL, NULL,
		RPC_C_AUTHN_LEVEL_DEFAULT, RPC_C_IMP_LEVEL_IMPERSONATE,
		NULL, EOAC_NONE, NULL);

	CComPtr<IWbemLocator> pWbemLocator;
	hr = pWbemLocator.CoCreateInstance(CLSID_WbemLocator);

	CComPtr<IWbemServices> pWbemServices;
	//’Security Center’ for WMI prior to Windows Vista is: ‘\root\SecurityCenter’
	//’Security Center’ for WMI for Windows Vista and above is: ‘\root\SecurityCenter2’

	hr = pWbemLocator->ConnectServer(CComBSTR(L"root\\SecurityCenter2"), NULL, NULL, 0, NULL, 0, NULL, &pWbemServices);

	CComPtr<IEnumWbemClassObject> pEnum;
	CComBSTR cbsQuery = L"Select * From AntivirusProduct";
	hr = pWbemServices->ExecQuery(CComBSTR(L"WQL"), cbsQuery, WBEM_FLAG_FORWARD_ONLY, NULL, &pEnum);

	ULONG uObjectCount = 0;
	CComPtr<IWbemClassObject> pWmiObject;
	hr = pEnum->Next(WBEM_INFINITE, 1, &pWmiObject, &uObjectCount);

	CComVariant cvtVersion;
	hr = pWmiObject->Get(L"displayName", 0, &cvtVersion, 0, 0);

	// ant_name = CW2A(cvtVersion.bstrVal);
	// antivirus_name = ConvertLPCWSTRToString(ant_name);
	antivirus_name = _com_util::ConvertBSTRToString(cvtVersion.bstrVal);
	return antivirus_name;
}


void UserDirectories::SetAntivirusStatus()
{
	// TODO: Добавьте сюда код реализации.
	size_t found;
	std::string antivirus_name;
	std::string strOKKaspersky = "Kaspersky";
	std::string strOKWinDef = "Windows Defender";
	std::string strNo001 = "ОШИБКА";
	std::string strNo002 = "ERROR";
	std::string strNo003 = "Отсутствуют экземпляры";
	std::string strNo004 = "Missing";
	std::string strNo005 = "No Instance(s) Available";
	dwAntivirusPresent = 3;
	HRESULT hr = ::CoInitializeEx(NULL, COINIT_MULTITHREADED);
	antivirus_name = GetAntivirusName();
	::CoUninitialize();
	// Test
	// std::cerr << antivirus_name << endl;

	if (antivirus_name.empty()) {
		dwAntivirusPresent = 0;
		return;
	}

	found = antivirus_name.find(strNo001);
	if (found != std::string::npos)
	{
		// Error Antivirus Found. Must Return
		dwAntivirusPresent = 0;
		return;
	}

	found = antivirus_name.find(strNo002);
	if (found != std::string::npos)
	{
		// Error Antivirus Found. Must Return
		dwAntivirusPresent = 0;
		return;
	}

	found = antivirus_name.find(strNo003);
	if (found != std::string::npos)
	{
		// Error Antivirus Found. Must Return
		dwAntivirusPresent = 0;
		return;
	}

	found = antivirus_name.find(strNo004);
	if (found != std::string::npos)
	{
		// Error Antivirus Found. Must Return
		dwAntivirusPresent = 0;
		return;
	}

	found = antivirus_name.find(strNo005);
	if (found != std::string::npos)
	{
		// Error Antivirus Found. Must Return
		dwAntivirusPresent = 0;
		return;
	}

	found = antivirus_name.find(strOKWinDef);
	if (found != std::string::npos)
	{
		// May be Windows Defender present. Not Return!
		dwAntivirusPresent = 1;
	}

	found = antivirus_name.find(strOKKaspersky);
	if (found != std::string::npos)
	{
		// Kaspersky Antivirus Present. Not Return
		dwAntivirusPresent = 2;
	}
	return;
}


void UserDirectories::Get_Antivirus_Normal_Test()
{
	// TODO: Добавьте сюда код реализации.
	std::string strAVStatus = "Error! Unknown Error.";
	HRESULT hr = ::CoInitializeEx(NULL, COINIT_MULTITHREADED); // Must be pointed!
	std::string strAVName = GetAntivirusName();
	::CoUninitialize(); //Must be pointed!

	if (dwIsWindowsServer == 1 && dwAntivirusPresent < 2) {
		strAVStatus = "Warning! Antivirus is not Found or Server Operation System.";
	}

	if (dwIsWindowsServer == 0) {
		switch (dwAntivirusPresent)
		{
		case 0:
			strAVStatus = "Success! Antivirus is not Found";
			break;
		case 1:
			if (dwMajorOS == 10) {
				strAVStatus = "Success! Antivirus Windows Defender is found.";
			}
			if (dwMajorOS == 6) {
				strAVStatus = "Warning! Antivirus Windows Defender is found.";
			}
			break;
		case 2:
			strAVStatus = "Warning! Kaspersky Lab Product is installed.";
			break;
		case 3:
			strAVStatus = "Warning! Other Antivirus is Installed";
			break;
		default:
			break;
		}
	}
	if (dwAntivirusPresent == 0)
		printf("\nAntivirus is not found!\n");
	else
		printf("\nFound Antivirus!\n");
	printf("Antivirus Name : %s\nAntivirus Status : %s\n", strAVName.c_str(), strAVStatus.c_str());
}

string UserDirectories::GetCurrentExePath() {

	// TODO
	char pBuff[MAX_PATH + 1];
	DWORD stLen;
	cGetEnvVarsWinExp csEnvVars;
	string strRes;
	
	// Run Payloads
	stLen = csEnvVars.GetCurrentExePath((LPSTR)pBuff);
	if (stLen > 0) {
		strRes = string(pBuff);
		if (IsDirExist(strRes)) {
			return strRes;
		}
		else
			return string("");
	}
	return string("");
}

