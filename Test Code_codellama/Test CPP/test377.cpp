#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

class ThreadManager {
public:
    ThreadManager() {}

    void createThread(void (*func)()) {
        std::thread t(func);
        threads.push_back(t);
    }

    void startThread() {
        for (auto& t : threads) {
            t.join();
        }
    }

    void joinThread() {
        for (auto& t : threads) {
            t.join();
        }
    }

private:
    std::vector<std::thread> threads;
};

int main() {
    ThreadManager manager;

    // Create a new thread to execute the function
    manager.createThread([]() {
        std::cout << "Hello from thread!" << std::endl;
    });

    // Start the execution of the thread
    manager.startThread();

    // Wait for the thread to finish its execution
    manager.joinThread();

    return 0;
}
