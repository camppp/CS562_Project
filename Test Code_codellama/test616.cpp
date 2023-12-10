#include <random>
#include <vector>

std::vector<double> generateRandomVector(int size, double lowerBound, double upperBound) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> urd(lowerBound, upperBound);
    std::vector<double> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = urd(gen);
    }
    return arr;
}
