#include <random>

template <typename T>
class UniformRealDistribution {
public:
    UniformRealDistribution(T min, T max) : distribution_(min, max) {
        random_engine_.seed(std::random_device()());
    }

    T generate() {
        return distribution_(random_engine_);
    }

private:
    std::uniform_real_distribution<T> distribution_;
    std::mt19937 random_engine_;
};

// Example usage
int main() {
    UniformRealDistribution<double> urd(0.0, 1.0);
    for (int i = 0; i < 10; ++i) {
        std::cout << urd.generate() << std::endl;
    }
    return 0;
}
