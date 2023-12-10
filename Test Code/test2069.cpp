python
def parse_header_info(file_path: str) -> dict:
    header_info = {}
    try:
        with open(file_path, 'r') as file:
            lines = file.readlines()
            header_started = False
            for line in lines:
                if line.strip() == "Author: <NAME>":
                    header_started = True
                    continue
                if header_started and line.strip() != "":
                    key, value = line.strip().split(": ", 1)
                    header_info[key] = value
                elif header_started and line.strip() == "":
                    break
    except FileNotFoundError:
        pass
    return header_info
