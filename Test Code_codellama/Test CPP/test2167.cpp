#include <vector>

std::vector<double> HPCP(const std::vector<double>& frequencies, const std::vector<double>& magnitudes) {
    // Calculate the number of harmonics in the audio signal
    int num_harmonics = frequencies.size();

    // Initialize the HPCP vector with all zeros
    std::vector<double> hpcp(12, 0.0);

    // Iterate over the frequencies and magnitudes
    for (int i = 0; i < num_harmonics; i++) {
        // Calculate the pitch class of the current harmonic
        int pitch_class = (int)frequencies[i] / 12;

        // Increment the corresponding element in the HPCP vector
        hpcp[pitch_class] += magnitudes[i];
    }

    return hpcp;
}
