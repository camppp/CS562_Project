#include <iostream>

class Timer {
private:
    long start;
    long stop;

public:
    void startTimer() {
        start = getCurrentTime(); // Assume this function returns the current time in milliseconds.
    }

    void stopTimer() {
        stop = getCurrentTime(); // Assume this function returns the current time in milliseconds.
    }

    int getSeconds() {
        return static_cast<int>((stop - start) / 1000); // Calculate elapsed time in seconds and cast to int.
    }
};
