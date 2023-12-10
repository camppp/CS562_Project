#include <iostream>
#include <map>

class Extrapolator {
private:
    std::map<int, int> dataPoints;

public:
    void Inform(int input, int output) {
        dataPoints[input] = output;
    }

    const int* Extrapolate(int input) {
        auto lower = dataPoints.lower_bound(input);
        if (lower == dataPoints.begin()) {
            return nullptr;  // Input is lower than the lowest data point
        }
        if (lower == dataPoints.end()) {
            return &dataPoints.rbegin()->second;  // Input is higher than the highest data point
        }

        auto upper = lower;
        --lower;

        double interpolation = lower->second + (static_cast<double>(input - lower->first) / (upper->first - lower->first)) * (upper->second - lower->second);
        int* result = new int(interpolation);
        return result;
    }
};

int main() {
    Extrapolator extrapolator;
    extrapolator.Inform(0, 200);
    const int* result = extrapolator.Extrapolate(1);
    if (result != nullptr) {
        std::cout << "Extrapolated value: " << *result << std::endl;
        delete result;
    } else {
        std::cout << "Input is out of range" << std::endl;
    }
    return 0;
}
