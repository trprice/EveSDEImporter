#include <catch2/catch.hpp>
#include "../src/parser/SDEParser.h"
#include <vector>
#include <string>
#include <iostream>
#include "fff.h"

DEFINE_FFF_GLOBALS;

FAKE_VALUE_FUNC(c4::yml::Tree, parse, c4::substr);

TEST_CASE("Try Parser With Fakes")
{
    SECTION("Test")
    {
        RESET_FAKE(parse);

        std::string str = "-   agentType: NonAgent\n    agentTypeID: 1\n-   agentType: BasicAgent\n    agentTypeID: 2";
        std::vector<char> agentTypeData(str.begin(), str.end());

        SDEParser parser(agentTypeData);

        CHECK(parse_fake.call_count == 1);
    }
}
