#include <iostream>
#include <chrono>

void simpleTimer(int duration) {
    auto start = std::chrono::high_resolution_clock::now();
    while (std::chrono::high_resolution_clock::now() - start < std::chrono::seconds(duration));
}
