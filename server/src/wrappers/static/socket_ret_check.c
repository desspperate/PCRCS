#ifndef SOCKET_RET_CHECK_C
#define SOCKET_RET_CHECK_C

#include <stdlib.h>

static void socket_ret_check(int ret)
{
    if (ret == -1) {
        exit(EXIT_FAILURE);
    }
}

#endif