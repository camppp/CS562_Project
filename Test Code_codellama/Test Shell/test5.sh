#!/bin/bash

# Get the domain from the specified route
HOST_FQDN=$(kubectl get route knative-eventing-in-mem-demo --output jsonpath='{.status.domain}' -n knative-eventing-in-mem-domain)

# Set the HOST_FQDN environment variable
export HOST_FQDN=$HOST_FQDN