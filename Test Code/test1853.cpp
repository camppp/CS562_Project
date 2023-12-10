#include <iostream>
#include <cmath>

// Define the gamma function using continued fraction method
template <typename T, bool flag>
T GammaQ_cf(T a, T x) {
    // Implementation of the continued fraction method for gamma function
    // This implementation is not provided in the code snippet but is assumed to be available

    // Placeholder implementation for demonstration purposes
    T result = 0.0;
    // ... continued fraction method implementation

    return result;
}

namespace detail {
    // Implementation of the lower incomplete gamma function using the gamma function with continued fraction method
    template <typename T, bool flag>
    T GammaP(T a, T x) {
        return GammaQ_cf<T, false>(a, x);
    }
}

// Wrapper function for the lower incomplete gamma function
// Calls the detail::GammaP function with float template parameter
inline float GammaP(float a, float x) {
    return detail::GammaP<float, true>(a, x);
}

int main() {
    // Example usage
    float a = 2.0;
    float x = 1.5;
    float result = GammaP(a, x);
    std::cout << "P(" << a << ", " << x << ") = " << result << std::endl;
    return 0;
}
