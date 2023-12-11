#include <chrono>

std::chrono::time_point<std::chrono::high_resolution_clock> start_time;

void startTimer() {
    start_time = std::chrono::high_resolution_clock::now();
}

long long calculateElapsedTime() {
    auto end_time = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
}


startTimer();
// your code here
long long elapsed_time = calculateElapsedTime();
std::cout << "Elapsed time: " << elapsed_time << " milliseconds" << std::endl;