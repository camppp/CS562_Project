#include <iostream>
#include <chrono>

class TupleImpl {
    // Implement the storage of tuple elements
    std::tuple<int, std::string, double> data;

public:
    // Constructor that initializes the tuple with the given values
    template <typename... Args>
    Tuple(Args... args) : data(args...) {}

    // Method to get the value at the specified index
    // Return type should be deduced based on the index
    auto get(size_t index) {
        return std::get<index>(data);
    }

    // Method to set the value at the specified index
    template <typename T>
    void set(size_t index, T value) {
        std::get<index>(data) = value;
    }

    // Method to return the number of elements in the tuple
    size_t size() {
        return std::tuple_size<decltype(data)>::value;
    }
};

int main() {
    Tuple t(10, "hello", 3.14);
    std::cout << t.get(1) << std::endl; // Output: hello
    t.set(0, 20);
    std::cout << t.get(0) << std::endl; // Output: 20
    std::cout << t.size() << std::endl; // Output: 3
    return 0;
}
