#!/bin/bash

# Set up the environment
setup_env
if [ $? -ne 0 ]; then
    echo "Error: Failed to set up the environment"
    exit 1
fi

# Create a source tarball
create_source_tarball
if [ $? -ne 0 ]; then
    echo "Error: Failed to create a source tarball"
    exit 1
fi

# Generate a spec file
create_specfile
if [ $? -ne 0 ]; then
    echo "Error: Failed to generate a spec file"
    exit 1
fi

# Build the RPM package
SPECFILE="$(ls *.spec)"
rpmbuild -ba $SPECFILE
if [ $? -ne 0 ]; then
    echo "Error: Failed to build the RPM package"
    exit 1
fi

echo "RPM package successfully built"