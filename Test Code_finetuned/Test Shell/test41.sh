#!/bin/bash

# Check if directory path is provided
if [ $# -eq 0 ]
then
    echo "No directory path provided. Please provide a directory path."
    exit 1
fi

# Check if directory exists
if [! -d "$1" ]
then
    echo "Directory does not exist. Please provide a valid directory path."
    exit 1
fi

# Initialize variables
total_entries=0
total_time=0
earliest_timestamp=""
latest_timestamp=""

# Loop through all log files in the directory
for file in "$1"/*.log
do
    # Check if file exists
    if [ -f "$file" ]
    then
        # Loop through each line in the file
        while IFS= read -r line
        do
            # Extract timestamp and execution time
            timestamp=$(echo "$line" | grep -oP '(?<=\[).*(?=\])')
            execution_time=$(echo "$line" | grep -oP '(?<=Execution time: ).*(?= seconds)')

            # Update total entries and total time
            total_entries=$((total_entries + 1))
            total_time=$(echo "$total_time + $execution_time" | bc)

            # Update earliest and latest timestamps
            if [ -z "$earliest_timestamp" ] || [[ "$timestamp" < "$earliest_timestamp" ]]
            then
                earliest_timestamp="$timestamp"
            fi

            if [ -z "$latest_timestamp" ] || [[ "$timestamp" > "$latest_timestamp" ]]
            then
                latest_timestamp="$timestamp"
            fi
        done < "$file"
    fi
done

# Calculate average execution time
average_time=$(echo "scale=2; $total_time / $total_entries" | bc)

# Print report
echo "Total number of log entries processed: $total_entries"
echo "Average execution time of the software: $average_time seconds"
echo "Timestamp of the earliest log entry: $earliest_timestamp"
echo "Timestamp of the latest log entry: $latest_timestamp"