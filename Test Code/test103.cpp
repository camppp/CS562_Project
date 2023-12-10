#include <windows.h>  // Assuming Windows platform for COM

static HRESULT COMInit() {
    HRESULT coResult = CoInitializeEx(NULL, COINIT_MULTITHREADED);  // Initialize COM with desired flags

    if (coResult == RPC_E_CHANGED_MODE) {
        // If COM was previously initialized with different init flags,
        // NFD still needs to operate. Eat this warning.
        return TRUE;
    }

    return SUCCEEDED(coResult);  // Return the result of COM initialization
}
