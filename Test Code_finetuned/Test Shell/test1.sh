#!/bin/bash

# Check if container ID is provided as an argument
if [ -z "$1" ]; then
    echo "Usage: $0 <container_id>"
    exit 1
fi

# Get the PID of the container
PID=$(docker inspect --format {{.State.Pid}} $1)

# Check if PID is found
if [ -z "$PID" ]; then
    echo "Container not found or PID not available"
    exit 1
fi

# Enter the namespace of the container
nsenter --target $PID --mount --uts --ipc --net --pid