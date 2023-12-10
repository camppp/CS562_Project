#include <iostream>
#include <cstdlib>
#include <ctime>

class Runner {
public:
    void Run() {
        // Simulate running process with a random time delay
        int timeTaken = rand() % 10 + 1;  // Random time between 1 and 10 seconds
        std::cout << "Runner finished in " << timeTaken << " seconds" << std::endl;
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

    // Display the finishing order of the runners
    std::cout << "Finishing order: ";
    if (runner1.timeTaken < runner2.timeTaken && runner1.timeTaken < runner3.timeTaken) {
        std::cout << "Runner 1";
    } else if (runner2.timeTaken < runner1.timeTaken && runner2.timeTaken < runner3.timeTaken) {
        std::cout << "Runner 2";
    } else {
        std::cout << "Runner 3";
    }
    std::cout << std::endl;

    return 0;
}
