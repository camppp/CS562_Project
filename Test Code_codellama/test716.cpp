#include <iostream>
#include <string>

int calculateValue(const std::string& input) {
    int count = 0;
    int total = 0;

    for (int i = 0; i < input.length() - 1; i++) {
        int sum = input[i] + input[i + 1];
        if (sum == 9) {
            count++;
        }
    }

    if (count % 2 == 0) {
        total = total * (1 + (count + 1) / 2);
    }

    return total;
}

int main() {
    std::string input = "123456789";
    std::cout << calculateValue(input) << std::endl;
    return 0;
}
