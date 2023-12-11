#!/bin/bash

# Check if the correct number of arguments is provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <executable_directory> <test_cases_directory>"
    exit 1
fi

# Create the output directory if it does not exist
mkdir -p output

# Iterate through 32 test cases
for i in {1..32}; do
    # Run the executable with the test case file as input
    output=$($1/executable < $2/test_case_$i.txt)

    # Append the test case number and the output to the result.csv file
    echo "Test Case $i:" >> output/result.csv
    echo "$output" >> output/result.csv
    echo "" >> output/result.csv
done