#include <iostream>
#include <vector>
#include <algorithm>

class FrequencySpectrum {
private:
    std::vector<std::pair<double, double>> _spectrum;

public:
    FrequencySpectrum(const std::vector<std::pair<double, double>>& spectrum) : _spectrum(spectrum) {}

    double calculateAverageAmplitude() const {
        double sum = 0.0;
        for (const auto& freqAmp : _spectrum) {
            sum += freqAmp.second;
        }
        return sum / _spectrum.size();
    }

    double findFrequencyWithHighestAmplitude() const {
        auto maxFreqAmp = std::max_element(_spectrum.begin(), _spectrum.end(),
            [](const std::pair<double, double>& a, const std::pair<double, double>& b) {
                return a.second < b.second;
            });
        return maxFreqAmp->first;
    }

    void filterFrequenciesBelowThreshold(double threshold) {
        _spectrum.erase(std::remove_if(_spectrum.begin(), _spectrum.end(),
            [threshold](const std::pair<double, double>& freqAmp) {
                return freqAmp.second < threshold;
            }), _spectrum.end());
    }
};

int main() {
    std::vector<std::pair<double, double>> spectrum = {{100, 0.5}, {200, 0.8}, {300, 0.3}, {400, 0.6}};
    FrequencySpectrum freqSpec(spectrum);

    std::cout << "Average Amplitude: " << freqSpec.calculateAverageAmplitude() << std::endl;
    std::cout << "Frequency with Highest Amplitude: " << freqSpec.findFrequencyWithHighestAmplitude() << std::endl;

    freqSpec.filterFrequenciesBelowThreshold(0.4);
    std::cout << "Filtered Spectrum: ";
    for (const auto& freqAmp : spectrum) {
        std::cout << "(" << freqAmp.first << ", " << freqAmp.second << ") ";
    }
    return 0;
}
