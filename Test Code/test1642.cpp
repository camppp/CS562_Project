#include <iostream>
#include <random>
#include <type_traits>

template <typename T>
bool runTest() {
    const T moveMag = std::is_same<T, float>::value ? 5e-3 : 1e-5;
    const T diffDeRelEps = std::is_same<T, float>::value ? 6e-2 : 5e-4;
    const size_t repsTot = 10;
    const size_t repsPassReq = 9;
    size_t passCount = 0;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<T> moveDist(0, moveMag);
    std::uniform_real_distribution<T> diffDist(0, diffDeRelEps);

    for (size_t i = 0; i < repsTot; ++i) {
        T movement = moveDist(gen);
        T relativeDiff = diffDist(gen);
        if (movement < relativeDiff) {
            passCount++;
        }
    }

    return passCount >= repsPassReq;
}

int main() {
    bool testResultFloat = runTest<float>();
    bool testResultDouble = runTest<double>();

    std::cout << "Test result for float: " << (testResultFloat ? "Pass" : "Fail") << std::endl;
    std::cout << "Test result for double: " << (testResultDouble ? "Pass" : "Fail") << std::endl;

    return 0;
}
