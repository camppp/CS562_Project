#include <windows.h>

DWORD GetFileAttributesWithErrors(const char* sPath, DWORD* nAttributes, DWORD* nError)
{
    *nAttributes = GetFileAttributes(sPath);
    if (*nAttributes == INVALID_FILE_ATTRIBUTES)
    {
        *nError = GetLastError();
        return *nError; // Return the error code
    }
    else
    {
        return ERROR_SUCCESS; // Return success code
    }
}
