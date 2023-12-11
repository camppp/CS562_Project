#!/bin/bash

# Task 1: Copy package.json, yarn.lock, and.env files to dist directory
cp package.json dist/
cp yarn.lock dist/
cp.env dist/

# Task 2: Copy dist directory to bin/dist
cp -r dist/ bin/dist/

# Task 3: Check if Docker image exists, if so, remove it
dockerName="registry.cn-hangzhou.aliyuncs.com/youkeda/sugar_server"
tag=$(date -u +"%Y%m%d%H%M%S")

if [[ "$(docker images -q $dockerName 2> /dev/null)"!= "" ]]; then
  echo "Removing existing Docker image: $dockerName"
  docker rmi $dockerName
else
  echo "No existing Docker image found: $dockerName"
fi

# Task 4: Set dockerName variable with tag based on current date and time
dockerName="$dockerName:$tag"
echo "Docker image name set to: $dockerName"