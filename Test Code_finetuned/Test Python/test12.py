import os
import glob

def create_anomaly_directories(output_path, anomaly_types):
    full_paths = []
    for anomaly_type in anomaly_types:
        base_dir = os.path.join(output_path, anomaly_type)
        dir_name = base_dir
        suffix = 1
        while os.path.exists(dir_name):
            dir_name = f"{base_dir}_{suffix}"
            suffix += 1
        os.makedirs(dir_name)
        full_paths.append(dir_name)
    return full_paths