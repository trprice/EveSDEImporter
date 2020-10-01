#pragma once

#include "ryml.hpp"
#include <string>

class SDEParser
{
private:
	std::string fileName;
    ryml::Tree parsedData;

	void readFile();


public:
	SDEParser(std::string fName) : fileName(fName)
	{
          readFile();
	}
};

