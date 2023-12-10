#include <iostream>
#include <string>
#include <regex>

std::pair<std::string, std::string> extractNamespaceAndFilename(const std::string& codeSnippet) {
    std::regex namespaceRegex(R"(namespace\s+(\w+))");
    std::regex filenameRegex(R"(end of\s+(\w+\.\w+))");

    std::smatch namespaceMatch, filenameMatch;

    if (std::regex_search(codeSnippet, namespaceMatch, namespaceRegex) &&
        std::regex_search(codeSnippet, filenameMatch, filenameRegex)) {
        return std::make_pair(namespaceMatch[1].str(), filenameMatch[1].str());
    } else {
        return std::make_pair("", "");
    }
}

int main() {
    std::string codeSnippet = "}\n} // end namespace detran\n\n//---------------------------------------------------------------------------//\n//              end of Equation_DD_3D.cc\n//---------------------------------------------------------------------------//\n";
    auto result = extractNamespaceAndFilename(codeSnippet);
    std::cout << "Namespace: " << result.first << std::endl;
    std::cout << "Filename: " << result.second << std::endl;
    return 0;
}
