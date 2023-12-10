#include <string>
#include <sstream>
#include <cmath>

int evaluateExpression(const std::string& expression) {
    std::stringstream ss(expression);
    int result = 0;
    char op = '+';
    while (ss >> result) {
        if (op == '+') {
            result += result;
        } else if (op == '-') {
            result -= result;
        } else if (op == '*') {
            result *= result;
        } else if (op == '/') {
            result /= result;
        }
        ss >> op;
    }
    return result;
}
