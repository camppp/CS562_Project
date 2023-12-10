#include <iostream>
#include <map>
#include <vector>

int main() {
    // Create a map with key-value pairs
    std::map<int, int> multipliers = {{0, 2}, {1, 3}, {2, 4}};

    // Create a vector with some initial values
    std::vector<int> values = {1, 2, 3, 4, 5};

    // Apply the transformation to the vector using a lambda function
    std::transform(values.begin(), values.end(), multipliers.begin(), [](int value, int multiplier) {
        return value * multiplier;
    });

    // Print the modified vector
    std::cout << "Modified vector: ";
    for (int value : values) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
