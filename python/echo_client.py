import socket

HOST = "127.0.0.1"
PORT = 18200

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
    sock.connect((HOST, PORT))
    while True:
        data = sock.recv(1024)
        print(f"Received: {data}")
