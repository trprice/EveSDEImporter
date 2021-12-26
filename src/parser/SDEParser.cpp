#include "SDEParser.h"
#include <fstream>
#include <iostream>
#include <assert.h>

SDEParser::SDEParser(std::vector<char> data)
{
  bytes = data;// will this call a copy constructor for std::vector?
  parseData();

  try {
    logger = spdlog::basic_logger_mt("SDEParser_Logger", "logs/SDEParser_logger.txt");
  }
  catch (const spdlog::spdlog_ex &ex) {
    std::cout << "Log init failed: " << ex.what() << std::endl;
  }
}

SDEParser::SDEParser(std::string fName) : fileName(fName)
{
  readFile();
  parseData();

  try {
    logger = spdlog::basic_logger_mt("SDEParser_Logger", "logs/SDEParser_logger.txt");
  } catch (const spdlog::spdlog_ex &ex) {
    std::cout << "Log init failed: " << ex.what() << std::endl;
  }
}

void SDEParser::readFile()
{
  std::ifstream ifs(fileName, std::ifstream::in );

  if (ifs.is_open()) {
    ifs.seekg(0, std::ifstream::end);
    int length = ifs.tellg();
    ifs.seekg(0, std::ifstream::beg);

    bytes.resize(length);
    ifs.read(&bytes[0], length);
  }
  else {
    logger->error("Could not open a filestream for the input file:");
  }
}

void SDEParser::parseData()
{
    c4::substr data(bytes.data(), bytes.size());
    parsedData = ryml::parse(data);
}