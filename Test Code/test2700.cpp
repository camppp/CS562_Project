#include <iostream>
#include <functional>
#include <map>
#include <chrono>
#include <thread>

class Timer {
public:
    using Callback = std::function<void()>;

    void registerTimer(int duration, Callback callback) {
        auto endTime = std::chrono::steady_clock::now() + std::chrono::milliseconds(duration);
        timers_[endTime] = callback;
    }

    void runTimers() {
        while (!timers_.empty()) {
            auto now = std::chrono::steady_clock::now();
            if (timers_.begin()->first <= now) {
                timers_.begin()->second();
                timers_.erase(timers_.begin());
            } else {
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
        }
    }

private:
    std::map<std::chrono::time_point<std::chrono::steady_clock>, Callback> timers_;
};

// Example usage
int main() {
    Timer timer;
    timer.registerTimer(2000, []() { std::cout << "Timer 1 expired" << std::endl; });
    timer.registerTimer(1000, []() { std::cout << "Timer 2 expired" << std::endl; });

    timer.runTimers();

    return 0;
}
