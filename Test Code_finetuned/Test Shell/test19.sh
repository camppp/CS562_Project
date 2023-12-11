#!/bin/bash

# Read the value of the environment variable MOIRA_API_URI
MOIRA_API_URI=$MOIRA_API_URI

# Use sed to replace the placeholder MOIRA_API_URI in the file /etc/nginx/conf.d/moira.conf
sed -i "s|MOIRA_API_URI|$MOIRA_API_URI|" /etc/nginx/conf.d/moira.conf

# Start the Nginx server in the foreground
nginx -g "daemon off;"