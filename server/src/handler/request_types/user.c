#ifndef USER_REQUEST_HANDLER_C
#define USER_REQUEST_HANDLER_C

#include <assert.h>
#include <string.h>

#include "user.h"
#include "../responses/response.h"
#include "../../wrappers/malloc.h"
#include "../../wrappers/socket.h"
#include "../../util/u8_to_str.h"
#include "../../hashmap/hash_map.h"
#include "../../queue/queue.h"

typedef unsigned char u8;

void r_handler_user(rcodes_user rcode, int client_fd, char *buf, map **users_queues)
{
    assert(buf != NULL);
    assert(users_queues != NULL);
    assert(*users_queues != NULL);

    u8 user_id [16];
    for (int i = 0; i < 16; ++i) {
        user_id[i] = buf[2 + i];
    }

    char *user_id_str = (char*)calloc_(49, sizeof(char));
    int i = 0;
    for (int j = 0; j < 16; ++j) {
        char *user_id_str_chunk = u8_to_str(user_id[j]);
        int k = 0;
        while (user_id_str_chunk[k] != 0) {
            user_id_str[i] = user_id_str_chunk[k];
            i++; k++;
        }
        free_(user_id_str_chunk);
    }
    user_id_str = (char*)realloc_(user_id_str, (i + 1) * sizeof(char));

    switch (rcode) {
        case GET:
            queue *user_queue;
            if ((user_queue = map_get(*users_queues, user_id_str)) == NOT_FOUND) {
                char* user_id_str_copy = (char*)calloc_(i + 1, sizeof(char));
                for (int j = 0; j < i + 1; ++j) {
                    user_id_str_copy[j] = user_id_str[j];
                }
                
                user_queue = queue_init();
                map_put(users_queues, user_id_str_copy, user_queue);
                response(client_fd, QUEUE_CREATED, NULL, 0);
            } else {
                if (queue_is_empty(user_queue)) {
                    response(client_fd, QUEUE_IS_CLEAR, NULL, 0);
                } else {
                    u8 *command = (u8*)queue_pop(user_queue);
                    response(client_fd, COMMAND_RECEIVED, command, strlen((char*)command));
                    free_(command);
                }
            }
            break;
        case OUT:
            /* write command result in user log */
            response(client_fd, RESULT_LOGGED, NULL, 0);
            break;
        default:
            response(client_fd, BAD_REQUEST, NULL, 0);
            break;
    }

    free_(user_id_str);
}

#endif