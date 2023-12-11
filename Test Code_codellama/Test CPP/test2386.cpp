#include <iostream>
#include <vector>

// Function to calculate the average waiting time for a set of processes
float calculateAverageWaitingTime(const std::vector<std::pair<int, int>>& processes) {
    // Initialize variables to keep track of the total waiting time and the number of processes
    float totalWaitingTime = 0;
    int numProcesses = 0;

    // Iterate over the processes and calculate the waiting time for each one
    for (const auto& process : processes) {
        // Calculate the waiting time for the current process
        float waitingTime = process.first - numProcesses;

        // Add the waiting time to the total waiting time and increment the number of processes
        totalWaitingTime += waitingTime;
        numProcesses++;
    }

    // Return the average waiting time
    return totalWaitingTime / numProcesses;
}
