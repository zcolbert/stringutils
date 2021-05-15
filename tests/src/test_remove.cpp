#include "../include/catch_amalgamated.hpp"
#include "../../stringutils.h"

SCENARIO("A specified character is removed from the given string", "[remove]") {

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
SCENARIO("A specified substring is removed from the given string", "[remove]") {

    GIVEN("A string, and a target substring") {

        WHEN("The string is empty") {
            std::string orig;
            THEN("An empty string is returned") {
                REQUIRE(remove(orig, "something").empty());
            }
        }
        WHEN("The substring is empty") {
            std::string orig = "Some text";
            THEN("The original string is returned") {
                REQUIRE(remove(orig, "") == orig);
            }
        }
        WHEN("The string does not contain the substring") {
            std::string orig = "Some text";
            THEN("The original string is returned") {
                REQUIRE(remove(orig, "notincluded") == orig);
            }
        }
        WHEN("The string contains the substring") {
            std::string orig = "subSome subsub textsub";
            THEN("The substring is removed from the string") {
                std::string expected = "Some  text";
                REQUIRE(remove(orig, "sub") == expected);
            }
        }
    }
}