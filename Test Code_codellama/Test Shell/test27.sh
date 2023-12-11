#!/bin/bash

# Modify the dhclient.conf file
sed -i 's/#prepend domain-name-servers 127.0.0.1;/prepend domain-name-servers 8.8.8.8, 8.8.4.4;/g' /etc/dhcp/dhclient.conf

# Restart the network interface
ifdown eth0 && ifup eth0

# Check for errors
if [ $? -ne 0 ]; then
  echo "Error: Failed to restart network interface"
  exit 1
fi

# Print success message
echo "Success: DNS servers updated and network interface restarted"