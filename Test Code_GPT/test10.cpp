#include <iostream>
#include <functional>
#include <chrono>

class RembThrottler {
public:
    RembThrottler(std::function<void(double)> sender, std::chrono::steady_clock::time_point& clock)
        : senderFunction(sender), clockReference(clock), alpha(0.1), rate(0.0) {}

    // Method to receive network feedback and update throttling parameters
    void receiveFeedback(double feedback) {
        if (feedback >= 0.0 && feedback <= 1.0) {
            // Update exponential moving average with feedback
            rate = alpha * feedback + (1 - alpha) * rate;
        } else {
            std::cerr << "Invalid feedback value. Feedback should be in the range [0.0, 1.0]." << std::endl;
        }
    }

    // Method to calculate the sending rate based on the current network feedback and time elapsed
    void calculateRate() {
        auto currentTime = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsedSeconds = currentTime - clockReference;

        // Calculate the sending rate based on the exponential moving average and time elapsed
        double calculatedRate = rate / elapsedSeconds.count();

        // Interface with the sender function to control the data transmission rate
        senderFunction(calculatedRate);

        // Update the clock reference for the next calculation
        clockReference = currentTime;
    }

private:
    std::function<void(double)> senderFunction;
    std::chrono::steady_clock::time_point& clockReference;
    double alpha; // Smoothing factor for exponential moving average
    double rate;  // Current sending rate
};

// Example usage
int main() {
    // Dummy sender function (replace with actual sender logic)
    auto sender = [](double sendingRate) {
        std::cout << "Sending data at rate: " << sendingRate << " bytes/second" << std::endl;
        // Add your logic to send data at the specified rate
    };

    std::chrono::steady_clock::time_point clockReference = std::chrono::steady_clock::now();

    RembThrottler rembThrottler(sender, clockReference);

    // Simulate receiving network feedback and updating the throttling parameters
    rembThrottler.receiveFeedback(0.8);

    // Simulate calculating the sending rate and interfacing with the sender function
    rembThrottler.calculateRate();

    return 0;
}
