def extract_developers(file_path: str) -> dict:
    with open(file_path, 'r') as f:
        text = f.read()

    developers = []
    for line in text.splitlines():
        if line.startswith('Developed by:'):
            developers.append(line.split(':')[1].strip())

    return {developer: developers.count(developer) for developer in developers}
