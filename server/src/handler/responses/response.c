#ifndef RESPONSE_C
#define RESPONSE_C

#include "response_statuses.h"
#include "../../wrappers/socket.h"

void response(int client_fd, response_status status)
{
    response_status status_ = status;
    send_(client_fd, &status_, RESPONSE_STATUS_SIZE, 0);
}

#endif