#include <iostream>
#include <unordered_map>
#include <unordered_set>

class Registrar {
public:
    void addCourse(const std::string& courseName) {
        courses[courseName];
    }

    void removeCourse(const std::string& courseName) {
        courses.erase(courseName);
    }

    void registerStudent(const std::string& studentName, const std::string& courseName) {
        courses[courseName].insert(studentName);
    }

    void unregisterStudent(const std::string& studentName, const std::string& courseName) {
        courses[courseName].erase(studentName);
    }

    void listCourses(const std::string& studentName) {
        for (const auto& course : courses) {
            if (course.second.count(studentName) > 0) {
                std::cout << course.first << std::endl;
            }
        }
    }

private:
    std::unordered_map<std::string, std::unordered_set<std::string>> courses;
};