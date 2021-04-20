#include "../include/catch_amalgamated.hpp"
#include "../../stringutils.h"


SCENARIO("Characters are stripped from the beginning of a string.", "[strip][lstrip]")
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
SCENARIO("A prefix substring is stripped from the beginning of a string.", "[strip][lstrip]")
{
    GIVEN("A string beginning with a substring prefix") {
        std::string prefix = "Prefix: ";

        WHEN("The string begins with the prefix") {
            std::string original = "Some string";
            std::string combined = prefix + original;
            THEN("The substring after the delimiting character is returned") {
                REQUIRE( lstrip(combined, prefix) == original );
            }
        }
        WHEN("The string begins with repetition of the prefix") {
            std::string original = "Some string";
            std::string combined = prefix + prefix + prefix + original;
            THEN("The substring after the last occurrence of the prefix is returned") {
                REQUIRE( lstrip(combined, prefix) == original );
            }
        }
        WHEN("The string consists only of the prefix") {
            THEN("An empty string is returned") {
                REQUIRE( lstrip(prefix + prefix, prefix).empty() );
            }
        }
        WHEN("The string contains, but does not begin with, the delimiter") {
            std::string original = "Some " + prefix + "string";
            THEN("The original string is returned") {
                REQUIRE( lstrip(original, prefix) == original );
            }
        }
        WHEN("The prefix substring is empty") {
            std::string original = "Some string";
            THEN("The original string is returned") {
                REQUIRE( lstrip(original, "") == original );
            }
        }
        WHEN("The string is empty") {
            THEN("An empty string is returned") {
                REQUIRE( lstrip("", prefix).empty() );
            }
        }
    }
}
SCENARIO("Whitespace is removed from the beginning of a string", "[strip][lstrip]")
{
    GIVEN("A string beginning with whitespace characters") {

        WHEN("The string contains, but does not begin with whitespace characters") {
            std::string original = "A string\twith\nwhitespace";
            THEN("The original string is returned") {
                REQUIRE( lstrip(original) == original );
            }
        }
        WHEN("The string consists only of whitespace characters") {
            THEN("An empty string is returned") {
                REQUIRE( lstrip("\t \n \t").empty() );
            }
        }
        WHEN("The string is empty") {
            THEN("An empty string is returned") {
                REQUIRE( lstrip("").empty() );
            }
        }
        WHEN("The string begins with a single space") {
            std::string original = " A string";
            THEN("The substring after the space is returned") {
                std::string expected = "A string";
                REQUIRE( lstrip(original) == expected );
            }
        }
        WHEN("The string begins with consecutive spaces") {
            std::string original = "      A string";
            THEN("The substring after the last leading space is returned") {
                std::string expected = "A string";
                REQUIRE( lstrip(original) == expected );
            }
        }
        WHEN("The string begins with a single tab") {
            std::string original = "\tA string";
            THEN("The substring after the tab is returned") {
                std::string expected = "A string";
                REQUIRE( lstrip(original) == expected );
            }
        }
        WHEN("The string begins with consecutive tabs") {
            std::string original = "\t\t\tA string";
            THEN("The substring after the last leading tab is returned") {
                std::string expected = "A string";
                REQUIRE( lstrip(original) == expected );
            }
        }
        WHEN("The string begins with a single newline") {
            std::string original = "\nA string";
            THEN("The substring following the newline is returned") {
                std::string expected = "A string";
                REQUIRE( lstrip(original) == expected );
            }
        }
        WHEN("The string begins with consecutive newlines") {
            std::string original = "\n\n\nA string";
            THEN("The substring following the last leading newline is returned") {
                std::string expected = "A string";
                REQUIRE( lstrip(original) == expected );
            }
        }
        WHEN("The string begins with a combination of whitespace characters") {
            std::string original = " \n\t \t \nA string";
            THEN("The substring beginning with the first non-whitespace character is returned") {
                std::string expected = "A string";
                REQUIRE( lstrip(original) == expected );
            }
        }
    }
}
