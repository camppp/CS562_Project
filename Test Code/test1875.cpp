#include <iostream>
#include <string>
#include <cctype>

std::string generateAcronym(const std::string& input) {
    std::string acronym;
    bool inWord = false;

    for (char c : input) {
        if (std::isalpha(c)) {
            if (!inWord) {
                acronym.push_back(std::toupper(c));
                inWord = true;
            }
        } else {
            inWord = false;
        }
    }

    return acronym;
}

int main() {
    std::string input1 = "World Health Organization";
    std::string input2 = "  United   Nations   Development   Programme  ";
    std::string input3 = "  International  Business   Machines  ";

    std::cout << "Acronym for \"" << input1 << "\": " << generateAcronym(input1) << std::endl;
    std::cout << "Acronym for \"" << input2 << "\": " << generateAcronym(input2) << std::endl;
    std::cout << "Acronym for \"" << input3 << "\": " << generateAcronym(input3) << std::endl;

    return 0;
}
