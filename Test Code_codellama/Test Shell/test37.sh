#!/bin/bash

# Initialize the variables
ROOT_PART=$(cat /proc/mounts | grep -o '^/dev/[a-z]d[0-9]')
ROOT_DEV=""
LAST_PART=""

# Determine the last partition of the root device
case $ROOT_PART in
    mmcblk0*)
        ROOT_DEV=$(echo $ROOT_PART | awk -F'/' '{print $3}')
        LAST_PART=$(echo $ROOT_DEV | tail -c 1)
        ;;
    sda*)
        ROOT_DEV=$(echo $ROOT_PART | awk -F'/' '{print $3}')
        LAST_PART=$(echo $ROOT_DEV | tail -c 1)
        ;;
    *)
        echo "Unknown root device: $ROOT_PART"
        exit 1
        ;;
esac

# Print the last partition of the root device
echo "Last partition of the root device: $LAST_PART"