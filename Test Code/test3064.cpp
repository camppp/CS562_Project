#include <iostream>

// Function prototypes
int add(int x, int y) { return x + y; }
int min(int x, int y) { return x - y; }
int mult(int x, int y) { return x * y; }
int div(int x, int y) { return x / y; }

// Function to perform arithmetic operations using function pointers
void fourop(int x, int y, int (*add)(int, int), int (*min)(int, int), int (*mult)(int, int), int (*div)(int, int)) {
    std::cout << x << " + " << y << " = " << add(x, y) << std::endl;
    std::cout << x << " - " << y << " = " << min(x, y) << std::endl;
    std::cout << x << " * " << y << " = " << mult(x, y) << std::endl;
    std::cout << x << " / " << y << " = " << div(x, y) << std::endl;
}

int main() {
    int x, y;
    std::cout << "Enter two integers: ";
    std::cin >> x >> y;

    fourop(x, y, add, min, mult, div);

    return 0;
}
