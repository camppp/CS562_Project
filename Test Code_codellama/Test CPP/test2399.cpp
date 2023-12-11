#include <iostream>
#include <string>
#include <vector>

// Define the states
enum class State {
    SignalLightOff,
    RedSignal,
    GreenSignal
};

// Define the events
enum class Event {
    CarDetected,
    RedSignalOff,
    GreenSignalOff
};

// Define the state machine
class TrafficSignal {
public:
    TrafficSignal() : state_(State::SignalLightOff) {}

    // Handle events
    void handleEvent(Event event) {
        switch (event) {
            case Event::CarDetected:
                state_ = State::RedSignal;
                break;
            case Event::RedSignalOff:
                state_ = State::GreenSignal;
                break;
            case Event::GreenSignalOff:
                state_ = State::RedSignal;
                break;
        }
    }

    // Get the current state
    State getState() {
        return state_;
    }

private:
    State state_;
};

int main() {
    TrafficSignal trafficSignal;

    // Simulate car detection
    trafficSignal.handleEvent(Event::CarDetected);
    std::cout << "Current state: " << trafficSignal.getState() << std::endl;

    // Simulate duration for red signal
    trafficSignal.handleEvent(Event::RedSignalOff);
    std::cout << "Current state: " << trafficSignal.getState() << std::endl;

    // Simulate duration for green signal
    trafficSignal.handleEvent(Event::GreenSignalOff);
    std::cout << "Current state: " << trafficSignal.getState() << std::endl;

    return 0;
}
