#ifndef ADMIN_REQUEST_HANDLER_H
#define ADMIN_REQUEST_HANDLER_H

#include "../../../queue/dynamic_array.h"

typedef enum {
    PUSH,
    AUTH,
    NEW_ADMIN,
    EXIT,
} rcodes_admin;

extern int r_handler_admin(rcodes_admin rcode, int client_fd, char *buf, dynamic *queues);

#endif