#pragma once

#include "ryml.hpp"
#include <string>
#include <vector>
#include "spdlog/sinks/basic_file_sink.h"

class SDEParser
{
private:
	std::string fileName;
    std::vector<char> bytes;
    ryml::Tree parsedData;
    std::shared_ptr<spdlog::logger> logger;

	void readFile();


public:
    void parseData();

	// Exists for the sake of being able to test without setting a file name.
	//		If we really need this for other purposes, create either:
	//			1. A setFile() type routine
	//			2. A version of readFile() that takes a file name.
    SDEParser(std::vector<char> data);

	SDEParser(std::string fName);

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

