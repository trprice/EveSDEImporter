#include <catch2/catch.hpp>

#include "..\src\parser\SDEParser.h"
#include "ryml.hpp"
#include <vector>
#include <string>

TEST_CASE("Tests to prove the parsing works")
{
  SECTION("Test a sequence of mappings similar to agtAgentTypes.yaml")
  {
    std::string str = "-   agentType: NonAgent\n    agentTypeID: 1\n-   agentType: BasicAgent\n    agentTypeID: 2";
    std::vector<char> data(str.begin(), str.end());

    SDEParser parser(data);

    ryml::Tree parsedData = parser.getParsedData();

    // Why is the size == 7 instead of 2 sequences?
    CHECK( parsedData.size() == 2 );

    REQUIRE(parsedData[0].is_seq());
  }
}