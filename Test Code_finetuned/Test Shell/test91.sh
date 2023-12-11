#!/bin/bash

# Function to check if logstash process is stopped
check_stopped() {
    while true; do
        if pgrep -u logstash -x logstash > /dev/null; then
            sleep 1
        else
            # Perform action when logstash process has stopped
            echo "Logstash process has stopped. Performing action..."
            # Add your action here
            break
        fi
    done
}

# Run the function
check_stopped