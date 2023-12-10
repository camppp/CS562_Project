#include <iostream>

bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    return false;
}

int getDaysInMonth(int month, int year) {
    const int daysinmonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2) {
        if (isLeapYear(year)) {
            return 29;
        } else {
            return 28;
        }
    } else {
        return daysinmonth[month - 1];
    }
}

int main() {
    // Test cases
    std::cout << getDaysInMonth(2, 2020) << std::endl;  // Output: 29
    std::cout << getDaysInMonth(2, 2021) << std::endl;  // Output: 28
    std::cout << getDaysInMonth(4, 2021) << std::endl;  // Output: 30
    return 0;
}
