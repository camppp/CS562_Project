#!/bin/bash

# Source the common settings file
source migration_common_settings.sh

# Check if ORACLE_HOME is set and Oracle libraries are present
if [! -z "${ORACLE_HOME}" ] && [ -d "${ORACLE_HOME}/lib" ]; then
    # Append ${ORACLE_HOME}/lib to LD_LIBRARY_PATH
    export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${ORACLE_HOME}/lib
fi