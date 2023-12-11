#include <iostream>
#include <string>
#include <stack>

bool isValidMathExpression(const std::string& expression) {
    // Check if the expression contains only valid characters
    for (char c : expression) {
        if (!isdigit(c) && c != '+' && c != '-' && c != '*' && c != '/' && c != '(' && c != ')') {
            return false;
        }
    }

    // Check if the parentheses are properly balanced
    std::stack<char> parentheses;
    for (char c : expression) {
        if (c == '(') {
            parentheses.push(c);
        } else if (c == ')') {
            if (parentheses.empty()) {
                return false;
            }
            parentheses.pop();
        }
    }
    if (!parentheses.empty()) {
        return false;
    }

    // Check if the expression follows the rules of a valid mathematical expression
    bool lastWasOperator = false;
    for (char c : expression) {
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (lastWasOperator) {
                return false;
            }
            lastWasOperator = true;
        } else {
            lastWasOperator = false;
        }
    }

    return true;
}

int main() {
    std::string expression = "3+4*(7-2)";
    std::cout << "Expression: " << expression << std::endl;
    std::cout << "Is valid: " << isValidMathExpression(expression) << std::endl;

    expression = "(5*2)/3-1";
    std::cout << "Expression: " << expression << std::endl;
    std::cout << "Is valid: " << isValidMathExpression(expression) << std::endl;

    expression = "4+*3";
    std::cout << "Expression: " << expression << std::endl;
    std::cout << "Is valid: " << isValidMathExpression(expression) << std::endl;

    expression = "((8-3)";
    std::cout << "Expression: " << expression << std::endl;
    std::cout << "Is valid: " << isValidMathExpression(expression) << std::endl;

    return 0;
}
