#!/bin/bash

# Initialize the logging file and set the logging mode
touch log.txt
LOG_MODE=discret

# Define the severity levels for log messages
INFO=0
WARNING=1
ERROR=2

# Define the log message format
LOG_FORMAT="%Y-%m-%d %H:%M:%S [%L] %M"

# Function to log a message
log() {
  local level=$1
  local message=$2
  local timestamp=$(date +"%Y-%m-%d %H:%M:%S")
  local log_message="${timestamp} [${level}] ${message}"

  if [ "$LOG_MODE" = "stdout" ]; then
    echo "$log_message"
  elif [ "$LOG_MODE" = "discret" ]; then
    echo "$log_message" >> log.txt
  fi
}

# Function to log an INFO message
info() {
  local message=$1
  log $INFO "$message"
  }