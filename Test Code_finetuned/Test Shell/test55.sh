#!/bin/bash

# Check if URL is provided as an argument
if [ -z "$1" ]
then
    echo "Please provide a URL as an argument."
    exit 1
fi

# Fetch HTML content from the provided URL
HTML_CONTENT=$(curl -s "$1")

# Check if curl command was successful
if [ $? -ne 0 ]
then
    echo "Failed to fetch HTML content from the provided URL."
    exit 1
fi

# Process the HTML content using blaze-from-html
echo "$HTML_CONTENT" | stack exec blaze-from-html

# Check if blaze-from-html command was successful
if [ $? -ne 0 ]
then
    echo "Failed to process HTML content."
    exit 1
fi