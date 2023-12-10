#include <iostream>

int main() {
    int v, t;

    std::cout << "Enter the initial velocity (V): ";
    std::cin >> v;

    std::cout << "Enter the time (T): ";
    std::cin >> t;

    int displacement = v * t;

    std::cout << "The displacement is: " << displacement << std::endl;

    return 0;
}
