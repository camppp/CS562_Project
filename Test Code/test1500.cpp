#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    int day, month, year;

    if (argc > 1) {
        day = std::atoi(argv[1]);
    } else { 
        std::cout << "Enter day: ";
        std::cin >> day;
    }

    if (argc > 2) {
        month = std::atoi(argv[2]);
    } else { 
        std::cout << "Enter month: ";
        std::cin >> month;
    }

    if (argc > 3) {
        year = std::atoi(argv[3]);
    } else { 
        std::cout << "Enter year: ";
        std::cin >> year;
    }

    int dayOfWeek = (day + 2 * (month + 12 * year) + 5 * (year / 4) - 2 * (year / 100) + 3 * (year / 400)) % 7;

    std::cout << "Day of the week: " << dayOfWeek << std::endl;

    return 0;
}
