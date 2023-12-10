#include <iostream>
#include <string>
#include <vector>
#include <cctype>

class SExpr {
private:
    std::string expression;

public:
    SExpr(const std::string& expr) : expression(expr) {}

    std::string toString() const {
        return expression;
    }

    bool isAtom() const {
        return expression.front() != '(';
    }

    bool isList() const {
        return expression.front() == '(';
    }

    int numElements() const {
        if (!isList()) {
            return 0;
        }

        int count = 0;
        bool inAtom = false;
        for (char c : expression) {
            if (c == '(') {
                inAtom = true;
            } else if (c == ')') {
                inAtom = false;
            } else if (!inAtom && std::isspace(c)) {
                count++;
            }
        }
        return count + 1; // Add 1 for the last element
    }
};

SExpr parseSExpr(const std::string& expr) {
    return SExpr(expr);
}

int main() {
    std::string input = "(1 2 3)";
    SExpr sexpr = parseSExpr(input);
    std::cout << "String representation: " << sexpr.toString() << std::endl;
    std::cout << "Is atom? " << (sexpr.isAtom() ? "Yes" : "No") << std::endl;
    std::cout << "Is list? " << (sexpr.isList() ? "Yes" : "No") << std::endl;
    std::cout << "Number of elements: " << sexpr.numElements() << std::endl;
    return 0;
}
