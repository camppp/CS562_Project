#include <iostream>
#include <chrono>
#include <vector>

// Function to calculate the time difference in years
double calculateTimeDifference(const std::chrono::system_clock::time_point& startTime,
                                const std::chrono::system_clock::time_point& endTime) {
    std::chrono::duration<double> elapsedTime = endTime - startTime;
    auto years = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::hours(24 * 365.25));
    return elapsedTime.count() / years.count();
}

int main() {
    // Get the current time as the start time
    auto startTime = std::chrono::system_clock::now();

    // Simulate some process...

    // Get the current time as the end time
    auto endTime = std::chrono::system_clock::now();

    // Calculate the time difference in years
    double timeDifferenceInYears = calculateTimeDifference(startTime, endTime);

    std::cout << "Time Difference: " << timeDifferenceInYears << " years" << std::endl;

    // Simulate a data structure (vector of integers)
    std::vector<int> dataStructure = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Perform an operation on the data structure (skip even numbers)
    std::cout << "Original Data Structure: ";
    for (int num : dataStructure) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Modified Data Structure (Skipping Even Numbers): ";
    for (int num : dataStructure) {
        if (num % 2 == 0) {
            // Skip even numbers
            continue;
        }
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
