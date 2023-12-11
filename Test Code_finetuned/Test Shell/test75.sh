#!/bin/bash

# Step 1: Start the "warsaw" service
sudo /etc/init.d/warsaw start

# Step 2: Run the "startup.sh" script as a non-privileged user
sudo -u non-privileged-user /path/to/startup.sh