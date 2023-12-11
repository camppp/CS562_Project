#!/bin/bash

# Check if Syncthing is installed
if sh sysutils/service.sh Syncthing syncthing $HOME/syncthing-linux-*; then
    echo "Syncthing is already installed."
    exit 0
fi

# Get the latest release version number
ver=$(curl -s https://github.com/syncthing/syncthing/releases/latest | grep -oP '(?<=/tag/v)[^"]+')

# Determine the system's architecture
arch="amd64"
if uname -m | grep -q 'arm'; then
    arch="arm"
fi

# Download the appropriate Syncthing binary
url="https://github.com/syncthing/syncthing/releases/download/v${ver}/syncthing-linux-${arch}-v${ver}.tar.gz"
wget -O /tmp/syncthing.tar.gz $url

# Extract the binary
tar -xzf /tmp/syncthing.tar.gz -C /tmp

# Move the binary to the home directory
mv /tmp/syncthing-linux-${arch}-v${ver}/syncthing $HOME/syncthing

# Clean up
rm -rf /tmp/syncthing-linux-${arch}-v${ver} /tmp/syncthing.tar.gz

echo "Syncthing has been successfully installed."