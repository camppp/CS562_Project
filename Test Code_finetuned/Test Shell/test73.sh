#!/bin/bash

# Change directory to the parent directory
cd..

# Download the source code for tmux
curl -L https://github.com/tmux/tmux/releases/download/$TMUX_VER/tmux-$TMUX_VER.tar.gz -o tmux-$TMUX_VER.tar.gz

# Extract the downloaded tarball
tar -xvf tmux-$TMUX_VER.tar.gz

# Change directory to the extracted tmux source directory
cd tmux-$TMUX_VER

# Configure the build with specific flags and installation directory
./configure --prefix=/usr/local

# Compile the source code using make
make

# Install the compiled binaries using sudo make install
sudo make install

# Change directory back to the parent directory
cd..