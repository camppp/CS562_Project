#!/bin/bash

# Check if the script is run as root
if [ "$EUID" -ne 0 ]
  then echo "Please run as root"
  exit
fi

# Remove all automatically installed packages that are no longer required by any installed package
apt-get -y -qq autoremove

# Purge all residual configuration files for packages that have been removed
apt-get -y -qq purge $(dpkg --list | grep '^rc' | awk '{print $2}')

# Purge old Linux kernel images, keeping only the latest two versions, excluding the currently running kernel
KERNEL_VERSIONS=$(dpkg --list | egrep 'linux-image-[0-9]' | awk '{print $3,$2}' | sort -nr | tail -n +2 | grep -v $(uname -r) | awk '{print $2}')

for i in $KERNEL_VERSIONS; do
    apt-get -y -qq purge $i
done