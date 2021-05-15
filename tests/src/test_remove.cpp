#include "../include/catch_amalgamated.hpp"
#include "../../stringutils.h"

SCENARIO("A specified character is removed from the given string") {

    GIVEN("A string and a target character") {

        WHEN("The string is empty") {
            std::string orig;
            THEN("An empty string is returned") {
                REQUIRE(remove(orig, 'x').empty());
            }
        }
        WHEN("The string does not contain the target character") {
            std::string orig = "Some text";
            THEN("The original string is returned") {
                REQUIRE(remove(orig, '?') == orig);
            }
        }
        WHEN("The string contains the target character") {
            std::string orig = "?Some ?? text?";
            THEN("The character is removed from the string") {
                std::string expected = "Some  text";
                REQUIRE(remove(orig, '?') == expected);
            }
        }
    }

}