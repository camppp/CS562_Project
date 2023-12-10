#include <iostream>
#include <random>

class RandomGenerator {
private:
    std::mt19937 eng;  // Mersenne Twister 19937 generator
    std::uniform_int_distribution<int> distr_int;
    std::uniform_real_distribution<double> distr_double;

public:
    // Constructor to initialize the random number generator engine and distributions
    RandomGenerator(int int_min, int int_max, double double_min, double double_max) 
        : eng(std::random_device{}()), distr_int(int_min, int_max), distr_double(double_min, double_max) {}

    // Generate and print a random integer
    void generateRandomInt() {
        std::cout << "Random int: " << distr_int(eng) << std::endl;
    }

    // Generate and print a random double
    void generateRandomDouble() {
        std::cout << "Random double: " << distr_double(eng) << std::endl;
    }
};

int main() {
    RandomGenerator rg(1, 100, 0.0, 1.0);
    rg.generateRandomInt();
    rg.generateRandomDouble();
    rg.generateRandomInt();
    return 0;
}
