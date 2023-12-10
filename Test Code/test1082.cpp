#include <iostream>
#include <fstream>

void performOperation(int n, std::ofstream& output) {
    while (n != 1) {
        output << n << " ";
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
    }
    output << "1" << std::endl << "Lie absolutely" << std::endl;
}

int main() {
    std::ifstream inputdata("input.txt");
    std::ofstream outputdata("output.txt");

    int n;
    while (inputdata >> n) {
        performOperation(n, outputdata);
    }

    inputdata.close();
    outputdata.close();
    return 0;
}
