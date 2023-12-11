#!/bin/bash

# Check if tag name is provided
if [ -z "$1" ]
then
    echo "Please provide a tag name."
    exit 1
fi

tag_name=$1

echo "Setting tag: $tag_name"

# Set the tag
git tag $tag_name

if [ $? -ne 0 ]
then
    echo "Error setting tag."
    exit 1
fi

echo "Pushing tag: $tag_name"

# Push the tag
git push origin $tag_name

if [ $? -ne 0 ]
then
    echo "Error pushing tag."
    exit 1
fi

echo "Tagging and pushing process completed successfully."