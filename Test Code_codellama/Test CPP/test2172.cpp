#include <iostream>
#include <fstream>

int main() {
    // Open the file for reading
    std::ifstream file("in.txt");

    // Check if the file was successfully opened
    if (!file.is_open()) {
        std::cout << "Error: Unable to open the file" << std::endl;
        return 1;
    }

    // Read the integers from the file
    int sum = 0;
    int number;
    while (file >> number) {
        sum += number;
    }

    // Output the sum to the console
    std::cout << "The sum of the integers in the file is: " << sum << std::endl;

    // Close the file
    file.close();

    return 0;
}
