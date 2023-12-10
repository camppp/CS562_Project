#include <stack>
#include <string>

bool validateParentheses(std::string s) {
    std::stack<char> stack;
    for (char c : s) {
        if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            if (stack.empty() || stack.top() != '(') {
                return false;  // Unbalanced parentheses
            }
            stack.pop();
        }
    }
    return stack.empty();  // Return true if stack is empty (balanced parentheses)
}
