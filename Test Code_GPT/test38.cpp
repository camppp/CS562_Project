#include <iostream>
#include <Eigen/Dense>

template <std::size_t N>
Eigen::Matrix<double, N, 1> toVectorNd(const std::string& str) {
    Eigen::Matrix<double, N, 1> result;

    // Initialize the stringstream with the input string
    std::istringstream iss(str);

    // Try to parse N doubles from the input string
    for (std::size_t i = 0; i < N; ++i) {
        double value;
        if (iss >> value) {
            result(i) = value;
        } else {
            // Parsing error or insufficient number of values
            throw std::invalid_argument("Error parsing input string");
        }
    }

    // Check if there are additional values in the input string
    std::string extra;
    if (iss >> extra) {
        throw std::invalid_argument("Error parsing input string");
    }

    return result;
}

int main() {
    try {
        // Example usage with N = 3
        Eigen::Matrix<double, 3, 1> result = toVectorNd<3>("1.1 2.2 3.3");
        std::cout << "Parsed Vector: \n" << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
