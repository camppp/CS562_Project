void wait(int timeout, std::function<bool()> condition) {
    std::unique_lock<std::mutex> lock(mutex);
    std::chrono::milliseconds duration(timeout);
    if (!condition()) {
        if (condition_variable.wait_for(lock, duration, condition)) {
            return true;
        } else {
            return false;
        }
    }
    return true;
}
