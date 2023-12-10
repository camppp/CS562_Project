#include <iostream>

int main() {
    int arr[5];
    int i;

    std::cout << "Enter 5 values: ";
    for (i = 0; i < 5; i++) {
        std::cin >> arr[i];
    }

    // Print the array
    for (i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}