#include <iostream>
#include <string>

int calculateValue(const std::string& input) {
    int64_t total = 1, count = 0;
    for (size_t p = 0; p < input.size() - 1; p++) {
        if ((input[p] - '0') + (input[p + 1] - '0') == 9) {
            ++count;
        } else {
            if (count % 2 == 0) {
                total *= (1 + (count + 1) / 2);
            }
            count = 0;
        }
    }
    if (count % 2 == 0) {
        total *= (1 + (count + 1) / 2);
    }
    return total;
}

int main() {
    std::string input;
    std::cout << "Enter a string of digits: ";
    std::cin >> input;
    int result = calculateValue(input);
    std::cout << "The final calculated value is: " << result << std::endl;
    return 0;
}
