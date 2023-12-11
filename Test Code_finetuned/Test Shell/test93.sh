#!/bin/bash

# Check if the directory path is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <directory>"
    exit 1
fi

# Check if the provided directory exists
if [! -d "$1" ]; then
    echo "Error: $1 is not a directory"
    exit 1
fi

# Check if the provided directory is readable
if [! -r "$1" ]; then
    echo "Error: Permission denied to read $1"
    exit 1
fi

# Generate the report
echo "Disk Usage Report for $1:"
du -sh "$1"/* 2>/dev/null | sort -hr | nl