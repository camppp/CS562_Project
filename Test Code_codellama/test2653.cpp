#include <emscripten/emscripten.h>
#include <emscripten/bind.h>
#include <functional>
#include <vector>
#include <thread>

class TaskScheduler {
public:
    void AddTask(std::function<void()> task) {
        tasks_.push_back(task);
    }

    void RunTasks() {
        for (auto& task : tasks_) {
            emscripten::async(task);
        }
    }

private:
    std::vector<std::function<void()>> tasks_;
};
