#include <Python.h>

template <class T>
class from_python {
public:
    from_python(PyObject* source)
        : base(source)
    {
        // Constructor implementation
    }

    T convert() {
        if (!PyObject_TypeCheck(base, &PyLong_Type)) {
            throw std::runtime_error("Invalid type for conversion");
        }

        PyLongObject* py_long = (PyLongObject*)base;
        T cpp_value = py_long->ob_digit[0];

        for (int i = 1; i < py_long->ob_size; i++) {
            cpp_value = cpp_value * 256 + py_long->ob_digit[i];
        }

        return cpp_value;
    }

private:
    PyObject* base;
};
