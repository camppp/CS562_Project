#include <iostream>
#include <cstdlib>
#include <ctime>

class RandomNumberGenerator {
public:
    RandomNumberGenerator(int min, int max) {
        this->min = min;
        this->max = max;
    }

    int generate() {
        return min + (rand() % (max - min + 1));
    }

    void setRange(int newMin, int newMax) {
        min = newMin;
        max = newMax;
    }

private:
    int min;
    int max;
};

int main() {
    RandomNumberGenerator rng(1, 10);
    std::cout << rng.generate() << std::endl;
    rng.setRange(5, 15);
    std::cout << rng.generate() << std::endl;
    return 0;
}
