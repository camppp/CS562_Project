#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Registrar {
private:
    std::unordered_set<std::string> courses;
    std::unordered_map<std::string, std::unordered_set<std::string>> studentCourses;

public:
    // Add a new course
    void addCourse(const std::string& courseName) {
        courses.insert(courseName);
    }

    // Remove a course
    void removeCourse(const std::string& courseName) {
        courses.erase(courseName);
        // Remove the course from all students
        for (auto& pair : studentCourses) {
            pair.second.erase(courseName);
        }
    }

    // Register a student for a course
    void registerStudent(const std::string& studentName, const std::string& courseName) {
        if (courses.count(courseName) == 0) {
            std::cout << "Course not found: " << courseName << std::endl;
            return;
        }

        studentCourses[studentName].insert(courseName);
    }

    // Unregister a student from a course
    void unregisterStudent(const std::string& studentName, const std::string& courseName) {
        studentCourses[studentName].erase(courseName);
    }

    // List all courses for a student
    void listCourses(const std::string& studentName) {
        if (studentCourses.count(studentName) == 0) {
            std::cout << "Student not found: " << studentName << std::endl;
            return;
        }

        std::cout << "Courses for student " << studentName << ": ";
        for (const auto& course : studentCourses[studentName]) {
            std::cout << course << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Registrar registrar;

    registrar.addCourse("Math101");
    registrar.addCourse("Physics201");
    registrar.addCourse("History101");

    registrar.registerStudent("Alice", "Math101");
    registrar.registerStudent("Bob", "Physics201");
    registrar.registerStudent("Alice", "History101");

    registrar.listCourses("Alice");

    registrar.unregisterStudent("Alice", "Math101");

    registrar.listCourses("Alice");

    registrar.removeCourse("Math101");

    registrar.listCourses("Alice");

    return 0;
}
