#include <iostream>
#include <vector>
#include <algorithm>

class Token {
public:
    int value;
    int priority;

    Token(int v, int p) : value(v), priority(p) {}
};

// Custom sorting algorithm
void customSort(std::vector<Token>& tokens) {
    std::sort(tokens.begin(), tokens.end(), [](const Token& t1, const Token& t2) {
        if (t1.priority != t2.priority) {
            return t1.priority > t2.priority;
        } else {
            return t1.value > t2.value;
        }
    });
}

int main() {
    std::vector<Token> tokens = {Token(3, 2), Token(5, 1), Token(4, 3), Token(2, 2)};
    customSort(tokens);

    for (const Token& token : tokens) {
        std::cout << "Value: " << token.value << ", Priority: " << token.priority << std::endl;
    }

    return 0;
}
