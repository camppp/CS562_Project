c
#include <Python.h>

int callPredictFunction(double param1, double param2, double param3, double* prediction) {
    // Initialize the Python interpreter and acquire the GIL
    Py_Initialize();
    PyGILState_STATE gstate = PyGILState_Ensure();

    // Retrieve the predict function from the Python module
    PyObject* module = PyImport_ImportModule("my_module");
    PyObject* predict_function = PyObject_GetAttrString(module, "predict");

    // Create a tuple of parameters for the predict function
    PyObject* params = PyTuple_New(3);
    PyTuple_SetItem(params, 0, PyFloat_FromDouble(param1));
    PyTuple_SetItem(params, 1, PyFloat_FromDouble(param2));
    PyTuple_SetItem(params, 2, PyFloat_FromDouble(param3));

    // Call the predict function with the parameters
    PyObject* result = PyObject_CallObject(predict_function, params);

    // Check for errors
    if (PyErr_Occurred()) {
        PyErr_Print();
        PyGILState_Release(gstate);
        return -1;
    }

    // Extract the prediction result from the Python object
    *prediction = PyFloat_AsDouble(result);

    // Release the GIL and return the prediction result
    PyGILState_Release(gstate);
    return 0;
}
