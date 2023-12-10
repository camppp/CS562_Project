#include <mutex>

class LockingMechanism {
private:
    std::mutex mtx;

public:
    void lock() {
        mtx.lock();
    }

    void unlock() {
        mtx.unlock();
    }
};
