#!/bin/bash

# Check if the build is successful
if [ $? -eq 0 ]; then
  echo "Building and testing"
  # Run the Maven command to run the tests
  mvn test
  # Check if any of the tests failed
  if [ $? -ne 0 ]; then
    echo "Tests failed"
    exit 1
  fi
else
  echo "Build failed"
  exit 1
fi