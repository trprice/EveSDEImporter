#include "SDEParser.h"
#include <fstream>
#include <iostream>
#include <assert.h>

void SDEParser::readFile()
{
  std::ifstream ifs(this->fileName.c_str(), std::ios::in | std::ios::binary | std::ios::ate);

  ifs.seekg(0, std::ios::end);
  int length = ifs.tellg();
  ifs.seekg(0, std::ios::beg);

  ifs.read(bytes.data(), length - 1);
}

void SDEParser::parseData()
{
    c4::substr data(bytes.data(), bytes.size());
    parsedData = ryml::parse(data);
}