#include <iostream>
#include <string>

std::string generateCopyrightNotice(int year) {
    return "Copyright (c) " + std::to_string(year) + " YourNameHere.";
}
