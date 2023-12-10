#include <iostream>

int main() {
    std::string inputStr = "Hello, World!";
    StringInputStream stream(inputStr);

    // Read characters from the input string until the end is reached
    while (!stream.isEnd()) {
        char ch = stream.get();
        if (ch != '\0') {
            std::cout << ch << " ";  // Output each character
        }
    }

    return 0;
}
