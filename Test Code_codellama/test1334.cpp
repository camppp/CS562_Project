#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;

    int j = input.size() - 1;
    for (int i = 0; i < input.size(); i++) {
        j--;
        if (j == 0 && std::isdigit(input[i])) {
            std::cout << "The last character in the string is a digit." << std::endl;
        }
    }

    return 0;
}
