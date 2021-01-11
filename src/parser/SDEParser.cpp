#include "SDEParser.h"
#include <fstream>
#include <iostream>
#include <assert.h>

void SDEParser::readFile()
{
  std::ifstream ifs(this->fileName, std::ifstream::in );

  if (ifs.is_open()) {
    ifs.seekg(0, std::ifstream::end);
    int length = ifs.tellg();
    ifs.seekg(0, std::ifstream::beg);

    bytes.resize(length);
    ifs.read(&bytes[0], length);
  }
  else {
    // What?
  }
}

void SDEParser::parseData()
{
    c4::substr data(bytes.data(), bytes.size());
    parsedData = ryml::parse(data);
}