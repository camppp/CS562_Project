#!/bin/bash

# Define the Docker image to use
DOCKER_IMAGE="clangformat"

# Define the directory to search for source files
SEARCH_DIR="src"

# Define the ClangFormat style to use
STYLE="file"

# Function to format a file
format_file() {
    docker run --rm -v "$(pwd)":/src "$DOCKER_IMAGE" clang-format -style="$STYLE" -i "$1"
}

# Find all C++ source files and format them
find "$SEARCH_DIR" -type f \( -name "*.cpp" -o -name "*.h" \) -exec bash -c 'format_file "$0"' {} \;