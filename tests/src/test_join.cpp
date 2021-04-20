#include "../include/catch_amalgamated.hpp"
#include "../../stringutils.h"


SCENARIO("A vector of strings is joined by an optional delimiter", "[join]")
{
    GIVEN("A vector containing strings")
    {
        std::vector<std::string> parts = {"First", "Second", "Third"};

        WHEN("A delimiter is not given") {
            std::string expected = "FirstSecondThird";

            THEN("The strings are concatenated together") {
                REQUIRE(join(parts) == expected);
            }
        }
        WHEN ("A single character is given as a delimiter") {
            std::string expected = "First-Second-Third";

            THEN("The strings are joined by the delimiter character") {
                REQUIRE(join(parts, '-') == expected);
            }
        }
        WHEN ("A string is given as a delimiter") {
            std::string expected = "First, Second, Third";

            THEN("The strings are joined by the delimiting substring") {
                REQUIRE(join(parts, ", ") == expected);
            }
        }
    }
}

