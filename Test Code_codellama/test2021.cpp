#include <iostream>
#include <string>

template <typename T>
string to_string(T Val) {
    string result;
    if constexpr (std::is_same_v<T, int>) {
        result = std::to_string(Val);
    } else if constexpr (std::is_same_v<T, unsigned int>) {
        result = std::to_string(Val);
    } else if constexpr (std::is_same_v<T, long>) {
        result = std::to_string(Val);
    } else if constexpr (std::is_same_v<T, unsigned long>) {
        result = std::to_string(Val);
    } else if constexpr (std::is_same_v<T, long long>) {
        result = std::to_string(Val);
    } else if constexpr (std::is_same_v<T, unsigned long long>) {
        result = std::to_string(Val);
    } else if constexpr (std::is_same_v<T, short>) {
        result = std::to_string(Val);
    } else if constexpr (std::is_same_v<T, unsigned short>) {
        result = std::to_string(Val);
    } else {
        throw std::invalid_argument("Unsupported integer type");
    }
    return result;
}

int main() {
    int i = 10;
    unsigned int ui = 10;
    long l = 10;
    unsigned long ul = 10;
    long long ll = 10;
    unsigned long long ull = 10;
    short s = 10;
    unsigned short us = 10;

    std::cout << to_string(i) << std::endl;
    std::cout << to_string(ui) << std::endl;
    std::cout << to_string(l) << std::endl;
    std::cout << to_string(ul) << std::endl;
    std::cout << to_string(ll) << std::endl;
    std::cout << to_string(ull) << std::endl;
    std::cout << to_string(s) << std::endl;
    std::cout << to_string(us) << std::endl;

    return 0;
}
