#include <iostream>
#include <string>
#include <map>
#include <set>

class Registrar {
public:
    // Add a new course to the registrar's records
    void addCourse(const std::string& courseName) {
        courses_.insert(courseName);
    }

    // Remove a course from the registrar's records
    void removeCourse(const std::string& courseName) {
        courses_.erase(courseName);
    }

    // Register a student for a specific course
    void registerStudent(const std::string& studentName, const std::string& courseName) {
        students_[studentName].insert(courseName);
    }

    // Unregister a student from a specific course
    void unregisterStudent(const std::string& studentName, const std::string& courseName) {
        students_[studentName].erase(courseName);
    }

    // List all the courses a student is registered for
    void listCourses(const std::string& studentName) {
        std::cout << "Courses for " << studentName << ": ";
        for (const auto& course : students_[studentName]) {
            std::cout << course << " ";
        }
        std::cout << std::endl;
    }

private:
    // Map of courses to their names
    std::map<std::string, std::set<std::string>> courses_;

    // Map of students to their registered courses
    std::map<std::string, std::set<std::string>> students_;
};
