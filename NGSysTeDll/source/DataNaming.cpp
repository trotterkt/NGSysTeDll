#include <time.h>
#include <stdlib.h>  
#include "include\DataNaming.h"

DataNaming::DataNaming(void)
{
	// :TODO: need to decide if use of environment variable should be applicable to
	// NGSysTE
	char* ngSysTeLoggingPathPtr;

	size_t requiredSize;

	getenv_s(&requiredSize, NULL, 0, "NGSysTE_Logging");
	if (requiredSize == 0)
	{
		printf("NGSysTE_Logging doesn't exist!\n");
		exit(1);
	}

	ngSysTeLoggingPathPtr = (char*)malloc(requiredSize * sizeof(char));
	if (!ngSysTeLoggingPathPtr)
	{
		printf("Failed to allocate memory!\n");
		exit(1);
		//:TODO: throw exceptions - except not recommended in constructor
	}

	// Get the value of the LIB environment variable.
	getenv_s(&requiredSize, ngSysTeLoggingPathPtr, requiredSize, "NGSysTE_Logging");


	//:TODO: normal call
	//setBaseFileName();
	myBaseInFileName = "301_2016_07_19_09_58_48_000_27_52_TEST"; // temp debugging
	myBaseOutFileName = "ste"; // temp debugging
}


DataNaming::~DataNaming(void)
{
}

void DataNaming::getDataLogOutFileName(std::string& fullName)
{
	fullName.clear();

	// make this more robust with booste::filesytem library
	fullName.append(myBaseDirectory);

	// :TODO: according to whatever the specified base filename format is...
	fullName.append(myBaseOutFileName);
	//fullName.append("ste");

	fullName.append(".log");

	// dont set if zero
	if(!myBaseOutFileName.length())
	{
		fullName.clear();
	}
}

void DataNaming::setBaseInFileName()
{
	time_t rawtime;
    struct tm timeinfo;
	errno_t err;

     _time64 (&rawtime);
     err = _localtime64_s (&timeinfo, &rawtime);
	 if (err)
	 {
		 printf("Invalid argument to _localtime64_s.");
		 exit(1);
	 }

	 // :TODO: according to whatever the specified base filename format is...
	 std::ostringstream timeBuffer;
	 timeBuffer << timeinfo.tm_year << "_"
		        << timeinfo.tm_mon << "_"
				<< timeinfo.tm_mday << "_"
				<< timeinfo.tm_hour << "_"
				<< timeinfo.tm_min << "_"
				<< timeinfo.tm_sec;
	// based on system date
	myBaseInFileName = timeBuffer.str();
}

void DataNaming::setBaseOutFileName()
{
	time_t rawtime;
	struct tm timeinfo;
	errno_t err;

	_time64(&rawtime);
	err = _localtime64_s(&timeinfo, &rawtime);
	if (err)
	{
		printf("Invalid argument to _localtime64_s.");
		exit(1);
	}

	// :TODO: according to whatever the specified base filename format is...
	std::ostringstream timeBuffer;
	timeBuffer << timeinfo.tm_year << "_"
		<< timeinfo.tm_mon << "_"
		<< timeinfo.tm_mday << "_"
		<< timeinfo.tm_hour << "_"
		<< timeinfo.tm_min << "_"
		<< timeinfo.tm_sec;
	// based on system date
	myBaseOutFileName = timeBuffer.str();
}
void DataNaming::getDataLogInFileName(std::string& fullName)
{
	fullName.clear();

	// make this more robust with booste::filesytem library
	fullName.append(myBaseDirectory);

	// :TODO: according to whatever the specified base filename format is...
	fullName.append("301_2016_07_19_09_58_48_000_27_52_TEST"); // :TODO: temp debug

	fullName.append(".log");

	// dont set if zero
	if(!myBaseInFileName.length())
	{
		fullName.clear();
	}
}

void DataNaming::getExcelDataLogFileName(std::string& fullName)
{
	fullName.clear();

	// make this more robust with booste::filesytem library
	fullName.append(myBaseDirectory);

	// :TODO: according to whatever the specified base filename format is...
	fullName.append(myBaseOutFileName); 

	// dont set if zero
	if(!myBaseOutFileName.length())
	{
		fullName.clear();
	}

	fullName.append(".csv");
}

