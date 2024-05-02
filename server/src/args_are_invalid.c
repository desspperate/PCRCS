#ifndef ARGS_ARE_INVALID_C
#define ARGS_ARE_INVALID_C

#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "util/str_to_u16.h"

int args_are_invalid(int argc, char **argv)
{
    if (argc != 2) {
        return 1;
    }

    int i = 0;
    for (i = 0; i < strlen(argv[1]); ++i) {
        if (argv[1][i] > '9' || argv[1][i] < '0') {
            return 1;
        }
    }

    if (i > 4) {
        return 1;
    }

    u16 port = str_to_u16(argv[1], i + 1);
    if (!(port > 1023 && port < 10000)) {
        return 1;
    }

    return 0;
}

#endif