#!/bin/bash

# Accept a container ID as input
container_id=$1

# Retrieve the process ID (PID) of the specified container using the docker inspect command
pid=$(docker inspect --format '{{.State.Pid}}' $container_id)

# Enter the namespace of the container using the nsenter command with the obtained PID and the options --mount, --uts, --ipc, --net, and --pid
nsenter --mount --uts --ipc --net --pid $pid