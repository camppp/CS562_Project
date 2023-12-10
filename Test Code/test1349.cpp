#include <type_traits>

template<int N>
typename std::enable_if<N==2, int>::type testme() { return 0; }

// Example usage
int main() {
    // Call testme with N=2
    int result1 = testme<2>();  // result1 will be 0

    // Attempt to call testme with N=3 (should not be callable)
    // int result2 = testme<3>();  // This line will cause a compilation error due to SFINAE
}
