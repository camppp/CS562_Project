#include <iostream>
#include <string>
#include <mutex>
#include <thread>

class ArithmeticEvaluator {
public:
    ArithmeticEvaluator(int max_x) : max_x_(max_x) {}

    std::string evaluate(const std::string& expr) {
        std::lock_guard<std::mutex> lock(mutex_);
        set_print(is_print_);
        set_num_threads(num_threads_);
        return pi(expr);
    }

    void enablePrint(bool is_print) {
        std::lock_guard<std::mutex> lock(mutex_);
        is_print_ = is_print;
    }

    void setNumThreads(int num_threads) {
        std::lock_guard<std::mutex> lock(mutex_);
        num_threads_ = num_threads;
    }

private:
    int max_x_;
    bool is_print_ = false;
    int num_threads_ = 1;
    std::mutex mutex_;
};
