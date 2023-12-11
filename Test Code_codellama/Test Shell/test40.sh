#!/bin/bash

# Set the SSID and password for the wireless network
echo "ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev" > /etc/wpa_supplicant/wpa_supplicant.conf
echo "update_config=1" >> /etc/wpa_supplicant/wpa_supplicant.conf
echo "network={" >> /etc/wpa_supplicant/wpa_supplicant.conf
echo "ssid=\"MyWirelessNetwork\"" >> /etc/wpa_supplicant/wpa_supplicant.conf
echo "scan_ssid=1" >> /etc/wpa_supplicant/wpa_supplicant.conf
echo "key_mgmt=WPA-PSK" >> /etc/wpa_supplicant/wpa_supplicant.conf
echo "psk=MyWirelessPassword" >> /etc/wpa_supplicant/wpa_supplicant.conf
echo "}" >> /etc/wpa_supplicant/wpa_supplicant.conf

# Restart the wpa_supplicant service
sudo systemctl restart wpa_supplicant