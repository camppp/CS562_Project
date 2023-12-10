c
#include <stdio.h>

// Global variable to keep track of the logging state
static bool logging_active = false;

// Function to start the logging process
void StartLog(void) {
    logging_active = true;
}

// Function to stop the logging process
void StopLog(void) {
    logging_active = false;
}

// Function to log a message if the logging process is active
void LogMessage(const char* message) {
    if (logging_active) {
        printf("%s\n", message);
    }
}

int main() {
    StartLog(); // Start logging
    LogMessage("This message should be logged"); // Log the message
    StopLog(); // Stop logging
    LogMessage("This message should not be logged"); // This message should not be logged
    return 0;
}
