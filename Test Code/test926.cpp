#include <random>

namespace Toolkit {
    class UniformIntRNG {
    private:
        std::mt19937 rng;  // Mersenne Twister pseudo-random generator
        std::uniform_int_distribution<int> distribution;

    public:
        UniformIntRNG() : rng(std::random_device{}()), distribution(0, 1) {}

        void setRange(int min, int max) {
            distribution = std::uniform_int_distribution<int>(min, max);
        }

        int generate() {
            return distribution(rng);
        }
    };
}
