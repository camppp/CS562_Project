#include <iostream>
#include <memory>
#include <vector>
#include <functional>

// TimerBase class representing the base class for timers
class TimerBase {
public:
    virtual ~TimerBase() {}
    virtual void addTimer(int expiration, std::function<void()> callback) = 0;
    virtual void advance(int ticks) = 0;
    virtual std::vector<std::function<void()>> getExpiredTimers() = 0;
};

// HHWheelTimer class representing the hierarchical hash-based wheel timer
class HHWheelTimer : public TimerBase {
public:
    HHWheelTimer() {
        // Initialize the wheel with 10 slots
        for (int i = 0; i < 10; i++) {
            slots_.push_back(std::vector<std::function<void()>>());
        }
    }

    void addTimer(int expiration, std::function<void()> callback) override {
        // Calculate the slot index based on the expiration time
        int slotIndex = expiration / 10;

        // Add the timer to the corresponding slot
        slots_[slotIndex].push_back(callback);
    }

    void advance(int ticks) override {
        // Advance the wheel by the specified number of ticks
        for (int i = 0; i < ticks; i++) {
            // Check for expired timers in each slot
            for (int j = 0; j < slots_.size(); j++) {
                if (!slots_[j].empty()) {
                    // Call the callback function for each expired timer
                    for (auto& callback : slots_[j]) {
                        callback();
                    }
                    // Clear the slot
                    slots_[j].clear();
                }
            }
        }
    }

    std::vector<std::function<void()>> getExpiredTimers() override {
        // Return all expired timers
        std::vector<std::function<void()>> expiredTimers;
        for (int i = 0; i < slots_.size(); i++) {
            if (!slots_[i].empty()) {
                expiredTimers.insert(expiredTimers.end(), slots_[i].begin(), slots_[i].end());
            }
        }
        return expiredTimers;
    }

private:
    // Array of slots, each representing a specific time interval
    std::vector<std::vector<std::function<void()>>> slots_;
};

// Factory method returning a TimerBase object
std::shared_ptr<TimerBase> createTimer() {
    return std::shared_ptr<TimerBase>(new HHWheelTimer());
}

int main() {
    // Create a timer using the factory method
    std::shared_ptr<TimerBase> timer = createTimer();

    // Add timers, advance the wheel, and retrieve expired timers
    timer->addTimer(10, [](){ std::cout << "Timer 1 expired" << std::endl; });
    timer->addTimer(5, [](){ std::cout << "Timer 2 expired" << std::endl; });
    timer->advance(5);
    std::vector<std::function<void()>> expiredTimers = timer->getExpiredTimers();
    for (const auto& callback : expiredTimers) {
        callback();
    }

    return 0;
}
