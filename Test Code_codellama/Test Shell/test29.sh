#!/bin/bash

# Copy package.json, yarn.lock, and .env files to dist directory
cp package.json dist/
cp yarn.lock dist/
cp .env dist/

# Copy dist directory to bin/dist directory
cp -r dist bin/dist

# Check if Docker image with tag registry.cn-hangzhou.aliyuncs.com/youkeda/sugar_server exists
if docker image ls registry.cn-hangzhou.aliyuncs.com/youkeda/sugar_server; then
  # Remove existing image
  docker rmi registry.cn-hangzhou.aliyuncs.com/youkeda/sugar_server
fi

# Set dockerName variable to registry.cn-hangzhou.aliyuncs.com/youkeda/sugar_server with a tag based on current date and time in CST-8 timezone
dockerName="registry.cn-hangzhou.aliyuncs.com/youk