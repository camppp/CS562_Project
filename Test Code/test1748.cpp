#include <mutex>
#include <thread>

class RecursiveMutex {
public:
    void lock() {
        std::unique_lock<std::mutex> lock(mutex_);
        if (owner_ == std::this_thread::get_id()) {
            ++count_;
            return;
        }
        while (count_ != 0) {
            cv_.wait(lock);
        }
        owner_ = std::this_thread::get_id();
        count_ = 1;
    }

    void unlock() {
        std::unique_lock<std::mutex> lock(mutex_);
        if (owner_ != std::this_thread::get_id()) {
            throw std::logic_error("Mutex is not locked by this thread");
        }
        if (--count_ == 0) {
            owner_ = std::thread::id();
            cv_.notify_one();
        }
    }

    bool try_lock() {
        std::unique_lock<std::mutex> lock(mutex_);
        if (owner_ == std::this_thread::get_id()) {
            ++count_;
            return true;
        }
        if (count_ == 0) {
            owner_ = std::this_thread::get_id();
            count_ = 1;
            return true;
        }
        return false;
    }

private:
    std::mutex mutex_;
    std::condition_variable cv_;
    std::thread::id owner_;
    unsigned int count_ = 0;
};
