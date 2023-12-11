import subprocess

def retrieve_memory_info(port: str, file_path: str) -> str:
    # Execute the ampy command with the appropriate arguments
    command = f"ampy -p {port} run {file_path}"
    result = subprocess.run(command, shell=True, stdout=subprocess.PIPE)

    # Return the memory information as a string
    return result.stdout.decode("utf-8")