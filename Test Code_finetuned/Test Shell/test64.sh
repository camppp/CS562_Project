#!/bin/bash

# Check if the deployment exists
deployment_exists=$(kubectl get deployment tekton-pipelines-webhook -n tekton-pipelines --no-headers -o name)

if [ -z "$deployment_exists" ]; then
    echo "Deployment tekton-pipelines-webhook does not exist in tekton-pipelines namespace."
    exit 1
fi

# Get the available replicas count
available_replicas=$(kubectl get deployment tekton-triggers-webhook -n tekton-pipelines -o jsonpath='{.status.availableReplicas}')

# Check if available replicas count is null or 0
if [ -z "$available_replicas" ] || [ "$available_replicas" -eq 0 ]; then
    echo "Available replicas count is null or 0 for tekton-triggers-webhook in tekton-pipelines namespace."
    # Add your specific action here
    # For example, you can scale the deployment
    kubectl scale deployment tekton-triggers-webhook -n tekton-pipelines --replicas=1
fi