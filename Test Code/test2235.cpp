#include <mutex>

class LockingMechanism {
private:
    std::mutex mtx;

public:
    void lock() {
        std::unique_lock<std::mutex> lock(mtx);
        while (lock.try_lock() == false) {
            // Wait for the lock to be released by another thread
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

    void unlock() {
        mtx.unlock();
    }
};
