#!/bin/bash

# Define the installation path
path="/path/to/installation"

# Create the directory
mkdir -p $path

# Navigate to the created directory
cd $path

# Create a subdirectory named 'local'
mkdir -p $path/local

# Remove any existing 'MPItrampoline' directory
rm -rf $path/MPItrampoline

# Clone the MPItrampoline repository
git clone https://github.com/eschnett/MPItrampoline.git $path/MPItrampoline

# Navigate to the 'MPItrampoline' directory
cd $path/MPItrampoline

# Use CMake to configure the build
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=$path/local/mpitrampoline.

# Build MPItrampoline
cmake --build.

# Install MPItrampoline
cmake --install.