#include <iostream>

class NumberManipulator {
public:
    void manipulate(int n) {
        if (n % 2 == 0) {
            std::cout << 2 * n << std::endl;
        } else {
            std::cout << 3 * n << std::endl;
        }
    }
};

int main() {
    NumberManipulator nm;
    nm.manipulate(5); // Output: 15
    nm.manipulate(8); // Output: 16
    return 0;
}
