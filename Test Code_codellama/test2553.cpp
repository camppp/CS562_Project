#include <iostream>
#include <string>
using namespace std;

class GradeBook {
private:
    string courseName;
    string instructorName;

public:
    // Constructor to initialize courseName and instructorName
    GradeBook(string name) {
        courseName = name;
        instructorName = "";
    }

    // Method to set the course name
    void setCourseName(string name) {
        courseName = name;
    }

    // Method to get the course name
    string getCourseName() {
        return courseName;
    }

    // Method to set the instructor name
    void setInstructorName(string name) {
        instructorName = name;
    }

    // Method to get the instructor name
    string getInstructorName() {
        return instructorName;
    }
};

int main() {
    GradeBook gb("Mathematics");
    cout << "Initial Course Name: " << gb.getCourseName() << endl;
    gb.setCourseName("Physics");
    cout << "Updated Course Name: " << gb.getCourseName() << endl;
    gb.setInstructorName("Dr. Smith");
    cout << "Instructor Name: " << gb.getInstructorName() << endl;

    return 0;
}
