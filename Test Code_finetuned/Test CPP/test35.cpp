import os
import logging

def file_search(file_path):
    # Check if the file exists
    if os.path.isfile(file_path):
        return True
    else:
        # Log the unsuccessful file search
        logging.error(f"File {file_path} not found.")
        return False

def check_env_var():
    # Check if the environment variable exists
    if 'RCSRESOURCEPATH' in os.environ:
        return os.environ['RCSRESOURCEPATH']
    else:
        # Log the unsuccessful environment variable check
        logging.error("Environment variable RCSRESOURCEPATH not set.")
        return None

def main():
    # Get the environment variable
    rcs_resource_path = check_env_var()

    if rcs_resource_path is not None:
        # Search for the file in the environment variable path
        file_path = os.path.join(rcs_resource_path, 'your_file.txt')
        if file_search(file_path):
            print(f"File found at {file_path}")
        else:
            print(f"File not found at {file_path}")
    else:
        print("Environment variable not set.")

if __name__ == "__main__":
    main()