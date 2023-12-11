def count_copyright_notices(file_path: str) -> int:
    with open(file_path, 'r') as f:
        lines = f.readlines()

    copyright_notices = 0
    for line in lines:
        if '#' in line and 'copyright' in line.lower():
            copyright_notices += 1

    return copyright_notices