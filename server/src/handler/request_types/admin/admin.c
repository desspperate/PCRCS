#ifndef ADMIN_REQUEST_HANDLER_C
#define ADMIN_REQUEST_HANDLER_C

#include <assert.h>
#include <string.h>

#include "admin.h"
#include "../../header.h"
#include "../../response/response.h"
#include "../../operator/push.h"
#include "../../auth/auth_config.h"
#include "../../auth/new_admin.h"
#include "../../auth/get_access_level.h"
#include "../../../queue/dynamic_array.h"
#include "../../../wrappers/malloc.h"

#include "get_auth_data.h"

#include <stdio.h>

int r_handler_admin(rcodes_admin rcode, int client_fd, char *buf, dynamic *queues)
{
    assert(buf != NULL);
    assert(queues != NULL);

    if (check_auth_data(buf + HEADER_LEN)) {
        response(client_fd, INCORRECT_MARKING_OF_AUTH_DATA, NULL, 0);
        return 0;
    }

    char   *login = (char*)calloc_(MAX_LOGIN_LEN, sizeof(char));
    char   *pword = (char*)calloc_(MAX_PASSWORD_LEN, sizeof(char));
    size_t  login_len;
    size_t  pword_len;

    login_len = get_login(login, buf + HEADER_LEN);
    pword_len = get_pword(pword, buf + HEADER_LEN + login_len + 1);

    login = (char*)realloc_(login, (login_len + 1) * sizeof(char)); 
    pword = (char*)realloc_(pword, (pword_len + 1) * sizeof(char)); 

    access_level *al = (access_level*)malloc_(sizeof(access_level));
    int code = get_access_level(al, login, login_len, pword, pword_len);
    if (code) {
        response(client_fd, 543 + code, NULL, 0);
        return 0;
    }

    switch (rcode) {
        case PUSH:
            if (queues->length == 0) {
                response(client_fd, ZERO_USERS, NULL , 0);
                break;
            }

            char *command = buf + HEADER_LEN;
            operator_push(queues, command, strlen(command)+1);

            response(client_fd, SUCCESS_PUSH, NULL, 0);
            break;
        case AUTH:
            /* response(client_fd, ACCESS_LEVEL, get_access_level(), sizeof(access_level)); */

            response(client_fd, ACCESS_LEVEL, NULL, 0);
            break;
        case NEW_ADMIN:
            response(client_fd, ADMIN_ADDED, NULL, 0);
            break;
        case EXIT:
            response(client_fd, SUCCESS_EXIT, NULL, 0);
            return 1;
        default:
            response(client_fd, BAD_REQUEST, NULL, 0);
            break;
    }

    return 0;
}

#endif