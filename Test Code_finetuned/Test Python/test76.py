import os
import ctypes

def call_c_function():
    # Define the path to the C library
    lib_path = os.path.join(os.path.dirname(__file__), "mymodule_c_with_ctypes", "lib", "libmymodule_c_with_ctypes.so")

    # Load the C library
    lib = ctypes.CDLL(lib_path)

    # Define the function prototype
    lib.hellofcctyp.restype = ctypes.c_char_p

    # Call the function
    result = lib.hellofcctyp()

    # Convert the result to a Python string and return it
    return result.decode('utf-8')