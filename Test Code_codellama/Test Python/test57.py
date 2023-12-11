import os

def calculate_total_size(directory_path):
    total_size = 0
    for root, dirs, files in os.walk(directory_path):
        for file in files:
            file_path = os.path.join(root, file)
            if os.path.islink(file_path):
                # If the file is a symbolic link, get the size of the file it points to
                file_size = os.path.getsize(os.readlink(file_path))
            else:
                # If the file is not a symbolic link, get its size directly
                file_size = os.path.getsize(file_path)
            total_size += file_size
    return total_size

directory_path = '/path/to/main_directory'
total_size = calculate_total_size(directory_path)
print(f'Total size: {total_size} bytes')