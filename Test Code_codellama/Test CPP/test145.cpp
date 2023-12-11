#include <iostream>
#include <chrono>
#include <thread>

class DPC {
public:
    using FunctionType = void(*)(void*);

    DPC(FunctionType function, void* context) : function_(function), context_(context) {}

    void SetTimer(unsigned int delayMs) {
        timer_ = std::chrono::steady_clock::now() + std::chrono::milliseconds(delayMs);
    }

    void Cancel() {
        timer_ = std::chrono::steady_clock::time_point::max();
    }

    ~DPC() {
        Cancel();
    }

    void operator()() {
        if (timer_ > std::chrono::steady_clock::now()) {
            return;
        }

        function_(context_);
    }

private:
    FunctionType function_;
    void* context_;
    std::chrono::steady_clock::time_point timer_;
};
