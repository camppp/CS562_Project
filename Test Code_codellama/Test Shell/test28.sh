#!/bin/bash

# Read the value of the environment variable MOIRA_API_URI
MOIRA_API_URI=$(printenv MOIRA_API_URI)

# Use sed to replace the placeholder MOIRA_API_URI in the file /etc/nginx/conf.d/moira.conf with the value obtained from the environment variable
sed -i /etc/nginx/conf.d/moira.conf -e "s|MOIRA_API_URI|$MOIRA_API_URI|"

# Start the Nginx server in the foreground
exec nginx -g "daemon off;"