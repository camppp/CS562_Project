#!/bin/bash

# Check if the user is root
if [ "$EUID" -ne 0 ]; then
    echo "Please run as root"
    exit
fi

# Check if the correct number of arguments are provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 {run|rund} directory"
    exit 1
fi

# Assign arguments to variables
action=$1
directory=$2

# Check if the specified directory exists
if [! -d "$directory" ]; then
    echo "Directory $directory does not exist"
    exit 1
fi

# Check if the specified directory is a chroot environment
if [! -f "$directory/etc/ld.so.cache" ]; then
    echo "Directory $directory is not a chroot environment"
    exit 1
fi

# Check if the specified action is valid
if [ "$action"!= "run" ] && [ "$action"!= "rund" ]; then
    echo "Invalid action. Please use 'run' or 'rund'"
    exit 1
fi

# Check if the.mucfile exists in the specified directory
if [! -f "$directory/.mucfile" ]; then
    echo ".mucfile not found in $directory"
    exit 1
fi

# Read the command from the.mucfile
command=$(cat "$directory/.mucfile")

# Execute the command within the chroot environment
if [ "$action" == "run" ]; then
    chroot "$directory" /bin/bash -c "$command"
elif [ "$action" == "rund" ]; then
    chroot "$directory" /bin/bash -c "sudo $command"
fi