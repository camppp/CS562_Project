#!/bin/bash

# Check if this is a pull request
if [ "$TRAVIS_PULL_REQUEST" != "false" ]; then
  # If it is a pull request, echo the message and run the run_tests function
  echo "Build Pull Request #$TRAVIS_PULL_REQUEST => Branch [$TRAVIS_BRANCH]"
  run_tests
else
  # If it is not a pull request, directly execute the release function
  release
fi