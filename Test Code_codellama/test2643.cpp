#include <iostream>

namespace test1 {

template<typename... Args>
void foo(Args... args) {
    // Create an array with one more element than the number of arguments
    int arr[sizeof...(args) + 1];

    // Initialize the array with the values of the arguments
    int i = 0;
    ((arr[i++] = args), ...);

    // Print the values of the initialized array
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

} // namespace test1
