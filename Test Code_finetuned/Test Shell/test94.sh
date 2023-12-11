#!/bin/bash

# Check if the process management file exists
if [ -f "process_management_file" ]; then
    # Read the process management file line by line
    while IFS= read -r line || [ -n "$line" ]; do
        # Extract the PID
        pid=$(echo $line | cut -d'' -f 1)

        # Check if the process with the PID exists
        if ps -p $pid > /dev/null; then
            # Terminate the process
            kill -9 $pid 2> /dev/null || true
        fi
    done < process_management_file

    # Remove the process management file
    rm -f process_management_file
else
    echo "Process management file not found"
fi