#include <functional>
#include <chrono>

class RembThrottler {
public:
    RembThrottler(std::function<void()> sender, std::chrono::steady_clock* clock)
        : sender_(sender), clock_(clock), alpha_(0.2), last_feedback_(0), last_send_time_(clock_->now()) {}

    void receiveFeedback(double feedback) {
        last_feedback_ = feedback;
    }

    void adjustSendingRate() {
        auto now = clock_->now();
        std::chrono::duration<double> elapsed_time = now - last_send_time_;
        double instant_rate = last_feedback_ / elapsed_time.count();
        if (last_send_time_ != now) {
            sending_rate_ = alpha_ * instant_rate + (1 - alpha_) * sending_rate_;
            last_send_time_ = now;
            sender_();
        }
    }

private:
    std::function<void()> sender_;
    std::chrono::steady_clock* clock_;
    double alpha_;  // Smoothing factor for exponential moving average
    double last_feedback_;
    std::chrono::time_point<std::chrono::steady_clock> last_send_time_;
    double sending_rate_ = 0;
};
