#include <iostream>
#include <string>
#include <regex>

std::string extractNamespace(const std::string& code) {
    std::regex namespaceRegex(R"(namespace\s+(\w+)\s*\{)");
    std::smatch match;
    std::string namespaceString;

    auto it = code.cbegin();
    while (std::regex_search(it, code.cend(), match, namespaceRegex)) {
        namespaceString += match[1].str() + "::";
        it = match.suffix().first;
    }

    if (!namespaceString.empty()) {
        namespaceString.pop_back();  // Remove the trailing "::"
    }

    return namespaceString;
}

int main() {
    const std::string code = R"(
    namespace canbus {
    namespace apollo {
    // Other code here
    }
    }
    )";

    std::cout << extractNamespace(code) << std::endl;  // Output: "canbus::apollo"
    return 0;
}
