import os

def count_file_extensions(file_paths):
    extension_counts = {}
    for file_path in file_paths:
        try:
            _, file_name = os.path.split(file_path)
            _, extension = os.path.splitext(file_name)
            if extension:
                extension = extension[1:]  # remove the dot
                if extension in extension_counts:
                    extension_counts[extension] += 1
                else:
                    extension_counts[extension] = 1
        except IOError:
            continue
    return extension_counts