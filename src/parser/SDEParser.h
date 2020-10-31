#pragma once

#include "ryml.hpp"
#include <string>
#include <vector>

class SDEParser
{
private:
	std::string fileName;
    std::vector<char> bytes;
    ryml::Tree parsedData;

	void readFile();


public:
    void parseData();

	// Exists for the sake of being able to test without setting a file name.
	//		If we really need this for other purposes, create either:
	//			1. A setFile() type routine
	//			2. A version of readFile() that takes a file name.
	SDEParser(std::vector<char> data) {
          bytes = data; // will this call a copy constructor for std::vector?
          parseData();
	}

	SDEParser(std::string fName) : fileName(fName)
	{
          readFile();
          parseData();
	}

	ryml::Tree getParsedData() {
          return parsedData;
	}

	// Return the keys of the map for the first item so that a schema can be created.
	// <schema type> GenerateSchema()
	//
	//		How do we send back all of the fields?
	//			A vector<std::string>?
	//			A templated object?
	
	// Return the values so that they can be inserted into the database.
	// vector<objects to hold values> GetValues()
};

