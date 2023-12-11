#!/bin/bash

# Check if ORACLE_HOME is set and Oracle libraries are present in the specified directory
if [ ! -z ${ORACLE_HOME} ] && [ -d ${ORACLE_HOME}/lib ]; then
  # Add ${ORACLE_HOME}/lib to LD_LIBRARY_PATH
  export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${ORACLE_HOME}/lib
fi