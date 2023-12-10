class CivilianTimeImp : public TimeImp {
public:
    CivilianTimeImp(int hr, int min, int pm) : TimeImp(hr, min) {
        setTime(hr, min, pm);
    }

    void setTime(int hr, int min, int pm) {
        if (pm == 1) {
            hr += 12;
        }
        this->hr = hr;
        this->min = min;
    }

    void displayTime() const {
        std::cout << std::setw(2) << std::setfill('0') << hr << ":"
                  << std::setw(2) << std::setfill('0') << min << " "
                  << (pm ? "PM" : "AM") << std::endl;
    }

private:
    int hr;
    int min;
    int pm;
};
