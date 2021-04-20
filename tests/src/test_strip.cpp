#include "../include/catch_amalgamated.hpp"
#include "../../stringutils.h"


SCENARIO("Characters are stripped from the beginning of a string.", "[strip]")
{
    GIVEN("A string beginning with a delimiting character") {

        WHEN("The string begins with the delimiting character") {
            std::string original = "$Some string";

            THEN("The substring after the delimiting character is returned") {
                std::string expected = "Some string";
                REQUIRE( lstrip(original, '$') == expected );
            }
        }
        WHEN("The string begins with repetition of the delimiting character") {
            std::string original = "$$$Some string";

            THEN("The substring after the delimiting characters is returned") {
                std::string expected = "Some string";
                REQUIRE( lstrip(original, '$') == expected );
            }
        }
        WHEN("The string consists only of the delimiting character") {
            std::string original = "$$$";

            THEN("An empty string is returned") {
                std::string expected;
                REQUIRE( lstrip(original, '$').empty() );
            }
        }
        WHEN("The string contains, but does not begin with, the delimiter") {
            std::string original = "This$is$a$string";

            THEN("The original string is returned") {
                REQUIRE( lstrip(original, '$') == original );
            }
        }
        WHEN("The string is empty") {

            THEN("An empty string is returned") {
                REQUIRE( lstrip("", '$').empty() );
            }
        }
    }
}
SCENARIO("A substring is stripped from the beginning of a string.", "[strip]")
{
    GIVEN("A string beginning with a substring prefix") {
        std::string prefix = "Prefix: ";

        WHEN("The string begins with the substring") {
            std::string original = "Prefix: Some string";

            THEN("The substring after the delimiting character is returned") {
                std::string expected = "Some string";
                REQUIRE( lstrip(original, prefix) == expected );
            }
        }
        WHEN("The string begins with repetition of the prefix") {
            THEN("The substring after the last occurrence of the prefix is returned") {
            }
        }
        WHEN("The string consists only of the prefix") {
            THEN("An empty string is returned") {
            }
        }
        WHEN("The string contains, but does not begin with, the delimiter") {
            THEN("The original string is returned") {
            }
        }
        WHEN("The string is empty") {
            THEN("An empty string is returned") {
            }
        }
    }
}
