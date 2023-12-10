#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>

class CustomLatch {
public:
    explicit CustomLatch(int count) : count_(count) {}

    void await() {
        std::unique_lock<std::mutex> lock(mutex_);
        while (count_ > 0) {
            condition_.wait(lock);
        }
    }

    void countDown() {
        std::lock_guard<std::mutex> lock(mutex_);
        if (count_ > 0) {
            count_--;
            if (count_ == 0) {
                condition_.notify_all();
            }
        }
    }

    int getCount() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return count_;
    }

private:
    int count_;
    mutable std::mutex mutex_;
    std::condition_variable condition_;
};

int main() {
    CustomLatch latch(3);

    std::vector<std::thread> threads;
    for (int i = 0; i < 3; ++i) {
        threads.emplace_back([&latch, i] {
            std::this_thread::sleep_for(std::chrono::seconds(i));
            std::cout << "Thread " << i << " is counting down the latch" << std::endl;
            latch.countDown();
        });
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "All threads have counted down the latch" << std::endl;
    latch.await();
    std::cout << "Latch has reached zero count" << std::endl;

    return 0;
}
