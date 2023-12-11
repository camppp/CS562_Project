#include <iostream>

class TimeImp {
public:
    TimeImp(int hr, int min) : hour(hr), minute(min) {}
    virtual void displayTime() const = 0;

protected:
    int hour;
    int minute;
};

class CivilianTimeImp : public TimeImp {
public:
    CivilianTimeImp(int hr, int min, int pm) : TimeImp(hr, min), isPM(pm) {}

    void setTime(int hr, int min, int pm) {
        hour = hr;
        minute = min;
        isPM = pm;
    }

    void displayTime() const override {
        std::cout << (hour % 12? hour % 12 : 12) << ":" << (minute < 10? "0" : "") << minute << " " << (isPM? "PM" : "AM") << std::endl;
    }

private:
    bool isPM;
};