import os

class SimpleShell:
    def __init__(self):
        self.history = []
    
    def run(self):
        while True:
            command = input("SimpleShell $ ")
            if command == 'exit':
                break
            elif command == 'history':
                self.show_history()
            else:
                self.execute_command(command)
    
    def execute_command(self, command):
        self.history.append(command)
        try:
            result = os.popen(command).read()
            print(result)
        except Exception as e:
            print(f"Error: {e}")
    
    def show_history(self):
        print("Command History:")
        for i, command in enumerate(self.history, start=1):
            print(f"{i}. {command}")

if __name__ == "__main__":
    shell = SimpleShell()
    shell.run()
