#!/bin/bash

# Function to validate input
validate_input() {
    if [ -z "$1" ]; then
        echo "Error: Input cannot be empty."
        exit 1
    fi
}

# Prompt user for input
echo "Enter the device name:"
read device_name
validate_input $device_name

echo "Enter the mount point:"
read mount_point
validate_input $mount_point

echo "Enter the filesystem type:"
read fs_type
validate_input $fs_type

echo "Enter the options:"
read options
validate_input $options

# Construct /etc/fstab entry
echo "$device_name $mount_point $fs_type $options 0 2" >> /etc/fstab

echo "Entry added to /etc/fstab successfully."