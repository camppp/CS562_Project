#!/bin/bash

# Check if git is installed
if ! command -v git &> /dev/null; then
  # Install git using the package manager
  sudo apt-get install git
fi

# Display success message
echo "Git has been successfully installed!"
echo "Installed version: $(git --version)"
echo "Path to executable: $(which git)"