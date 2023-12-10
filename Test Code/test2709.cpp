#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

class Scheduler {
public:
    Scheduler() : running(true) {}

    void startAsync() {
        worker = std::thread([this] { this->run(); });
    }

    void addTask(void (*task)()) {
        std::unique_lock<std::mutex> lock(mutex);
        tasks.push(task);
        condition.notify_one();
    }

    void run() {
        while (running) {
            std::unique_lock<std::mutex> lock(mutex);
            condition.wait(lock, [this] { return !tasks.empty() || !running; });
            if (!tasks.empty()) {
                auto task = tasks.front();
                tasks.pop();
                lock.unlock();  // Release the lock before executing the task
                task();  // Execute the task
            }
        }
    }

    ~Scheduler() {
        running = false;
        condition.notify_one();  // Notify the running thread to exit
        if (worker.joinable()) {
            worker.join();
        }
    }

private:
    std::queue<void (*)()> tasks;
    std::mutex mutex;
    std::condition_variable condition;
    std::thread worker;
    bool running;
};

void bar() {
    std::cout << "bar(): notify" << std::endl;
}

void foo() {
    std::cout << "foo(): notify" << std::endl;
}

int main() {
    Scheduler scheduler;
    scheduler.startAsync();

    scheduler.addTask(bar);
    scheduler.addTask(foo);

    getchar();  // Wait for user input

    return 0;
}
