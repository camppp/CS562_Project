#include <iostream>
#include <chrono>

void simpleTimer(int duration) {
    auto start = std::chrono::high_resolution_clock::now();
    while (true) {
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        if (elapsed.count() >= duration) {
            break;
        }
    }
}

int main() {
    std::cout << "Timer started\n";
    simpleTimer(5); // This should pause the program for 5 seconds
    std::cout << "Timer ended\n";
    return 0;
}
