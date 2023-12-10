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

    std::cout << "Enter month: ";
    std::cin >> month;

    std::cout << "Enter year: ";
    std::cin >> year;

    if (month < 3) {
        month += 12;
        year--;
    }

    int century = year / 100;
    year %= 100;

    int dayOfWeek = (day + 13 * (month + 1) / 5 + year + year / 4 + century / 4 - 2 * century) % 7;

    switch (dayOfWeek) {
        case 0:
            std::cout << "Saturday" << std::endl;
            break;
        case 1:
            std::cout << "Sunday" << std::endl;
            break;
        case 2:
            std::cout << "Monday" << std::endl;
            break;
        case 3:
            std::cout << "Tuesday" << std::endl;
            break;
        case 4:
            std::cout << "Wednesday" << std::endl;
            break;
        case 5:
            std::cout << "Thursday" << std::endl;
            break;
        case 6:
            std::cout << "Friday" << std::endl;
            break;
    }

    return 0;
}
