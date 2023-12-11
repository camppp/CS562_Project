import getpass
import subprocess

def run_command(command):
    try:
        subprocess.run(command, check=True, text=True, input=password + '\n', capture_output=True)
    except subprocess.CalledProcessError as e:
        print(f"Error occurred: {e.stderr}")
    else:
        print("Command executed successfully.")

password = getpass.getpass(prompt="Enter sudo password: ")

# Stop pi-blaster service
stop_command = ["sudo", "service", "pi-blaster", "stop"]
run_command(stop_command)

# Start pi-blaster service with --pcm argument
start_command = ["sudo", "service", "pi-blaster", "start", "--pcm"]
run_command(start_command)