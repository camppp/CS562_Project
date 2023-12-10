#include <iostream>
#include <cmath>

class CustomTimeStamp {
private:
    int seconds;
    int nanoseconds;

public:
    CustomTimeStamp(int seconds, int nanoseconds) {
        this->seconds = seconds;
        this->nanoseconds = nanoseconds;
    }

    void setTime(int seconds, int nanoseconds) {
        this->seconds = seconds;
        this->nanoseconds = nanoseconds;
    }

    int getSeconds() {
        return seconds;
    }

    int getNanoseconds() {
        return nanoseconds;
    }

    bool compare(CustomTimeStamp other) {
        if (seconds > other.seconds) {
            return true;
        } else if (seconds < other.seconds) {
            return false;
        } else {
            return nanoseconds > other.nanoseconds;
        }
    }

    double calculateTimeDifference(CustomTimeStamp other) {
        double secondsDiff = fabs(seconds - other.seconds);
        double nanosecondsDiff = fabs(nanoseconds - other.nanoseconds);
        return secondsDiff + nanosecondsDiff / 1e9;
    }
};

int main() {
    CustomTimeStamp t1(10, 0);
    CustomTimeStamp t2(11, 0);

    std::cout << "t1: " << t1.getSeconds() << "." << t1.getNanoseconds() << std::endl;
    std::cout << "t2: " << t2.getSeconds() << "." << t2.getNanoseconds() << std::endl;

    if (t1.compare(t2)) {
        std::cout << "t1 is less than t2" << std::endl;
    } else {
        std::cout << "t1 is greater than or equal to t2" << std::endl;
    }

    double timeDiff = t1.calculateTimeDifference(t2);
    std::cout << "Time difference: " << timeDiff << " seconds" << std::endl;

    return 0;
}
