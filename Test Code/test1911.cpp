python
from typing import Tuple

def find_license_agreement(file_path: str) -> Tuple[int, int]:
    start_line = -1
    end_line = -1

    with open(file_path, 'r') as file:
        lines = file.readlines()
        for i, line in enumerate(lines):
            if line.strip().startswith('**'):
                if start_line == -1:
                    start_line = i + 1
                else:
                    end_line = i + 1

    return (start_line, end_line)
