#pragma once

#define no_init_all deprecated
#include <iostream>
#include "UserDirectories.h"
#include "Downloads.h"
#include "StartProcess.h"
#include <iostream>

class DownloadAndExecute
{

	// Private Members
private:
	UserDirectories strVar;
	Downloads dnld;

	// Public Members
public:
	// Constructors

	DownloadAndExecute();

	void GetDirectoryAndFile();
	void Download();
	void CopyAndDelete();
	int OpenAndCLose();
	int CheckExclusion();
	int UnzipEicarFile();
};

