#include <iostream>
#include <string>
#include <map>
#include <vector>

// Data structure to store classes and their associated libraries
struct ClassLibrary {
    std::string name;
    std::string library;
};

// Function to add a new class to the data structure
void addClass(const std::string& name, const std::string& library) {
    ClassLibrary cl{name, library};
    classes.push_back(cl);
}

// Function to retrieve all classes from a specific library
std::vector<ClassLibrary> getClassesFromLibrary(const std::string& library) {
    std::vector<ClassLibrary> classesFromLibrary;
    for (const auto& cl : classes) {
        if (cl.library == library) {
            classesFromLibrary.push_back(cl);
        }
    }
    return classesFromLibrary;
}

// Function to remove a class from the data structure
void removeClass(const std::string& name) {
    for (auto it = classes.begin(); it != classes.end(); ++it) {
        if (it->name == name) {
            classes.erase(it);
            break;
        }
    }
}

int main() {
    // Add some classes to the data structure
    addClass("class_1", "library_1");
    addClass("class_2", "library_2");
    addClass("class_3", "library_3");

    // Retrieve all classes from a specific library
    std::vector<ClassLibrary> classesFromLibrary = getClassesFromLibrary("library_2");
    for (const auto& cl : classesFromLibrary) {
        std::cout << cl.name << " from " << cl.library << std::endl;
    }

    // Remove a class from the data structure
    removeClass("class_2");

    return 0;
}
