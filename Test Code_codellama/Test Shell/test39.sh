#!/bin/bash

# Set the path to the Docker image
DOCKER_IMAGE="clangformat/clangformat"

# Set the path to the source directory
SRC_DIR="src"

# Set the style to use for formatting
STYLE="file"

# Function to format a single source file
format_file() {
  local file="$1"
  local style="$2"

  # Run ClangFormat on the file using the specified style
  docker run --rm -v "$(pwd):/src" "$DOCKER_IMAGE" clang-format -style="$style" -i "$file"
}

# Function to format all source files in the specified directory and its subdirectories
format_all() {
  local dir="$1"

  # Find all C++ source files in the directory and its subdirectories
  find "$dir" -type f -name "*.cpp" -o -name "*.h" | while read -r