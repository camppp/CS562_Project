#include <iostream>

int main() {
    int inst, data1, data2, data0;

    std::cin >> inst >> data1 >> data2;

    if (inst == OP_ADD)
        data0 = data1 + data2;
    else if (inst == OP_SUB)
        data0 = data1 - data2;
    else if (inst == OP_MUL)
        data0 = data1 * data2;

    std::cout << "Result: " << data0 << std::endl;

    return 0;
}
