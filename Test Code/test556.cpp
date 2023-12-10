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
    auto start_time = std::chrono::system_clock::now();
    int ccount = 0;

    // Measure the number of cycles executed within a 2-second time interval
    while (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - start_time).count() < 2) {
        processor.cycle();
        ++ccount;
    }
    std::cout << "Number of cycles executed in 2 seconds: " << ccount << std::endl;

    return 0;
}
