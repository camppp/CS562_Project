#include <string>
#include <stack>

bool isValidNamespace(const std::string& input) {
    std::stack<char> stack;
    bool isNamespaceKeywordFound = false;

    for (char c : input) {
        if (c == '{') {
            if (isNamespaceKeywordFound) {
                stack.push(c);
            }
        } else if (c == '}') {
            if (!stack.empty()) {
                stack.pop();
            } else {
                return false; // Unmatched closing brace
            }
        } else if (c == 'n' && input.substr(0, 9) == "namespace") {
            isNamespaceKeywordFound = true;
        }
    }

    return stack.empty() && isNamespaceKeywordFound;
}
