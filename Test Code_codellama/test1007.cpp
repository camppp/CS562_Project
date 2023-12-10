#include <random>

template <typename T>
class UniformRealDistribution {
public:
    UniformRealDistribution(T min, T max) : min_(min), max_(max) {
        // Initialize the random number engine
        std::mt19937 engine;

        // Initialize the uniform real distribution
        std::uniform_real_distribution<T> distribution(min_, max_);

        // Seed the distribution with a random number
        distribution.seed(engine());
    }

    T generate() {
        // Generate a random number within the specified range
        return distribution(engine);
    }

private:
    T min_;
    T max_;
    std::mt19937 engine;
    std::uniform_real_distribution<T> distribution;
};
