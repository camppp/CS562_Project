#!/bin/bash

# Set the namespace
NAMESPACE="your-namespace"

# Get the list of pods in the namespace
PODS=$(kubectl get pods -n $NAMESPACE -o go-template --template '{{range.items}}{{.metadata.name}}{{"\n"}}{{end}}')

# Loop through each pod
for POD in $PODS
do
    # Get the status of the pod
    STATUS=$(kubectl get pods $POD -n $NAMESPACE -o go-template --template '{{.status.phase}}')

    # If the pod is not in the "Running" or "Completed" state, delete it
    if [ "$STATUS"!= "Running" ] && [ "$STATUS"!= "Completed" ]
    then
        echo "Deleting the pod : $POD"
        kubectl delete pods $POD -n $NAMESPACE --force --grace-period=0
    fi
done