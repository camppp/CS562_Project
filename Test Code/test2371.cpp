#include <iostream>
#include <vector>

template <typename T, size_t N>
class vector_ref {
private:
    T* data;
    size_t size;

public:
    vector_ref(T* data, size_t size) : data(data), size(size) {}

    // Overloaded assignment operator to perform arithmetic operations on the selected elements
    vector_ref& operator=(const vector_ref& other) {
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
        return *this;
    }

    // Overloaded addition operator to perform element-wise addition
    vector_ref operator+(const vector_ref& other) const {
        vector_ref result(*this);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] += other.data[i];
        }
        return result;
    }
};

int main() {
    // Example usage
    std::vector<float> m1 = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    vector_ref<float, 4> v1(&m1[0], 4);  // Reference to rows 1 and 2 of m1
    vector_ref<float, 4> v2(&m1[2], 4);  // Reference to rows 2 and 3 of m1

    v2 = v1 + v2;  // Perform arithmetic operation on the selected elements

    // Output the modified vector elements
    for (size_t i = 0; i < m1.size(); ++i) {
        std::cout << m1[i] << " ";
    }
    return 0;
}
