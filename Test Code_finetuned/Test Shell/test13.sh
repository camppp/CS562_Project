#!/bin/bash

# Determine the directory in which the script is located
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

# Make a POST request to the specified URL
response=$(curl -s -o /dev/null -w "HTTP_CODE:%{http_code}\nHEADERS:%{header_names}\nHEADER_VALUES:%{header_values}\n" -X POST http://localhost:8080/challenge-response/v1/newSession?nonceSize=32)

# Extract the session path from the response header
session_path=$(echo "$response" | grep -A 1 "Location" | tail -n 1 | cut -d'' -f 2)

# Print the session path
echo "Session path: $session_path"