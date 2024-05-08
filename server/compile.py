import subprocess
import config
import termcolor


def compile() -> int:
    res = subprocess.call([config.COMPILER,
                           '-fsanitize=address',
                           '-o',
                          f'{config.BIN_PATH}/{config.EXECUTABLE_FILE_NAME}',
                           '-g',
                          f'{config.SRC_PATH}/main.c',
                          f'{config.SRC_PATH}/util/u16_to_binstr.c',
                          f'{config.SRC_PATH}/util/binstr_to_u16.c',
                          f'{config.SRC_PATH}/util/binstr_to_u8.c',
                          f'{config.SRC_PATH}/util/binstr_print.c',
                          f'{config.SRC_PATH}/util/binstr_init.c',
                          f'{config.SRC_PATH}/util/str_to_u16.c',
                          f'{config.SRC_PATH}/util/u8_to_str.c',
                          f'{config.SRC_PATH}/util/reverse.c',
                          f'{config.SRC_PATH}/wrappers/malloc.c',
                          f'{config.SRC_PATH}/wrappers/socket.c',
                          f'{config.SRC_PATH}/hashmap/hash_map.c',
                          f'{config.SRC_PATH}/hashmap/my_hash.c',
                          f'{config.SRC_PATH}/hashmap/pair_list.c',
                          f'{config.SRC_PATH}/queue/dynamic_array.c',
                          f'{config.SRC_PATH}/queue/queue.c',
                          f'{config.SRC_PATH}/handler/header.c',                
                          f'{config.SRC_PATH}/handler/request_types/user.c',                
                          f'{config.SRC_PATH}/handler/request_types/admin.c',                
                          f'{config.SRC_PATH}/handler/request_types/system.c', 
                          f'{config.SRC_PATH}/handler/responses/response.c',  
                          f'{config.SRC_PATH}/args_are_invalid.c',           
                          ])
    
    return res


if __name__ == '__main__':
    if compile():
        print(termcolor.colored('Compilation failed!', 'light_red'))
    else:
        print(termcolor.colored('Compilation successful!', 'light_green'))