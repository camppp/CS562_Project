#!/bin/bash

# Check if the message variable is set
if [ -z "$message" ]
then
    echo "Error: The message variable is not set."
    exit 1
fi

# Add all changes to the Git staging area
git add.

# Commit the changes with the provided message
git commit -m "$message"

# Push the committed changes to the remote repository
git push