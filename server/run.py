import compile
import termcolor
import subprocess
import config


if compile.compile():
    print(termcolor.colored('Compilation failed!', 'light_red'))
else:
    print(termcolor.colored('Compilation successful!', 'light_green'))

print(termcolor.colored('Server stdout:', 'light_grey'))
subprocess.call([f'{config.BIN_PATH}/{config.EXECUTABLE_FILE_NAME}'])