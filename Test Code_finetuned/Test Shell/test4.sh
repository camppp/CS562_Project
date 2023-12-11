#!/bin/bash

# Start of script
echo "$(date +"%H:%M:%S") START IPv6 script ==="

# Extract and display IPv6-related environment variables
export | grep -E 'ipv6|IPV6'

# End of script
echo "$(date +"%H:%M:%S") END IPv6 script ==="

#!/bin/bash

# Start of script
echo "$(date +"%H:%M:%S") START IPv6 script ==="

# Set environment variables
export IPV6_VAR1="value1"
export IPV6_VAR2="value2"

# Extract and display IPv6-related environment variables
export | grep -E 'ipv6|IPV6'

# End of script
echo "$(date +"%H:%M:%S") END IPv6 script ==="