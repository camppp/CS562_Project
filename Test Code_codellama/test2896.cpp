#include <cstdint>
#include <vector>
#include <string>
#include <iostream>

class PrivateFrequencyOracle {
public:
    PrivateFrequencyOracle(int K_, double eps_, bool debug_=false, uint32_t seed=0) : K(K_), eps(eps_), debug(debug_), seed(seed) {
        // Initialize the count-min sketch data structure
        countMinSketch.resize(K, std::vector<int>(K));
    }

    void insert(const std::string& element) {
        // Hash the element to get a set of indices
        std::vector<int> indices = hash(element, K);

        // Update the count-min sketch data structure
        for (int i = 0; i < K; i++) {
            countMinSketch[i][indices[i]]++;
        }
    }

    int query(const std::string& element) {
        // Hash the element to get a set of indices
        std::vector<int> indices = hash(element, K);

        // Compute the estimated frequency of the element
        int estimatedFrequency = 0;
        for (int i = 0; i < K; i++) {
            estimatedFrequency += countMinSketch[i][indices[i]];
        }

        // Add noise to the estimated frequency
        estimatedFrequency += addNoise(estimatedFrequency, eps);

        // Return the estimated frequency
        return estimatedFrequency;
    }

private:
    int K; // Number of hash functions
    double eps; // Privacy parameter
    bool debug; // Debug flag
    uint32_t seed; // Seed for hash functions
    std::vector<std::vector<int>> countMinSketch; // Count-Min Sketch data structure

    // Hash function to map elements to a set of indices
    std::vector<int> hash(const std::string& element, int K) {
        // Initialize the hash values to 0
        std::vector<int> hashValues(K, 0);

        // Compute the hash values for each index
        for (int i = 0; i < K; i++) {
            hashValues[i] = (int)((element[i] - 'a' + 1) * (element[i] - 'a' + 1) % (K - 1));
        }

        // Return the hash values
        return hashValues;
    }

    // Add noise to the estimated frequency
    int addNoise(int estimatedFrequency, double eps) {
        // Generate a random number between 0 and 1
        double randomNumber = (double)rand() / RAND_MAX;

        // Add noise to the estimated frequency
        return (int)(estimatedFrequency + eps * (randomNumber - 0.5));
    }
};
