#include <chrono>
#include <future>
#include <stdexcept>

template <typename Function, typename... Args>
auto timeLimitedExecution(Function func, int timeLimit, Args... args) {
    using namespace std::chrono;

    // Create a future to hold the result of the function
    std::future<decltype(func(args...))> future = std::async(func, args...);

    // Create a deadline for the function to complete within
    auto deadline = high_resolution_clock::now() + milliseconds(timeLimit);

    // Wait for the function to complete within the time limit
    if (future.wait_until(deadline) == std::future_status::timeout) {
        // The function exceeded the time limit, return a default value or throw an exception
        return decltype(func(args...))();
    }

    // The function completed within the time limit, return its result
    return future.get();
}
