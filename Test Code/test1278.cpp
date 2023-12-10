#include <iostream>

namespace Tristeon
{
    template <typename T>
    struct IsPointer : std::false_type {};

    template <typename T>
    struct IsPointer<T*> : std::true_type {};
}

int main() {
    std::cout << "Is int* a pointer type? " << Tristeon::IsPointer<int*>::value << std::endl; // Outputs "Is int* a pointer type? 1"
    std::cout << "Is float a pointer type? " << Tristeon::IsPointer<float>::value << std::endl; // Outputs "Is float a pointer type? 0"
    return 0;
}
