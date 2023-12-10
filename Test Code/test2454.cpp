python
def extract_developers(file_path: str) -> dict:
    developers = {}
    with open(file_path, 'r') as file:
        lines = file.readlines()
        start_index = lines.index('** Developed by:                                                      **\n') + 1
        developer_lines = lines[start_index:]
        for line in developer_lines:
            if line.strip():
                developer = line.strip()
                developers[developer] = developers.get(developer, 0) + 1
    return developers
