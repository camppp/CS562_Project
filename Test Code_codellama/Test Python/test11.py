import os

def create_anomaly_directories(output_path, anomaly_types):
    # Create a list to store the full paths of the created directories
    directories = []

    # Iterate over the anomaly types
    for anomaly_type in anomaly_types:
        # Create a directory with the current anomaly type as the name
        directory = os.path.join(output_path, anomaly_type)

        # Check if the directory already exists
        if os.path.exists(directory):
            # If the directory already exists, append a numerical suffix to make it unique
            suffix = 1
            while True:
                new_directory = directory + "_" + str(suffix)
                if not os.path.exists(new_directory):
                    directory = new_directory
                    break
                suffix += 1

        # Add the full path of the created directory to the list
        directories.append(directory)

    # Return the list of full paths of the created directories
    return directories