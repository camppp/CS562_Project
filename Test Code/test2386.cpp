#include <iostream>
#include <vector>

// Function to calculate the average waiting time for a set of processes
float calculateAverageWaitingTime(const std::vector<std::pair<int, int>>& processes) {
    int n = processes.size();
    int totalWaitingTime = 0;
    int currentTime = 0;

    for (const auto& process : processes) {
        int arrivalTime = process.first;
        int burstTime = process.second;

        // Calculate waiting time for the current process
        int waitingTime = std::max(0, currentTime - arrivalTime);
        totalWaitingTime += waitingTime;

        // Update current time for the next process
        currentTime += burstTime;

        // Update current time if the process arrived after the current time
        if (arrivalTime > currentTime) {
            currentTime = arrivalTime + burstTime;
        }
    }

    // Calculate the average waiting time
    float averageWaitingTime = static_cast<float>(totalWaitingTime) / n;
    return averageWaitingTime;
}
