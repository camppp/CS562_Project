#!/bin/bash

# Step 1: Build the project
mvn clean install

# Check if the build was successful
if [ $? -eq 0 ]; then
    echo "Building and testing"
    mvn test
else
    echo "Build failed"
    exit 1
fi

# Check if the tests were successful
if [ $? -eq 0 ]; then
    echo "Tests passed"
else
    echo "Tests failed"
    exit 1
fi