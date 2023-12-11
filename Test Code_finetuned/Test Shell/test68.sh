#!/bin/bash

# Set default value for WAITER_PORT if not already set
: ${WAITER_PORT:=8080}

# Execute shell script with WAITER_PORT as argument
${WAITER_DIR}/bin/run-using-shell-scheduler.sh ${WAITER_PORT}

# Export environment variables for integration tests
export KITCHEN_DIR=/path/to/kitchen/dir
export NGINX_DIR=/path/to/nginx/dir
export SEDIMENT_DIR=/path/to/sediment/dir

# Run integration tests
${KITCHEN_DIR}/bin/kitchen -t ${WAITER_DIR}/test/integration/kitchen
${NGINX_DIR}/bin/run-nginx-server.sh ${WAITER_DIR}/test/integration/nginx
${SEDIMENT_DIR}/bin/run-sediment-server.sh ${WAITER_DIR}/test/integration/sediment