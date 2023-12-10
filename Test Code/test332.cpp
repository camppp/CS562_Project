#include <iostream>
#include <string>

std::string generateCopyrightNotice(int year) {
    std::string name = "YourNameHere";
    return "Copyright (c) " + std::to_string(year) + " " + name + ".";
}
