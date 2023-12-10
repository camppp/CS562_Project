#include <mutex>
#include <vector>
#include <diag_msgs/diag_error.h>

class diag_subscriber {
public:
    diag_subscriber() : mtx_(), buffer_() {}

    void callback_(const diag_msgs::diag_error& msg) {
        std::lock_guard<std::mutex> lock(mtx_);
        buffer_.push_back(msg);
    }

    void processBuffer() {
        std::lock_guard<std::mutex> lock(mtx_);
        for (const auto& msg : buffer_) {
            // Process the diagnostic error message
        }
        buffer_.clear();
    }

private:
    std::mutex mtx_;
    std::vector<diag_msgs::diag_error> buffer_;
};
