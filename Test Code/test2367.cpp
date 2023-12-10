#include <iostream>

// Primary template for is_arithmetic trait
template <typename T>
struct is_arithmetic {
    static constexpr bool value = false;
};

// Specializations for arithmetic types
template <>
struct is_arithmetic<int> {
    static constexpr bool value = true;
};

template <>
struct is_arithmetic<float> {
    static constexpr bool value = true;
};

template <>
struct is_arithmetic<double> {
    static constexpr bool value = true;
};

template <typename T>
struct is_arithmetic<T*> {
    static constexpr bool value = true;
};

int main() {
    // Using the is_arithmetic trait to check types
    std::cout << std::boolalpha;
    std::cout << "int is arithmetic: " << is_arithmetic<int>::value << std::endl;
    std::cout << "float is arithmetic: " << is_arithmetic<float>::value << std::endl;
    std::cout << "char* is arithmetic: " << is_arithmetic<char*>::value << std::endl;

    return 0;
}
