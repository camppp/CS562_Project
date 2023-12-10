#include <emscripten/emscripten.h>
#include <emscripten/bind.h>
#include <functional>
#include <vector>
#include <thread>

class TaskScheduler {
public:
    void AddTask(std::function<void()> task) {
        tasks.push_back(task);
    }

    void RunTasks() {
        for (auto& task : tasks) {
            emscripten_async([](void* taskPtr) {
                auto task = *static_cast<std::function<void()>*>(taskPtr);
                task();
                delete static_cast<std::function<void()>*>(taskPtr);
            }, new std::function<void()>(task), nullptr);
        }
    }

private:
    std::vector<std::function<void()>> tasks;
};

// Example usage
int main() {
    TaskScheduler scheduler;
    scheduler.AddTask([]() {
        // Task 1 implementation
    });
    scheduler.AddTask([]() {
        // Task 2 implementation
    });
    scheduler.RunTasks();
    return 0;
}
