#include <iostream>
#include <stack>
#include <string>

bool isProperlyNested(std::string braceString) {
    std::stack<char> stack;
    for (char brace : braceString) {
        if (brace == '{') {
            stack.push(brace);
        } else if (brace == '}') {
            if (stack.empty() || stack.top() != '{') {
                return false;
            }
            stack.pop();
        }
    }
    return stack.empty();
}

int main() {
    std::string braceString1 = "{ { } } { }";
    std::string braceString2 = "{ { } } } {";
    std::string braceString3 = "{ { { } }";

    std::cout << std::boolalpha << isProperlyNested(braceString1) << std::endl;  // Output: true
    std::cout << std::boolalpha << isProperlyNested(braceString2) << std::endl;  // Output: false
    std::cout << std::boolalpha << isProperlyNested(braceString3) << std::endl;  // Output: false

    return 0;
}
