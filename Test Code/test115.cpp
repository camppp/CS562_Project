#include <iostream>
#include <cmath>

class Process {
public:
    double x0() {
        return 0;
    }

    double evolve(double t, double x, double dt, double dw) {
        return x + dt * (x * (1 - x) + dw);
    }
};

double minMax(double mandatoryPoint, Process process) {
    double min = process.x0();
    double max = process.x0();

    for (double t = 0; t < 10; t += 0.1) {
        double x = process.evolve(t, min, 0.1, 0);
        if (x < min) {
            min = x;
        }
        if (x > max) {
            max = x;
        }
    }

    return std::make_pair(min, max);
}

int main() {
    Process process;
    double mandatoryPoint = 0.5;
    auto result = minMax(mandatoryPoint, process);
    std::cout << "Min: " << result.first << std::endl;
    std::cout << "Max: " << result.second << std::endl;
    return 0;
}
