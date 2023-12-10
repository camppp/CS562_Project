#include <iostream>
#include <map>
#include <string>

class TimeFitStructMap {
public:
    TimeFitStructMap(const std::string & label) : label_(label) {}

    void addTimeFitStruct(const std::string & time, const std::string & fit) {
        timeFitStructs_[time] = fit;
    }

    std::string getTimeFitStruct(const std::string & time) {
        return timeFitStructs_[time];
    }

    void removeTimeFitStruct(const std::string & time) {
        timeFitStructs_.erase(time);
    }

private:
    std::string label_;
    std::map<std::string, std::string> timeFitStructs_;
};

int main() {
    TimeFitStructMap timeFitStructMap("label");

    timeFitStructMap.addTimeFitStruct("time1", "fit1");
    timeFitStructMap.addTimeFitStruct("time2", "fit2");
    timeFitStructMap.addTimeFitStruct("time3", "fit3");

    std::cout << "TimeFitStructMap for label: " << timeFitStructMap.label_ << std::endl;
    std::cout << "TimeFitStructs: " << std::endl;
    for (const auto & timeFitStruct : timeFitStructMap.timeFitStructs_) {
        std::cout << "Time: " << timeFitStruct.first << ", Fit: " << timeFitStruct.second << std::endl;
    }

    std::cout << "Retrieving time fit struct for time1: " << timeFitStructMap.getTimeFitStruct("time1") << std::endl;
    std::cout << "Removing time fit struct for time2: " << timeFitStructMap.removeTimeFitStruct("time2") << std::endl;

    return 0;
}
