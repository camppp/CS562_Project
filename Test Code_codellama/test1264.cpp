#include <iostream>
#include <fstream>
#include <cmath>

int main() {
    // Open the file in read-write mode
    std::ifstream file("file.txt");
    if (!file) {
        std::cerr << "Error: unable to open file" << std::endl;
        return 1;
    }

    // Read the integers from the file
    int num;
    while (file >> num) {
        // Calculate the square of the integer
        int squared = num * num;

        // Write the squared integer back to the file
        file << squared << " ";
    }

    // Calculate the sum of all the squared integers
    int sum = 0;
    while (file >> num) {
        sum += num;
    }

    // Output the sum to the console
    std::cout << "Sum of squared integers: " << sum << std::endl;

    // Close the file
    file.close();

    return 0;
}
