#include <string>
#include <sstream>

std::string extractInnermostNamespace(const std::string& codeSnippet) {
    std::stringstream ss(codeSnippet);
    std::string namespaceName;

    // Skip over any leading whitespace and comments
    while (ss.peek() == ' ' || ss.peek() == '\t' || ss.peek() == '\n' || ss.peek() == '/') {
        ss.ignore(1);
    }

    // Check if the next character is the start of a namespace declaration
    if (ss.peek() == 'n' || ss.peek() == 'N') {
        // Skip over the namespace keyword
        ss.ignore(2);

        // Extract the namespace name
        while (ss.peek() != ' ' && ss.peek() != '\t' && ss.peek() != '\n' && ss.peek() != '/') {
            namespaceName += ss.peek();
            ss.ignore(1);
        }
    }

    return namespaceName;
}
