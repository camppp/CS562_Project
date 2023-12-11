#!/bin/bash

# Check if the correct number of arguments are provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <directory> <filename>"
    exit 1
fi

# Assign command-line arguments to variables
directory="$1"
filename="$2"

# Check if the directory exists
if [! -d "$directory" ]; then
    echo "Error: Directory $directory does not exist."
    exit 1
fi

# Search for the file in the directory and its subdirectories
if find "$directory" -name "$filename" -print -quit | grep -q.; then
    echo "found $filename"
else
    echo "did not find $filename"
fi