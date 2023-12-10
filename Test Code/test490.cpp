#include <iostream>
#include "base/strings/string_util.h"

int main() {
    std::string input;
    std::getline(std::cin, input);

    // Convert the input string to lowercase
    base::StringToLower(&input);

    // Remove leading and trailing whitespace
    base::TrimWhitespace(input, base::TRIM_ALL, &input);

    // Split the string into individual words
    std::vector<std::string> words;
    base::SplitString(input, ' ', &words);

    // Print each word on a new line
    for (const auto& word : words) {
        std::cout << word << std::endl;
    }

    return 0;
}
