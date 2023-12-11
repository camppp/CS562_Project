void CloseLinuxHandle(HANDLE hDevice)
{
    // Check if the handle is valid
    if (hDevice == NULL)
    {
        // Handle is invalid, return
        return;
    }

    // Release the resources associated with the handle
    close(hDevice);

    // Set the handle to NULL to indicate that it has been closed
    hDevice = NULL;
}
