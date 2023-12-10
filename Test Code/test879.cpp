#include <windows.h>

// Define the RV and BasicError classes if not already defined
class RV {
    // Define RV class members if needed
};

class BasicError {
public:
    static BasicError bad_system_call() {
        // Implement bad_system_call method to return a BasicError object representing a bad system call
        return BasicError();
    }
};

// Function to unload a shared library and return appropriate value based on success or failure
template<typename RV>
RV unloadLibrary(void* handle) {
    BOOL r = ::FreeLibrary((HMODULE)handle);
    return r ? RV() : BasicError::bad_system_call();
}
