import os
import psutil

# Define the process name pattern to match
process_name = "python mp_classify"

# Get a list of all running processes
processes = psutil.process_iter()

# Iterate over the list of processes and check if the process name matches the pattern
for process in processes:
    try:
        # Get the process name
        process_name = process.name()

        # Check if the process name matches the pattern
        if process_name.startswith(process_name):
            # Terminate the process
            process.terminate()
            print(f"Terminated process {process_name}")
    except psutil.NoSuchProcess:
        # Process has already terminated
        pass