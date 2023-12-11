def modify_file(file_path, word_to_modify):
    with open(file_path, "r") as f:
        file_contents = f.read()

    modified_contents = file_contents.replace(word_to_modify, word_to_modify + ",")

    with open(file_path, "w") as f:
        f.write(modified_contents)