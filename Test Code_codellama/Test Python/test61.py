import os

def classify_file(file_path):
    file_type = None
    if file_path.endswith(('.txt', '.text')):
        file_type = 'text'
    elif file_path.endswith(('.jpg', '.jpeg', '.png', '.gif')):
        file_type = 'image'
    elif file_path.endswith(('.exe', '.dll', '.so', '.dylib')):
        file_type = 'binary'
    else:
        file_type = 'other'
    return file_type

def count_files(directory):
    file_counts = {}
    for root, dirs, files in os.walk(directory):
        for file in files:
            file_path = os.path.join(root, file)
            file_type = classify_file(file_path)
            if file_type not in file_counts:
                file_counts[file_type] = 0
            file_counts[file_type] += 1
    return file_counts

def main():
    directory = '/path/to/data/directory'
    file_counts = count_files(directory)
    print('File types and their counts:')
    for file_type, count in file_counts.items():
        print(f'{file_type}: {count}')

if __name__ == '__main__':
    main()