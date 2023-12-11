#!/bin/bash

# Set the path to the CoreDNS source code
COREDNS_SRC="/path/to/coredns"

# Set the path to the coredns-mdns repository
COREDNS_MDNS_REPO="/path/to/coredns-mdns"

# Set the path to the CoreDNS binary
COREDNS_BIN="/path/to/coredns-bin"

# Compile CoreDNS
echo "Compiling CoreDNS..."
cd $COREDNS_SRC || { echo "Error: Unable to access CoreDNS source directory"; exit 1; }
go build -o $COREDNS_BIN || { echo "Error: Failed to compile CoreDNS"; exit 1; }

# Copy the CoreDNS binary to the coredns-mdns repository
echo "Copying CoreDNS binary to coredns-mdns repository..."
cp $COREDNS_BIN $COREDNS_MDNS_REPO || { echo "Error: Failed to copy CoreDNS binary to coredns-mdns repository"; exit 1; }

echo "CoreDNS build and deployment process completed successfully."