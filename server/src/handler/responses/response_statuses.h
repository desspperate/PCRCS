#ifndef RESPONSE_STATUS_H
#define RESPONSE_STATUS_H

#define RESPONSE_STATUS_SIZE 0x4U

typedef enum {
    BUG = 0,
    SUCCESS = 1,
    QUEUE_CREATED = 91,
    COMMAND_RECEIVED = 92,
    QUEUE_IS_CLEAR = 93,
    RESULT_LOGGED = 94,
    RESULT_NOT_LOGGED = 181,
    BAD_REQUEST = 360,
} response_status;

#endif