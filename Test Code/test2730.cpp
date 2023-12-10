#include <iostream>
#include <thread>
#include <vector>
#include <functional>
#include <mutex>
#include <condition_variable>

class TaskScheduler {
public:
    TaskScheduler() : counter(0) {}

    void schedule(const std::function<void()>& task) {
        std::unique_lock<std::mutex> lock(mutex);
        tasks.push_back(task);
    }

    void execute() {
        std::vector<std::thread> threads;
        for (int i = 0; i < tasks.size(); ++i) {
            threads.emplace_back([this, i] {
                std::unique_lock<std::mutex> lock(mutex);
                if (i < tasks.size()) {
                    tasks[i]();
                    ++counter;
                }
                cv.notify_one();
            });
        }

        for (auto& t : threads) {
            t.join();
        }
    }

    int getCounter() const {
        return counter;
    }

private:
    std::vector<std::function<void()>> tasks;
    std::mutex mutex;
    std::condition_variable cv;
    int counter;
};

int main() {
    TaskScheduler scheduler;

    // Schedule tasks
    scheduler.schedule([] { std::cout << "Task 1 executed" << std::endl; });
    scheduler.schedule([] { std::cout << "Task 2 executed" << std::endl; });
    scheduler.schedule([] { std::cout << "Task 3 executed" << std::endl; });

    // Execute tasks concurrently
    scheduler.execute();

    // Verify the counter
    std::cout << "Total tasks executed: " << scheduler.getCounter() << std::endl;

    return 0;
}
