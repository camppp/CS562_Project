#!/bin/bash

# Set the ZIP variable
ZIP=1

# Get the current date in the format YYYY-MM-DD
NOW_DATE=$(date +"%Y-%m-%d")

# Check if ZIP is set to 1
if [ $ZIP -eq 1 ]; then
    # Zip the directory /tmp/gh-bk/ with the specified options
    zip -r /tmp/gh-bk-${NOW_DATE}.zip /tmp/gh-bk/

    # Upload the zip file to the remote storage using rclone
    rclone move /tmp/gh-bk-${NOW_DATE}.zip remote:path/to/destination

    # Print a message indicating the move operation
    echo "Moved /tmp/gh-bk-${NOW_DATE}.zip to remote storage"
else
    # Move the directory /tmp/gh-bk to the remote storage using rclone
    rclone move /tmp/gh-bk remote:path/to/destination

    # Print a message indicating the move operation
    echo "Moved /tmp/gh-bk to remote storage"
fi