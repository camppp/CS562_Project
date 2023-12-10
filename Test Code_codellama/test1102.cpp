#include <mutex>

void capst_journal::trace(const char* message) {
    std::lock_guard<std::mutex> lock(mutex_);
    // Critical section
    // Write the log message to the journal
    // ...
}
