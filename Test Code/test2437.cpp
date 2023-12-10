#include <iostream>
#include "colors.h"

int main() {
    std::string colorChoice;
    std::string textMessage;

    std::cout << "Enter the color choice (red, green, yellow, blue, magenta, cyan): ";
    std::cin >> colorChoice;

    std::cout << "Enter the text message: ";
    std::cin.ignore();  // Clear the input buffer
    std::getline(std::cin, textMessage);

    if (colorChoice == "red") {
        std::cout << RED_TEXT(textMessage) << std::endl;
    } else if (colorChoice == "green") {
        std::cout << GREEN_TEXT(textMessage) << std::endl;
    } else if (colorChoice == "yellow") {
        std::cout << YELLOW_TEXT(textMessage) << std::endl;
    } else if (colorChoice == "blue") {
        std::cout << BLUE_TEXT(textMessage) << std::endl;
    } else if (colorChoice == "magenta") {
        std::cout << MAGENTA_TEXT(textMessage) << std::endl;
    } else if (colorChoice == "cyan") {
        std::cout << CYAN_TEXT(textMessage) << std::endl;
    } else {
        std::cout << "Invalid color choice!" << std::endl;
    }

    return 0;
}
