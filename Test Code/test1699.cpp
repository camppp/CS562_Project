#include <iostream>
#include <string>
#include <stdexcept>

class TimeUnit {
public:
    enum Unit { SECOND, MINUTE, HOUR, DAY, WEEK, MONTH, YEAR };

    TimeUnit(Unit unit, int value) : unit(unit), value(value) {}

    int toSeconds() const {
        int secondsInUnit;
        switch (unit) {
            case SECOND:
                secondsInUnit = value;
                break;
            case MINUTE:
                secondsInUnit = value * 60;
                break;
            case HOUR:
                secondsInUnit = value * 3600;
                break;
            case DAY:
                secondsInUnit = value * 86400;
                break;
            case WEEK:
                secondsInUnit = value * 604800;
                break;
            case MONTH:
                secondsInUnit = value * 2629746;  // Average seconds in a month
                break;
            case YEAR:
                secondsInUnit = value * 31556952;  // Average seconds in a year
                break;
            default:
                throw std::invalid_argument("Unknown time unit");
        }
        return secondsInUnit;
    }

    void convertTo(Unit targetUnit) {
        int currentSeconds = toSeconds();
        switch (targetUnit) {
            case SECOND:
                value = currentSeconds;
                unit = SECOND;
                break;
            case MINUTE:
                value = currentSeconds / 60;
                unit = MINUTE;
                break;
            case HOUR:
                value = currentSeconds / 3600;
                unit = HOUR;
                break;
            case DAY:
                value = currentSeconds / 86400;
                unit = DAY;
                break;
            case WEEK:
                value = currentSeconds / 604800;
                unit = WEEK;
                break;
            case MONTH:
                value = currentSeconds / 2629746;  // Average seconds in a month
                unit = MONTH;
                break;
            case YEAR:
                value = currentSeconds / 31556952;  // Average seconds in a year
                unit = YEAR;
                break;
            default:
                throw std::invalid_argument("Unknown time unit");
        }
    }

private:
    Unit unit;
    int value;
};

int main() {
    TimeUnit time1(TimeUnit::DAY, 5);
    std::cout << "Time 1 in seconds: " << time1.toSeconds() << std::endl;

    time1.convertTo(TimeUnit::WEEK);
    std::cout << "Time 1 converted to weeks: " << time1.toSeconds() << " seconds" << std::endl;

    TimeUnit time2(TimeUnit::HOUR, 3);
    time2.convertTo(TimeUnit::MINUTE);
    std::cout << "Time 2 converted to minutes: " << time2.toSeconds() << " seconds" << std::endl;

    return 0;
}
