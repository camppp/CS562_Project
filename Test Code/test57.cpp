#include <chrono>

class DisjSet {
    // Assume implementation of Disjoint Set data structure
};

class Timer {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;

public:
    Timer() : start_time(std::chrono::high_resolution_clock::now()) {}

    long long calculateElapsedTime() {
        auto end_time = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    }
};

long long calculateElapsedTime() {
    Timer timer;
    return timer.calculateElapsedTime();
}
