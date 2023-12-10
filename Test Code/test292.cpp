#include <iostream>
#include <vector>
#include <algorithm>

class FrequencySpectrum {
public:
    FrequencySpectrum(const std::vector<std::pair<double, double>>& frequencyAmplitudePairs) {
        // Initialize the frequency spectrum with the given frequency-amplitude pairs
        for (const auto& pair : frequencyAmplitudePairs) {
            frequencies.push_back(pair.first);
            amplitudes.push_back(pair.second);
        }
    }

    double averageAmplitude() const {
        // Calculate the average amplitude of the frequency spectrum
        double sum = 0.0;
        for (const auto& amplitude : amplitudes) {
            sum += amplitude;
        }
        return sum / amplitudes.size();
    }

    double highestAmplitudeFrequency() const {
        // Find the frequency with the highest amplitude in the spectrum
        double highestAmplitude = 0.0;
        double highestFrequency = 0.0;
        for (size_t i = 0; i < frequencies.size(); ++i) {
            if (amplitudes[i] > highestAmplitude) {
                highestAmplitude = amplitudes[i];
                highestFrequency = frequencies[i];
            }
        }
        return highestFrequency;
    }

    void filterFrequencies(double threshold) {
        // Filter out frequencies below the given threshold amplitude
        for (size_t i = 0; i < frequencies.size(); ++i) {
            if (amplitudes[i] < threshold) {
                frequencies.erase(frequencies.begin() + i);
                amplitudes.erase(amplitudes.begin() + i);
                --i;
            }
        }
    }

private:
    std::vector<double> frequencies;
    std::vector<double> amplitudes;
};
