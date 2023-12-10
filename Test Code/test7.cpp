#include "string.h"
#include "TimeImp.hpp"
#include "CivilianTimeImp.hpp"

class CivilianTimeImp : public TimeImp {
private:
    char whichM_[4]; // To store "AM" or "PM"

public:
    CivilianTimeImp(int hr, int min, int pm) : TimeImp(hr, min) {
        if (pm)
            strcpy(whichM_, " PM");
        else
            strcpy(whichM_, " AM");
    }

    void setTime(int hr, int min, int pm) {
        setHour(hr);
        setMinute(min);
        if (pm)
            strcpy(whichM_, " PM");
        else
            strcpy(whichM_, " AM");
    }

    void displayTime() const {
        int hr = getHour();
        int min = getMinute();
        printf("%02d:%02d%s\n", (hr == 0 || hr == 12) ? 12 : hr % 12, min, whichM_);
    }
};
