#!/bin/bash

# Prompt the user to input the device name, mount point, filesystem type, and options for each filesystem entry
echo "Enter the device name for the first filesystem entry:"
read device1
echo "Enter the mount point for the first filesystem entry:"
read mount1
echo "Enter the filesystem type for the first filesystem entry:"
read type1
echo "Enter the options for the first filesystem entry:"
read options1

echo "Enter the device name for the second filesystem entry:"
read device2
echo "Enter the mount point for the second filesystem entry:"
read mount2
echo "Enter the filesystem type for the second filesystem entry:"
read type2
echo "Enter the options for the second filesystem entry:"
read options2

# Construct the /etc/fstab file with the provided information in the format shown in the code snippet
cat << EOF > /etc/fstab
$device1 $mount1 $type1 $options1
$device2 $mount2 $type2 $options2
