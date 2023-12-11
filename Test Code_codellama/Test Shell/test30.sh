#!/bin/bash

# Recursively copy the contents of the /usr/src/.jx3 directory to the /root directory
rsync -avz /usr/src/.jx3/ /root/

# Create a new directory named jenkinsx3 within the /root directory and navigate into it
mkdir -p /root/jenkinsx3
cd /root/jenkinsx3