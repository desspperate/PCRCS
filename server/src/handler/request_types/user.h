#ifndef USER_REQUEST_HANDLER_H
#define USER_REQUEST_HANDLER_H

#include "../../hashmap/hash_map.h"

typedef enum {
    GET = 0,
    OUT = 1,
} rcodes_user;

extern void r_handler_user(rcodes_user rcode, int client_fd, char *buf, map **user_queues);

#endif