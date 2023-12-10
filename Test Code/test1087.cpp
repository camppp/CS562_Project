#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

class main_thread_callback {
public:
    virtual void callback_run() = 0;
};

namespace {
    typedef std::function<void()> func_t;

    class mtcallback_func : public main_thread_callback {
    public:
        mtcallback_func(func_t const &f) : m_f(f) {}

        void callback_run() {
            m_f();
        }

    private:
        func_t m_f;
    };
}

void executeCallbackInMainThread(mtcallback_func& callback) {
    std::mutex mtx;
    std::condition_variable cv;
    bool callbackExecuted = false;

    // Create a separate thread to execute the callback function
    std::thread callbackThread([&]() {
        // Simulate some work before executing the callback
        std::this_thread::sleep_for(std::chrono::seconds(2));

        // Execute the callback function
        callback.callback_run();

        // Notify the main thread about the completion of the callback execution
        {
            std::lock_guard<std::mutex> lock(mtx);
            callbackExecuted = true;
        }
        cv.notify_one();
    });

    // Wait for the callback execution to complete in the main thread
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&] { return callbackExecuted; });
    }

    callbackThread.join();
}

int main() {
    // Create an instance of mtcallback_func with a lambda function as the callback
    mtcallback_func callback([]() {
        std::cout << "Callback function executed" << std::endl;
    });

    // Execute the callback in the main thread
    executeCallbackInMainThread(callback);

    return 0;
}
