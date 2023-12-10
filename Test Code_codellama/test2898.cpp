#include <iostream>

const int OP_ADD = 1;
const int OP_SUB = 2;
const int OP_MUL = 3;

int main() {
    int inst, data1, data2, data0;

    // Read input values for inst, data1, and data2
    std::cin >> inst >> data1 >> data2;

    // Perform the corresponding arithmetic operation based on the value of inst
    if (inst == OP_ADD) {
        data0 = data1 + data2;
    } else if (inst == OP_SUB) {
        data0 = data1 - data2;
    } else if (inst == OP_MUL) {
        data0 = data1 * data2;
    } else {
        std::cerr << "Invalid operation" << std::endl;
        return 1;
    }

    // Output the result of the operation
    std::cout << data0 << std::endl;

    return 0;
}
