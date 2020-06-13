#pragma once

#include "ryml.hpp"
#include <string>

class SDEParser
{
private:
	std::string fileName;
	std::string fileData;

	void readFile();


public:
	SDEParser(std::string fName) : fileName(fName)
	{
		
	}
};

