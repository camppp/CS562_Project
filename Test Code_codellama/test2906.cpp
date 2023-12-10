#include <iostream>
#include <string>

int main() {
    std::string line;
    std::string author;
    int year;
    std::string month;
    int day;
    int hour;
    int minute;
    int second;

    while (std::getline(std::cin, line)) {
        // Extract the author's name and the year from the line
        author = line.substr(15, line.find("by") - 15);
        year = std::stoi(line.substr(line.find("by") + 3, 4));

        // Extract the date from the line
        month = line.substr(line.find("by") + 7, 3);
        day = std::stoi(line.substr(line.find("by") + 10, 2));
        hour = std::stoi(line.substr(line.find("by") + 13, 2));
        minute = std::stoi(line.substr(line.find("by") + 16, 2));
        second = std::stoi(line.substr(line.find("by") + 19, 2));

        // Output the author's name and the date of the file
        std::cout << "Author: " << author << ", Date: " << month << "/" << day << "/" << year << "-" << hour << ":" << minute << ":" << second << std::endl;
    }

    return 0;
}
