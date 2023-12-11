#!/bin/bash

# Check if the correct number of arguments are provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 IMAGE_NAME:TAG REPOSITORY"
    exit 1
fi

IMAGE_NAME=$1
REPOSITORY=$2

# Build the Docker image
docker build -t $IMAGE_NAME.

# Check if the build was successful
if [ $? -ne 0 ]; then
    echo "Docker build failed"
    exit 1
fi

# Push the Docker image to the repository
docker push $REPOSITORY

# Check if the push was successful
if [ $? -ne 0 ]; then
    echo "Docker push failed"
    exit 1
fi

echo "Docker image $IMAGE_NAME successfully pushed to $REPOSITORY"