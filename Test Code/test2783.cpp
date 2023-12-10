#include <string>

std::string extractInnermostNamespace(const std::string& codeSnippet) {
    size_t pos = codeSnippet.find_last_of("namespace");
    if (pos != std::string::npos) {
        size_t start = codeSnippet.find_first_of("{", pos);
        size_t end = codeSnippet.find_last_of("}", start);
        if (start != std::string::npos && end != std::string::npos) {
            std::string namespaceBlock = codeSnippet.substr(start, end - start + 1);
            size_t lastNamespacePos = namespaceBlock.find_last_of("namespace");
            if (lastNamespacePos != std::string::npos) {
                size_t namespaceStart = namespaceBlock.find_first_of(" ", lastNamespacePos);
                size_t namespaceEnd = namespaceBlock.find_first_of("{", namespaceStart);
                if (namespaceStart != std::string::npos && namespaceEnd != std::string::npos) {
                    std::string innermostNamespace = namespaceBlock.substr(namespaceStart + 1, namespaceEnd - namespaceStart - 2);
                    return innermostNamespace;
                }
            }
        }
    }
    return "";
}
