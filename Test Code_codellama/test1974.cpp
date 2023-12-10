class FileTransferDTO:
    def __init__(self, required_to_added_to_command_line, data_staged, storage_resource_id):
        self.required_to_added_to_command_line = required_to_added_to_command_line
        self.data_staged = data_staged
        self.storage_resource_id = storage_resource_id

    def to_string(self):
        return f"Command-line arguments: {self.required_to_added_to_command_line}, Data staged: {self.data_staged}, Storage resource ID: {self.storage_resource_id}"
