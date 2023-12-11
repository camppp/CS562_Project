import socket

def server(address: str, port: int) -> None:
    # Create a socket object
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Set socket options to enable address reuse
    server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

    # Bind the socket to the address and port
    server_socket.bind((address, port))

    # Listen for incoming connections
    server_socket.listen(5)

    print(f"Server is listening on {address}:{port}")

    while True:
        # Accept incoming connections
        client_socket, client_address = server_socket.accept()
        print(f"Accepted connection from {client_address}")

        # Close the client socket
        client_socket.close()

# Test the server
server('127.0.0.1', 8080)