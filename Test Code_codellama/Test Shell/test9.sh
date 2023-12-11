#!/bin/bash

# Start of script
date +"%H:%M:%S: START IPv6 script ===="

# Extract and display IPv6-related environment variables
export | grep -E 'ipv6|IPV6'

# End of script
date +"%H:%M:%S: END IPv6 script ==="