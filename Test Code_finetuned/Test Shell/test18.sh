#!/bin/bash

# Check if the script is run with root privileges
if [ "$EUID" -ne 0 ]
  then echo "Please run this script with root privileges."
  exit
fi

# Modify dhclient.conf
sed -i's/#prepend domain-name-servers 127.0.0.1;/prepend domain-name-servers 8.8.8.8, 8.8.4.4;/g' /etc/dhcp/dhclient.conf

# Check if sed command was successful
if [ $? -eq 0 ]
then
  echo "dhclient.conf updated successfully."
else
  echo "Failed to update dhclient.conf."
  exit 1
fi

# Restart network interface
/etc/init.d/networking restart

# Check if network interface restart was successful
if [ $? -eq 0 ]
then
  echo "Network interface restarted successfully."
else
  echo "Failed to restart network interface."
  exit 1
fi