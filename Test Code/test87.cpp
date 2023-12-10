int InitializeStreamContext() {
    if (sm_fInitcsIsapiStreamContexts) {
        return 0; // Already initialized
    }

    // Perform initialization process
    // ...

    // Simulate an error during initialization
    // Replace this with actual initialization code
    if (/* error condition */) {
        hr = E_FAIL; // Set appropriate error code
        Terminate();
        return 1; // Return non-zero error code
    }

    sm_fInitcsIsapiStreamContexts = TRUE;
    return 0; // Successful initialization
}
