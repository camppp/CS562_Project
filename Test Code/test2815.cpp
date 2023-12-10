#include <iostream>
#include <string>

namespace roerei {
    std::string customStringManipulation(const std::string& input) {
        std::string modifiedString = input;
        size_t found = modifiedString.find("roerei");
        if (found != std::string::npos) {
            modifiedString.replace(found, 6, "success");
        }
        found = modifiedString.find("apple");
        if (found != std::string::npos) {
            modifiedString.replace(found, 5, "banana");
        }
        found = modifiedString.find("123");
        if (found != std::string::npos) {
            modifiedString.replace(found, 3, "456");
        }
        return modifiedString;
    }
}
