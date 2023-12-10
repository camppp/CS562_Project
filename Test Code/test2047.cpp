#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

class MyClass {
public:
    void printMessage(const std::string& message) {
        // Implement the printMessage function
        std::cout << message << std::endl;
    }
};

PYBIND11_MODULE(example, m) {
    py::class_<MyClass>(m, "MyClass", R"pbdoc(
        This is the documentation string for MyClass.
        You can provide a detailed description of the class and its member functions here.
    )pbdoc")
        .def(py::init<>())
        .def("printMessage", &MyClass::printMessage, "Print a message");
}
