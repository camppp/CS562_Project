import os

# Initialize the command history list
history = []

# Define a function to execute a command
def execute_command(command):
    # Split the command into a list of arguments
    args = command.split()
    # Execute the command
    os.system(args[0], args[1:])
    # Add the command to the history list
    history.append(command)

# Define a function to print the command history
def print_history():
    # Print each command in the history list
    for command in history:
        print(command)

# Define a function to clear the command history
def clear_history():
    # Clear the history list
    history = []

# Define a function to handle user input
def handle_input():
    # Get the user input
    command = input("$ ")
    # Execute the command
    execute_command(command)

# Start the shell
while True:
    # Handle user input
    handle_input()