#!/bin/bash

# Start ELM process in the background and save its process ID
ELM_PID=$(./elm &)

# Start UWSGI process in the background and save its process ID
UWSGI_PID=$(./uwsgi &)

# Use trap command to catch signals SIGINT, SIGTERM, and ERR
trap 'kill -TERM $ELM_PID $UWSGI_PID' SIGINT SIGTERM ERR

# Wait for ELM process to complete and print "ELM process completed"
wait $ELM_PID
echo "ELM process completed"

# Wait for UWSGI process to complete and print "UWSGI process completed"
wait $UWSGI_PID
echo "UWSGI process completed"