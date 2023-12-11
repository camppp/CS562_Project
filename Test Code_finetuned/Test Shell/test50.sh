#!/bin/bash

# Check if cpus_per_task is set
if [ -z "$cpus_per_task" ]; then
    echo "Error: cpus_per_task is not set."
    exit 1
fi

# Check if NB_PROCS is set
if [ -z "$NB_PROCS" ]; then
    echo "Error: NB_PROCS is not set."
    exit 1
fi

# Set the mpirun command
mpirun_command="mpirun -np $NB_PROCS"

# Set the job submission system to PBS
job_submission_system="qsub"

# Print the commands
echo "mpirun command: $mpirun_command"
echo "Job submission system: $job_submission_system"