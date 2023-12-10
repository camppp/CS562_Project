#include <iostream>
#include <cmath>
#include "igamma_small_data.ipp"
#include "igamma_big_data.ipp"

template <typename T>
void do_test_gamma_2(const std::vector<std::pair<T, T>>& data, const std::string& name, const std::string& description) {
    std::cout << "Performing round trip sanity checks for " << name << ": " << description << std::endl;

    for (const auto& pair : data) {
        T a = pair.first;  // Incomplete gamma parameter 'a'
        T x = pair.second; // Incomplete gamma parameter 'x'

        // Calculate incomplete gamma value using the provided parameters
        T incomplete_gamma_value = calculate_incomplete_gamma(a, x);

        // Perform round trip calculation by integrating the incomplete gamma function
        T round_trip_value = perform_round_trip(a, incomplete_gamma_value);

        // Compare the round trip value with the original incomplete gamma value
        if (std::abs(round_trip_value - x) < 1e-6) {
            std::cout << "Round trip sanity check passed for a=" << a << ", x=" << x << std::endl;
        } else {
            std::cout << "Round trip sanity check failed for a=" << a << ", x=" << x << std::endl;
        }
    }
}

template <typename T>
T calculate_incomplete_gamma(T a, T x) {
    // Implement the calculation of incomplete gamma function using the parameters 'a' and 'x'
    // Return the calculated incomplete gamma value
    // Example implementation:
    // T result = ...; // Perform the calculation
    // return result;
}

template <typename T>
T perform_round_trip(T a, T incomplete_gamma_value) {
    // Implement the round trip calculation by integrating the incomplete gamma function
    // Return the round trip value
    // Example implementation:
    // T result = ...; // Perform the round trip calculation
    // return result;
}

int main() {
    // Call do_test_gamma_2 with the small and big data sets
    do_test_gamma_2<double>(igamma_small_data, "Small Data", "Running round trip sanity checks on incomplete gamma small values");
    do_test_gamma_2<double>(igamma_big_data, "Big Data", "Running round trip sanity checks on incomplete gamma large values");

    return 0;
}
