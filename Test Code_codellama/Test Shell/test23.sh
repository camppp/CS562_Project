#!/bin/bash

# Create a directory specified by the variable $path
mkdir -p $path

# Navigate to the created directory
cd $path

# Create a subdirectory named local within the $path directory
mkdir local

# Remove any existing MPItrampoline directory within the $path
rm -rf MPItrampoline

# Clone the MPItrampoline repository from https://github.com/eschnett/MPItrampoline into the $path/MPItrampoline directory
git clone https://github.com/eschnett/MPItrampoline.git

# Navigate to the MPItrampoline directory
cd MPItrampoline

# Use CMake to configure the build, specifying the build type as Debug and the installation prefix as $path/local/mpitrampoline
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=$path/local/mpitrampoline
