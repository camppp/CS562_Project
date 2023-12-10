#include <iostream>
#include <vector>
#include <cmath>

class RembThrottler {
public:
    RembThrottler(SenderFunction sender, ClockReference clock) : sender_(sender), clock_(clock) {}

    void receiveNetworkFeedback(const std::vector<double>& feedback) {
        // Update the throttling parameters based on the network feedback
        for (int i = 0; i < feedback.size(); i++) {
            double feedback_i = feedback[i];
            // Calculate the exponential moving average of the feedback
            double moving_average = (1 - alpha_) * moving_average_ + alpha_ * feedback_i;
            // Update the throttling parameters
            throttling_parameters_[i] = moving_average;
        }
    }

    void calculateSendingRate(double time_elapsed) {
        // Calculate the sending rate based on the current network feedback and time elapsed
        double sending_rate = 0;
        for (int i = 0; i < throttling_parameters_.size(); i++) {
            sending_rate += throttling_parameters_[i] * time_elapsed;
        }
        sending_rate /= time_elapsed;
        return sending_rate;
    }

    void interfaceWithSender(double time_elapsed) {
        // Interface with the sender function to control the data transmission rate
        double sending_rate = calculateSendingRate(time_elapsed);
        sender_(sending_rate);
    }

private:
    SenderFunction sender_;
    ClockReference clock_;
    double alpha_ = 0.5; // Exponential moving average parameter
    std::vector<double> throttling_parameters_;
};
