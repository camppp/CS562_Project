import socket

def get_local_hostname():
    hostname = socket.gethostname()
    return hostname

if __name__ == '__main__':
    hostname = get_local_hostname()
    print(hostname)