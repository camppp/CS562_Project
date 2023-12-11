#!/bin/bash

# Check if the user has sudo privileges
if [ $(id -u) -ne 0 ]; then
    echo "This script requires sudo privileges. Please run with sudo."
    exit 1
fi

# Execute the installation script for AWS CLI tools
./aws/install

# Check if the installation was successful
if [ $? -eq 0 ]; then
    echo "AWS CLI tools installed successfully."
else
    echo "An error occurred during the installation. Please check the logs for more information."
fi