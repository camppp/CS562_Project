import json

class JsonVariableManager:
    def __init__(self, file_path):
        self.file_path = file_path
        self.data = None

    def load_json_file(self, file_path):
        try:
            with open(file_path, 'r') as f:
                self.data = json.load(f)
        except FileNotFoundError:
            print(f"File not found: {file_path}")
        except json.JSONDecodeError:
            print(f"Invalid JSON format: {file_path}")

    def get_variable(self, key):
        if self.data is None:
            print("JSON file not loaded")
            return None
        if key not in self.data:
            print(f"Key not found: {key}")
            return None
        return self.data[key]

    def update_variable(self, key, value):
        if self.data is None:
            print("JSON file not loaded")
            return