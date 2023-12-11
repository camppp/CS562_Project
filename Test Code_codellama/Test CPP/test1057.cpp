#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <chrono>

class Queue {
public:
    void wait(int timeout, std::function<bool()> condition) {
        std::unique_lock<std::mutex> lock(mutex_);
        std::chrono::milliseconds timeout_ms(timeout);
        std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
        while (!condition()) {
            if (std::chrono::steady_clock::now() - start > timeout_ms) {
                return false;
            }
            condition_variable_.wait_for(lock, timeout_ms);
        }
        return true;
    }

private:
    std::mutex mutex_;
    std::condition_variable condition_variable_;
    std::atomic_flag locked = ATOMIC_FLAG_INIT;
};

int main() {
    Queue queue;
    std::thread t([&queue]() {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        queue.locked.clear(std::memory_order_release);
    });
    bool result = queue.wait(3000, [&]() {
        return !queue.locked.test_and_set(std::memory_order_acquire);
    });
    std::cout << "Condition met within timeout: " << std::boolalpha << result << std::endl;
    t.join();
    return 0;
}
