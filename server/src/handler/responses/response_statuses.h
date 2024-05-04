#ifndef RESPONSE_STATUS_H
#define RESPONSE_STATUS_H

#define RESPONSE_STATUS_SIZE 0x4U

typedef enum {
    BUG = 0,
    SUCCESS = 1,
    COMMAND_RECEIVED = 91,
    QUEUE_IS_CLEAR = 92,
    RESULT_LOGGED = 93,
    RESULT_NOT_LOGGED = 181,
    BAD_REQUEST = 360,
} response_status;

#endif