#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

class CustomLatch {
public:
    CustomLatch(int count) : count_(count) {}

    void await() {
        std::unique_lock<std::mutex> lock(mutex_);
        while (count_ > 0) {
            condition_.wait(lock);
        }
    }

    void countDown() {
        std::unique_lock<std::mutex> lock(mutex_);
        count_--;
        condition_.notify_all();
    }

    int getCount() {
        std::unique_lock<std::mutex> lock(mutex_);
        return count_;
    }

private:
    int count_;
    std::mutex mutex_;
    std::condition_variable condition_;
};
