#!/bin/bash

# Exit immediately if any command exits with a non-zero status
set -e

# Execute the test script
./.github/test.sh

# If the test script is successful, generate an HTML coverage report
if [ $? -eq 0 ]; then
    go tool cover -html=coverage.txt
fi