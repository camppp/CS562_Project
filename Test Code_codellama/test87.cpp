c
int InitializeStreamContext()
{
    // Check if the stream context has already been initialized
    if (sm_fInitcsIsapiStreamContexts)
    {
        // If it has, return immediately without performing any initialization
        return 0;
    }

    // Initialize the stream context
    HRESULT hr = S_OK;
    hr = InitializeStreamContextInternal();

    // Check for errors
    if (FAILED(hr))
    {
        // If an error occurred, set the HRESULT and call Terminate
        Terminate();
        return hr;
    }

    // Set the flag indicating that the stream context has been initialized
    sm_fInitcsIsapiStreamContexts = TRUE;

    // Return success
    return 0;
}
