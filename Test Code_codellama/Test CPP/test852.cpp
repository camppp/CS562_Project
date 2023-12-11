#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> addStudentData(int numStudents) {
    vector<string> studentNames;
    for (int i = 0; i < numStudents; i++) {
        string name;
        cout << "Enter name for student " << i + 1 << ": ";
        cin >> name;
        studentNames.push_back(name);
    }
    return studentNames;
}
