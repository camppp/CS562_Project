#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

// Function to calculate the time difference in years
double calculateTimeDifference(const std::tm& startTime, const std::tm& endTime) {
    std::time_t start = std::mktime(const_cast<std::tm*>(&startTime));
    std::time_t end = std::mktime(const_cast<std::tm*>(&endTime));
    double differenceInSeconds = std::difftime(end, start);
    const double secondsInYear = 60 * 60 * 24 * 365.25; // accounting for leap years
    return differenceInSeconds / secondsInYear;
}

int main() {
    // Example usage of calculateTimeDifference function
    std::tm startTime = {0, 0, 0, 1, 0, 100}; // Example start time (year 2000)
    std::tm endTime = {0, 0, 0, 1, 0, 105};   // Example end time (year 2005)
    double timeDifferenceInYears = calculateTimeDifference(startTime, endTime);
    std::cout << "Time difference in years: " << timeDifferenceInYears << std::endl;

    // Example iteration through a data structure and skipping elements based on a condition
    std::vector<int> dataStructure = {1, 2, 3, 4, 5};
    std::vector<int> elementsToSkip = {2, 4};
    for (const auto& element : dataStructure) {
        if (std::find(elementsToSkip.begin(), elementsToSkip.end(), element) != elementsToSkip.end()) {
            continue; // Skipping the element
        }
        std::cout << element << " "; // Process the element
    }
    std::cout << std::endl;

    return 0;
}
