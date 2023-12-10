#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> addStudentData(int numStudents) {
    std::vector<std::string> studentNames;
    for (int i = 0; i < numStudents; i++) {
        std::string name;
        std::cout << "Enter name for student " << i + 1 << ": ";
        std::cin >> name;
        studentNames.push_back(name);
    }
    return studentNames;
}
