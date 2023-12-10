// modulator.cpp

#include "modulator.hpp"
#include <cmath>

FMModulator::FMModulator(double modulationIndex) : modulationIndex(modulationIndex) {}

std::vector<double> FMModulator::modulate(const std::vector<double>& inputSignal) {
    std::vector<double> modulatedSignal;
    double phase = 0.0;

    for (double sample : inputSignal) {
        double frequencyDeviation = modulationIndex * sample;
        phase += frequencyDeviation;
        modulatedSignal.push_back(std::sin(2 * M_PI * phase));
    }

    return modulatedSignal;
}
