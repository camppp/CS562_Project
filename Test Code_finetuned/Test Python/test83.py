import os

class CodeSnippetManager:
    def __init__(self):
        self.file_count = 0

    def get_pyname(self):
        self.file_count += 1
        return f'test_{self.file_count}'

    def write_file(self, code, directory='.'):
        filename = self.get_pyname()
        filepath = os.path.join(directory, filename)
        with open(filepath, 'w') as f:
            f.write(code)

# Usage
manager = CodeSnippetManager()
code_snippet = 'print("Hello, World!")'
manager.write_file(code_snippet)