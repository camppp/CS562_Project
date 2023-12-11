#!/bin/bash

# Determine the directory in which the script is located
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

# Make a POST request to the URL and extract the session path from the response header
SESSION_PATH=$(curl -s -X POST "http://localhost:8080/challenge-response/v1/newSession?nonceSize=32" | grep -oP '(?<=sessionPath=).*' | cut -d'=' -f2 | tr -d '"')

# Print the session path to the standard output
echo $SESSION_PATH