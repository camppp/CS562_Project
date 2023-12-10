#include <mutex>
#include <condition_variable>

class condition_semaphore {
public:
    constexpr condition_semaphore() noexcept = default;
    condition_semaphore(condition_semaphore const&) = delete;
    condition_semaphore& operator=(condition_semaphore const&) = delete;

    ~condition_semaphore() {
        my.load(memory_order_acquire); // barrier
        if(mysemaphore)
            CloseHandle(mysemaphore);
    }

    void wait() {
        std::unique_lock<std::mutex> lock(mutex);
        condition.wait(lock, [this] { return my.load(std::memory_order_acquire) != 0; });
    }

    void notify() {
        std::lock_guard<std::mutex> lock(mutex);
        my.store(1, std::memory_order_release);
        condition.notify_one();
    }

private:
    std::atomic<int> my{0};
    std::mutex mutex;
    std::condition_variable condition;
};
