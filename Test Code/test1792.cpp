#include <chrono>

class Timer {
private:
    std::chrono::high_resolution_clock::time_point startTime;
    std::chrono::high_resolution_clock::time_point endTime;
    bool running;

public:
    Timer() : running(false) {}

    void start() {
        if (!running) {
            startTime = std::chrono::high_resolution_clock::now();
            running = true;
        }
    }

    void stop() {
        if (running) {
            endTime = std::chrono::high_resolution_clock::now();
            running = false;
        }
    }

    float elapsed() const {
        if (running) {
            std::chrono::duration<float> duration = std::chrono::high_resolution_clock::now() - startTime;
            return duration.count();
        } else {
            std::chrono::duration<float> duration = endTime - startTime;
            return duration.count();
        }
    }
};
