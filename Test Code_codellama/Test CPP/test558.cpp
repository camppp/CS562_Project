#include <mutex>
#include <condition_variable>

class condition_semaphore {
public:
    condition_semaphore() : condition_(), mutex_(), waiting_threads_() {}

    ~condition_semaphore() {
        std::unique_lock<std::mutex> lock(mutex_);
        waiting_threads_.clear();
    }

    void wait() {
        std::unique_lock<std::mutex> lock(mutex_);
        while (!condition_) {
            condition_.wait(lock);
        }
    }

    void notify() {
        std::unique_lock<std::mutex> lock(mutex_);
        if (!waiting_threads_.empty()) {
            condition_.notify_one();
        }
    }

private:
    std::condition_variable condition_;
    std::mutex mutex_;
    std::vector<std::thread::id> waiting_threads_;
};
