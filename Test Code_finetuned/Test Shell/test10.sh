#!/bin/bash

# Check if the correct number of arguments are provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 input_file specified_age"
    exit 1
fi

# Assign the command-line arguments to variables
input_file=$1
specified_age=$2

# Check if the input file exists
if [! -f "$input_file" ]; then
    echo "Error: Input file not found"
    exit 1
fi

# Read the input file line by line and check if the age is greater than the specified age
while read -r name age; do
    if [ "$age" -gt "$specified_age" ]; then
        echo "$name"
    fi
done < "$input_file"