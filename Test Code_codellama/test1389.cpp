#include <iostream>
#include <functional>
#include <thread>
#include <mutex>
#include <condition_variable>

class CCallbackTimer {
public:
    CCallbackTimer(std::function<void()> callback, int delay) : callback_(callback), delay_(delay) {}

    void start() {
        std::lock_guard<std::mutex> lock(mutex_);
        if (thread_.joinable()) {
            thread_.join();
        }
        thread_ = std::thread([this]() {
            std::unique_lock<std::mutex> lock(mutex_);
            while (true) {
                if (delay_ > 0) {
                    std::this_thread::sleep_for(std::chrono::seconds(delay_));
                    delay_ = 0;
                }
                if (callback_) {
                    callback_();
                }
                if (delay_ == 0) {
                    break;
                }
            }
        });
    }

    void stop() {
        std::lock_guard<std::mutex> lock(mutex_);
        if (thread_.joinable()) {
            thread_.join();
        }
    }

    void reset() {
        std::lock_guard<std::mutex> lock(mutex_);
        delay_ = 0;
    }

private:
    std::function<void()> callback_;
    int delay_;
    std::thread thread_;
    std::mutex mutex_;
};
