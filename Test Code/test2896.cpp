#include <cstdint>
#include <vector>
#include <string>
#include <cmath>
#include <random>
#include <iostream>

class PrivateFrequencyOracle {
public:
    PrivateFrequencyOracle(int K_, double eps_, bool debug_=false, uint32_t seed=0)
        : K(K_), eps(eps_), debug(debug_), seed(seed) {
        int width = static_cast<int>(std::ceil(2 / eps));
        countMinSketch = std::vector<std::vector<int>>(K, std::vector<int>(width, 0));
        // Initialize hash functions using seed
        std::mt19937_64 generator(seed);
        for (int i = 0; i < K; ++i) {
            hashSeeds.push_back(generator());
        }
    }

    void insert(const std::string& element) {
        for (int i = 0; i < K; ++i) {
            int hashValue = hash(element, hashSeeds[i]);
            countMinSketch[i][hashValue % countMinSketch[i].size()]++;
        }
    }

    int query(const std::string& element) {
        int minFrequency = INT_MAX;
        for (int i = 0; i < K; ++i) {
            int hashValue = hash(element, hashSeeds[i]);
            minFrequency = std::min(minFrequency, countMinSketch[i][hashValue % countMinSketch[i].size()]);
        }
        return minFrequency;
    }

private:
    int K; // Number of hash functions
    double eps; // Privacy parameter
    bool debug; // Debug flag
    uint32_t seed; // Seed for hash functions
    std::vector<std::vector<int>> countMinSketch; // Count-Min Sketch data structure
    std::vector<uint64_t> hashSeeds; // Hash function seeds

    int hash(const std::string& element, uint64_t seed) {
        std::hash<std::string> hasher;
        return hasher(element + std::to_string(seed));
    }
};
