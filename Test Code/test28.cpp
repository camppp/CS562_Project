#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Registrar {
private:
    std::unordered_map<std::string, std::unordered_set<std::string>> studentCourses;
    std::unordered_set<std::string> courses;

public:
    void addCourse(const std::string& courseName) {
        courses.insert(courseName);
    }

    void removeCourse(const std::string& courseName) {
        courses.erase(courseName);
        for (auto& student : studentCourses) {
            student.second.erase(courseName);
        }
    }

    void registerStudent(const std::string& studentName, const std::string& courseName) {
        studentCourses[studentName].insert(courseName);
    }

    void unregisterStudent(const std::string& studentName, const std::string& courseName) {
        studentCourses[studentName].erase(courseName);
    }

    void listCourses(const std::string& studentName) {
        std::cout << "Courses registered by " << studentName << ":\n";
        for (const auto& course : studentCourses[studentName]) {
            std::cout << course << std::endl;
        }
    }
};

int main() {
    Registrar registrar;
    registrar.addCourse("Math");
    registrar.addCourse("Physics");
    registrar.addCourse("Biology");

    registrar.registerStudent("Alice", "Math");
    registrar.registerStudent("Alice", "Physics");
    registrar.registerStudent("Bob", "Physics");
    registrar.registerStudent("Charlie", "Biology");

    registrar.listCourses("Alice");
    registrar.listCourses("Bob");
    registrar.listCourses("Charlie");

    registrar.unregisterStudent("Alice", "Physics");
    registrar.listCourses("Alice");

    registrar.removeCourse("Physics");
    registrar.listCourses("Alice");
    registrar.listCourses("Bob");
}
