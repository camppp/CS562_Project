import os
import shutil

# Define paths
DATASET_DIR = "/path/to/dataset"
MODEL_DIR = "/path/to/model"
TRAIN_FEATURES_PREFIX = "/path/to/train/features"

# Set paths
INPUT_FILE = os.path.join(DATASET_DIR, "input.txt")
START_PATH = os.path.join(MODEL_DIR, "start.txt")
FINISH_PATH = os.path.join(MODEL_DIR, "finish.txt")
LOCK_PATH = os.path.join(MODEL_DIR, "lock.txt")
LAST_OUTPUT_FILE = os.path.join(MODEL_DIR, "last_output.txt")

# Create features directory if it does not exist
FEATURES_DIR = os.path.join(MODEL_DIR, "features")
if not os.path.exists(FEATURES_DIR):
    os.makedirs(FEATURES_DIR)

# Check if experiment was started before
if os.path.exists(START_PATH):
    # Perform cleanup if necessary
    if os.path.exists(FINISH_PATH):
        # Remove lock file
        if os.path.exists(LOCK_PATH):
            os.remove(LOCK_PATH)
        # Remove last output file
        if os.path.exists(LAST_OUTPUT_FILE):
            os.remove(LAST_OUTPUT_FILE)
        # Remove features directory
        if os.path.exists(FEATURES_DIR):
            shutil.rmtree(FEATURES_DIR)