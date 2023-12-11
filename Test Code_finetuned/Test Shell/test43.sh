#!/bin/bash

# Add Souffle repository
sudo apt-add-repository -y "deb https://dl.bintray.com/souffle-lang/deb-unstable buster main"

# Update package lists
sudo apt-get update

# Import Souffle repository GPG key
sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys 379CE192D401AB61

# Install Souffle
sudo apt-get install -y souffle

echo "Souffle has been successfully installed!"