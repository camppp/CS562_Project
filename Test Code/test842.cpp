#include <iostream>

class NumberManipulator {
public:
    void manipulate(int n) {
        if (n % 2 == 0) {
            std::cout << n * 2 << std::endl;
        } else {
            std::cout << n * 3 << std::endl;
        }
    }
};

int main() {
    NumberManipulator nm;
    nm.manipulate(5); // Output: 15
    nm.manipulate(8); // Output: 16
    return 0;
}
