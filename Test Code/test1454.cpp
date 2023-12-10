#include <stdio.h>
#include <stdbool.h>

bool loggingActive = false;

// Function to start the logging process
void StartLog(void) {
    loggingActive = true;
}

// Function to log a message if the logging process is active
void LogMessage(const char* message) {
    if (loggingActive) {
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
