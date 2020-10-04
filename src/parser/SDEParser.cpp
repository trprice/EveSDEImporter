#include "SDEParser.h"
#include <fstream>
#include <vector>
#include <iostream>

void SDEParser::readFile()
{
	std::ifstream ifs(this->fileName.c_str(), std::ios::in | std::ios::binary | std::ios::ate);

	ifs.seekg(0, std::ios::end);
	int length = ifs.tellg();
	ifs.seekg(0, std::ios::beg);

	std::vector<char> bytes(length);
    ifs.read(bytes.data(), length-1);

	c4::substr data(bytes.data(), bytes.size());

	std::cout << data.data() << std::endl;

	parsedData = ryml::parse(data);

	ryml::NodeRef node = parsedData["agentType: NonAgent"];
    std::cout << node.key() << ": " << node.val() << std::endl;
}