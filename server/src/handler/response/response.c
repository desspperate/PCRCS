#ifndef RESPONSE_C
#define RESPONSE_C

#include "response_statuses.h"
#include "../../wrappers/socket.h"
#include "../../wrappers/malloc.h"

typedef unsigned char u8;

typedef union {
    u8  bytes [4];
    int i;
} raw_response_status;

void response(int client_fd, response_status status, u8 *data, size_t data_len)
{
    if (data == NULL) {
        response_status status_ = status;
        send_(client_fd, &status_, RESPONSE_STATUS_SIZE, 0);
        return;
    }

    u8 *response = (u8*)calloc_(data_len + RESPONSE_STATUS_SIZE, sizeof(char));
    raw_response_status raw_status = { status };
    for (int i = 0; i < 4; ++i) {
        response[i] = raw_status.bytes[i];
    }
    for (int i = 0; i < data_len; ++i) {
        response[i + 4] = data[i]; 
    }
    
    send_(client_fd, response, data_len + RESPONSE_STATUS_SIZE, 0);
    free_(response);
}

#endif