#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

class ArithmeticEvaluator {
public:
    ArithmeticEvaluator(int max_x) : max_x_(max_x) {}

    std::string evaluate(const std::string& expr) {
        std::lock_guard<std::mutex> lock(mutex_);
        return pi(expr, max_x_);
    }

    void enablePrint(bool enable) {
        std::lock_guard<std::mutex> lock(mutex_);
        set_print(enable);
    }

    void setNumThreads(int num_threads) {
        std::lock_guard<std::mutex> lock(mutex_);
        set_num_threads(num_threads);
    }

private:
    int max_x_;
    std::mutex mutex_;
    std::condition_variable cv_;
    std::vector<std::thread> threads_;
};
