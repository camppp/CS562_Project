// Complete the function to load a string resource from a Windows DLL
int LoadStringFromDLL(HINSTANCE hInst, LPCSTR lpszName, int nID, LPSTR lpszBuf, int nMaxBuf) {
    int nLen = 0;
    
    // Check if the resource handle is valid
    if (hInst == NULL) {
        // Handle the error when the resource handle is invalid
        // For example, log the error or return an error code
        return -1; // Indicate an error occurred
    }

    // Find the string resource in the DLL
    HRSRC hResInfo = ::FindResourceA(hInst, lpszName, (LPCSTR)RT_STRING);
    if (hResInfo != NULL) {
        // Load the string resource into the buffer
        nLen = ::LoadStringA(hInst, nID, lpszBuf, nMaxBuf);
        if (nLen > 0) {
            // String loaded successfully
            return nLen;
        } else {
            // Handle the error when the string loading fails
            // For example, log the error or return an error code
            return 0; // Indicate that the string loading failed
        }
    } else {
        // Handle the error when the resource is not found
        // For example, log the error or return an error code
        return 0; // Indicate that the resource was not found
    }
}
