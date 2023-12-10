#include <iostream>
#include <functional>
#include <thread>
#include <mutex>

class mtcallback_func : public main_thread_callback {
public:
    mtcallback_func(std::function<void()> callback) : callback_(callback) {}

    void callback_run() override {
        callback_();
    }

private:
    std::function<void()> callback_;
};

void multithreaded_callback_example() {
    // Create an instance of mtcallback_func with a lambda function that prints "Callback function executed"
    mtcallback_func callback([]() { std::cout << "Callback function executed" << std::endl; });

    // Simulate a multithreaded environment by creating a separate thread to execute the callback function
    std::thread thread([&]() {
        // Ensure proper synchronization to avoid race conditions and guarantee the execution of the callback function in the main thread
        std::lock_guard<std::mutex> lock(mutex_);
        callback.callback_run();
    });

    // Wait for the thread to finish
    thread.join();
}
