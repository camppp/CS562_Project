#include <iostream>
#include <random>
#include <type_traits>
#include <chrono>
using namespace std;
using namespace std::chrono;

class RandomNumberGenerator {
private:
    mt19937 rng;  // Mersenne Twister pseudo-random generator
    uniform_int_distribution<int> distribution;

public:
    RandomNumberGenerator(int min, int max) : rng(system_clock::now().time_since_epoch().count()), distribution(min, max) {}

    int generate() {
        return distribution(rng);
    }

    void setRange(int newMin, int newMax) {
        distribution = uniform_int_distribution<int>(newMin, newMax);
    }
};

int main() {
    RandomNumberGenerator rng(1, 100);  // Create a random number generator with range [1, 100]
    for (int i = 0; i < 10; ++i) {
        cout << rng.generate() << " ";  // Generate and print 10 random numbers within the specified range
    }
    cout << endl;

    rng.setRange(50, 150);  // Change the range to [50, 150]
    for (int i = 0; i < 10; ++i) {
        cout << rng.generate() << " ";  // Generate and print 10 random numbers within the new range
    }
    cout << endl;

    return 0;
}
