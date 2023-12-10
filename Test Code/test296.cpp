#include <iostream>
#include <gpcl.hpp>

int main() {
    try {
        gpcl::vector<int> numbers; // Using the container provided by gpcl.hpp library

        // Read integers from standard input and store them in the container
        int num;
        while (std::cin >> num) {
            numbers.push_back(num);
        }

        // Calculate the sum of all the integers
        int sum = 0;
        for (int n : numbers) {
            sum += n;
        }

        // Print the sum to the standard output
        std::cout << "Sum of the integers: " << sum << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
        return 1;
    }

    return 0;
}
