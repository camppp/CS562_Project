#!/bin/bash

# Check if the correct number of arguments are provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <Kubernetes Context> <Namespace>"
    exit 1
fi

# Assign the arguments to variables
context=$1
namespace=$2

# Get the secrets from the specified namespace in the provided Kubernetes context
secrets=$(kubectl --context=$context -n $namespace get secrets | grep "istio.io/key-and-cert")

# Loop through each secret
while read -r line; do
    # Extract the secret name
    secret_name=$(echo $line | awk '{print $1}')

    # Get the secret details
    secret_details=$(kubectl --context=$context -n $namespace get secret $secret_name -o json)

    # Extract and print relevant information
    echo "Secret Name: $secret_name"
    echo "Secret Details:"
    echo $secret_details | jq
    echo "-----------------------------"
done <<< "$secrets"