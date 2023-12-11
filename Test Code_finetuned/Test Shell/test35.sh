#!/bin/bash

# Set the memory settings
mem=1024

# Append commands to start.sh
echo "cd /opt/minecraft/survival" >> start.sh
echo "java -Xms${mem}M -Xmx${mem}M -jar server.jar -nogui" >> start.sh

# Set execute permissions on start.sh and run the updater
chmod +x start.sh
./start.sh

# Set ownership and execute permissions on updater
chown minecraft:minecraft updatemc.sh
chmod +x updatemc.sh
./updatemc.sh