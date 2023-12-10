#include <pybind11/pybind11.h>
#include <string>

// Define a C++ class named MyClass with a member function void printMessage(const std::string& message)
class MyClass {
public:
    void printMessage(const std::string& message) {
        std::cout << message << std::endl;
    }
};

// Create a Python binding for the MyClass using pybind11, providing the appropriate documentation string for the class
PYBIND11_MODULE(my_module, m) {
    py::class_<MyClass>(m, "MyClass")
        .def(py::init<>())
        .def("printMessage", &MyClass::printMessage, "Prints a message to the console");
}
