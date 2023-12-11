#!/bin/bash

# Get the domain from the specified route
HOST_FQDN=$(kubectl get route knative-eventing-in-mem-demo --output jsonpath='{.status.domain}' -n knative-eventing-in-mem-domain)

# Set the domain as an environment variable
export HOST_FQDN

# Print the environment variable
echo "HOST_FQDN is set to: $HOST_FQDN"