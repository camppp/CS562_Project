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
        return (int)((stop - start) / 1000); // Calculate the elapsed time in seconds and round down to the nearest whole number.
    }
};
