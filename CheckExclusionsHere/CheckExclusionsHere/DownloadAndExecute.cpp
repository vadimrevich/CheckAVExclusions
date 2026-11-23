#include "DownloadAndExecute.h"
#include <exception>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

namespace fs = std::experimental::filesystem;

DownloadAndExecute::DownloadAndExecute() {

	// TODO
	dnld.SetCurrrentExePath();
	dnld.CreateURLSimp();
}

void DownloadAndExecute::GetDirectoryAndFile() {
	
	// TODO
	string currDir = dnld.GetLocalPath();
	std::cout << "A current Exe file full path: " << currDir << std::endl;
}

void DownloadAndExecute::Download()
{
	// TODO: Добавьте сюда код реализации.
	dnld.Download();
	// string currDir = dnld.GetLocalPath();
	// std::cout << "A current Exe file full path: " << currDir << std::endl;
}


void DownloadAndExecute::CopyAndDelete()
{
	// TODO: Добавьте сюда код реализации.
	string currDir = dnld.GetLocalPath();
	string destDir = currDir + string(".tmp");
	cGetEnvVarsWinExp cstrVar;

	if (cstrVar.IsFileExist(currDir)) {
		fs::path sourceFile = currDir.c_str();
		fs::path targetFile = destDir.c_str();

		try {
			fs::copy_file(sourceFile, targetFile, fs::copy_options::overwrite_existing);
			fs::remove(targetFile);
		}
		catch (std::exception e) {
			// std::cerr << e.what() << std::endl;
		}
	}
}


int DownloadAndExecute::OpenAndCLose()
{
	// TODO: Добавьте сюда код реализации.
	cGetEnvVarsWinExp cstrVar;
	string str = string("");
	string filePath = dnld.GetLocalPath();

	// Run Payloads
	if (cstrVar.IsFileExist(filePath)) {
		ifstream file(filePath);
		
		if (!file.is_open()) {
			// Test
			// std::cerr << "Failed to open file: " << filePath << std::endl;

			return 1;
		}

		// Read the file line by line into a string
		string line;
		while (getline(file, line)) {

			// Test
			// cout << line << endl;
			str = str + line + string("\n");
		}

		// Close the file
		file.close();

		return 0;
	}
	else {

		// Test
		// std::cerr << "Failed to find file: " << filePath << std::endl;
		return 1;
	}

}


int DownloadAndExecute::CheckExclusion()
{
	// TODO: Добавьте сюда код реализации.
	cGetEnvVarsWinExp cstrVar;
	int iRes = 0;
	int iSleep = 90; //1,5 Minutes

	// Run Payloads
	// Download();
	iRes = UnzipEicarFile();
	if (iRes > 0)
		return 2;
	iRes = 0;
	CopyAndDelete();
	iRes = OpenAndCLose();

	if (iRes > 0)
		return 1;
	Sleep(iSleep);
	if (cstrVar.IsFileExist(dnld.GetLocalPath()))
		return 0;
	else
		return 1;
}


int DownloadAndExecute::UnzipEicarFile()
{
	// TODO: Добавьте сюда код реализации.
	
	return dnld.UnzipEicarFile();
}
