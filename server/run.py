import compile
import termcolor
import subprocess
import config
import sys
import time


if compile.compile():
    print(f'[{termcolor.colored("FAILED", "light_red")}] Compilation failed.')
    exit()
else:
    print(f'[  {termcolor.colored("OK", "light_green")}  ] Compilation successfull.')

server = subprocess.Popen([f'{config.BIN_PATH}/{config.EXECUTABLE_FILE_NAME}', sys.argv[1]], cwd='bin/')

time.sleep(0.5)
if server.poll():
    print(f'[{termcolor.colored("FAILED", "light_red")}] Server startup failed.')
    exit()
else:
    print(f'[  {termcolor.colored("OK", "light_green")}  ] Server started.')
    
    
while server.poll() is None:
    try:
        print('[  Oo  ] Server is running...', end='\r')
        time.sleep(0.2)
        print('[  oO  ] Server is running...', end='\r')
        time.sleep(0.2)
    except KeyboardInterrupt:
        server.terminate()
        

if server.poll():
    print(f'\r[{termcolor.colored("FAILED", "light_red")}] Server stopped due to a error.')
    exit()
else:
    print(f'\r[  {termcolor.colored("OK", "light_green")}  ] Server stopped successfully.')
    exit()