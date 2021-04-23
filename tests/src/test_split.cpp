#include "../include/catch_amalgamated.hpp"
#include "../../stringutils.h"


SCENARIO("A string is split at each group of whitespace characters", "[split]")
{
    GIVEN("A string") {
        WHEN ("The string contains one or more delimiters") {
            std::string orig = "A string\twith\nwhitespace";

            THEN("The string is split at each delimiter") {
                std::vector<std::string> expected = {
                        "A", "string", "with", "whitespace"
                };
                REQUIRE( split(orig) == expected );
            }
        }
        WHEN("The string has leading or trailing whitespace") {
            std::string orig = "\t A string\twith\nwhitespace\n";

            THEN("The whitespace is trimmed before splitting") {
                std::vector<std::string> expected = {
                        "A", "string", "with", "whitespace"
                };
                REQUIRE( split(orig) == expected );
            }
        }
        WHEN ("The string contains repeated delimiters") {
            std::string orig = "A  string\t\twith\n\nwhitespace";

            THEN("Repeated delimiters are consumed and treated as one") {
                std::vector<std::string> expected = {
                        "A", "string", "with", "whitespace"
                };
                REQUIRE( split(orig) == expected );
            }
        }
        WHEN ("The string does not contain delimiters") {
            std::string orig = "Astringwithoutwhitespace";

            THEN("A vector containing the original string is returned") {
                std::vector<std::string> expected = { orig };
                REQUIRE( split(orig) == expected );
            }
        }
        WHEN ("The string is empty") {
            THEN("An empty vector is returned") {
                REQUIRE( split("").empty() );
            }
        }
    }
}
SCENARIO("A string is split at each group of delimiter characters", "[split]")
{
    GIVEN("A string") {
        WHEN ("The string contains one or more delimiters") {
            std::string orig = "A,string,with,delimiters";

            THEN("The string is split at each delimiter") {
                std::vector<std::string> expected = {
                        "A", "string", "with", "delimiters"
                };
                REQUIRE( split(orig, ',') == expected );
            }
        }
        WHEN("The string has leading or trailing delimiters") {
            std::string orig = ",,A,string,with,delimiters,,";

            THEN("The delimiters are trimmed before splitting") {
                std::vector<std::string> expected = {
                        "A", "string", "with", "delimiters"
                };
                REQUIRE( split(orig, ',') == expected );
            }
        }
        WHEN ("The string contains repeated delimiters") {
            std::string orig = "A,string,,with,,delimiters";

            THEN("Repeated delimiters are consumed and treated as one") {
                std::vector<std::string> expected = {
                        "A", "string", "with", "delimiters"
                };
                REQUIRE( split(orig, ',') == expected );
            }
        }
        WHEN ("The string does not contain delimiters") {
            std::string orig = "Astringwithoutdelimiters";

            THEN("A vector containing the original string is returned") {
                std::vector<std::string> expected = { orig };
                REQUIRE( split(orig, ',') == expected );
            }
        }
        WHEN ("The string is empty") {
            THEN("An empty vector is returned") {
                REQUIRE( split("", ',').empty() );
            }
        }
    }
}
