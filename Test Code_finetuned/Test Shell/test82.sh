#!/bin/bash

# Change directory to the "nginx-operator" directory
cd nginx-operator

# Create a copy of the file "deploy/operator.yaml" and name it "deploy/operator-copy.yaml"
cp deploy/operator.yaml deploy/operator-copy.yaml

# Replace the placeholder "REPLACE_IMAGE" in the "deploy/operator.yaml" file with the value of the variable $IMAGE
sed -i "s|REPLACE_IMAGE|$IMAGE|g" deploy/operator.yaml

# Store the current directory path in the variable OPERATORDIR
OPERATORDIR=$(pwd)

echo "Operator directory: $OPERATORDIR"