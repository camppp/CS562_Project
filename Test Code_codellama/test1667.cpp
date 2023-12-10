#include <iostream>
#include <chrono>

class IcePerfDerived : public IcePerfBase {
public:
    void initLeader() {
        // Measure the time taken to initialize the leader process
        auto start = std::chrono::steady_clock::now();
        // Initialize the leader process
        // ...
        auto end = std::chrono::steady_clock::now();
        // Calculate the time taken to initialize the leader process
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        // Print the time taken to initialize the leader process in milliseconds
        std::cout << "Time taken to initialize leader process: " << duration.count() << " milliseconds" << std::endl;
    }
};
