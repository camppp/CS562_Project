#!/bin/bash

# Check if the version number is provided as an argument
if [ -z "$1" ]; then
    echo "Usage: $0 <version>"
    exit 1
fi

# Assign the version number to a variable
CONFTEST=$1

# Construct the download URL
URL="https://github.com/open-policy-agent/conftest/releases/download/v${CONFTEST}/conftest_${CONFTEST}_Linux_x86_64.tar.gz"

# Download the tar.gz file
curl -L -o conftest.tar.gz $URL

# Extract the contents of the downloaded tar.gz file
tar -xvf conftest.tar.gz

# Move the conftest binary to /usr/local/bin
sudo mv conftest /usr/local/bin

# Print a message indicating the successful installation of conftest
echo "conftest v${CONFTEST} has been successfully installed."