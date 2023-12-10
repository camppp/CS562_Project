#include <iostream>

int main() {
    int arr[5];
    int input;

    std::cout << "Enter 5 values to fill the array: " << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cin >> arr[i];
    }

    std::cout << "Array values: ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}