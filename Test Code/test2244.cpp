#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

// Define a structure to represent a class
struct ClassInfo {
    std::string library;
    // Add any other relevant information about the class
};

class ClassManager {
private:
    std::unordered_map<std::string, ClassInfo> classMap; // Map to store class information

public:
    // Function to add a new class to the data structure
    void addClass(const std::string& className, const std::string& library) {
        classMap[className] = {library};
    }

    // Function to retrieve all classes from a specific library
    std::vector<std::string> getClassesFromLibrary(const std::string& library) {
        std::vector<std::string> classes;
        for (const auto& entry : classMap) {
            if (entry.second.library == library) {
                classes.push_back(entry.first);
            }
        }
        return classes;
    }

    // Function to remove a class from the data structure
    void removeClass(const std::string& className) {
        classMap.erase(className);
    }
};

int main() {
    // Usage example
    ClassManager manager;
    manager.addClass("class_1", "lib_1");
    manager.addClass("class_2", "lib_2");
    manager.addClass("class_3", "lib_1");
    manager.addClass("class_4", "lib_3");

    std::vector<std::string> classesInLib1 = manager.getClassesFromLibrary("lib_1");
    std::cout << "Classes in lib_1: ";
    for (const auto& className : classesInLib1) {
        std::cout << className << " ";
    }
    std::cout << std::endl;

    manager.removeClass("class_2");

    return 0;
}
