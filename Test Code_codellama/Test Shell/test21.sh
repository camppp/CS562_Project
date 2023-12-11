#!/bin/bash

# Check if .env file exists
if [ ! -f .env ]; then
  echo "Error: .env not found."
  exit 1
fi

# Create .env file if it does not exist
if [ ! -f .env ]; then
  cp .env.example .env
fi

# Start Supervisor process manager in foreground
/usr/bin/supervisord -c /etc/supervisor/supervisord.conf