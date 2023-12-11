#!/bin/bash

# Accept command-line arguments
TARGET_DIR=$1
CONFIG_FILE=$2

# Create a minimal ARM64 root filesystem using multistrap
multistrap -d $TARGET_DIR -c $CONFIG_FILE

# Identify symbolic links in the directory $TARGET_DIR/usr/lib/aarch64-linux-gnu
# and adjust their targets to be relative paths
find $TARGET_DIR/usr/lib/aarch64-linux-gnu -type l -exec sh -c '
  for link in "$@"; do
    target=$(readlink -f "$link")
    if [[ $target == $TARGET_DIR/usr/lib/aarch64-linux-gnu/* ]]; then
      echo "Adjusting target of $link to be relative"
      ln -sf $(basename "$target") "$link"
    fi
  done' _ {} +

