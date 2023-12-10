#include <iostream>
#include <string>

class TextNumberContainer {
private:
    std::string text;
    int num;

public:
    TextNumberContainer(const std::string& text, int num) : text(text), num(num) {}

    std::string getText() {
        return text;
    }

    int getNum() {
        return num;
    }
};

int main() {
    // Example usage
    TextNumberContainer container("Hello, World!", 42);
    std::cout << "Stored Text: " << container.getText() << std::endl;
    std::cout << "Stored Number: " << container.getNum() << std::endl;
    return 0;
}
