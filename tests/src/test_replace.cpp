#include "../include/catch_amalgamated.hpp"
#include "../../stringutils.h"


SCENARIO("All instances of a character within a string are replaced with a new character.", "[replace]") {

    GIVEN ("A string, an existing character, and a replacement character") {

        WHEN ("The string is empty") {
            std::string orig;
            THEN ("An empty string is returned") {
                REQUIRE(replace(orig, 'x', 'y') == orig);
            }
        }
        WHEN ("The target character does not exist in the string") {
            std::string orig = "Some text";
            THEN ("The original string is returned") {
                REQUIRE(replace(orig, '-', '.') == orig);
            }
        }
        WHEN ("The target character exists in the string") {
            std::string orig = "xSome xx textx";
            THEN ("The target character is replaced wit the new character") {
                std::string expected = "ySome yy teyty";
                REQUIRE(replace(orig, 'x', 'y') == expected);
            }
        }
    }
}
SCENARIO("All instances of a substring within a string are replaced by a new substring") {
    GIVEN("A string, an existing substring, and a replacement substring") {

        WHEN("The string is empty") {
            std::string orig;
            THEN("An empty string is returned") {
                REQUIRE(replace(orig, "sub1", "sub2").empty());
            }
        }
        WHEN("The string does not contain the target substring") {
            std::string orig = "Some text";
            THEN("The original string is returned") {
                REQUIRE(replace(orig, "sub1", "sub2") == orig);
            }
        }
        WHEN("The string contains the substring") {
            std::string orig = "sub1Some sub1sub1 textsub1";
            THEN("The target substring is replaced by the new substring") {
                std::string expected = "newSome newnew textnew";
                REQUIRE(replace(orig, "sub1", "new") == expected);
            }
        }
    }
}