#!/bin/bash

# Check if git is installed
if! command -v git &> /dev/null
then
    echo "Git is not installed. Installing now..."

    # Use package manager to install git
    if command -v apt-get &> /dev/null
    then
        sudo apt-get install git -y
    elif command -v yum &> /dev/null
    then
        sudo yum install git -y
    elif command -v dnf &> /dev/null
    then
        sudo dnf install git -y
    else
        echo "Unsupported package manager. Please install git manually."
        exit 1
    fi

    # Check if installation was successful
    if! command -v git &> /dev/null
    then
        echo "Failed to install git. Please install it manually."
        exit 1
    fi
else
    echo "Git is already installed."
fi

# Display installed version and path to executable
git_version=$(git --version)
git_path=$(which git)

echo "Git version: $git_version"
echo "Git path: $git_path"