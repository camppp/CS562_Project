#include <iostream>

// Base class for combined signals
class CombinedSignal {
public:
    virtual double calculateCombinedValue(double signal1, double signal2) const = 0;
};

// Class for calculating the difference between two signals
class DifferenceCombinedSignal : public CombinedSignal {
public:
    double calculateCombinedValue(double signal1, double signal2) const override {
        return signal1 - signal2;
    }
};

int main() {
    // Example usage
    CombinedSignal* combinedSignal = new DifferenceCombinedSignal();
    double signal1 = 10.5;
    double signal2 = 5.2;
    double combinedValue = combinedSignal->calculateCombinedValue(signal1, signal2);
    std::cout << "Combined value: " << combinedValue << std::endl;

    delete combinedSignal;
    return 0;
}
