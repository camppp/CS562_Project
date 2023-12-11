#!/bin/bash

# Check if the script is run with at least one argument
if [ $# -lt 1 ]; then
    echo "Usage: $0 <profile_arg>"
    exit 1
fi

PROFILE_ARG=$1
OUTPUT_BIN="/path/to/your/output/binary/file"
OUTPUT="/path/to/your/output/directory"

# Check if the output binary file exists
if [! -f "$OUTPUT_BIN" ]; then
    echo "Error: Output binary file not found"
    exit 1
fi

# Check if the output directory exists
if [! -d "$OUTPUT" ]; then
    echo "Error: Output directory not found"
    exit 1
fi

# Check if the profile argument is provided
if [ "$PROFILE_ARG" = "your_profile_arg" ]; then
    cp "$OUTPUT_BIN" "$OUTPUT"
    echo "Copied $OUTPUT_BIN to $OUTPUT"
else
    echo "Profile argument not provided. No action taken."
fi