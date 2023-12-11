#!/bin/bash

# Start ELM process in the background and save its process ID
./elm_process &
ELM_PID=$!--

# Start UWSGI process in the background and save its process ID
./uwsgi_process &
UWSGI_PID=$!--

# Function to handle signals and terminate processes
trap_handler() {
    echo "killing"
    kill -15 $ELM_PID
    wait $ELM_PID
    echo "ELM process completed"
    kill -15 $UWSGI_PID
    wait $UWSGI_PID
    echo "UWSGI process completed"
    exit 1
}

# Trap signals and call the trap_handler function
trap 'trap_handler' SIGINT SIGTERM ERR

# Wait for the ELM process to complete
wait $ELM_PID
echo "ELM process completed"

# Wait for the UWSGI process to complete
wait $UWSGI_PID
echo "UWSGI process completed"