#include "../include/catch_amalgamated.hpp"
#include "../../stringutils.h"


SCENARIO("Whitespace is removed from the beginning of a string", "[strip][lstrip]")
{
    GIVEN("A string") {

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
        WHEN("The string does not contain whitespace") {
            std::string original = "Sometextwithoutspaces";
            THEN("The original string is returned") {
                REQUIRE( lstrip(original) == original );
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
SCENARIO("Characters are stripped from the beginning of a string.", "[strip][lstrip]")
{
    GIVEN("A string, and a prefix character") {

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
        WHEN("The string does not contain the delimiter") {
            std::string original = "Some text";
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
    GIVEN("A string, and a prefix substring") {
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
        WHEN("The string does not contain the substring") {
            std::string original = "Some text";
            THEN("The original string is returned") {
                REQUIRE( lstrip(original, "notintheoriginal") == original );
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
SCENARIO("Whitespace is removed from the end of a string", "[strip][rstrip]")
{
    GIVEN("A string") {

        WHEN("The string contains, but does not end with whitespace characters") {
            std::string original = " A string\tcontaining\nwhitespace";
            THEN("The original string is returned") {
                REQUIRE( rstrip(original) == original );
            }
        }
        WHEN("The string consists only of whitespace characters") {
            THEN("An empty string is returned") {
                REQUIRE( rstrip(" \t\n \t\n").empty() );
            }
        }
        WHEN("The string is empty") {
            THEN("An empty string is returned") {
                REQUIRE( rstrip("").empty() );
            }
        }
        WHEN("The string does not contain whitespace") {
            std::string original = "Sometextwithoutspaces";
            THEN("The original string is returned") {
                REQUIRE( rstrip(original) == original );
            }
        }
        WHEN("The string ends with a single space") {
            std::string original = "Some text";
            THEN("The substring before the first trailing space is returned") {
                REQUIRE( rstrip(original + ' ') == original );
            }
        }
        WHEN("The string ends with consecutive spaces") {
            std::string original = "Some text";
            THEN("The substring before the first trailing space is returned") {
                REQUIRE( rstrip(original + ' ' + ' ') == original );
            }
        }
        WHEN("The string ends with a single tab") {
            std::string original = "Some text";
            THEN("The substring before the first trailing tab is returned") {
                REQUIRE( rstrip(original + '\t') == original );
            }
        }
        WHEN("The string ends with consecutive tabs") {
            std::string original = "Some text";
            THEN("The substring before the first trailing tab is returned") {
                REQUIRE( rstrip(original + '\t' + '\t') == original );
            }
        }
        WHEN("The string ends with a single newline") {
            std::string original = "Some text";
            THEN("The substring before the newline is returned") {
                REQUIRE( rstrip(original + '\n') == original );
            }
        }
        WHEN("The string ends with consecutive newlines") {
            std::string original = "Some text";
            THEN("The substring before the first trailing newline is returned") {
                REQUIRE( rstrip(original + '\n' + '\n') == original );
            }
        }
        WHEN("The string ends with a combination of whitespace characters") {
            std::string original = "Some text \t \n\n \t\n";
            std::string expected = "Some text";
            THEN("The substring ending with the first trailing whitespace character is returned") {
                REQUIRE(rstrip(original) == expected );
            }
        }
    }
}
SCENARIO("Characters are stripped from the end of a string.", "[strip][rstrip]")
{
    GIVEN("A string, and a suffix character") {

        WHEN("The string ends with the delimiting character") {
            std::string original = "Some text";
            THEN("The substring before the first occurrence of the trailing character is returned") {
                REQUIRE( rstrip(original+'$', '$') == original );
            }
        }
        WHEN("The string ends with repetition of the delimiting character") {
            std::string original = "Some text";
            std::string suffix = "$$$";
            THEN("The substring before the first occurrence of the trailing character is returned") {
                REQUIRE( rstrip(original+suffix, '$') == original );
            }
        }
        WHEN("The string consists only of the delimiting character") {
            THEN("An empty string is returned") {
                REQUIRE( rstrip("$$$", '$').empty() );
            }
        }
        WHEN("The string does not contain the delimiting character") {
            std::string original = "Some text";
            THEN("The original string is returned") {
                REQUIRE( rstrip(original, '$') == original );
            }
        }
        WHEN("The string contains, but does not end with, the delimiter") {
            std::string original = "$Some $$ text";
            THEN("The original string is returned") {
                REQUIRE( rstrip(original, '$') == original );
            }
        }
        WHEN("The string is empty") {
            THEN("An empty string is returned") {
                REQUIRE( rstrip("", '$').empty() );
            }
        }
    }
}
SCENARIO("A suffix substring is stripped from the end of a string.", "[strip][rstrip]")
{
    GIVEN("A string, and a suffix substring") {
        std::string suffix = " - Suffix";

        WHEN("The string ends with the suffix") {
            std::string original = "Some text";
            std::string appended = original + suffix;
            THEN("The substring before the first occurrence of the suffix is returned") {
                REQUIRE( rstrip(appended, suffix) == original );
            }
        }
        WHEN("The string ends with repetition of the suffix") {
            std::string original = "Some text";
            std::string appended = original + suffix + suffix + suffix;
            THEN("The substring before the first occurrence of the suffix is returned") {
                REQUIRE( rstrip(appended, suffix) == original );
            }
        }
        WHEN("The string consists only of the suffix") {
            THEN("An empty string is returned") {
                REQUIRE( rstrip(suffix+suffix, suffix).empty() );
            }
        }
        WHEN("The string contains, but does not end with, the suffix") {
            std::string original = "Some " + suffix + " text";
            THEN("The original string is returned") {
                REQUIRE( rstrip(original, suffix) == original );
            }
        }
        WHEN("The string does not contain the substring") {
            std::string original = "Some text";
            THEN("The original string is returned") {
                REQUIRE( rstrip(original, "notintheoriginal") == original );
            }
        }
        WHEN("The suffix substring is empty") {
            std::string original = "Some text";
            THEN("The original string is returned") {
                REQUIRE( rstrip(original, "") == original );
            }
        }
        WHEN("The string is empty") {
            THEN("An empty string is returned") {
                REQUIRE( rstrip("", suffix).empty() );
            }
        }
    }
}
SCENARIO("Whitespace is stripped from the beginning and end of a string", "[strip]")
{
    GIVEN("A string")
    {
        WHEN("The string begins with whitespace"){
            std::string original = " \t\n Some text";
            THEN("The substring after the whitespace is returned") {
                REQUIRE( strip(original) == "Some text" );
            }
        }
        WHEN("The string ends with whitespace") {
            std::string original = "Some text \t\n";
            THEN("The substring before the whitespace is returned") {
                REQUIRE( strip(original) == "Some text" );
            }
        }
        WHEN("The string begins and ends with whitespace") {
            std::string original = " \t\nSome text\t \n";
            THEN("The substring between leading and trailing whitespace is returned") {
                REQUIRE( strip(original) == "Some text" );
            }
        }
        WHEN("The string contains, but does not begin or end with, whitespace") {
            std::string original = "Some text\twith\nspace";
            THEN("The original string is returned") {
                REQUIRE( strip(original) == original );
            }
        }
        WHEN("The string contains no whitespace") {
            std::string original = "Sometextwithoutspaces";
            THEN("The original string is returned") {
                REQUIRE( strip(original) == original );
            }
        }
        WHEN("The string is empty") {
            THEN("An empty string is returned") {
                REQUIRE( strip("").empty() );
            }
        }
    }
}
SCENARIO("A character is stripped from the beginning and end of a string.", "[strip]")
{
    GIVEN("A string, and a prefix/suffix character") {

        WHEN("The string begins with the delimiting character") {
            std::string original = "Some text";
            THEN("The substring after the last occurrence of the leading character is returned") {
                REQUIRE( strip('$'+original, '$') == original );
            }
        }
        WHEN("The string begins with repetition of the delimiting character") {
            std::string original = "Some text";
            THEN("The substring after the last occurrence of the leading character is returned") {
                REQUIRE( strip("$$$"+original, '$') == original );
            }
        }
        WHEN("The string ends with the delimiting character") {
            std::string original = "Some text";
            THEN("The substring before the first occurrence of the trailing character is returned") {
                REQUIRE( strip(original+'$', '$') == original );
            }
        }
        WHEN("The string ends with repetition of the delimiting character") {
            std::string original = "Some text";
            THEN("The substring before the first occurrence of the trailing character is returned") {
                REQUIRE( strip(original+"$$$", '$') == original );
            }
        }
        WHEN("The string begins and ends with the delimiting character") {
            std::string original = "Some text";
            THEN("The substring between the last leading and first trailing character is returned") {
                REQUIRE( strip('$'+original+'$', '$') == original );
            }
        }
        WHEN("The string begins ends with repetition of the delimiting character") {
            std::string original = "Some text";
            THEN("The substring between the last leading and first trailing character is returned") {
                REQUIRE( strip("$$$"+original+"$$$", '$') == original );
            }
        }
        WHEN("The string consists only of the delimiting character") {
            THEN("An empty string is returned") {
                REQUIRE( strip("$$$", '$').empty() );
            }
        }
        WHEN("The string does not contain the delimiting character") {
            std::string original = "Some text";
            THEN("The original string is returned") {
                REQUIRE( strip(original, '$') == original );
            }
        }
        WHEN("The string contains, but does not begin or end with, the delimiter") {
            std::string original = "Some $ $$ $$$ text";
            THEN("The original string is returned") {
                REQUIRE( strip(original, '$') == original );
            }
        }
        WHEN("The string is empty") {
            THEN("An empty string is returned") {
                REQUIRE( strip("", '$').empty() );
            }
        }
    }
}
SCENARIO("A substring is stripped from the beginning and end of a string.", "[strip]")
{
    GIVEN("A string, and a substring prefix/suffix") {
        std::string substring = "-SUBSTRING-";

        WHEN("The string begins with the substring") {
            std::string original = "Some text";
            THEN("The substring after the last occurrence of the leading substring is returned") {
                REQUIRE( strip("-SUBSTRING-Some text", "-SUBSTRING-") == "Some text");
                //REQUIRE( strip(substring+original, substring) == original );
            }
        }
        WHEN("The string begins with repetition of the substring") {
            std::string original = "Some text";
            THEN("The substring after the last occurrence of the leading substring is returned") {
                REQUIRE( strip(substring+substring+original, substring) == original );
            }
        }
        WHEN("The string ends with the substring") {
            std::string original = "Some text";
            THEN("The substring before the first occurrence of the trailing substring is returned") {
                REQUIRE( strip(original+substring, substring) == original );
            }
        }
        WHEN("The string ends with repetition of the substring") {
            std::string original = "Some text";
            THEN("The substring before the first occurrence of the trailing substring is returned") {
                REQUIRE( strip(original+substring+substring, substring) == original );
            }
        }
        WHEN("The string begins and ends with the substring") {
            std::string original = "Some text";
            THEN("The substring between the last leading and first trailing substring is returned") {
                REQUIRE( strip(substring+original+substring, substring) == original );
            }
        }
        WHEN("The string begins and ends with repetition of the delimiting character") {
            std::string original = "Some text";
            THEN("The substring between the last leading and first trailing substring is returned") {
                REQUIRE( strip(substring+substring+original+substring+substring, substring) == original );
            }
        }
        WHEN("The string consists only of the substring") {
            THEN("An empty string is returned") {
                REQUIRE( strip(substring, substring).empty() );
            }
        }
        WHEN("The string does not contain the substring") {
            std::string original = "Some text";
            THEN("The original string is returned") {
                REQUIRE( strip(original, "notintheoriginal") == original );
            }
        }
        WHEN("The string contains, but does not end with, the delimiter") {
            std::string original = "Some " + substring + " text";
            THEN("The original string is returned") {
                REQUIRE( strip(original, substring) == original );
            }
        }
        WHEN("The string is empty") {
            THEN("An empty string is returned") {
                REQUIRE( strip("", substring).empty() );
            }
        }
    }
}
