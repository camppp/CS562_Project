#include <iostream>
#include <tuple>

class Tuple {
public:
    // Constructor that initializes the tuple with the given values
    template <typename... Args>
    Tuple(Args... args) : data(std::make_tuple(args...)) {}

    // Method to get the value at the specified index
    template <size_t Index>
    auto get() {
        return std::get<Index>(data);
    }

    // Method to set the value at the specified index
    template <size_t Index, typename T>
    void set(T value) {
        std::get<Index>(data) = value;
    }

    // Method to return the number of elements in the tuple
    static constexpr size_t size() {
        return std::tuple_size<decltype(data)>::value;
    }

private:
    std::tuple<decltype(args)...> data; // Storage of tuple elements
};

int main() {
    Tuple t(10, "hello", 3.14);
    std::cout << t.get<1>() << std::endl; // Output: hello
    t.set<0>(20);
    std::cout << t.get<0>() << std::endl; // Output: 20
    std::cout << t.size() << std::endl; // Output: 3
    return 0;
}
