#include <mutex>
#include <vector>

class Scheduler {
public:
    Scheduler(uint32_t size, bool initializer = true) : size_(size), tasks_(size, initializer) {}

    ~Scheduler() {
        std::lock_guard<std::mutex> lock(mutex_);
        tasks_.clear();
    }

    void setTask(uint32_t index) {
        std::lock_guard<std::mutex> lock(mutex_);
        tasks_[index] = true;
    }

    void clearTask(uint32_t index) {
        std::lock_guard<std::mutex> lock(mutex_);
        tasks_[index] = false;
    }

    bool allTasksCompleted() const {
        std::lock_guard<std::mutex> lock(mutex_);
        for (const auto& task : tasks_) {
            if (!task) {
                return false;
            }
        }
        return true;
    }

private:
    std::mutex mutex_;
    uint32_t size_;
    std::vector<bool> tasks_;
};
