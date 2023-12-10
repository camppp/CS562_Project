#include <iostream>
#include <string>

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    void setTime(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
    }

    std::string getTime() {
        return std::to_string(hour) + ":" + std::to_string(minute) + ":" + std::to_string(second);
    }

    void addSeconds(int s) {
        int totalSeconds = hour * 3600 + minute * 60 + second + s;
        hour = (totalSeconds / 3600) % 24;
        minute = (totalSeconds / 60) % 60;
        second = totalSeconds % 60;
    }

    void subtractSeconds(int s) {
        int totalSeconds = hour * 3600 + minute * 60 + second - s;
        if (totalSeconds < 0) {
            totalSeconds += 86400;  // Adding a day's worth of seconds
        }
        hour = (totalSeconds / 3600) % 24;
        minute = (totalSeconds / 60) % 60;
        second = totalSeconds % 60;
    }
};

int main() {
    Time showtime;
    showtime.setTime(21, 30, 0);
    std::cout << "Initial Time: " << showtime.getTime() << std::endl;

    showtime.addSeconds(3600);
    std::cout << "Time after adding 3600 seconds: " << showtime.getTime() << std::endl;

    showtime.subtractSeconds(1800);
    std::cout << "Time after subtracting 1800 seconds: " << showtime.getTime() << std::endl;

    return 0;
}
