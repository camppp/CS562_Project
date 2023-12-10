bool checkTimeoutAndStop(const Timer& timer, std::atomic<bool>& global_stop_flag, double timeout, double skip_timeout, bool& skip_step) {
    // Check if the global stop flag is set
    if (global_stop_flag) {
        return true;
    }

    // Check if the elapsed time exceeds the timeout
    if (timer.elapsed() > timeout) {
        return true;
    }

    // Check if the elapsed time exceeds the skip timeout
    if (timer.elapsed() > skip_timeout) {
        skip_step = true;
        return true;
    }

    // If none of the above conditions are met, return false
    return false;
}
