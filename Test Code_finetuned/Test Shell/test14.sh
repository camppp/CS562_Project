#!/bin/bash

# Check if.env file exists
if [! -f.env ]; then
    echo "Error:.env not found."
    # Copy.env.example to.env
    cp.env.example.env
fi

# Start Supervisor process manager
/usr/bin/supervisord -n -c /etc/supervisor/supervisord.conf