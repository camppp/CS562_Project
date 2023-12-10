#include <iostream>
#include <memory>
#include <vector>
#include <functional>
#include <unordered_map>

class TimerBase {
public:
    virtual ~TimerBase() {}
    virtual void addTimer(int expiration, std::function<void()> callback) = 0;
    virtual void advance(int ticks) = 0;
    virtual std::vector<std::function<void()>> getExpiredTimers() = 0;
};

class HHWheelTimer : public TimerBase {
private:
    // Define the structure to hold timers at each slot of the wheel
    std::vector<std::unordered_map<int, std::function<void()>>> wheel;
    int currentSlot;

public:
    HHWheelTimer() : wheel(5), currentSlot(0) {}

    void addTimer(int expiration, std::function<void()> callback) override {
        int slot = (currentSlot + expiration) % wheel.size();
        wheel[slot][expiration] = callback;
    }

    void advance(int ticks) override {
        currentSlot = (currentSlot + ticks) % wheel.size();
    }

    std::vector<std::function<void()>> getExpiredTimers() override {
        std::vector<std::function<void()>> expiredTimers;
        for (const auto& timer : wheel[currentSlot]) {
            expiredTimers.push_back(timer.second);
        }
        wheel[currentSlot].clear();
        return expiredTimers;
    }
};

std::shared_ptr<TimerBase> createTimer() {
    return std::shared_ptr<TimerBase>(new HHWheelTimer());
}

int main() {
    std::shared_ptr<TimerBase> timer = createTimer();

    timer->addTimer(10, [](){ std::cout << "Timer 1 expired" << std::endl; });
    timer->addTimer(5, [](){ std::cout << "Timer 2 expired" << std::endl; });
    timer->advance(5);
    std::vector<std::function<void()>> expiredTimers = timer->getExpiredTimers();
    for (const auto& callback : expiredTimers) {
        callback();
    }

    return 0;
}
