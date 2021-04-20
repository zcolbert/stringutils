#include "../include/catch_amalgamated.hpp"
#include "../../stringutils.h"


SCENARIO("A string is split at each occurrence of a delimiter", "[split]")
{
    GIVEN("A string containing delimiting characters") {
        std::string original = "Hello, this is a string. \tGoodbye.";

        WHEN ("No delimiter is specified") {
            std::vector<std::string> expected = {
                "Hello,", "this", "is", "a", "string.", "Goodbye."
            };
            THEN("The string is split at whitespace") {
            }
        }
    }
}
