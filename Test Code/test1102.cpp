#include <iostream>
#include <mutex>
#include <string>
#include <vector>

class CapstJournal {
public:
    void trace(const std::function<void()>& logFunction) {
        std::lock_guard<std::mutex> lock(mutex_);
        logFunction();
    }

private:
    std::mutex mutex_;
};

int main() {
    CapstJournal capst_journal;

    // Example usage
    capst_journal.trace([]{
        std::string text = "Logging a message";
        // Perform any additional logging operations here
        std::cout << text << std::endl;
    });

    return 0;
}
