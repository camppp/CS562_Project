#!/bin/bash

# Set the duration to wait between checks
duration=30

# Set the number of nodes to check
nodes=$(oc get nodes -o name | wc -l)

# Loop until all nodes are running
while true; do
  # Get the current status of all nodes
  nodes=$(oc get nodes -o jsonpath='{range .items[*]}{.metadata.name}{" "}{.status.phase}{"\n"}{end}')

  # Check if all nodes are running
  if [[ $nodes == *"Running"* ]]; then
    echo "All nodes are running"
    break
  fi

  # Display the current status of each node
  echo "Current status of nodes:"
  echo "$nodes"

  # Wait for the specified duration before checking again
  sleep $duration
done