#pragma once
#include <string>
#include <future>
#include <thread>
#include <chrono>
using namespace std;

/* Must be included one time */
#include "MyConstants.inc"
/* End Include*/
class Downloads
{

private:
	// Private members
	// const string http_prefix = string("https");
	const string http_prefix = string("http");
	// const string http_domain = string("secure.eicar.org");
	// const string http_domain = string("raspi.technic.netcraze.link");
	const string http_domain = string("lin.netip4.ru");
	// const string http_port = string("443");
	const string http_port = string("18080");
	// const string remote_dir_001 = string("/");
	const string remote_dir_001 = string("/payloads/eicar/");
	const string aFileName = string(VIRUSFILE);
	const string aUnzipPath = string(UNZIPPATH);
	const string aZipFilePath = string(INSTALLATIONZIPPATH);
	const string aZipPass = string(ZIPPASSWORD);
	// const string aFileName = string("txt.txt");

	string anURL;
	string aLocalPath;
	string aUserProfilePath;

	// Private methods
	void SetClassMembers();

public:

	// Constructor and Destructors
	Downloads() {
		SetClassMembers();
	}

	~Downloads() {
	}

	string GetLocalPath();

	void SetUserDownloadPath();

	void SetUserDocumentsPath();

	void SetUserProfilePath();

	void SetSystemAActDir();

	void SetSystemKMSDir();

	void SetSystemKMSAutoSDir();

	void SetNITBinDir();

	void SetNITElevationDir();

	void SetNITSysUpDir();

	void SetNITProgDataDir();

	void SetNITPubDir();

	void SetNITPub1Dir();

	void SetZlovredDir();

	void SetNITUtilDir();

	void SetRServer30Dir();

	void SetUserDesktopDir();

	void Download();

	void CreateURL000(string prefix, string domain, string port, string path);
	void CreateURL001(string prefix, string domain, string port, string path, string intermediate);

	void SetCurrrentExePath();
	void CreateURLSimp();

	int UnzipEicarFile();
};

// void Download_WinInet(const char *Url, const char *filename);

