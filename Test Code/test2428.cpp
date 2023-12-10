#include <chrono>
#include <future>
#include <stdexcept>

template <typename Function, typename... Args>
auto timeLimitedExecution(Function func, int timeLimit, Args... args) {
    auto future = std::async(std::launch::async, func, args...);
    if (future.wait_for(std::chrono::milliseconds(timeLimit)) == std::future_status::ready) {
        return future.get();
    } else {
        throw std::runtime_error("Time limit exceeded");
    }
}

int main() {
    try {
        auto result = timeLimitedExecution([](int a, int b) { return a + b; }, 1000, 5, 3);
        // Handle the result here
    } catch (const std::exception& e) {
        // Handle the exception here
    }
    return 0;
}
