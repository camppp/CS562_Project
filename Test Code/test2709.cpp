#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

class Scheduler {
public:
    Scheduler() : running(false) {}

    void startAsync() {
        running = true;
        thread = std::thread(&Scheduler::run, this);
    }

    void addTask(std::function<void()> task) {
        std::lock_guard<std::mutex> lock(mutex);
        tasks.push_back(task);
        condition.notify_one();
    }

private:
    void run() {
        while (running) {
            std::function<void()> task;
            {
                std::unique_lock<std::mutex> lock(mutex);
                condition.wait(lock, [this] { return !tasks.empty(); });
                task = tasks.front();
                tasks.pop_front();
            }
            task();
        }
    }

    std::mutex mutex;
    std::condition_variable condition;
    std::deque<std::function<void()>> tasks;
    std::thread thread;
    bool running;
};

int main() {
    Scheduler scheduler;
    scheduler.startAsync();

    scheduler.addTask([] { std::cout << "bar" << std::endl; });
    scheduler.addTask([] { std::cout << "foo" << std::endl; });

    std::cout << "Press enter to exit" << std::endl;
    std::cin.get();

    return 0;
}
