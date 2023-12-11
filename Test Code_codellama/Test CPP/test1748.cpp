#include <mutex>
#include <condition_variable>

class RecursiveMutex {
public:
    RecursiveMutex() : lockCount(0) {}

    void lock() {
        std::unique_lock<std::mutex> lock(mutex);
        if (lockCount == 0) {
            // First lock, acquire the mutex
            mutex.lock();
        } else {
            // Increment the lock count
            lockCount++;
        }
    }

    void unlock() {
        std::unique_lock<std::mutex> lock(mutex);
        if (lockCount == 0) {
            // Mutex is already unlocked, do nothing
        } else if (lockCount == 1) {
            // Last lock, release the mutex
            mutex.unlock();
        } else {
            // Decrement the lock count
            lockCount--;
        }
    }

    bool try_lock() {
        std::unique_lock<std::mutex> lock(mutex, std::try_to_lock);
        if (lock.owns_lock()) {
            // Mutex was acquired, increment the lock count
            lockCount++;
            return true;
        } else {
            // Mutex was not acquired, return false
            return false;
        }
    }

private:
    std::mutex mutex;
    int lockCount;
};
