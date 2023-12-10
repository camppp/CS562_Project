#include <iostream>

class CustomVector {
private:
    size_t capacity;

public:
    // Default constructor
    CustomVector() : capacity(0) {
        // Initialize the capacity to 0
    }

    // Method to check if the vector's capacity is 0
    bool isCapacityZero() {
        return capacity == 0;
    }
};

int main() {
    CustomVector vector;
    bool capacityZero = vector.isCapacityZero();
    std::cout << std::boolalpha << capacityZero;  // Output: true
    return 0;
}
