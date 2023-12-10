#include <future>
#include <chrono>

class timed_waiter {
public:
    timed_waiter(std::future<T> future) : future_(future) {}

    std::future_status wait_until(const std::chrono::time_point<clock, duration>& timeout_time) {
        std::future_status status = std::future_status::timeout;
        while (status == std::future_status::timeout && future_.wait_until(timeout_time) == std::future_status::timeout) {
            status = future_.wait_until(timeout_time);
        }
        return status;
    }

    std::future_status wait_for(const std::chrono::duration<rep, period>& rel_time) {
        std::future_status status = std::future_status::timeout;
        while (status == std::future_status::timeout && future_.wait_for(rel_time) == std::future_status::timeout) {
            status = future_.wait_for(rel_time);
        }
        return status;
    }

private:
    std::future<T> future_;
};
