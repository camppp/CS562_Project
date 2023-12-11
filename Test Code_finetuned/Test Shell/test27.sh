#!/bin/bash

# Set the SSID and password for the wireless network
SSID="YourWirelessNetworkSSID"
PASSWORD="YourWirelessNetworkPassword"

# Set up the /etc/network/interfaces file
echo "auto lo" > /etc/network/interfaces
echo "iface lo inet loopback" >> /etc/network/interfaces
echo "auto wlan0" >> /etc/network/interfaces
echo "allow-hotplug wlan0" >> /etc/network/interfaces
echo "iface wlan0 inet dhcp" >> /etc/network/interfaces

# Set up the /etc/wpa_supplicant/wpa_supplicant.conf file
echo "country=US" > /etc/wpa_supplicant/wpa_supplicant.conf
echo "ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev" >> /etc/wpa_supplicant/wpa_supplicant.conf
echo "update_config=1" >> /etc/wpa_supplicant/wpa_supplicant.conf
echo "network={" >> /etc/wpa_supplicant/wpa_supplicant.conf
echo "    ssid=\"$SSID\"" >> /etc/wpa_supplicant/wpa_supplicant.conf
echo "    psk=\"$PASSWORD\"" >> /etc/wpa_supplicant/wpa_supplicant.conf
echo "}" >> /etc/wpa_supplicant/wpa_supplicant.conf

# Restart the networking service
/etc/init.d/networking restart