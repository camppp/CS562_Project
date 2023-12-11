#!/bin/bash

# Set default values for environment variables
AUTH=${AUTH:-noauth}
SSL=${SSL:-nossl}
MONGODB_URI=${MONGODB_URI:-}
TOPOLOGY=${TOPOLOGY:-standalone}

# Check if any of the commands fail
set -e

# Set the environment variables
export AUTH=$AUTH
export SSL=$SSL
export MONGODB_URI=$MONGODB_URI
export TOPOLOGY=$TOPOLOGY

# Print the environment variables
echo "AUTH: $AUTH"
echo "SSL: $SSL"
echo "MONGODB_URI: $MONGODB_URI"
echo "TOPOLOGY: $TOPOLOGY"