#pragma once
#include <vector>
#include <string.h>
#include "evidence.h"
#include <fstream>
#include <windows.h>
class FileClass
{
protected:
	char filePath[200];

public:
	FileClass(char* filePath);
	~FileClass();
	virtual void write_to_file(std::vector<evidence> repository) = 0;
};


class CSVFile : public FileClass {
public:
	CSVFile(char* filePath) : FileClass(filePath) {};
	virtual void write_to_file(std::vector<evidence> repository) override;
};

class HTMLFile : public FileClass {
public:
	HTMLFile(char* filePath) : FileClass(filePath) {};
	virtual void write_to_file(std::vector<evidence> repository) override;
};




