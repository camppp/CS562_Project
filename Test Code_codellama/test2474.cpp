def parse_http_response(response: str, fields: List[str]) -> Dict[str, str]:
    # Split the response header into individual lines
    lines = response.splitlines()

    # Initialize an empty dictionary to store the extracted header fields
    headers = {}

    # Iterate over the lines in the response header
    for line in lines:
        # Split the line into a key-value pair using the ':' character
        key, value = line.split(':', 1)

        # If the key is in the list of fields to extract, add it to the headers dictionary
        if key in fields:
            headers[key] = value.strip()

    # Return the headers dictionary
    return headers
