c
void enableDebugging(void* output, bool enableDebug) {
    // Assign the output to a variable
    void* _dbg = output;

    // Set the _enableDebug flag based on the value of enableDebug and the existence of a non-NULL output
    bool _enableDebug = enableDebug && output != NULL;

    // Implement the logic for outputting debug messages to the designated output when debugging is enabled
    if (_enableDebug) {
        // Output the debug message to the designated output
        printf("Debug message: %s\n", "Debugging is enabled");
    }
}
