#!/bin/bash

# Get the Node.js version
NODE_VERSION=$(node --version)

# Check if the version contains "0.10"
if [[ $NODE_VERSION == *"0.10"* ]]; then
  echo "fail"
  exit 1
else
  echo "pass"
  exit 0
fi