#include <iostream>
#include <type_traits>

// Function overload for lvalue references
template <typename T>
void print(const T& t) {
    static_assert(!std::is_rvalue_reference<T>::value, "Invalid overload for rvalue references");
    std::cout << "Lvalue reference: " << t << std::endl;
}

// Function overload for rvalue references
void print(int&& t) {
    std::cout << "Rvalue reference: " << t << std::endl;
}

int main() {
    int x = 5;
    print(x);  // Calls the lvalue reference overload
    print(10); // Calls the rvalue reference overload
    return 0;
}
