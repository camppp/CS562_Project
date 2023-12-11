#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int num;
    while (input >> num) {
        int result = num;
        while (result != 1) {
            if (result % 2 == 0) {
                result /= 2;
            } else {
                result = (result * 3) + 1;
            }
            output << result << " ";
        }
        output << "Lie absolutely" << endl;
    }

    input.close();
    output.close();

    return 0;
}
