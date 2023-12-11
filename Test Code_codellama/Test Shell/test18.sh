#!/bin/bash

# Get the input file name and specified age from the command-line arguments
input_file=$1
specified_age=$2

# Read the input file and extract the names and ages
while read -r name age; do
  if [ "$age" -gt "$specified_age" ]; then
    echo "$name"
  fi
done < "$input_file"