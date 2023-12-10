#include <iostream>
#include <cctype>

int main() {
    std::string password;
    int lower = 0, upper = 0, special = 0, number = 0;

    std::cout << "Enter the password: ";
    std::cin >> password;

    for (char ch : password) {
        if (islower(ch)) {
            lower++;
        } else if (isupper(ch)) {
            upper++;
        } else if (isdigit(ch)) {
            number++;
        } else {
            special++;
        }
    }

    if (lower > 0 && upper > 0 && special > 0 && number > 0) {
        std::cout << "Valid Password";
    } else {
        std::cout << "Invalid Password";
    }

    return 0;
}
