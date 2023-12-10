#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

struct Student {
    std::string name;
    std::vector<int> scores;
};

int main() {
    int numStudents;
    std::cin >> numStudents;

    std::vector<Student> students(numStudents);

    for (int i = 0; i < numStudents; ++i) {
        std::cin >> students[i].name;
        int score;
        while (std::cin >> score) {
            students[i].scores.push_back(score);
        }
    }

    for (const auto& student : students) {
        double average = 0.0;
        for (int score : student.scores) {
            average += score;
        }
        average /= student.scores.size();
        std::cout << student.name << " " << std::fixed << std::setprecision(2) << average << std::endl;
    }

    return 0;
}
