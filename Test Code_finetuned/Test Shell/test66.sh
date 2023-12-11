#!/bin/sh

# Check if the directory exists
if [! -d "build" ]; then
  echo "Error: build directory does not exist. Please run the build process first."
  exit 1
fi

# Change directory to the build directory
cd build || exit

# Compile all.java files to.class files
echo "Compiling.java files to.class files..."
javac../src/main/java/com/roomba/comm/*.java

# Check if the compilation was successful
if [ $? -ne 0 ]; then
  echo "Error: Compilation failed. Please check your code."
  exit 1
fi

# Build the jar file
echo "Building jar file..."
jar cvf RoombaComm.jar -C../src/main/java/.

# Check if the jar file was created successfully
if [ $? -ne 0 ]; then
  echo "Error: Failed to create jar file. Please check your code."
  exit 1
fi

echo "Jar file created successfully."