#!/bin/bash

# Function to check if a directory with the given name exists and create it if not
should_it_make_deep_link_directory() {
  local dir_name=$1
  local dir_path="$HOME/$dir_name"

  if [ ! -d "$dir_path" ]; then
    mkdir -p "$dir_path"
    if [ $? -ne 0 ]; then
      echo "Error: failed to create directory $dir_path"
      return 1
    fi
  fi

  return 0
}

# Get the name of the directory to create
read -p "Enter the name of the directory to create: " dir_name

# Check if the directory already exists
if should_it_make_deep_link_directory "$dir_name"; then
  echo "Directory $dir_name already exists."
else
  echo "Directory $dir_name created successfully."
fi

# Change back to the original directory
popd