#!/bin/bash

# Define the functions
run_tests() {
    echo "Running tests..."
    # Add your test commands here
}

release() {
    echo "Creating release for version $TRAVIS_TAG..."
    # Add your release commands here
}

# Check if the build is for a pull request
if [ "$TRAVIS_PULL_REQUEST"!= "false" ]; then
    echo "Build Pull Request #$TRAVIS_PULL_REQUEST => Branch [$TRAVIS_BRANCH]"
    run_tests
else
    release
fi