#!/bin/bash

# Disclaimer
echo "This script is intended for testing purposes only."
echo "It has been tested in non-root mode on a specific platform and version."
echo "It may not work as expected with newer versions or distributions."
echo "-----------------------------------------------------------------------------"

# Update the system
echo "Updating the system..."
yum update -y

# Install dependencies
echo "Installing dependencies..."
while IFS= read -r package
do
  yum install -y $package
done < packages.txt