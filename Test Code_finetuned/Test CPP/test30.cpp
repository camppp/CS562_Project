#include <iostream>
#include <chrono>
#include <vector>

// Function to calculate time difference in years
double calculateTimeDifference(std::chrono::time_point<std::chrono::system_clock> start, std::chrono::time_point<std::chrono::system_clock> end) {
    std::chrono::duration<double> diff = end - start;
    return diff.count() / 31556952; // Conversion factor from seconds to years
}

int main() {
    // Start time
    auto start = std::chrono::system_clock::now();

    // Perform some operation here

    // End time
    auto end = std::chrono::system_clock::now();

    // Calculate time difference in years
    double timeDifference = calculateTimeDifference(start, end);

    std::cout << "Time difference: " << timeDifference << " years" << std::endl;

    // Data structure
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Iterate through the data structure and skip elements based on a condition
    for (int i = 0; i < data.size(); i++) {
        if (data[i] % 2 == 0) { // Skip even numbers
            continue;
        }
        std::cout << "Element: " << data[i] << std::endl;
    }

    return 0;
}