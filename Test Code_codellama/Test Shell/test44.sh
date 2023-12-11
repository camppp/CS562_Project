#!/bin/bash

# Set the memory settings for the Minecraft server
mem=1024

# Append commands to the start.sh script to change directory to /opt/minecraft/survival and start the Minecraft server using Java with specified memory settings
echo "cd /opt/minecraft/survival" >> start.sh
echo "java -Xms${mem}M -Xmx${mem}M -jar server.jar -nogui" >> start.sh

# Set execute permissions and ownership for the start.sh script
chmod +x start.sh
chown minecraft:minecraft start.sh

# Run the updater script
/updatemc.sh