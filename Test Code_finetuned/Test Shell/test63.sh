#!/bin/bash

# Check if the file exists
if [! -f "main.go" ]; then
    echo "Error: main.go not found"
    exit 1
fi

# Update the command
sed -i.bak's/"git-cleanup [^"]*"/"git-cleanup $1"/' main.go

# Check if the update was successful
if [ $? -ne 0 ]; then
    echo "Error: Failed to update the command"
    exit 1
fi

# Remove the backup file
rm main.go.bak

# Check if the backup file was removed
if [ $? -ne 0 ]; then
    echo "Error: Failed to remove the backup file"
    exit 1
fi

echo "Command updated successfully"