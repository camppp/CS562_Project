#include <mutex>
#include <vector>
#include "diag_msgs.h"  // Assuming the definition of diag_msgs::diag_error

class diag_subscriber {
private:
    std::mutex mtx_;
    std::vector<diag_msgs::diag_error> buffer_;

public:
    void callback_(diag_msgs::diag_error msg) {
        mtx_.lock();
        buffer_.push_back(msg);
        mtx_.unlock();
    }

    void processBuffer() {
        mtx_.lock();
        for (const auto& msg : buffer_) {
            // Process the diagnostic error message (e.g., log, analyze, etc.)
            // Example: ROS_ERROR_STREAM(msg);
        }
        buffer_.clear();
        mtx_.unlock();
    }
};
