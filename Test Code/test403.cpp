python
def parse_documentation(comment: str) -> (str, str):
    lines = comment.split('\n')
    return_value = None
    related_function = None
    for line in lines:
        if line.startswith("/// \treturn"):
            return_value = line.split("/// \treturn ")[1]
        elif line.startswith("/// \tsee"):
            related_function = line.split("/// \tsee ")[1]
    return return_value.strip(), related_function.strip()
