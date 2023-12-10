#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    // Check if there are any command line arguments
    if (argc == 1) {
        std::cout << "No command line arguments provided" << std::endl;
        return 0;
    }

    // Parse the command line arguments into a vector of integers
    std::vector<int> integers;
    for (int i = 1; i < argc; i++) {
        try {
            integers.push_back(std::stoi(argv[i]));
        } catch (std::invalid_argument& e) {
            std::cout << "Invalid command line argument: " << argv[i] << std::endl;
            return 1;
        }
    }

    // Calculate the sum of the even integers
    int sum = 0;
    for (int i = 0; i < integers.size(); i++) {
        if (integers[i] % 2 == 0) {
            sum += integers[i];
        }
    }

    // Output the sum
    std::cout << "Sum of even integers: " << sum << std::endl;

    return 0;
}
