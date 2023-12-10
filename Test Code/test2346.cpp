#include <mutex>
#include <condition_variable>

class MultiThreadedLock {
private:
    std::mutex mtx;
    std::condition_variable cv;
    int numReaders;
    bool isWriter;

public:
    MultiThreadedLock() : numReaders(0), isWriter(false) {}

    bool tryLockRead() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this] { return !isWriter; });
        ++numReaders;
        return true;
    }

    bool tryLockWrite() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this] { return numReaders == 0 && !isWriter; });
        isWriter = true;
        return true;
    }

    int lockStatus() const {
        std::lock_guard<std::mutex> lock(mtx);
        if (isWriter) {
            return -1; // Write lock acquired
        } else {
            return numReaders; // Number of read locks acquired
        }
    }

    void unlockRead() {
        std::lock_guard<std::mutex> lock(mtx);
        if (numReaders > 0) {
            --numReaders;
            if (numReaders == 0) {
                cv.notify_all();
            }
        }
    }

    void unlockWrite() {
        std::lock_guard<std::mutex> lock(mtx);
        isWriter = false;
        cv.notify_all();
    }
};
