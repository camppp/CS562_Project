import socket

class PortScanner:
    def __init__(self, target, portlist):
        self.target = target
        self.portlist = portlist

    def initialize_scan(self):
        print('[+] Initializing scan...')
        print('[i] Target host: {}'.format(self.target))
        print('[i] Ports: {}'.format(self.portlist))

    def scan_ports(self):
        for port in self.portlist:
            try:
                s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                s.connect((self.target, port))
                print('[+] Port {} is open'.format(port))
                s.close()
            except socket.error as e:
                print('[-] Port {} is closed'.format(port))
                print('[-] An error occurred during scanning: {}'.format(e))