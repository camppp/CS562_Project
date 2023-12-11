#!/bin/bash

# Set the ZIP variable to 1 to enable zipping the directory
ZIP=1

# Set the remote storage path
REMOTE_PATH=/path/to/remote/storage

# Set the directory to be backed up
BACKUP_DIR=/tmp/gh-bk

# Set the timestamp for the backup file
NOW_DATE=$(date +%Y-%m-%d_%H-%M-%S)

# Zip the directory if the ZIP variable is set to 1
if [ $ZIP -eq 1 ]; then
  # Zip the directory with the specified options
  zip -r $BACKUP_DIR.zip $BACKUP_DIR

  # Move the zip file to the remote storage
  rclone move $BACKUP_DIR.zip $REMOTE_PATH

  # Print a message indicating the move operation
  echo "Moved $BACKUP_DIR.zip to $REMOTE_PATH"
