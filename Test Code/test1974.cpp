python
class FileTransferDTO:
    def __init__(self, required_to_added_to_command_line, data_staged, storage_resource_id):
        self.requiredToAddedToCommandLine = required_to_added_to_command_line
        self.dataStaged = data_staged
        self.storageResourceId = storage_resource_id

    def to_string(self):
        return f"Command-line arguments: {self.requiredToAddedToCommandLine}, Data staged: {self.dataStaged}, Storage resource ID: {self.storageResourceId}"

# Example usage
dto = FileTransferDTO("-f file.txt -o output.txt", True, 12345)
print(dto.to_string())  # Output: Command-line arguments: -f file.txt -o output.txt, Data staged: True, Storage resource ID: 12345
