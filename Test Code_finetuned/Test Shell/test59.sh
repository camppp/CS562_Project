#!/bin/bash

# Check if directory is provided as argument
if [ -z "$1" ]; then
    echo "Error: No directory provided."
    exit 1
fi

# Check if directory exists
if [! -d "$1" ]; then
    echo "Error: Directory does not exist."
    exit 1
fi

# Check if directory contains NIfTI files
if [ -z "$(ls -A $1/*.nii* 2>/dev/null)" ]; then
    echo "Error: Directory does not contain any NIfTI files."
    exit 1
fi

# Convert NIfTI files to MINC
count=0
for i in $1/*.nii*; do
    output_file="$(echo $i | cut -d "." -f1).mnc"
    if nii2mnc -short $i $output_file; then
        echo "Converted $i to $output_file"
        count=$((count+1))
    else
        echo "Error: Failed to convert $i"
    fi
done

# Display success message
if [ $count -gt 0 ]; then
    echo "Success: Converted $count NIfTI files to MINC."
else
    echo "No files were converted."
fi