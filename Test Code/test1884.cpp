python
def count_unique_contributors(file_path):
    contributors = set()
    with open(file_path, 'r') as file:
        lines = file.readlines()
        for line in lines:
            if line.startswith("// Copyright (C)"):
                contributor = line.split("by ")[1].strip()
                contributors.add(contributor)
    return len(contributors)

# Example usage
file_path = "path_to_source_code_file"
unique_contributors_count = count_unique_contributors(file_path)
print(unique_contributors_count)
