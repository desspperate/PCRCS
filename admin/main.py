from fastapi import FastAPI
import socket
import config
from expression_ids import ids
from responses import responses


SEPARATOR_CHAR = 1


app = FastAPI()


@app.get('/{expression}')
def expression_handler(expression: str):
    client_fd = socket.socket() 
    
    try:
        client_fd.connect((config.IP, config.PORT))
    except ConnectionRefusedError:
        return 'PCRCS server is turned off.'
    
    end_of_id = 0
    while expression[end_of_id] != ' ':
        end_of_id += 1
        if end_of_id == len(expression) - 1:
            end_of_id += 1
            break
    
    global id_num
    try:
        id_num = ids[expression[0:end_of_id]]
    except KeyError:
        return 'This expression id is\'t exists.'

    code_bin = bin(id_num)[2:]
    while len(code_bin) != 11:
        code_bin = '0' + code_bin
    type_bin = '00001'
    header_bin = type_bin + code_bin
    
    request_buf = bytearray()
    
    for i in int.to_bytes(int(header_bin, 2), 2, 'big'):
        request_buf.append(i)
    
    if id_num == 0:
        command_start = expression.find('"')
        command_end = expression[command_start+1:].find('"') + command_start
        for i in expression[command_start+1:command_end+1]:
            request_buf.append(ord(i))
    if id_num == 2:
        login_start = expression.find('"')
        login_end = expression[login_start+1:].find('"') + login_start
        for i in expression[login_start+1:login_end+1]:
            request_buf.append(ord(i))
        request_buf.append(SEPARATOR_CHAR)
        pword_start = expression[login_end+2:].find('"') + login_end + 2
        pword_end = expression[pword_start+1:].find('"') + pword_start
        for i in expression[pword_start+1:pword_end+1]:
            request_buf.append(ord(i))
        request_buf.append(SEPARATOR_CHAR)
        for i in expression.split()[-1][1:-1]:
            request_buf.append(ord(i))
        request_buf.append(ord('\n'))
    
    client_fd.send(request_buf)
    server_response = client_fd.recv(4)
    client_fd.close()
    
    return responses[int.from_bytes(server_response, 'little')]
