#include <iostream>
#include <string>
#include <stdexcept>

class TimeUnit {
public:
    enum Unit { SECOND, MINUTE, HOUR, DAY, WEEK, MONTH, YEAR };

    TimeUnit(Unit unit, int value) : unit(unit), value(value) {}

    int toSeconds() const {
        switch (unit) {
            case SECOND:
                return value;
            case MINUTE:
                return value * 60;
            case HOUR:
                return value * 3600;
            case DAY:
                return value * 86400;
            case WEEK:
                return value * 604800;
            case MONTH:
                return value * 2629800;
            case YEAR:
                return value * 31557600;
            default:
                throw std::invalid_argument("Invalid unit");
        }
    }

    void convertTo(Unit targetUnit) {
        if (targetUnit == unit) {
            return;
        }

        int newValue = 0;
        switch (targetUnit) {
            case SECOND:
                newValue = value;
                break;
            case MINUTE:
                newValue = value / 60;
                break;
            case HOUR:
                newValue = value / 3600;
                break;
            case DAY:
                newValue = value / 86400;
                break;
            case WEEK:
                newValue = value / 604800;
                break;
            case MONTH:
                newValue = value / 2629800;
                break;
            case YEAR:
                newValue = value / 31557600;
                break;
            default:
                throw std::invalid_argument("Invalid unit");
        }

        unit = targetUnit;
        value = newValue;
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
