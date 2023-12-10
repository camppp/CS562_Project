#include <iostream>
#include <fstream>

int main() {
    std::ifstream fin;
    fin.open("in.txt");

    if (!fin.is_open()) {
        std::cout << "Error: Unable to open the file" << std::endl;
    } else {
        int num, sum = 0;
        while (fin >> num) {
            sum += num;
        }
        std::cout << "Sum of the integers in the file: " << sum << std::endl;
    }

    fin.close();  // Close the file
    return 0;
}
