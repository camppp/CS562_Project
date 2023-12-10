#include <mutex>
#include <vector>

class Scheduler {
private:
    std::mutex scheduleMutex;
    std::vector<bool> schedule;

public:
    Scheduler(uint32_t size, bool initializer = true) : schedule(size, initializer) {}

    ~Scheduler() {}

    void setTask(uint32_t index) {
        std::lock_guard<std::mutex> lock(scheduleMutex);
        if (index < schedule.size()) {
            schedule[index] = true;
        }
    }

    void clearTask(uint32_t index) {
        std::lock_guard<std::mutex> lock(scheduleMutex);
        if (index < schedule.size()) {
            schedule[index] = false;
        }
    }

    bool allTasksCompleted() const {
        std::lock_guard<std::mutex> lock(scheduleMutex);
        for (bool task : schedule) {
            if (!task) {
                return false;
            }
        }
        return true;
    }
};
