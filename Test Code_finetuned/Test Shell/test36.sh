#!/bin/bash

# Log file
LOG_FILE="/var/log/kafkamanager-shutdown.log"

# Check if Kafka Manager is running
PID=$(lsof -i :9000 | grep LISTEN | awk '{print $2}')

if [ -z "$PID" ]; then
  echo "$(date) - Kafka Manager is not running. Exiting." >> $LOG_FILE
  exit 0
fi

echo "$(date) - Kafka Manager is running with PID: $PID" >> $LOG_FILE

# Attempt to shutdown Kafka Manager
kill -9 $PID

# Check if the shutdown was successful
if [ $? -eq 0 ]; then
  echo "$(date) - Kafka Manager with PID $PID has been successfully shutdown." >> $LOG_FILE
else
  echo "$(date) - An error occurred while trying to shutdown Kafka Manager with PID $PID. Please check the logs." >> $LOG_FILE
fi