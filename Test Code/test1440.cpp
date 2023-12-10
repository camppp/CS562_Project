#include <iostream>
#include <string>
#include <random>

std::string generateGASolution(int nPopX, int maxBitX, int maxBestX) {
    std::string gaString;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, 1);

    int length = std::uniform_int_distribution<int>(1, maxBitX)(gen);
    for (int i = 0; i < length; ++i) {
        gaString += std::to_string(distribution(gen));
    }

    return gaString;
}

int main() {
    int nPopX = 600, maxBitX = 16, maxBestX = 150;
    std::string gaSolution = generateGASolution(nPopX, maxBitX, maxBestX);
    std::cout << "Randomly generated GA string: " << gaSolution << std::endl;
    return 0;
}
