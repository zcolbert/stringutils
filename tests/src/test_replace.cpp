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