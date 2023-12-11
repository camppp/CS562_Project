import os
import subprocess

def main():
    # Change directory to /opt/graphite/webapp
    try:
        os.chdir('/opt/graphite/webapp')
    except OSError as e:
        print(f"Error changing directory: {e}")
        return

    # Execute Gunicorn Django server
    try:
        subprocess.run(['gunicorn', 'graphite.wsgi:application', '-b', '127.0.0.1:8000', '-w', '2', '--pythonpath', '.', '--settings', 'graphite.settings', '--log-file', '/srv/data/log/graphite.log'], check=True)
    except subprocess.CalledProcessError as e:
        print(f"Error running Gunicorn: {e}")
        return

if __name__ == "__main__":
    main()