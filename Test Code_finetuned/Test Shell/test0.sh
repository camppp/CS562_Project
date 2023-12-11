#!/bin/bash

# Initialize the logging file and set the logging mode
LOG_FILE="logfile.log"
LOG_MODE="discret"

# Create the log file if it doesn't exist
touch $LOG_FILE

# Function to log messages
log() {
    local severity=$1
    local message=$2
    local timestamp=$(date)

    if [ "$LOG_MODE" = "stdout" ]; then
        echo "[$timestamp] [$severity] $message"
    elif [ "$LOG_MODE" = "discret" ]; then
        echo "[$timestamp] [$severity] $message" >> $LOG_FILE
    else
        echo "Invalid LOG_MODE: $LOG_MODE"
        exit 1
    fi
}

# Log messages with different severity levels
log "INFO" "This is an informational message"
log "WARNING" "This is a warning message"
log "ERROR" "This is an error message"