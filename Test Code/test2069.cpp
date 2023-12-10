def parse_header_info(file_path: str) -> dict:
    # Open the file and read its contents
    with open(file_path, "r") as f:
        contents = f.read()

    # Find the start of the header section
    start_index = contents.find("Following may not be used in part or in whole without the")

    # Find the end of the header section
    end_index = contents.find("Purpose:")

    # Extract the header section
    header = contents[start_index:end_index]

    # Split the header section into individual lines
    lines = header.split("\n")

    # Extract the author's name, date, and purpose from the header section
    author = lines[1].split(":")[1].strip()
    date = lines[2].split(":")[1].strip()
    purpose = lines[3].split(":")[1].strip()

    # Return a dictionary containing the extracted information
    return {"Author": author, "Date": date, "Purpose": purpose}
