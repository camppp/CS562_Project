#include <iostream>
#include "library.hpp"

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    long long sum = asm_slowFunction(arr, 5);
    std::cout << "Sum: " << sum << std::endl;
    return 0;
}
