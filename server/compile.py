import subprocess
import config
import termcolor


def compile() -> int:
    res = subprocess.call([config.COMPILER,
                           '-o',
                          f'{config.BIN_PATH}/{config.EXECUTABLE_FILE_NAME}',
                           '-g',
                          f'{config.SRC_PATH}/main.c',
                          f'{config.SRC_PATH}/util/u16_to_binstr.c',
                          f'{config.SRC_PATH}/util/binstr_to_u16.c',
                          f'{config.SRC_PATH}/util/binstr_to_u8.c',
                          f'{config.SRC_PATH}/util/u8_pow.c',
                          f'{config.SRC_PATH}/util/u16_pow.c',
                          f'{config.SRC_PATH}/util/binstr_print.c',
                          f'{config.SRC_PATH}/wrappers/malloc.c',                   
                          ])
    
    return res


if __name__ == '__main__':
    if compile():
        print(termcolor.colored('Compilation failed!', 'light_red'))
    else:
        print(termcolor.colored('Compilation successful!', 'light_green'))