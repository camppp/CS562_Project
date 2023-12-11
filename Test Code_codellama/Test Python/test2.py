def parse_names(value: str) -> List[str]:
    # Remove leading and trailing whitespace
    value = value.strip()

    # Split the input string into a list of names
    names = value.split()

    # Remove any empty strings from the list
    names = [name for name in names if name]

    # Remove any carriage return or newline characters
    names = [name.replace('\r', '').replace('\n', '') for name in names]

    return names