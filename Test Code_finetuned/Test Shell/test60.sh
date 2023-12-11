#!/bin/bash

# Define the required fields filter
requireFields='.abi |.[] | select(.type == "function") | {name, inputs, outputs}'

# Process BloomAaveBridge.json
cat./build/contracts/BloomAaveBridge.json | jq "$requireFields" > BloomAaveBridge.json

# Process BloomERC1155.json
cat./build/contracts/BloomERC1155.json | jq "$requireFields" > BloomERC1155.json