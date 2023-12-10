#include <chrono>

using namespace std::chrono;

long calculateElapsedTime() {
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return duration.count();
}
