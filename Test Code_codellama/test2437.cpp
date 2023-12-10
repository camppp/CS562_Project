#include <iostream>
#include "colors.h"

int main() {
    std::string color, message;
    std::cout << "Enter a color (red, green, yellow, blue, magenta, cyan): ";
    std::cin >> color;
    std::cout << "Enter a message: ";
    std::cin >> message;

    if (color == "red") {
        std::cout << RED << message << RESET << std::endl;
    } else if (color == "green") {
        std::cout << GREEN << message << RESET << std::endl;
    } else if (color == "yellow") {
        std::cout << YELLOW << message << RESET << std::endl;
    } else if (color == "blue") {
        std::cout << BLUE << message << RESET << std::endl;
    } else if (color == "magenta") {
        std::cout << MAGENTA << message << RESET << std::endl;
    } else if (color == "cyan") {
        std::cout << CYAN << message << RESET << std::endl;
    } else {
        std::cout << "Invalid color" << std::endl;
    }

    return 0;
}
