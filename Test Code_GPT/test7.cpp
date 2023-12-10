#include <iostream>
#include "TimeImp.h" // Assuming TimeImp is correctly implemented

class CivilianTimeImp : public TimeImp {
public:
    CivilianTimeImp(int hr, int min, int pm) : TimeImp(hr, min), isPM(pm) {}

    void setTime(int hr, int min, int pm) {
        setHour(hr);
        setMinute(min);
        isPM = pm;
    }

    void displayTime() const {
        int hour = getHour();
        int minute = getMinute();

        std::cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":";

        if (minute < 10) {
            std::cout << "0" << minute;
        } else {
            std::cout << minute;
        }

        std::cout << (isPM ? " PM" : " AM") << std::endl;
    }

private:
    int isPM; // Flag indicating whether the time is in the PM (1) or AM (0) period
};

// Example usage
int main() {
    CivilianTimeImp civilianTime(14, 30, 0);
    civilianTime.displayTime(); // Output: 2:30 AM

    civilianTime.setTime(18, 45, 1);
    civilianTime.displayTime(); // Output: 6:45 PM

    return 0;
}
