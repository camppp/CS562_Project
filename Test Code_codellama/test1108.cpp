int getDaysInMonth(int month, int year) {
    if (month == 2 && isLeapYear(year)) {
        return 29;
    } else if (month == 2 && !isLeapYear(year)) {
        return 28;
    } else {
        return daysinmonth[month - 1];
    }
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
