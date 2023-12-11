#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

class TaskScheduler {
public:
    TaskScheduler(int numThreads) : numThreads_(numThreads) {
        tasks_.reserve(numThreads);
        for (int i = 0; i < numThreads; ++i) {
            threads_.emplace_back([this] {
                while (true) {
                    std::unique_lock<std::mutex> lock(mutex_);
                    condition_.wait(lock, [this] { return !tasks_.empty(); });
                    auto task = tasks_.front();
                    tasks_.pop_front();
                    lock.unlock();
                    task();
                }
            });
        }
    }

    ~TaskScheduler() {
        for (auto& thread : threads_) {
            thread.join();
        }
    }

    void schedule(std::function<void()> task) {
        std::unique_lock<std::mutex> lock(mutex_);
        tasks_.push_back(task);
        condition_.notify_one();
    }

    void execute() {
        for (auto& thread : threads_) {
            thread.join();
        }
    }

private:
    int numThreads_;
    std::vector<std::thread> threads_;
    std::vector<std::function<void()>> tasks_;
    std::mutex mutex_;
    std::condition_variable condition_;
};
