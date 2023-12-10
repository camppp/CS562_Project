#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

class Runner {
public:
    int timeTaken;

    void Run() {
        // Simulate running process with a random time delay
        timeTaken = rand() % 10 + 1;  // Random time between 1 and 10 seconds
        std::cout << "Runner finished in " << timeTaken << " seconds" << std::endl;
    }

    bool operator<(const Runner& other) const {
        return timeTaken < other.timeTaken;
    }
};

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Create three runners
    Runner runner1, runner2, runner3;

    // Simulate the race
    runner1.Run();
    runner2.Run();
    runner3.Run();

    // Store the runners in a vector
    std::vector<Runner> runners = {runner1, runner2, runner3};

    // Sort the runners based on their finishing times
    std::sort(runners.begin(), runners.end());

    // Display the finishing order
    std::cout << "Finishing order:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << "Runner " << i + 1 << " finished in " << runners[i].timeTaken << " seconds" << std::endl;
    }

    return 0;
}
