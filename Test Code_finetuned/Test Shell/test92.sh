#!/bin/bash

# Check if gcloud is installed
if! command -v gcloud &> /dev/null
then
    echo "Error: gcloud is not installed on this system."
else
    # Extract and print the version number
    gcloud version | grep 'Google Cloud SDK' | cut -d''-f4
fi