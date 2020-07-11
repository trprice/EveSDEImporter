#include "SDEParser.h"
#include <fstream>
#include <vector>

void SDEParser::readFile()
{
	std::ifstream ifs(this->fileName.c_str(), std::ios::in | std::ios::binary | std::ios::ate);

	std::ifstream::pos_type fileSize = ifs.tellg();
	ifs.seekg(0, std::ios::beg);

	std::vector<char> bytes(fileSize);
	ifs.read(bytes.data(), fileSize);

	this->fileData = std::string(bytes.data(), fileSize);
}