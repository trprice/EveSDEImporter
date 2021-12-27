#include "SDEParser.h"
#include <fstream>
#include <iostream>
#include <assert.h>

SDEParser::SDEParser(std::vector<char> data)
{
  try {
    logger = spdlog::basic_logger_mt("SDEParser_Logger", "logs/SDEParser_logger.txt");
    logger->set_level(spdlog::level::debug);
  }
  catch (const spdlog::spdlog_ex &ex) {
    std::cout << "Log init failed: " << ex.what() << std::endl;
  }

  bytes = data;// will this call a copy constructor for std::vector?
  parseData();
}

SDEParser::SDEParser(std::string fName) : fileName(fName)
{
  try {
    logger = spdlog::basic_logger_mt("SDEParser_Logger", "logs/SDEParser_logger.txt");
    logger->set_level(spdlog::level::debug);
  } catch (const spdlog::spdlog_ex &ex) {
    std::cout << "Log init failed: " << ex.what() << std::endl;
  }

  logger->debug("Parsing the following file: {}", fileName);
  readFile();
  parseData();
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

    logger->debug("Read {} bytes from {}", length, fileName);
  }
  else {
    logger->error("Could not open a filestream for the input file: {}", fileName);
  }
}

void SDEParser::parseData()
{
    c4::substr data(bytes.data(), bytes.size());
    parsedData = ryml::parse(data);
}