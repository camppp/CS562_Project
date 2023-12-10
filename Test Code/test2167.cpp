#include <vector>
#include <cmath>

std::vector<double> HPCP(const std::vector<double>& frequencies, const std::vector<double>& magnitudes) {
    std::vector<double> hpcp(12, 0.0);  // Initialize HPCP vector with zeros

    // Iterate over the input frequencies and magnitudes
    for (size_t i = 0; i < frequencies.size(); ++i) {
        double frequency = frequencies[i];
        double magnitude = magnitudes[i];

        // Calculate the pitch class index based on the frequency
        int pitch_class_index = static_cast<int>(12.0 * std::log2(frequency / 440.0) + 0.5) % 12;

        // Update the HPCP vector with the magnitude at the corresponding pitch class index
        hpcp[pitch_class_index] += magnitude;
    }

    return hpcp;
}

int main() {
    // Test the HPCP function
    std::vector<double> frequencies(10);  // Input frequencies
    std::vector<double> magnitudes(10);   // Input magnitudes
    std::vector<double> actual_hpcp = HPCP(frequencies, magnitudes);  // Calculate HPCP

    std::vector<double> expected_hpcp(12);  // Expected HPCP vector
    // Compare actual_hpcp with expected_hpcp using a function like EXPECT_VEC_EQ

    return 0;
}
