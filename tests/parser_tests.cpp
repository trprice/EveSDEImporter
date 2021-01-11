#include <catch2/catch.hpp>

#include "..\src\parser\SDEParser.h"
#include "ryml.hpp"
#include <vector>
#include <string>
#include <iostream>

TEST_CASE("Tests to prove the parsing works")
{
  SECTION("Test a sequence of mappings similar to agtAgentTypes.yaml")
  {
    std::string str = "-   agentType: NonAgent\n    agentTypeID: 1\n-   agentType: BasicAgent\n    agentTypeID: 2";
    std::vector<char> agentTypeData(str.begin(), str.end());

    SDEParser parser(agentTypeData);

    ryml::Tree parsedData = parser.getParsedData();

    // Is this the correct explanation for the size being 7?
    //      1 document
    //      2 sequences
    //      4 mappings
    //      ----------
    //      7 total
    CHECK(parsedData.size() == 7);

    // My understanding is that the above document should be a sequence of maps. Testing the tree object for is_seq() doesn't compile. Possibly because the is_XXX() functions have to be run on a NodeRef.
    REQUIRE(parsedData[0].is_map());

    ryml::NodeRef node = parsedData;// Take the root
    CHECK(node.is_seq());// As a node this is a squence.

    CHECK(node[0].is_map());
    CHECK(node[0]["agentType"].is_keyval());
    CHECK(node[0]["agentType"].has_val());
    CHECK(node[0]["agentType"].val() == "NonAgent");

    CHECK(node[1].is_map());
    CHECK(node[1]["agentType"].is_keyval());
    CHECK(node[1]["agentType"].has_val());
    CHECK(node[1]["agentType"].val() == "BasicAgent");
  }

  SECTION("Test a sequence of mappings similar to agtAgent.yaml")
  {
    std::string str = "-   agentID: 3008416\n    agentTypeID : 2\n    corporationID : 1000002\n    divisionID : 22\n    isLocator : false\n    level : 1\n    locationID : 60000004\n    quality : 20\n-   agentID : 3008417\n    agentTypeID : 2\n    corporationID : 1000002\n    divisionID : 22\n    isLocator : false\n    level : 1\n    locationID : 60000259\n    quality : 20";
    std::vector<char> data(str.begin(), str.end());
    SDEParser parser(data);

    ryml::Tree parsedData = parser.getParsedData();

    //      1 document
    //      2 sequences
    //      16 mappings
    //      ----------
    //      19 total
    CHECK(parsedData.size() == 19);

    ryml::NodeRef node = parsedData;// Take the root
    CHECK(node.is_seq());// As a node this is a squence.

    CHECK(node[0].is_map());
    CHECK(node[0]["agentID"].is_keyval());
    CHECK(node[0]["agentID"].has_val());
    CHECK(node[0]["agentID"].val() == "3008416");

    CHECK(node[1].is_map());
    CHECK(node[1]["agentID"].val() == "3008417");
  }

  SECTION("Test Parsing A File")
  {
    std::string fileName = "F:\\development\\EveSDEImporter\\testData\\agtAgentTypes.yaml";
    SDEParser parser(fileName);

    ryml::Tree parsedData = parser.getParsedData();

    CHECK(parsedData.size() == 37);
  }
}