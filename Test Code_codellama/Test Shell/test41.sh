#!/bin/bash

# Log file location
LOG_FILE=/var/log/kafkamanager-shutdown.log

# Function to log a message to the log file
log() {
  echo "$(date) - $1" >> $LOG_FILE
}

# Function to check if the Kafka Manager process is running
is_running() {
  local pid=$(pgrep -f "kafka-manager")
  if [ -z "$pid" ]; then
    log "Kafka Manager process is not running"
    exit 0
  fi
  echo $pid
}

# Function to shut down the Kafka Manager process
shutdown() {
  local pid=$(is_running)
  if [ -z "$pid" ]; then
    log "Kafka Manager process is not running"
    exit 0
  fi
  log "Shutting down Kafka Manager process with PID $pid"
  kill -9 $pid
  log "Kafka"
}