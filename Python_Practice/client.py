import socket
import os, sys

#HOST = '127.0.0.1'  # The server's hostname or IP address
#HOST = "192.168.1.69"
HOST = "192.168.1.73"
PORT = 65432        # The port used by the server

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST, PORT))
while True:
    msg = str(input("Enter Message:"))
    msg = str.encode(msg)
    s.sendall(msg)
    #s.sendall(b'Hello, world')
    data = s.recv(1024)
    print('Server:', repr(data.decode()))

s.close()
