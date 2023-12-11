#include <iostream>

double celsius(int fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

int main() {
    for (int fahrenheit = 0; fahrenheit <= 20; fahrenheit++) {
        std::cout << fahrenheit << "\t" << celsius(fahrenheit) << std::endl;
    }
    return 0;
}
