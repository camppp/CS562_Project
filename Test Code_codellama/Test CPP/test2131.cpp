#include "modulator.hpp"

FMModulator::FMModulator(double modulationIndex) : modulationIndex(modulationIndex) {}

std::vector<double> FMModulator::modulate(const std::vector<double>& inputSignal) {
    std::vector<double> modulatedSignal;
    for (int i = 0; i < inputSignal.size(); i++) {
        modulatedSignal.push_back(inputSignal[i] * modulationIndex);
    }
    return modulatedSignal;
}
