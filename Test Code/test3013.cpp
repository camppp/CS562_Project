#include <string>
#include <algorithm>

namespace hersh {
    std::string evaluate(const std::string& input) {
        // Remove leading and trailing whitespace from the input string
        std::string modifiedString = input;
        modifiedString.erase(0, modifiedString.find_first_not_of(" \t\n\r"));
        modifiedString.erase(modifiedString.find_last_not_of(" \t\n\r") + 1);

        return modifiedString;
    }
}

// Test cases
TEST_CASE("hersh::evaluate function") {
    SECTION("Empty input") {
        REQUIRE(hersh::evaluate("") == "");
    }
    SECTION("Non-empty input") {
        REQUIRE(hersh::evaluate("something ") == "something");
    }
}
