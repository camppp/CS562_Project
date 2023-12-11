#!/bin/sh

# Function to check and create directory
should_it_make_deep_link_directory() {
    if [! -d "$1" ]; then
        mkdir "$1"
        return 0
    else
        return 1
    fi
}

# Save the current directory
original_dir=$(pwd)

# Change to the user's home directory
cd ~

# Call the function
should_it_make_deep_link_directory "deep_link_dir"

# Check the return status
if [ $? -eq 0 ]; then
    echo "Directory deep_link_dir was successfully created."
else
    echo "Directory deep_link_dir already exists."
fi

# Change back to the original directory
cd "$original_dir"