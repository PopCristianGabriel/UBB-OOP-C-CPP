#include "File.h"



FileClass::FileClass(char* filePath)
{
	strcpy(this->filePath,filePath);
}


FileClass::~FileClass()
{
}

void CSVFile::write_to_file(std::vector<evidence> repositorySaves)
{
	std::ofstream file(this->filePath);
	for (evidence evidence : repositorySaves) {
		file << evidence.get_evidence_id() << ", " << evidence.get_evidence_measurement() << ", " << evidence.get_evidence_image_clarity() << ", " << evidence.get_evidence_quantity() << ", " << evidence.get_evidence_photograph() << std::endl;
	}
	file.close();
	LPCTSTR helpFile = this->filePath;
	ShellExecute(NULL, "open", helpFile, NULL, NULL, SW_SHOWNORMAL);
}

void HTMLFile::write_to_file(std::vector<evidence> repositorySaves)
{
	std::ofstream file(this->filePath);
	file << "<!DOCTYPE html>\n";
	file << "	<html>\n";
	file << "		<head>";
	file << "			<title>myList</title>\n";
	file << "		</head>\n";
	file << "		<body>";
	file << "			<table border=\"1\">\n";
	for (evidence evidence : repositorySaves) {
		file << "			<tr>";
		file << "<td>" << evidence.get_evidence_id() << "</td\n>";
		file << "<td>" << evidence.get_evidence_measurement() << "</td\n>";
		file << "<td>" << evidence.get_evidence_image_clarity() << "</td\n>";
		file << "<td>" << evidence.get_evidence_quantity() << "</td\n>";
		file << "<td>" << evidence.get_evidence_photograph() << "</td\n>";
		file << "			</tr>\n";
	}
	file << "</table>";
	file << "</body>";
	file << "</html>";
	file.close();
	LPCTSTR helpFile = this->filePath;
	ShellExecute(NULL, "open", helpFile, NULL, NULL, SW_SHOWNORMAL);
}
