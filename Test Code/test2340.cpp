python
def match_file_type(file_path: str, file_type_pattern: str) -> bool:
    if "*" not in file_type_pattern:
        return file_path.endswith(file_type_pattern)
    else:
        prefix, suffix = file_type_pattern.split("*")
        return file_path.startswith(prefix) and file_path.endswith(suffix)
