import json

class JsonVariableManager:
    def __init__(self):
        self.data = None

    def load_json_file(self, file_path):
        try:
            with open(file_path, 'r') as file:
                self.data = json.load(file)
        except FileNotFoundError:
            print(f"File not found at path: {file_path}")
        except json.JSONDecodeError:
            print(f"Invalid JSON format in file: {file_path}")

    def get_variable(self, key):
        try:
            return self.data[key]
        except TypeError:
            print("JSON data not loaded yet.")
        except KeyError:
            print(f"Key {key} not found in JSON data.")

    def update_variable(self, key, value):
        try:
            self.data[key] = value
        except TypeError:
            print("JSON data not loaded yet.")
        except KeyError:
            print(f"Key {key} not found in JSON data.")

    def save_json_file(self, file_path):
        try:
            with open(file_path, 'w') as file:
                json.dump(self.data, file)
        except TypeError:
            print("JSON data not loaded yet.")