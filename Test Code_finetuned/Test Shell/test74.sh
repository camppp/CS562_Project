#!/bin/bash

# Define the file path
file_path="./release-after-hook.sh"

# Check if the file exists
if [ -f "$file_path" ]; then
    echo "File exists. Executing the script..."
   ./scripts/release-after-hook.sh
else
    echo "File does not exist."
fi