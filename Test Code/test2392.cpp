python
def set_titles(last_file_name_used: str) -> None:
    # Assuming files is a list of file objects or file names
    for i, file in enumerate(files, start=1):
        new_title = f"{last_file_name_used}{i}"
        # Set the title for the file using new_title
        file.set_title(new_title)
