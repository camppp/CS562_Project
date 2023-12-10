#include <iostream>
#include <chrono>

class Processor {
public:
    void cycle() {
        // Simulate processing cycle
    }
};

int main() {
    Processor processor;
    auto time_point = std::chrono::high_resolution_clock::now();
    int ccount = 0;

    // Your task is to complete the following loop to measure the number of cycles
    while (std::chrono::high_resolution_clock::now() - time_point < std::chrono::seconds(2)) {
        processor.cycle();
        ++ccount;
    }
    std::cout << ccount << std::endl;

    return 0;
}
