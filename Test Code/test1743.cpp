void enableDebugging(void* output, bool enableDebug) {
    _dbg = output;
    _enableDebug = (enableDebug && (_dbg != NULL));

    // Assuming debug messages are to be output using printf when debugging is enabled
    if (_enableDebug) {
        printf("Debugging enabled. Output destination: %p\n", _dbg);
        // Additional debug message output logic can be added here
    } else {
        printf("Debugging disabled\n");
    }
}
