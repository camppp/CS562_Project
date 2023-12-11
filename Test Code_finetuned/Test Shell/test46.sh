#!/bin/bash

if [ -z "$1" ]; then
    echo "Error: No device selected"
    exit 1
else
    echo "$1" > /tmp/selected_device
    echo "Device \"$1\" selected"
fi

./device_selection.sh light