#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

int main() {
    const size_t NUM = 10; // Define the number of random numbers to collect.

    // Collect random numbers.
    std::vector<int> randomNumbers;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 100); // Generate random numbers between 1 and 100.

    for (size_t ii = 0; ii < NUM; ++ii) {
        randomNumbers.push_back(dis(gen)); // Collect random numbers and store them in a vector.
    }

    // Perform operations on collected numbers.
    // 1. Calculate the sum of all collected numbers.
    int sum = 0;
    for (int num : randomNumbers) {
        sum += num;
    }

    // 2. Find the maximum and minimum values among the collected numbers.
    int maxNum = *std::max_element(randomNumbers.begin(), randomNumbers.end());
    int minNum = *std::min_element(randomNumbers.begin(), randomNumbers.end());

    // 3. Sort the collected numbers in ascending order.
    std::sort(randomNumbers.begin(), randomNumbers.end());

    // Output the results.
    std::cout << "Collected random numbers: ";
    for (int num : randomNumbers) {
        std::cout << num << " ";
    }
    std::cout << "\nSum of all collected numbers: " << sum << std::endl;
    std::cout << "Maximum value: " << maxNum << std::endl;
    std::cout << "Minimum value: " << minNum << std::endl;

    return 0;
}
