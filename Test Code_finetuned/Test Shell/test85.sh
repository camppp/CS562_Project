#!/bin/bash

# Identify the stuck ingress networks
stuck_networks=$(docker network ls | grep -e 'ingress.*overlay' | awk '{print $1}')

# Check if any stuck ingress networks are found
if [ -z "$stuck_networks" ]
then
    echo "No stuck ingress networks found."
    exit 0
fi

# Remove each identified stuck ingress network
for network in $stuck_networks
do
    echo "Removing network $network"
    docker network rm $network
    if [ $? -ne 0 ]
    then
        echo "Failed to remove network $network"
    fi
done