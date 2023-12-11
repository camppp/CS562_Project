#include <string>
#include <regex>

std::string extractNamespace(const std::string& code) {
    std::regex namespaceRegex("namespace ([a-zA-Z_][a-zA-Z0-9_]*) {");
    std::smatch matches;
    if (std::regex_search(code, matches, namespaceRegex)) {
        return matches[1].str();
    }
    return "";
}
