#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct Student {
    std::string name;
    int score;
};

void displayStudentTable(const std::vector<Student>& students) {
    std::cout << std::setw(15) << std::left << "Student" << "Score" << std::endl;
    for (const auto& student : students) {
        std::cout << std::setw(15) << std::left << student.name << student.score << std::endl;
    }
}

int main() {
    std::vector<Student> students = {{"Alice", 95}, {"Bob", 87}, {"Charlie", 78}};
    displayStudentTable(students);
    return 0;
}
