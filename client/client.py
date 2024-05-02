import socket
import time
from os import system


IP = '127.0.0.1'
PORT = 9015
BUF_LEN = 256

if __name__ == '__main__':
    while (True):
        time.sleep(0.5)
        request_buf = b'Hello, world!'
        
        client_fd = socket.socket(family=2, type=1)
        is_server_on = 0
        while (not is_server_on):
            try:
                client_fd.connect((IP, PORT))
                is_server_on = 1
            except ConnectionRefusedError:
                print('Server is turned off')
                time.sleep(10)
                
        client_fd.send(request_buf)
        
        response = client_fd.recv(BUF_LEN).decode()
        
        print(f'response: {response}')
        
        client_fd.close()
