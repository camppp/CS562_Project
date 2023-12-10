#include <iostream>
#include <cmath>

class CustomTimeStamp {
private:
    long seconds;
    long nanoseconds;

public:
    void setTime(long sec, long nsec) {
        seconds = sec;
        nanoseconds = nsec;
    }

    long getSeconds() const {
        return seconds;
    }

    long getNanoSeconds() const {
        return nanoseconds;
    }

    int compare(const CustomTimeStamp& other) const {
        if (seconds > other.seconds) {
            return 1;
        } else if (seconds < other.seconds) {
            return -1;
        } else {
            if (nanoseconds > other.nanoseconds) {
                return 1;
            } else if (nanoseconds < other.nanoseconds) {
                return -1;
            } else {
                return 0;
            }
        }
    }

    void timeDifference(const CustomTimeStamp& other, long& diffSec, long& diffNsec) const {
        diffSec = std::abs(seconds - other.seconds);
        diffNsec = std::abs(nanoseconds - other.nanoseconds);
    }
};

int main() {
    CustomTimeStamp ts1, ts2;
    ts1.setTime(10, 500000000);
    ts2.setTime(8, 700000000);

    std::cout << "Timestamp 1: " << ts1.getSeconds() << " seconds, " << ts1.getNanoSeconds() << " nanoseconds" << std::endl;
    std::cout << "Timestamp 2: " << ts2.getSeconds() << " seconds, " << ts2.getNanoSeconds() << " nanoseconds" << std::endl;

    int comparison = ts1.compare(ts2);
    if (comparison > 0) {
        std::cout << "Timestamp 1 is greater than Timestamp 2" << std::endl;
    } else if (comparison < 0) {
        std::cout << "Timestamp 1 is less than Timestamp 2" << std::endl;
    } else {
        std::cout << "Timestamp 1 is equal to Timestamp 2" << std::endl;
    }

    long diffSec, diffNsec;
    ts1.timeDifference(ts2, diffSec, diffNsec);
    std::cout << "Time difference: " << diffSec << " seconds, " << diffNsec << " nanoseconds" << std::endl;

    return 0;
}
