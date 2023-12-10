#include <iostream>
#include <type_traits>
#include <string>

template <typename T1, typename T2>
std::string compareAndWarn(const T1& value1, const T2& value2) {
    using CommonType = std::common_type_t<T1, T2>;

    if constexpr (std::is_signed_v<T1> != std::is_signed_v<T2>) {
        return "different signs";
    } else if constexpr (std::is_signed_v<CommonType>) {
        if (static_cast<CommonType>(value1) < static_cast<CommonType>(value2)) {
            return "less";
        } else {
            return "greater or equal";
        }
    } else {
        return "cannot deduce common type";
    }
}

int main() {
    // Test cases
    std::cout << compareAndWarn((int)other, (unsigned long)(0xffff'ffff'ffff'ffff)) << std::endl; // Output: "different signs"
    std::cout << compareAndWarn((unsigned long)other, (int)(0xffff'ffff)) << std::endl; // Output: "different signs"
    std::cout << compareAndWarn((int)other, (long)(0xffff'ffff)) << std::endl; // Output: "less"

    return 0;
}
