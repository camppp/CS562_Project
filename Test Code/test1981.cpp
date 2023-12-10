#include <Arduino.h>

class Timer {
private:
    uint32_t duration;
    uint32_t nextTick;
    bool ticked;

public:
    Timer(uint32_t duration) : duration(duration), nextTick(0), ticked(false) {}

    void start() {
        nextTick = millis() + duration;
        ticked = false;
    }

    bool hasTicked() {
        if (!ticked)
            ticked = (0 >= (int32_t)(nextTick - millis()));
        return ticked;
    }
};

int main() {
    // Create a timer with a duration of 1000 milliseconds
    Timer timer(1000);

    // Start the timer
    timer.start();

    // Simulate time passing
    delay(500);

    // Check if the timer has expired
    if (timer.hasTicked()) {
        Serial.println("Timer has expired");
    } else {
        Serial.println("Timer has not expired");
    }

    return 0;
}
