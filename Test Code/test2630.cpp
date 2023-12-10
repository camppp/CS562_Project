#include <iostream>
#include <stack>
#include <string>

bool isValidMathExpression(const std::string& expression) {
    std::stack<char> parenthesesStack;

    for (char c : expression) {
        if (c == '(') {
            parenthesesStack.push(c);
        } else if (c == ')') {
            if (parenthesesStack.empty() || parenthesesStack.top() != '(') {
                return false;  // Unbalanced parentheses
            }
            parenthesesStack.pop();
        } else if (!isdigit(c) && c != '+' && c != '-' && c != '*' && c != '/') {
            return false;  // Invalid character
        }
    }

    if (!parenthesesStack.empty()) {
        return false;  // Unbalanced parentheses
    }

    if (expression.front() == '+' || expression.front() == '-' || expression.front() == '*' || expression.front() == '/' ||
        expression.back() == '+' || expression.back() == '-' || expression.back() == '*' || expression.back() == '/') {
        return false;  // Operator at the beginning or end
    }

    for (size_t i = 0; i < expression.size() - 1; ++i) {
        if ((expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') &&
            (expression[i + 1] == '+' || expression[i + 1] == '-' || expression[i + 1] == '*' || expression[i + 1] == '/')) {
            return false;  // Two consecutive operators
        }
    }

    return true;  // All conditions satisfied, valid expression
}

int main() {
    std::string expression1 = "3+4*(7-2)";
    std::string expression2 = "(5*2)/3-1";
    std::string expression3 = "4+*3";
    std::string expression4 = "((8-3)";

    std::cout << std::boolalpha;
    std::cout << "Expression 1 is valid: " << isValidMathExpression(expression1) << std::endl;
    std::cout << "Expression 2 is valid: " << isValidMathExpression(expression2) << std::endl;
    std::cout << "Expression 3 is valid: " << isValidMathExpression(expression3) << std::endl;
    std::cout << "Expression 4 is valid: " << isValidMathExpression(expression4) << std::endl;

    return 0;
}
