#!/bin/bash

# Specify the duration to wait before checking the node status again
wait_duration=60

while true; do
    # Get the status of all nodes
    node_status=$(oc get nodes -o jsonpath='{range.items[*]}{.metadata.name}{"\t"}{.status.conditions[?(@.type=="Ready")].status}{"\n"}{end}')

    # Check if all nodes are running
    all_nodes_running=$(echo "$node_status" | grep -v "Running" | wc -l)

    if [ $all_nodes_running -eq 0 ]; then
        echo "All nodes are running."
        break
    else
        echo "Not all nodes are running. Current status:"
        echo "$node_status"
    fi

    # Wait for the specified duration
    sleep $wait_duration
done