#include <iostream>
#include <vector>
#include <algorithm>
#include <wwiv/common/strings.h>

std::vector<std::string> removeDuplicates(const std::vector<std::string>& input) {
    std::vector<std::string> uniqueStrings;
    for (const auto& str : input) {
        if (std::find(uniqueStrings.begin(), uniqueStrings.end(), str) == uniqueStrings.end()) {
            uniqueStrings.push_back(str);
        }
    }
    return uniqueStrings;
}

int main() {
    std::vector<std::string> inputStrings;
    std::string input;
    std::cout << "Enter a list of strings (enter 'done' to finish input):" << std::endl;
    while (true) {
        std::cin >> input;
        if (input == "done") {
            break;
        }
        inputStrings.push_back(input);
    }

    std::vector<std::string> uniqueStrings = removeDuplicates(inputStrings);

    std::cout << "Unique strings:" << std::endl;
    for (const auto& str : uniqueStrings) {
        std::cout << str << std::endl;
    }

    return 0;
}
