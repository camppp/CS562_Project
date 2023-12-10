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
        if (!PyCallable_Check(base)) {
            PyErr_SetString(PyExc_TypeError, "Parameter must be callable");
            throw error_already_set();
        }

        PyObject* result = PyObject_CallObject(base, nullptr);
        if (result == nullptr) {
            throw error_already_set();
        }

        if (!PyArg_Parse(result, "T", &value)) {
            PyErr_SetString(PyExc_TypeError, "Failed to parse Python object to C++ object");
            throw error_already_set();
        }

        Py_DECREF(result);
        return value;
    }

private:
    PyObject* base;
    T value;
};
