#!/bin/bash

# Check if the client list is provided as an argument
if [ $# -eq 0 ]
then
    echo "No client list provided. Please provide a list of client names as arguments."
    exit 1
fi

# Loop over each client
for client in "$@"
do
    echo "Processing $client..."

    # Remove existing certificate files
    rm -f "$client.key" "$client.csr" "$client.crt"

    # Request a new certificate
    certstrap --depot-path. request-cert --domain "$client" --passphrase ""

    # Sign the certificate
    certstrap --depot-path. sign --years 30 --CA "ca" "$client"

    # Remove the certificate signing request file
    rm -f "$client.csr"

    # Add the signed certificate and key to the git repository
    git add "$client.key" "$client.crt"

    echo "Done processing $client."
done

# Commit the changes to the git repository
git commit -m "Added new certificates and keys for clients"