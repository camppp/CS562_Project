#!/bin/bash

# Check if the correct number of arguments are provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <target_dir> <config_file>"
    exit 1
fi

TARGET_DIR=$1
CONFIG_FILE=$2

# Check if the target directory exists
if [! -d "$TARGET_DIR" ]; then
    echo "Error: Target directory does not exist."
    exit 1
fi

# Check if the configuration file exists
if [! -f "$CONFIG_FILE" ]; then
    echo "Error: Configuration file does not exist."
    exit 1
fi

# Create the root filesystem using multistrap
multistrap -a arm64 -d $TARGET_DIR -f $CONFIG_FILE

# Check if multistrap was successful
if [ $? -ne 0 ]; then
    echo "Error: Failed to create root filesystem."
    exit 1
fi

# Change to the target directory
cd $TARGET_DIR

# Find all symbolic links in /usr/lib/aarch64-linux-gnu and adjust their targets to be relative paths
find usr/lib/aarch64-linux-gnu -type l -exec sh -c 'target=$(readlink "$1"); echo "$1 -> $target"; mv "$1" "$1.bak"; ln -s "${target#/usr/lib/aarch64-linux-gnu/}" "$1"' _ {} \;

# Check if the find command was successful
if [ $? -ne 0 ]; then
    echo "Error: Failed to adjust symbolic links."
    exit 1
fi

# Create symbolic links for the pkgconfig files in /usr/lib/aarch64-linux-gnu/pkgconfig to the corresponding location in /usr/share/pkgconfig
find usr/lib/aarch64-linux-gnu/pkgconfig -type f -exec sh -c 'target=$(basename "$1"); echo "$1 -> $target"; ln -s "$1" "usr/share/pkgconfig/$target"' _ {} \;

# Check if the find command was successful
if [ $? -ne 0 ]; then
    echo "Error: Failed to create pkgconfig symbolic links."
    exit 1
fi

echo "Setup completed successfully."