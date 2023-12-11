#include <iostream>
#include <type_traits>

template <typename T1, typename T2>
std::string compareAndWarn(T1 value1, T2 value2) {
    using CommonType = std::common_type_t<T1, T2>;
    if constexpr (std::is_same_v<CommonType, void>) {
        return "cannot deduce common type";
    } else {
        if (value1 < value2) {
            return "less";
        } else if (value1 > value2) {
            return "different signs";
        } else {
            return "equal";
        }
    }
}

int main() {
    int other = 10;
    std::cout << compareAndWarn((int)other, (unsigned long)(0xffff'ffff'ffff'ffff)); // Output: "different signs"
    std::cout << compareAndWarn((unsigned long)other, (int)(0xffff'ffff)); // Output: "different signs"
    std::cout << compareAndWarn((int)other, (long)(0xffff'ffff)); // Output: "less"
    return 0;
}
