#include <iostream>
#include <cmath>

int main() {
    double x, y, z, pi;
    std::cout << "Enter the values for x, y, z, and pi: ";
    std::cin >> x >> y >> z >> pi;

    double f2 = (1 + 3*pi*pi)*std::cos(z)*std::sin(x)*std::sin(y);
    std::cout << "The value of f[2] is: " << f2 << std::endl;

    return 0;
}
