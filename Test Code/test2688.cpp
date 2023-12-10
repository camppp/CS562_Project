#include <iostream>
#include <chrono>

class Panel {
public:
    void init() {
        // Initialize the panel
    }

    void openPanel() {
        // Set the duration of the animation
        int duration = 500;
        if (setDuration != nullptr) {
            duration = setDuration();
        }

        // Print the message
        std::cout << "Opening panel with animation for " << duration << " milliseconds" << std::endl;

        // Open the panel with animation
        // ...
    }

    void closePanel() {
        // Set the duration of the animation
        int duration = 500;
        if (setDuration != nullptr) {
            duration = setDuration();
        }

        // Print the message
        std::cout << "Closing panel with animation for " << duration << " milliseconds" << std::endl;

        // Close the panel with animation
        // ...
    }

    void setDuration(int duration) {
        this->duration = duration;
    }

private:
    int duration;
};
