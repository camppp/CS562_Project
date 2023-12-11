#!/bin/bash

# Set the maximum heap memory
max_memory=4G

# Set the initial heap memory
max_memory_startup=4G

# Set the JAR file name
jar_file="your_jar_file.jar"

# Execute the Java application
java -Xms$max_memory_startup -Xmx$max_memory -jar $jar_file