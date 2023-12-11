#!/bin/bash

# Check if /usr/src/.jx3 directory exists
if [ -d "/usr/src/.jx3" ]; then
    # Copy contents of /usr/src/.jx3 to /root
    cp -r /usr/src/.jx3 /root
    echo "Backup of /usr/src/.jx3 completed."
else
    echo "Error: /usr/src/.jx3 directory does not exist."
fi

# Create a new directory named jenkinsx3 within /root
mkdir /root/jenkinsx3

# Check if the directory was created successfully
if [ -d "/root/jenkinsx3" ]; then
    echo "Directory /root/jenkinsx3 created successfully."
else
    echo "Error: Failed to create /root/jenkinsx3 directory."
fi

# Navigate into the new directory
cd /root/jenkinsx3 || { echo "Error: Failed to navigate into /root/jenkinsx3 directory."; exit 1; }

echo "Script execution completed."