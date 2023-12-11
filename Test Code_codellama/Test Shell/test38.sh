#!/bin/bash

# Remove all automatically installed packages that are no longer required by any installed package
apt-get autoremove -y

# Purge all residual configuration files for packages that have been removed
dpkg --purge $(dpkg --get-selections | grep -v deinstall | awk '{print $1}')

# Purge old Linux kernel images, keeping only the latest two versions, excluding the currently running kernel
dpkg --list | grep linux-image | awk '{print $2}' | sort -r | tail -n +3 | xargs apt-get purge -y