#include <iostream>
#include <queue>
#include <tuple>
#include <glm/glm.hpp>
#include <chrono>

class PathGenerator {
public:
    void tryPut(std::tuple<int, glm::vec3, glm::vec3> advertisement) {
        // Implement the logic to put the advertisement's ID, position, and data into the path generator
        // Example:
        // pathQueue.push(advertisement);
    }
};

class WaitQueue {
public:
    void push(std::pair<std::pair<int, glm::vec3>, std::pair<double, std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<double>>>> advertisement) {
        // Implement the logic to store the advertisement's ID, position, random wait time, and a time point into the wait queue
        // Example:
        // waitQueue.push(advertisement);
    }
};

int main() {
    PathGenerator pathGenerator;
    WaitQueue waitQueue;

    // Example usage
    int id = 1;
    glm::vec3 position(0.0f, 0.0f, 0.0f);
    glm::vec3 data(1.0f, 2.0f, 3.0f);
    pathGenerator.tryPut(std::make_tuple(id, position, data));

    double randomWaitTime = data.x + glm::linearRand(0.0f, 6.0f);
    waitQueue.push(std::make_pair(std::make_pair(id, position), std::make_pair(randomWaitTime, std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<double>>::min())));

    return 0;
}
