#ifndef RESPONSE_C
#define RESPONSE_C

#include <stddef.h>

#include "response_statuses.h"

extern void response(int client_fd, response_status status, char *data, size_t data_len);

#endif