#!/bin/bash

# Stop the process manager pm2
pm2 stop

# Shut down and remove all containers managed by docker-compose, including their associated volumes
docker-compose down --volumes

# Remove any existing containers and volumes
docker rm -f $(docker ps -a -q)
docker volume rm $(docker volume ls -q)

# Remove any existing images
docker rmi $(docker images -q)

# Clean up any existing networks
docker network rm $(docker network ls -q)

# Clean up any existing volumes
docker volume rm $(docker volume ls -q)

# Clean up any existing images
docker rmi $(docker images -q)

# Clean up any existing networks
docker network rm $(docker network ls -q)

# Clean up any existing volumes
docker volume rm $(docker volume ls -q)

# Clean up any existing images
docker rmi $(docker images -q)

# Clean up any existing networks
docker network rm $(docker network ls -q)
