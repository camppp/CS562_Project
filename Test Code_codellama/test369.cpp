#include <iostream>
#include <chrono>

namespace kTest::utility {

class ProfilerTester : public TesterBase {
public:
    ProfilerTester() {}
    ~ProfilerTester() {}

    void Prepare() override {
        // Set up the necessary resources for profiling
        // ...
    }

    void Profile(const std::function<void()> &func) {
        // Start the timer
        auto start = std::chrono::high_resolution_clock::now();

        // Execute the function
        func();

        // Stop the timer
        auto end = std::chrono::high_resolution_clock::now();

        // Calculate the execution time in milliseconds
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        // Print the execution time
        std::cout << "Execution time: " << duration.count() << " milliseconds" << std::endl;
    }
};

} // namespace kTest::utility
