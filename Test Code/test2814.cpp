// Define the FRL macro to iterate i from l to r (inclusive)
#define FRL(i, l, r) for (int i = (l); i <= (r); ++i)

// Sample program demonstrating the usage of FRL macro
#include <iostream>

int main() {
    int sum = 0;
    FRL(i, 3, 7) {
        sum += i;
    }
    std::cout << "Sum of numbers from 3 to 7: " << sum << std::endl;
    return 0;
}
