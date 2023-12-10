#include <iostream>
#include <string>
#include <map>

// Define the namespace MyNamespace
namespace MyNamespace {

    // Define the class MyClass
    class MyClass {
    public:
        MyClass() {
            // Constructor logic for MyClass
        }
    };

    // Define a registration mechanism for classes within the namespace
    class Registration {
    public:
        // Map to store registered classes
        static std::map<std::string, void*> registeredClasses;

        // Function to register a class
        template <typename T>
        static void RegisterClass(const std::string& className) {
            registeredClasses[className] = new T();
            std::cout << "Class " << className << " registered successfully in MyNamespace." << std::endl;
        }
    };
}

// Register the class MyClass within the MyNamespace
int main() {
    MyNamespace::Registration::RegisterClass<MyNamespace::MyClass>("MyClass");
    return 0;
}
