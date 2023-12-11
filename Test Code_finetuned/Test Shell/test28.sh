#!/bin/bash

# Initialize the variable ROOT_PART with the root device name
ROOT_PART=$(lsblk -o NAME,MOUNTPOINT | grep'/$' | awk '{print $1}')

# Use a case statement to set the variable ROOT_DEV based on the root device name
case $ROOT_PART in
    mmcblk0*)
        ROOT_DEV="mmcblk0"
        ;;
    sda*)
        ROOT_DEV="sda"
        ;;
    *)
        echo "Unknown root device: $ROOT_PART"
        exit 1
        ;;
esac

# Extract the last partition name and store it in the variable LAST_PART
LAST_PART=$(lsblk -o NAME,MOUNTPOINT | grep "$ROOT_DEV" | tail -n 1 | awk '{print $1}')

echo "The last partition of the root device is: $LAST_PART"