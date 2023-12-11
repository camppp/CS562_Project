#!/bin/bash

# Initialize an array to hold the frequency of each outcome
declare -A frequencies

# Simulate 1000 dice rolls
for ((i=0; i<1000; i++)); do
    roll=$((1 + RANDOM % 6))  # Generate a random number between 1 and 6
    ((frequencies[$roll]++))  # Increment the frequency of the current roll
done

# Display the frequency of each outcome
for ((i=1; i<=6; i++)); do
    echo "Outcome $i occurred ${frequencies[$i]} times"
done