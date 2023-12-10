#include <Python.h>

int callPredictFunction(double param1, double param2, double param3, double* prediction) {
    PyGILState_STATE gstate = PyGILState_Ensure();

    PyObject *pModule = PyImport_ImportModule("your_module_name");  // Replace "your_module_name" with the actual module name

    if (pModule) {
        // Importing the Predict Function
        PyObject *pFunc = PyObject_GetAttrString(pModule, "predict");

        if (pFunc && PyCallable_Check(pFunc)) {
            // Creating PyObjects Parameters for Predict Function
            PyObject *pArgs = PyTuple_New(3);
            PyTuple_SetItem(pArgs, 0, PyFloat_FromDouble(param1));
            PyTuple_SetItem(pArgs, 1, PyFloat_FromDouble(param2));
            PyTuple_SetItem(pArgs, 2, PyFloat_FromDouble(param3));

            // Calling the Predict Function
            PyObject *pValue = PyObject_CallObject(pFunc, pArgs);

            if (pValue != NULL && PyFloat_Check(pValue)) {
                *prediction = PyFloat_AsDouble(pValue);
                Py_DECREF(pValue);
            } else {
                PyErr_Print();
                Py_XDECREF(pValue);
                Py_XDECREF(pArgs);
                Py_XDECREF(pFunc);
                Py_XDECREF(pModule);
                PyGILState_Release(gstate);
                return -1;  // Error occurred during prediction
            }

            Py_XDECREF(pArgs);
            Py_XDECREF(pFunc);
        } else {
            PyErr_Print();
            Py_XDECREF(pFunc);
            Py_XDECREF(pModule);
            PyGILState_Release(gstate);
            return -1;  // Error occurred during function retrieval
        }

        Py_XDECREF(pModule);
    } else {
        PyErr_Print();
        PyGILState_Release(gstate);
        return -1;  // Error occurred during module import
    }

    PyGILState_Release(gstate);
    return 0;  // Prediction successful
}
