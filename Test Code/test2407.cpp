#include <iostream>

class Timeline {
private:
    bool stopped;
    double speed;

public:
    // Constructor to initialize the timeline with default speed and stopped state
    Timeline() : stopped(true), speed(1.0) {}

    // Method to check if the timeline is in a stopped state
    bool hasStopped() const {
        return stopped;
    }

    // Method to set the speed of the timeline
    void setSpeed(double newSpeed) {
        speed = newSpeed;
        if (speed == 0.0) {
            stopped = true;
        } else {
            stopped = false;
        }
    }
};

int main() {
    // Test the Timeline class
    Timeline timeline;
    std::cout << "Timeline is stopped: " << std::boolalpha << timeline.hasStopped() << std::endl;

    timeline.setSpeed(2.0);
    std::cout << "Timeline is stopped: " << std::boolalpha << timeline.hasStopped() << std::endl;

    timeline.setSpeed(-1.5);
    std::cout << "Timeline is stopped: " << std::boolalpha << timeline.hasStopped() << std::endl;

    return 0;
}
