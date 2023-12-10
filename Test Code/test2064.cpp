#include <atomic>

class Timer {
public:
    double get_elapsed_time() const {
        // implementation of getting elapsed time
        return 0.0;  // placeholder, actual implementation depends on the timer
    }
};

bool checkTimeoutAndStop(const Timer& timer, std::atomic<bool>& global_stop_flag, double timeout, double skip_timeout, bool& skip_step) {
    if (timer.get_elapsed_time() > timeout || global_stop_flag.load(std::memory_order_acquire)) {
        return true;
    }
    if (timer.get_elapsed_time() > skip_timeout) {
        skip_step = true;
        return true;
    }
    return false;
}
