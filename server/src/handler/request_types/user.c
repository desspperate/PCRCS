#ifndef USER_REQUEST_HANDLER_C
#define USER_REQUEST_HANDLER_C

#include <stdio.h>

#include "user.h"
#include "../../wrappers/socket.h"
#include "../responses/response.h"

typedef unsigned char u8;

void r_handler_user(rcodes_user rcode, int client_fd, char *buf)
{
    u8 user_id [16];
    for (int i = 0; i < 16; ++i) {
        user_id[i] = buf[2 + i];
    }

    switch (rcode) {
        case GET:
            /* get command from user queue and send it to user */
            response(client_fd, COMMAND_RECEIVED);
            break;
        case OUT:
            /* write command result in user log */
            response(client_fd, RESULT_LOGGED);
            break;
        default:
            response(client_fd, BAD_REQUEST);
            break;
    }
}

#endif