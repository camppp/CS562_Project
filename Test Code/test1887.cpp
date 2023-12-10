c
DWORD GetFileAttributesWithErrors(const char* sPath, DWORD* nAttributes, DWORD* nError)
{
    // Check if the file path is valid
    if (sPath == NULL || nAttributes == NULL || nError == NULL)
    {
        // Return error code if the file path is invalid
        *nError = ERROR_INVALID_PARAMETER;
        return ERROR_INVALID_PARAMETER;
    }

    // Retrieve the file attributes
    *nAttributes = GetFileAttributes(sPath);

    // Check if the file attributes were retrieved successfully
    if (*nAttributes == INVALID_FILE_ATTRIBUTES)
    {
        // Return error code if the file attributes could not be retrieved
        *nError = GetLastError();
        return *nError;
    }

    // Return success
    return ERROR_SUCCESS;
}
