class FileProcessingException(Exception):
    def __init__(self, message):
        super().__init__(message)

def process_file(file_path):
    try:
        with open(file_path, 'r') as file:
            # Perform file processing here
            # For the purpose of this problem, we'll just return the file contents
            return file.read()
    except FileNotFoundError:
        raise FileProcessingException("File not found")
    except Exception as e:
        raise FileProcessingException("Error processing file")
    return "File processed successfully"