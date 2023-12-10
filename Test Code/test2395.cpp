++
#include <iostream>
#include <string>
#include <regex>

std::pair<std::string, std::string> parseHeaderFile(const std::string& headerContent) {
    std::string macroDefinition;
    std::string uniqueIdentifier;

    // Extract macro definition using regex
    std::regex macroRegex("#define\\s+(\\w+)\\s+(.*)");
    std::smatch match;
    if (std::regex_search(headerContent, match, macroRegex)) {
        macroDefinition = match.str(1) + "\t" + match.str(2);
    }

    // Extract unique identifier string using regex
    std::regex idRegex("#define\\s+IDSTR\\s+\"(.*)\"");
    if (std::regex_search(headerContent, match, idRegex)) {
        uniqueIdentifier = match.str(1);
    }

    return std::make_pair(macroDefinition, uniqueIdentifier);
}

int main() {
    std::string headerContent = R"(
        #define ALTI_SR2_PERM64	{13,14,15,0,1,2,3,4,19,19,19,8,9,10,11,12}
    #endif	/* For OSX */
    #define IDSTR	"SFMT-607:2-15-3-13-3:fdff37ff-ef7f3f7d-ff777b7d-7ff7fb2f"

    #endif /* SFMT_PARAMS607_H */
    )";

    std::pair<std::string, std::string> result = parseHeaderFile(headerContent);
    std::cout << "Macro Definition: " << result.first << std::endl;
    std::cout << "Unique Identifier: " << result.second << std::endl;

    return 0;
}
