#include <Arduino.h>  // Include necessary library for millis() function

class Timer {
private:
    uint32_t duration;  // Duration of the timer in milliseconds
    uint32_t nextTick;  // Next tick time based on the current time plus duration
    bool ticked;        // Flag to indicate if the timer has expired

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
