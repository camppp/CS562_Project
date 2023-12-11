#!/bin/bash

# Stop the process manager pm2
echo "Stopping pm2..."
pm2 stop all
if [ $? -ne 0 ]; then
    echo "Error: Failed to stop pm2"
    exit 1
fi

# Shut down and remove all containers managed by docker-compose
echo "Stopping and removing docker-compose services..."
docker-compose down -v
if [ $? -ne 0 ]; then
    echo "Error: Failed to stop or remove docker-compose services"
    exit 1
fi

# Your deployment process goes here
# For example, you might want to build your docker image and start the containers
echo "Deploying new version..."
docker-compose up -d
if [ $? -ne 0 ]; then
    echo "Error: Failed to deploy new version"
    exit 1
fi

echo "Deployment completed successfully"