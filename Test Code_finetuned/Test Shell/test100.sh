#!/bin/bash

# Arguments
EXAMPLE_PROJECT=$1
EXAMPLE_JAR=$2
EXAMPLE_CLASS_NAME=$3

# Check if the Dragonfly project exists
if! dragonfly project list | grep -q $EXAMPLE_PROJECT; then
    echo "Creating Dragonfly project: $EXAMPLE_PROJECT"
    if! dragonfly project create $EXAMPLE_PROJECT; then
        echo "Failed to create Dragonfly project: $EXAMPLE_PROJECT"
        exit 1
    fi
fi

# Deploy the JAR file to the Dragonfly project
echo "Deploying JAR file: $EXAMPLE_JAR to project: $EXAMPLE_PROJECT"
if! dragonfly deploy $EXAMPLE_PROJECT $EXAMPLE_JAR; then
    echo "Failed to deploy JAR file: $EXAMPLE_JAR to project: $EXAMPLE_PROJECT"
    exit 1
fi

# Execute the Java application
echo "Executing Java application: $EXAMPLE_CLASS_NAME"
if! dragonfly run $EXAMPLE_PROJECT $EXAMPLE_CLASS_NAME; then
    echo "Failed to execute Java application: $EXAMPLE_CLASS_NAME"
    exit 1
fi

echo "Deployment and execution of Java application completed successfully"