#!/bin/bash

# Run the installation script with elevated privileges
sudo./install.sh

# Check the exit status of the installation script
if [ $? -ne 0 ]; then
    echo "Installation failed. Exiting."
    exit 1
fi

# If the installation is successful, execute the examples script
./examples.sh

# Print "Done" to indicate successful completion
echo "Done"