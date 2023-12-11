#!/bin/bash

yellow_echo() {
    echo -e "\033[33m$1\033[0m"
}

check_processor() {
    if systemctl is-active processor > /dev/null 2>&1; then
        yellow_echo "Processor service is running smoothly."
    else
        yellow_echo "Processor service is in error. Attempting to restart..."
        if systemctl start processor > /dev/null 2>&1; then
            yellow_echo "Processor service has been successfully restarted."
        else
            yellow_echo "Failed to restart the processor service."
        fi
    fi
}

check_processor