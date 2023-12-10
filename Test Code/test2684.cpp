#include <iostream>
#include <string>
#include <regex>

std::pair<std::string, std::string> extractConditions(const std::string& headerSnippet) {
    std::regex ifndefRegex("#ifndef\\s+(\\w+)");
    std::regex defineRegex("#define\\s+(\\w+)");

    std::smatch match;
    std::string ifndefCondition, defineCondition;

    if (std::regex_search(headerSnippet, match, ifndefRegex)) {
        ifndefCondition = match[1].str();
    }

    if (std::regex_search(headerSnippet, match, defineRegex)) {
        defineCondition = match[1].str();
    }

    return std::make_pair(ifndefCondition, defineCondition);
}

int main() {
    std::string headerSnippet = R"(
#ifndef TrackerConditions_Mu2eDetector_hh
#define TrackerConditions_Mu2eDetector_hh
// ... other code
#endif /* TrackerConditions_Mu2eDetector_hh */
)";

    auto conditions = extractConditions(headerSnippet);
    std::cout << "Condition used in #ifndef: " << conditions.first << std::endl;
    std::cout << "Condition used in #define: " << conditions.second << std::endl;

    return 0;
}
