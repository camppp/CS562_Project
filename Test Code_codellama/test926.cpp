#include <iostream>
#include <cstdlib>
#include <ctime>

namespace Toolkit {
    class UniformIntRNG {
    private:
        int min;
        int max;
        std::mt19937 gen;

    public:
        UniformIntRNG() {
            gen = std::mt19937(std::random_device()());
        }

        void setRange(int min, int max) {
            this->min = min;
            this->max = max;
        }

        int generate() {
            std::uniform_int_distribution<int> dist(min, max);
            return dist(gen);
        }
    };
}

int main() {
    Toolkit::UniformIntRNG rng;
    rng.setRange(1, 10);
    std::cout << rng.generate() << std::endl;
    return 0;
}
