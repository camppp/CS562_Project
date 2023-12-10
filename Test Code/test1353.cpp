#include <iostream>
#include <cctype>

bool validateInput(const char* arg1, int arg2) {
    // Check if arg1 is a single character from the set {'c', 'o', 'i'}
    if (std::isalpha(arg1[0]) && std::islower(arg1[0])) {
        if (arg1[0] == 'c' || arg1[0] == 'o' || arg1[0] == 'i') {
            // Check if arg2 is a positive integer
            if (arg2 > 0) {
                return true;  // Input arguments meet the criteria
            }
        }
    }
    return false;  // Input arguments do not meet the criteria
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Invalid number of arguments." << std::endl;
        return 1;
    }

    // Validate the input arguments
    if (validateInput(argv[1], std::stoi(argv[2]))) {
        std::cout << "Input arguments are valid." << std::endl;
    } else {
        std::cout << "Input arguments are invalid." << std::endl;
    }

    return 0;
}
