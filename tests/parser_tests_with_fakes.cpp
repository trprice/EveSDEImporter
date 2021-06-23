#include <catch2/catch.hpp>
#include "fff.h"
#include "../src/parser/SDEParser.h"
#include <vector>
#include <string>
#include <iostream>

TEST_CASE("Try Parser With Fakes")
{
    SECTION("Test")
    {
      std::string str = "-   agentType: NonAgent\n    agentTypeID: 1\n-   agentType: BasicAgent\n    agentTypeID: 2";
      std::vector<char> agentTypeData(str.begin(), str.end());

      SDEParser parser(agentTypeData);
    }
}
